/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumaujea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 00:34:46 by qumaujea          #+#    #+#             */
/*   Updated: 2017/06/09 08:22:17 by apoisson         ###   ########.fr       */
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

void	check_line(char *line)
{
	int			i;
	int			label;

	label = check_label(line);
	i = -1;
	while (str[++i])
	{
		if (label)
	}
}

void	get_comment(t_header *header, char *line, int verif)
{
	int		i;

	if (verif == 6)
		ft_perror("Error: too many .comment");
	i = -1;
	while (line[++i] && line[i] != )
	{

	}
	return (verif);
}

int		check_header(t_header *header, char *line)
{
	static int	verif = 0;
	int			i;

	i = -1;
	while (line[++i])
	{
		while (ft_check_spaces(line[i]))
			i++;
		if (line[i] == '.')
		{
			if (ft_strequ(ft_strsub(line, i + 1, 6), "comment"))
				return (get_comment(header, line, verif += 3));
			else if (ft_strequ(ft_strsub(line, i + 1, 4), "name"))
				return (get_name(header, line, verif += 1));
			else
				ft_perror("Error: lexical error");
		}
		else if (verif != 4 && !ft_check_spaces(line[i]) && line[i])
			ft_perror("Error: lexical error");
	}
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
	while (get_next_line(fd, &line))
	{
		r += check_header(header, line);
		if (r < 0 || r == 2 || r > 4)
			ft_perror("Error: bad header");
		if (r == 4)
			break ;
	}
	/*
	while (get_next_line(fd, &line))
		check_line(line);
		*/
	if (close(fd) == -1)
		ft_perror("Error: close failed");
	return (0);
}
