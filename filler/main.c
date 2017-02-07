/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 23:52:54 by apoisson          #+#    #+#             */
/*   Updated: 2017/02/07 04:39:09 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>
#include <stdio.h>

int	debug = 1;

void	ft_display_map(char **map, int fd)
{
	int	i;

	i = 0;
	while (map[i])
	{
		dprintf(fd, "%s\n", map[i]);
		i++;
	}
}

void	ft_display_info(t_info *info, int fd)
{
	dprintf(fd, "Player : %c\n", info->player);
	dprintf(fd, "Map : %d %d\n", info->x_map, info->y_map);
	ft_display_map(info->map, fd);
	dprintf(fd, "Piece : %d %d\n", info->x_piece, info->y_piece);
	ft_display_map(info->piece, fd);
}

int		main(void)
{
	char	*path = "log.txt";
	int		fd = open(path, O_WRONLY | O_CREAT | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	int	nb_piece = 0;

	t_info	*info;
	char	*line;
	int		i;
	int		x;
	int		y;
	
	get_next_line(0, &line);
	info = ft_new_info(((line[10] == '1') ? 'o' : 'x'));
	dprintf(fd, "LIGNE 1 : %s\n\n", line);

	while (1)
	{
		if (get_next_line(0, &line))
			dprintf(fd, "> %s\n", line);
		i = 0;
		while (line[i])
		{
			if (line[i] > '0' && line[i] < '9')
			{
				info->x_map = ft_atoi(line + i);
				while (line[i] > '0' && line[i] < '9')
					i++;
				info->y_map = ft_atoi(line + i);
				dprintf(fd, "Map (MaJ) : [%d|%d]\n", info->x_map, info->y_map);
				break ;
			}
			i++;
		}
		info->map = ft_memalloc((sizeof(char *)) * (info->x_map + 1));
		(info->map)[info->x_map] = 0;
		get_next_line(0, &line);
		i = 0;
		while (i < info->x_map)
		{
			get_next_line(0, &line);
			(info->map)[i] = ft_strdup(ft_strsub(line, 4, info->x_map));
			i++;
		}

		if (debug)
			ft_display_map(info->map, fd);

		get_next_line(0, &line);
		i = 0;
		while (line[i])
		{
			if (line[i] > '0' && line[i] < '9')
			{
				info->x_piece =	ft_atoi(line + i);
				while (line[i] > '0' && line[i] < '9')
					i++;
				info->y_piece =	ft_atoi(line + i);
				dprintf(fd, "Piece (Maj) : [%d|%d]\n", info->x_piece, info->y_piece);
				break ;
			}
			i++;
		}
		info->piece = ft_memalloc((sizeof(char *)) * (info->x_piece + 1));
		info->piece[info->x_piece] = 0;
		i = 0;
		while (i < info->x_piece)
		{
			get_next_line(0, &line);
			(info->piece)[i] = ft_strdup(line);
			i++;
		}

		if (debug)
			ft_display_map(info->piece, fd);

		x = 0;
		while (x < info->x_map)
		{
			y = 0;
			while (y < info->y_map)
			{
				if ((info->map)[x][y] == info->player
						|| (info->map)[x][y] == info->player - 32)
					break ;
				y++;
			}
			if ((info->map)[x][y] == info->player
					|| (info->map)[x][y] == info->player - 32)
				break ;
			x++;
		}
		if (debug)
		{
			dprintf(fd, "%d %d\n", x, y);
			dprintf(fd, "nb_piece = %d\n", ++nb_piece);
		}
		dprintf(1, "%d %d\n", x, y);
	}
	return (0);
}
