/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumaujea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 23:47:04 by qumaujea          #+#    #+#             */
/*   Updated: 2017/04/14 04:43:13 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		exit_error(char *err)
{
	perror(err);
	exit(0);
}

static void	get_content(t_env *env, char *file)
{
	int		i;
	int		fd;
	char	*line;

	if ((fd = open(file, O_RDONLY)) < 0)
		exit_error(file);
	i = 0;
	while (get_next_line(fd, &line))
	{
		CONTENT[i++] = ft_strdup(line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if (close(fd))
		exit_error("Error");
}

static void	get_size(t_env *env, char *file)
{
	int		i;
	int		fd;
	char	*line;

	if ((fd = open(file, O_RDONLY)) < 0)
		exit_error(file);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (i++ == 0)
			WIN_X = (int)ft_strlen(line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	WIN_Y = i;
	if (close(fd))
		exit_error("Error");
}

t_data		*ft_new_data(int y)
{
	t_data	*data;

	if (!(data = ft_memalloc(sizeof(t_data)))
			|| !(data->content_file = ft_memalloc(sizeof(char *) * (y + 1)))
			|| !(data->map = ft_memalloc(sizeof(int *) * (y + 1))))
		exit_error("Malloc failed");
	(data->map)[y + 1] = 0;
	return (data);
}

t_env		*ft_new_env(char *file, int size)
{
	t_env	*env;

	if (!(env = ft_memalloc(sizeof(t_env))))
		exit_error("Malloc failed");
	if (!(MLX = mlx_init()))
		exit_error("mlx_init failed");
	get_size(env, file);
	DATA = ft_new_data(WIN_Y);
	get_content(env, file);
	WIN_SIZE = size;
	WIN = NULL;
	X = 0;
	Y = 0;
	Z = 0;
	MAX_Z = 0;
	return (env);
}
