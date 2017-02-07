/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 23:52:54 by apoisson          #+#    #+#             */
/*   Updated: 2017/02/07 02:26:01 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*path;
	int		fd;
	char	*line;
	int		i;
	char	**map;
	int		n_map;
	int		m_map;
	char	**piece;
	int		n_piece;
	int		m_piece;

	path = "log.txt";
	fd = open(path, O_WRONLY | O_CREAT | O_TRUNC);
	i = 0;
	map = NULL;
	piece = NULL;
	n_map = 0;
	m_map = 0;
	n_piece = 0;
	m_piece = 0;
	get_next_line(0, &line);
	while (1)
	{
		get_next_line(0, &line);
		//write(fd, line, ft_strlen(line));
		//line = ft_strdup("Plateau 8 7:\n");
		while (line[i])
		{
			if (line[i] > '0' && line[i] < '9')
			{
				n_map =	ft_atoi(line + i);
				while (line[i] > '0' && line[i] < '9')
					i++;
				m_map =	ft_atoi(line + i);
				dprintf(fd, "Map : [%d|%d]\n", n_map, m_map);
				break ;
			}
			i++;
		}
		map = ft_memalloc((sizeof(char *)) * (n_map + 1));
		map[n_map] = 0;
		i = 0;
		while (i < n_map + 1)
		{
			get_next_line(0, &line);
			map[i] = ft_strdup(line);
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
		ft_putendl("2 1");
	}
	return (0);
}
