/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 00:08:50 by apoisson          #+#    #+#             */
/*   Updated: 2017/04/17 04:12:58 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_exit(t_env *env)
{
	mlx_destroy_window(MLX, WIN);
	exit(0);
	return (1);
}

void		refresh(t_env *env)
{
	mlx_clear_window(MLX, WIN);
	process(env);
	mlx_do_sync(MLX);
}

void		adjust_win_size(t_env *env)
{
	if ((WIN_X * WIN_SIZE > 2000)
			|| (WIN_Y * WIN_SIZE > 1250))
	{
		WIN_SIZE = 2;
		Z = -4;
	}
	else if ((WIN_X * WIN_SIZE < 500)
			|| (WIN_Y * WIN_SIZE < 500))
	{
		WIN_SIZE = 40;
		Z = 12;
	}
}

/*
** Gere toutes les entrees clavier
** Deplacement, zoom, exit
*/

int			key_handler(int key, t_env *env)
{
	if (key == 53)
		ft_exit(env);
	if (key == 69 || (key == 78 && Z > -4))
	{
		Z = (key == 69) ? Z + 1 : Z - 1;
		refresh(env);
	}
	if (key == LEFT || key == RIGHT)
	{
		X = (key == LEFT) ? X - 3 : X + 3;
		refresh(env);
	}
	if (key == DOWN || key == UP)
	{
		Y = (key == DOWN) ? Y + 3 : Y - 3;
		refresh(env);
	}
	return (1);
}

int			main(int ac, char **av)
{
	t_env	*env;

	if (ac != 2)
	{
		ft_putendl("Usage : ./fdf map_file");
		return (0);
	}
	if (!ft_strstr(av[1], ".fdf"))
	{
		ft_putendl("Invalid file");
		return (0);
	}
	env = ft_new_env(av[1], SIZE);
	moulisplit(env);
	adjust_win_size(env);
	if (!(WIN = mlx_new_window(MLX, WIN_X * (WIN_SIZE),
			WIN_Y * (WIN_SIZE), "FdF")))
		exit_error("mlx_new_window failed");
	mlx_do_sync(MLX);
	process(env);
	mlx_hook(WIN, 17, 0, &ft_exit, env);
	mlx_hook(WIN, 2, 0, &key_handler, env);
	mlx_loop(MLX);
	return (1);
}
