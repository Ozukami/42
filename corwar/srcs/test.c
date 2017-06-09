/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumaujea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 00:34:46 by qumaujea          #+#    #+#             */
/*   Updated: 2017/06/09 09:45:17 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <fcntl.h>
#include "op.h"
#include "corewar.h"

int		check_label(char *str)
{
	int			i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '%')
			return (0);
		if (str[i] == ':')
			return (1);
	}
	return (0);
}

int		get_name(t_header *header, char **split, int verif)
{
	if (split[2])
		ft_perror("Error: lexical error");
	if (verif == 2)
		ft_perror("Error: too many .name");
	if (ft_strlen(split[1]) > PROG_NAME_LENGTH)
		ft_perror("Error: name is too large");
	ft_strcpy(header->prog_name, (const char *)split[1]);
	return (verif);
}

int		get_comment(t_header *header, char **split, int verif)
{
	if (split[2])
		ft_perror("Error: lexical error");
	if (verif == 6)
		ft_perror("Error: too many .comment");
	if (ft_strlen(split[1]) > COMMENT_LENGTH)
		ft_perror("Error: comment is too large");
	ft_strcpy(header->comment, (const char *)split[1]);
	return (verif);
}

int		check_header(t_header *header, char *line)
{
	static int	verif = 0;

	if (!line)
		return (0);
	if (line[0] == '.')
	{
		if (ft_strequ(ft_strsub(line, 1, 7), "comment"))
			return (get_comment(header, ft_strsplit(line, '\"'), verif += 3));
		else if (ft_strequ(ft_strsub(line, 1, 4), "name"))
			return (get_name(header, ft_strsplit(line, '\"'), verif += 1));
		else
			ft_perror("Error: lexical error");
	}
	else if (verif != 4)
		ft_perror("Error: lexical error");
	return (0);
}

int		main(int ac, char **av)
{
	int			fd;
	int			r;
	t_header	*header;
	char 		*line;

	if (ac < 2)
		ft_perror("usage: ./asm champ.s");
	if ((fd = open(av[1], O_RDONLY)) == -1)
		ft_perror("Error: open failed");
	if (!(header = ft_memalloc(sizeof(t_header))))
		ft_perror("Malloc failed");
	while (get_next_line(fd, &line) && r != 4)
		r += check_header(header, str_epur(line));
	/*
	while (get_next_line(fd, &line))
		check_line(line);
		*/
	if (close(fd) == -1)
		ft_perror("Error: close failed");
	return (0);
}
