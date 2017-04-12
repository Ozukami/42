/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumaujea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 23:47:04 by qumaujea          #+#    #+#             */
/*   Updated: 2017/04/12 01:22:29 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_data		*ft_new_data(int y)
{
	t_data	*new;

	if (!(new = ft_memalloc(sizeof(t_data)))
			|| !(new->content_file = ft_memalloc(sizeof(char *) * (y + 1)))
			|| !(new->map = ft_memalloc(sizeof(int *) * (y + 1))))
		exit(0);
	(new->map)[y + 1] = 0;
	return (new);
}

static void	get_content(t_env *env, char *file)
{
	int		i;
	int		fd;
	char	*line;

	if (!(env->data->content_file = ft_memalloc(sizeof(char *)
					* (env->win_y + 1))))
		exit(0);
	if (!(fd = open(file, O_RDONLY)))
		exit(0);
	i = 0;
	while (get_next_line(fd, &line))
	{
		(env->data->content_file)[i++] = ft_strdup(line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if (close(fd))
		exit(0);
}

static void	get_size(t_env *env, char *file)
{
	int		i;
	int		fd;
	char	*line;

	if (!(fd = open(file, O_RDONLY)))
		exit(0);
	i = 0;
	while (get_next_line(fd, &line))
	{
		if (i++ == 0)
			env->win_x = (int)ft_strlen(line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	env->win_y = i;
	if (close(fd))
		exit(0);
}

t_env		*ft_new_env(char *file, int size)
{
	t_env	*new;

	if (!(new = ft_memalloc(sizeof(t_env)))
			|| !(new->mlx = mlx_init()))
		exit(0);
	get_size(new, file);
	new->data = ft_new_data(new->win_y);
	get_content(new, file);
	new->win_size = size;
	new->win = NULL;
	new->zoom = 0;
	new->offset_x = 0;
	new->offset_y = 0;
	return (new);
}
