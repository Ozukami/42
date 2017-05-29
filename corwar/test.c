/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumaujea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 00:34:46 by qumaujea          #+#    #+#             */
/*   Updated: 2017/05/29 02:13:16 by qumaujea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <fcntl.h>

int		check_label(char *str)
{
	if (str[ft_strlen(str) - 1] == ':')
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
			asm_to_hex(split[i], split[i + 1]);
			i++;
		}
	}
}

int		main(int ac, char **av)
{
	char 	*line;

	if (!ac)
		return (1);
	while (get_next_line(0, &line))
		check_line(line);
	return (0);
}
