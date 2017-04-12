/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 00:08:50 by apoisson          #+#    #+#             */
/*   Updated: 2017/04/12 05:49:04 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_tab_size(char **tab)
{
	int		len;

	len = 0;
	while (tab[len])
		len++;
	return (len);
}

/*
** Fais le cafe, et parfois des crepes
*/

void		ft_moulisplit(t_env *env)
{
	char	**split;
	int		i;
	int		j;
	int		k;

	i = 0;
	while (i < env->win_y)
	{
		j = 0;
		split = ft_strsplit(((env->data)->content_file)[i], ' ');
		env->win_x = ft_tab_size(split);
		k = env->win_x - 1;
		if (!(((env->data)->map)[i] = ft_memalloc(sizeof(int) * env->win_x)))
			exit(0);
		while (split[j])
		{
			((env->data)->map)[i][k--] = atoi(split[j]);
			j++;
		}
		i++;
		free_map(split);
		free(split);
	}
	free_map((env->data)->content_file);
	free(env->data->content_file);
}

/*
** Calcule les coordonnees dans le nouveau plan puis trace
** rect = ((x,y) (x2,y2) color)
** altitude = (z,z2)
*/

void		ft_test_2(t_env *env, t_rect *line, t_coord *z)
{
	int x_tmp;
	int y_tmp;
	int x2_tmp;
	int y2_tmp;

	x_tmp = (L_X1 - L_Y1);
	y_tmp = (L_X1 + L_Y1) / 1.5;
	x2_tmp = (L_X2 - L_Y2);
	y2_tmp = (L_X2 + L_Y2) / 1.5;
	ft_draw_line(env, ft_new_rect(
			ft_new_coord((x_tmp + ((WIN_X * WIN_SIZE) / 2)),
				(y_tmp + ((WIN_Y * WIN_SIZE) / 9) - z->x)),
			ft_new_coord((x2_tmp + ((WIN_X * WIN_SIZE) / 2)),
				(y2_tmp + ((WIN_Y * WIN_SIZE) / 9) - z->y)),
			(L_COLOR + (z->y * 700))));
	ft_free_rect(line);
	free(z);
}

void		ft_process(t_env *env)
{
	int		i;
	int		j;

	i = 0;
	while (i < env->win_y - 1)
	{
		j = 0;
		while (j < env->win_x - 1)
		{
			ft_test_2(env,
					ft_new_rect(ft_new_coord(i * (5 + Z) + X, j * (5 + Z) + Y),
						ft_new_coord((i + 1) * (5 + Z) + X, j * (5 + Z) + Y),
						0x00007104), ft_new_coord((int)((env->data)->map)[i][j],
					(int)((env->data)->map)[i + 1][j]));
			ft_test_2(env,
					ft_new_rect(ft_new_coord(i * (5 + Z) + X, j * (5 + Z) + Y),
						ft_new_coord(i * (5 + Z) + X, (j + 1) * (5 + Z) + Y),
						0x00007104), ft_new_coord((int)((env->data)->map)[i][j],
					(int)((env->data)->map)[i][j + 1]));
			j++;
		}
		i++;
	}
}

int			ft_exit(t_env *env)
{
	mlx_destroy_window(MLX, WIN);
	exit(1);
	return (1);
}

void		refresh(t_env *env)
{
	mlx_clear_window(MLX, WIN);
	ft_process(env);
	mlx_do_sync(MLX);
}

int			ft_key_handler(int key, t_env *env)
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
		return (0);
	env = ft_new_env(av[1], 10);
	ft_moulisplit(env);
	if ((env->win_x * env->win_size > 2000)
			|| (env->win_y * env->win_size > 1250))
	{
		env->win_size = 2;
		env->zoom = -4;
	}
	if (!(env->win = mlx_new_window(env->mlx, WIN_X * (WIN_SIZE),
			WIN_Y * (WIN_SIZE), "FdF")))
		exit(0);
	ft_process(env);
	mlx_hook(env->win, 17, 0, &ft_exit, env);
	mlx_hook(env->win, 2, 0, &ft_key_handler, env);
	mlx_loop(env->mlx);
	return (0);
}
