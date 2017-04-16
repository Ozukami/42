/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 00:08:50 by apoisson          #+#    #+#             */
/*   Updated: 2017/04/17 01:35:39 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			tab_size(char **tab)
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

void		moulisplit(t_env *env)
{
	char	**split;
	int		i;
	int		j;
	int		k;

	i = -1;
	while (++i < WIN_Y)
	{
		split = ft_strsplit(CONTENT[i], ' ');
		WIN_X = tab_size(split);
		k = WIN_X - 1;
		if (!(MAP[i] = ft_memalloc(sizeof(int) * WIN_X)))
			exit_error("Malloc failed");
		j = -1;
		while (split[++j])
		{
			MAP[i][k--] = atoi(split[j]);
			MAX_Z = ft_max(MAX_Z, atoi(split[j]));
			MIN_Z = ft_min(MIN_Z, atoi(split[j]));
		}
		free_map(split);
	}
	free_map(CONTENT);
}

int			get_color(t_env *env, t_coord *z)
{
	int		color;

	color = 0x00FF00FF;
	if (!DIFF_Z)
	{
		if (z->x == MIN_Z)
			color = 0x0021D04A;
		else if (z->x == MAX_Z)
			color = 0x00E92525;
		else
			color = 0x00007104 + (z->x * 250);
	}
	else
		color = 0x00007104 + (z->y * 450) + (z->x * 450);
	return (color);
}

/*
** Calcule les coordonnees dans le nouveau plan puis trace
** rect = ((x,y) (x2,y2) color)
** altitude = (z,z2)
*/

void		draw_iso(t_env *env, t_rect *line, t_coord *z)
{
	int iso_x1;
	int iso_y1;
	int iso_x2;
	int iso_y2;

	iso_x1 = L_X1 * (5 + Z) + X;
	iso_x1 -= L_Y1 * (5 + Z) + Y;
	iso_y1 = ((L_X1 * (5 + Z) + X) + (L_Y1 * (5 + Z) + Y)) / 1.5;
	iso_x2 = L_X2 * (5 + Z) + X;
	iso_x2 -= L_Y2 * (5 + Z) + Y;
	iso_y2 = ((L_X2 * (5 + Z) + X) + (L_Y2 * (5 + Z) + Y)) / 1.5;
	ft_draw_line(env, NR(NC((iso_x1 + (WIN_X * WIN_SIZE / 2)),
							(iso_y1 + (WIN_Y * WIN_SIZE / 9) - z->x)),
					NC((iso_x2 + (WIN_X * WIN_SIZE / 2)),
							(iso_y2 + (WIN_Y * WIN_SIZE / 9) - z->y)),
					/*(L_COLOR + ((DIFF_Z) ?
						(z->y * 450) + (z->x * 450) : (z->x * 250)))*/
					get_color(env, z)));
	ft_free_rect(line);
	free(z);
}

/*
** Call the draw_iso function for every points of the map
*/

void		process(t_env *env)
{
	int		i;
	int		j;

	i = 0;
	while (i < WIN_Y)
	{
		j = 0;
		while (j < WIN_X)
		{
			if (i != WIN_Y - 1)
				draw_iso(env, NR(NC(i, j), NC(i + 1, j), 0x00007104),
						NC(MAP[i][j], MAP[i + 1][j]));
			//mlx_do_sync(MLX);
			if (j != WIN_X - 1)
				draw_iso(env, NR(NC(i, j), NC(i, j + 1), 0x00007104),
						NC(MAP[i][j], MAP[i][j + 1]));
			//mlx_do_sync(MLX);
			j++;
		}
		i++;
	}
}

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
