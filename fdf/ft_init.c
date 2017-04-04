/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumaujea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 23:47:04 by qumaujea          #+#    #+#             */
/*   Updated: 2017/04/04 00:57:00 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_data	*ft_new_data(int y)
{
	t_data	*new;

	new = ft_memalloc(sizeof(t_data));
	new->content_file = ft_memalloc(sizeof(char *) * (y + 1));
	new->map = ft_memalloc(sizeof(double *) * (y + 1));
	(new->map)[y + 1] = 0;
	new->buf = NULL;
	return (new);
}

t_env	*ft_new_env(char *file, int size)
{
	int		i;
	t_env	*new;
	char	*line;
	int		fd;

	new = ft_memalloc(sizeof(t_env));
	line = NULL;
	if (!(fd = open(file, O_RDONLY)))
		exit(0);
	i = 1;
	if (get_next_line(fd, &line))
	{
		new->win_x = (int)ft_strlen(line);
		ft_strdel(&line);
	}
	while (get_next_line(fd, &line))
	{
		ft_strdel(&line);
		i++;
	}
	new->win_y = i;
	new->data = ft_new_data(new->win_y);
	new->mlx = mlx_init();
	new->win_size = size;
	new->win = NULL;
	if (close(fd))
		exit(0);
	return (new);
}
