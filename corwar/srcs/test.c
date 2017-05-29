/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumaujea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 00:34:46 by qumaujea          #+#    #+#             */
/*   Updated: 2017/05/29 04:45:34 by qumaujea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <fcntl.h>
#include "op.h"
#include "corewar.h"

int		check_label(char *str)
{
	if (str[ft_strlen(str) - 1] == ':')
		return (1);
	return (0);
}

int		check_op(char *str)
{
	int		i;

	i = -1;
	while (++i < 17)
		if (ft_strequ((g_op_tab[i]).op, str))
			return (1);
	return (0);
}

void	asm_to_hex(char *op, char *arg)
{
	printf("%s	%s\n", op, arg);
}

void	check_line(char *line)
{
	char **split;

	split = ft_strsplit_whitespaces(line, ' ', '	');
	int i = -1;
	while (split[++i])
	{
		if (!check_label(split[i]))
		{
			if (!check_op(split[i]))
				exit(0);
			/*
			if (!check_args(split[i + 1]))
*/
			asm_to_hex(split[i], split[i + 1]);
			i++;
		}
	}
}

int		main(int ac, char **av)
{
	char 	*line;

	(void)av;
	if (!ac)
		return (1);
	while (get_next_line(0, &line))
		check_line(line);
	return (0);
}
