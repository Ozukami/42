/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 04:54:51 by apoisson          #+#    #+#             */
/*   Updated: 2017/04/11 05:50:00 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf_data		*new_fdf_data(char *file)
{
	t_fdf_data	*fdf_data;
	int			i;
	int			fd;
	char		*line;

	if (!(fdf_data = ft_memalloc(sizeof(t_fdf_data))))
		exit(0);
	fdf_data->map = NULL;
	if (!(fd = open(file, O_RDONLY)))
		exit(0);
	i = 0;
	while (get_next_line(fd, &line))
	{
		if (i++ == 0)
			fdf_data->x = (int)ft_strlen(line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if (close(fd))
		exit(0);
	return (fdf_data);
}

t_mlx_data		*new_mlx_data(void *mlx)
{
	t_mlx_data	*mlx_data;

	if (!(mlx_data = ft_memalloc(sizeof(t_mlx_data))))
		exit(0);
	mlx_data->mlx = mlx;
	mlx_data->win = NULL;
	mlx_data->win_x = 0;
	mlx_data->win_y = 0;
	mlx_data->scale = 0;
	mlx_data->zoom = 0;
	mlx_data->off_x = 0;
	mlx_data->off_y = 0;	
	return (mlx_data);
}

t_env			*new_env(void *mlx, char *file)
{
	t_env		*env;

	if (!(env = ft_memalloc(sizeof(t_env))))
		exit(0);
	MLX_DATA = new_mlx_data(mlx);
	FDF_DATA = new_fdf_data(file);
	return (env);
}

int				main(int ac, char **av)
{
	void		*mlx;
	t_env		*env;

	if (ac != 2)
		return (0);
	if (!(mlx = mlx_init()))
		return (0);
	env = new_env(mlx, av[1]);
	get_size(env);
	set_win_size(env);
	if (!(WIN = mlx_new_window(MLX, WIN_X, WIN_Y, "FdF")))
		return (0);
	draw_fdf(env);
	mlx_hook(WIN, 17, 0, &ft_exit, env);
	mlx_hook(WIN, 2, 0, &key_handler, env);
	mlx_loop(MLX);
	return (1);
}
