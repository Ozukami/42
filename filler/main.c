/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 23:52:54 by apoisson          #+#    #+#             */
/*   Updated: 2017/02/07 06:21:46 by qumaujea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>
#include <stdio.h>

int	debug = 0;

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

t_place		*ft_new_place(int x, int y)
{
	t_place	*new;
	
	new = ft_memalloc(sizeof(t_place));
	new->x = x;
	new->y = y;
	return (new);
}

void		ft_add_place(t_place **list, t_place *new)
{
	new->next = *list;
	*list = new;
}

int			ft_check_place(t_info *info, int x, int y)
{
	int		i;
	int		j;
	int		verif;

	i = 0;
	j = 0;
	verif = 0;
	if (x + info->x_piece > info->x_map
			|| y + info->y_piece > info->y_map)
		return (0);
	while ((info->piece)[i])
	{
		j = 0;
		while ((info->piece)[i][j])
		{
			if ((info->piece)[i][j] != '.')
			{
				if ((info->piece)[i + x][j + y] != '.')
				{
					if ((info->map)[i + x][j + y] != info->player)
						return (0);
					else
						if (verif++)
							return (0);
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}	

void		ft_get_place(t_info *info)
{
	int		x;
	int		y;
	t_place	*list;

	x = 0;
	while ((info->map)[x])
	{	
		y = 0;
		while ((info->map)[x][y])
		{
			if (ft_check_place(info, x, y))
				ft_add_place(&list, ft_new_place(x, y));
			y++;
		}
		x++;
	}
	if (list)
		dprintf(1, "%d %d\n", list->x, list->y);
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
/*
		x = 0;
		while (x < info->x_map)
		{
			y = 0;
			while (y < info->y_map)
			{
				if ((info->map)[x][y] == info->player
						|| (info->map)[x][y] == info->player - 32)
					ft_place(info, x, y);
					//	break ;
				y++;
			}
			if ((info->map)[x][y] == info->player
					|| (info->map)[x][y] == info->player - 32)
				break ;
			x++;
		}
*/
		ft_get_place(info);
		x = 0;
		y = 0;
		if (debug)
		{
			dprintf(fd, "%d %d\n", x, y);
			dprintf(fd, "nb_piece = %d\n", ++nb_piece);
		}
//		dprintf(1, "%d %d\n", x, y);
	}
	return (0);
}
