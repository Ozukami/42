/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 23:52:54 by apoisson          #+#    #+#             */
/*   Updated: 2017/02/07 03:59:11 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*path;
	int		fd;
	char	*line;
	int		i;
	char	p;
	char	**map;
	int		x_map;
	int		y_map;
	char	**piece;
	int		n_piece;
	int		m_piece;
	int		x;
	int		y;
	
	path = "log.txt";
	fd = open(path, O_WRONLY | O_CREAT | O_TRUNC);
	i = 0;
	map = NULL;
	piece = NULL;
	x_map = 0;
	y_map = 0;
	n_piece = 0;
	m_piece = 0;
	p = 'x';
	x = 0;
	y = 0;
	get_next_line(0, &line);
	dprintf(fd, "LIGNE 1 : %s\n\n", line);
	while (1)
	{
		if (get_next_line(0, &line))
			dprintf(fd, "	%s\n", line);
		//get_next_line(0, &line);
		//write(fd, line, ft_strlen(line));
		//line = ft_strdup("Plateau 8 7:\n");
		while (line[i])
		{
			if (line[i] > '0' && line[i] < '9')
			{
				x_map =	ft_atoi(line + i);
				while (line[i] > '0' && line[i] < '9')
					i++;
				y_map =	ft_atoi(line + i);
				dprintf(fd, "Map : [%d|%d]\n", x_map, y_map);
				break ;
			}
			i++;
		}
		map = ft_memalloc((sizeof(char *)) * (x_map + 1));
		map[x_map] = 0;
		i = 0;
		get_next_line(0, &line);
		while (i < x_map)
		{
			get_next_line(0, &line);
			map[i] = ft_strdup(ft_strsub(line, 4, x_map));
			i++;
		}
		i = 0;
		while (map[i])
		{
			dprintf(fd, "%s\n", map[i]);
			i++;
		}

		i = 0;
		get_next_line(0, &line);
		while (line[i])
		{
			if (line[i] > '0' && line[i] < '9')
			{
				n_piece =	ft_atoi(line + i);
				while (line[i] > '0' && line[i] < '9')
					i++;
				m_piece =	ft_atoi(line + i);
				dprintf(fd, "Piece : [%d|%d]\n", n_piece, m_piece);
				break ;
			}
			i++;
		}
		piece = ft_memalloc((sizeof(char *)) * (n_piece + 1));
		piece[n_piece] = 0;
		i = 0;
		while (i < n_piece)
		{
			get_next_line(0, &line);
			piece[i] = ft_strdup(line);
			i++;
		}
		i = 0;
		while (piece[i])
		{
			dprintf(fd, "%s\n", piece[i]);
			i++;
		}
		x = 0;
		while (x < x_map)
		{
			y = 0;
			while (y < y_map)
			{
				//dprintf(fd, "[%d|%d]{%c}", x, y, map[x][y]);
				if (map[x][y] == p || map[x][y] == p - 32)
					break ;
				y++;
			}
			if (map[x][y] == p || map[x][y] == p - 32)
				break ;
			x++;
		}
		dprintf(fd, "%d %d\n", x, y);
		dprintf(1, "%d %d\n", x, y);
	}
	return (0);
}
