/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumaujea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 00:34:46 by qumaujea          #+#    #+#             */
/*   Updated: 2017/06/10 02:47:19 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <fcntl.h>
#include "op.h"
#include "corewar.h"

int		get_label(char *str, t_instruction *instruction)
{
	int			i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
	{
		if ((!ft_strchr(LABEL_CHARS, str[i]) && str[i] != LABEL_CHAR)
				|| str[i] == DIRECT_CHAR)
			return (0);
		if (str[i] == LABEL_CHAR)
		{
			instruction->label = ft_strsub(str, 0, i);
			return (i);
		}
	}
	return (0);
}

/*
** Verify if the op using the automaton
** and stock it into instruction
*/

int		get_op(char *str, t_instruction *instruction)
{

	(void)str;
	(void)instruction;
	return (1);
}

/*
** Verify if the params match with the op
** and stock it into instruction
*/

int		get_args(char *str, t_instruction *instruction)
{

	(void)str;
	(void)instruction;
	return (1);
}

t_instruction	*get_instruction(char *line)
{
	t_instruction	*instruction;
	int				i;

	if (!(instruction = ft_memalloc(sizeof(t_instruction))))
		ft_perror("Error: malloc failed");
	instruction->label = NULL;
	instruction->next = NULL;
	if ((i = get_label(line, instruction)) > 0)
		line = str_epur(ft_strsubf(line, i + 1, ft_strlen(line) - i));
	if ((i = get_op(line, instruction)) < 1)
		ft_perror("Error: syntax error");
	line = str_epur(ft_strsubf(line, i + 1, ft_strlen(line) - i));
	if ((i = get_args(line, instruction)) < 1)
		ft_perror("Error: syntax error");
	return (instruction);
}

int		get_name(t_header *header, char **split, int verif)
{
	if (split[2])
		ft_perror("Error: lexical error");
	if (verif == 2)
		ft_perror("Error: too many .name");
	if (ft_strlen(split[1]) > PROG_NAME_LENGTH)
		ft_perror("Error: name is too large");
	ft_strcpy(header->prog_name, split[1]);
	free_map(split);
	return (1);
}

int		get_comment(t_header *header, char **split, int verif)
{
	if (split[2])
		ft_perror("Error: lexical error");
	if (verif == 6)
		ft_perror("Error: too many .comment");
	if (ft_strlen(split[1]) > COMMENT_LENGTH)
		ft_perror("Error: comment is too large");
	ft_strcpy(header->comment, split[1]);
	free_map(split);
	return (3);
}

int		check_header(t_header *header, char *line)
{
	static int	verif = 0;

	printf("|%s|\n", line);
	if (!line)
		return (0);
	if (line[0] == COMMENT_CHAR)
		return (0);
	if (line[0] == '.')
	{
		if (ft_strequf_l(ft_strsub(line, 0, 8), COMMENT_CMD_STRING))
			return (get_comment(header, ft_strsplitf(line, '\"'), verif += 3));
		else if (ft_strequf_l(ft_strsub(line, 0, 5), NAME_CMD_STRING))
			return (get_name(header, ft_strsplitf(line, '\"'), verif += 1));
		else
			ft_perror("Error: lexical error");
	}
	else if (verif != 4)
		ft_perror("Error: lexical error");
	return (0);
}

void	parse_file(int fd, t_header *header)
{
	int			r;
	char		*line;
	t_instruction	*l_inst;
	t_instruction	*current;

	r = 0;
	while (r != 4 && get_next_line(fd, &line))
		r += check_header(header, str_epur(line));
	while (get_next_line(fd, &line))
	{
		if ((line = str_epur(line)) && line[0] != COMMENT_CHAR)
			break ;
		ft_strdel(&line);
	}
	l_inst = get_instruction(str_epur(line));
	current = l_inst;
	while (get_next_line(fd, &line))
	{
		if (line[0] && line[0] != COMMENT_CHAR)
		{
			current->next = get_instruction(str_epur(line));
			current = current->next;
		}
	}
	while (1)
		;
}

int		main(int ac, char **av)
{
	int			fd;
	t_header	*header;

	if (ac < 2)
		ft_perror("usage: ./asm champ.s");
	if ((fd = open(av[1], O_RDONLY)) == -1)
		ft_perror("Error: open failed");
	if (!(header = ft_memalloc(sizeof(t_header))))
		ft_perror("Error: malloc failed");
	parse_file(fd, header);
	if (close(fd) == -1)
		ft_perror("Error: close failed");
	return (0);
}
