/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 11:12:54 by apoisson          #+#    #+#             */
/*   Updated: 2016/12/03 14:40:39 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		main(int ac, char **av)
{
	char	*line;
	int		fd;
	int		fd2;
	int		fd3;

	fd = 0;
	if (ac == 1)
	{
		while (get_next_line(fd, &line) > 0)
			ft_putendl(line);
	}
	else if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		while (get_next_line(fd, &line) > 0)
			ft_putendl(line);
	}
	else if (ac == 4)
	{
		fd = open(av[1], O_RDONLY);
		fd2 = open(av[2], O_RDONLY);
		fd3 = open(av[3], O_RDONLY);
		get_next_line(fd, &line);
		ft_putendl(line);
		get_next_line(fd2, &line);
		ft_putendl(line);
		get_next_line(fd3, &line);
		ft_putendl(line);
		get_next_line(fd3, &line);
		ft_putendl(line);
		get_next_line(fd, &line);
		ft_putendl(line);
		get_next_line(fd, &line);
		ft_putendl(line);
		get_next_line(fd2, &line);
		ft_putendl(line);
		get_next_line(fd, &line);
		ft_putendl(line);
		get_next_line(fd2, &line);
		ft_putendl(line);
		get_next_line(fd2, &line);
		ft_putendl(line);
		get_next_line(fd3, &line);
		ft_putendl(line);
		get_next_line(fd3, &line);
		ft_putendl(line);
		close(fd);
		close(fd2);
		close(fd3);
	}
	return (0);
}
