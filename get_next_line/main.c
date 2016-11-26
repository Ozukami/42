/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 11:12:54 by apoisson          #+#    #+#             */
/*   Updated: 2016/11/23 09:08:55 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

void	f(void)
{
	static int	i = 0;

	printf("%d\n", i);
	i++;
}

int		main(int ac, char **av)
{
	char	*line;
	int		fd;

	fd = 0;
	if (ac == 1)
		while (get_next_line(fd, &line))
			ft_putendl(line);
	else if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		while (get_next_line(fd, &line))
			ft_putendl(line);
		/*
		{
			ft_putchar('[');
			ft_putstr(line);
			ft_putchar(']');
		}*/
	}
	return (0);
}
