/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumaujea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 23:04:32 by qumaujea          #+#    #+#             */
/*   Updated: 2017/03/30 01:28:36 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		my_draw_line(t_env *env, t_rect *line);
void		ft_draw_line(t_env *env, int x, int y, int x2, int y2, int color);

int			ft_tab_size(char **tab)
{
	int		len;

	len = 0;
	while (tab[len])
		len++;
	return (len);
}

// Fais le cafe, et parfois des crepes
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
		k = env->win_x - 1;
		split = ft_strsplit(((env->data)->content_file)[i], ' ');
		env->win_x = ft_tab_size(split);
		((env->data)->map)[i] = ft_memalloc(sizeof(double) * env->win_x);
		while (split[j])
		{
			((env->data)->map)[i][k--] = atof(split[j]);
			j++;
		}
		i++;
	}
}

// Calcule les coordonnees dans le nouveau plan puis trace
void		ft_test(t_env *env, int x, int y, int x2, int y2, int color, int z, int z2)
{
	int x_tmp = (x-y);
	int y_tmp = (x+y) / 1.5;
	int x2_tmp = (x2-y2);
	int y2_tmp = (x2+y2) / 1.5;

	ft_draw_line(env, x_tmp + ((env->win_x * env->win_size)) / 1.5,
			y_tmp + (env->win_y * env->win_size / 9) - z,
			x2_tmp + ((env->win_x * env->win_size)) / 1.5,
			y2_tmp + (env->win_y * env->win_size / 9) - z2, color);
}

void		ft_tmp(t_env *env, int x, int y)
{
	my_draw_line(env, ft_new_rect(
				ft_new_coord(250, 250),
				ft_new_coord(x, y),
				0x00FF0000));
	//ft_draw_line(env, 260, 250, 10 + x, y, 0x0000FF00);
	ft_draw_line(env, 751, 250, 501 + x, y, 0x0000FF00);
	mlx_do_sync(env->win);
	sleep(1);
}

int			main(int ac, char **av)
{
	/*
	int		i;
	int		j;
	int		fd; 
	*/
	t_env	*env;
	int		hour;

	(void)ac;
	(void)av;
	env = ft_memalloc(sizeof(t_env));
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, 1001, 500, "Test");
	ft_draw_line(env, 501, 0, 501, 500, 0x00FF00FF);
	hour = 1;
	switch (hour)
	{
		case 1:
			ft_tmp(env, 250, 100);
		case 2:
			ft_tmp(env, 300, 150);
		case 3:
			ft_tmp(env, 350, 200);
		case 4:
			ft_tmp(env, 400, 250);
		case 5:
			ft_tmp(env, 350, 300);
		case 6:
			ft_tmp(env, 300, 350);
		case 7:
			ft_tmp(env, 250, 400);
		case 8:
			ft_tmp(env, 200, 350);
		case 9:
			ft_tmp(env, 150, 300);
		case 10:
			ft_tmp(env, 100, 250);
		case 11:
			ft_tmp(env, 150, 200);
		case 12:
			ft_tmp(env, 200, 150);
		default :
			break ;
	}
	/*
	if (ac < 2)
		return (0);
	env = ft_new_env(av[1], 10);
	if (!(fd = open(av[1], O_RDONLY)))
		exit(0);
	(env->data)->content_file = malloc(sizeof(char *) * (env->win_y + 1));
	i = 0;
	while (get_next_line(fd, &(env->data->buf)))
		((env->data)->content_file)[i++] = ft_strdup((env->data->buf));
	if (close(fd))
		exit(0);
	ft_moulisplit(env);
	env->win = mlx_new_window(env->mlx, env->win_x * env->win_size,
			env->win_y * env->win_size, "FdF");
	i = 0;
	while (i < env->win_y - 1)
	{
		j = 0;
		while (j < env->win_x - 1)
		{
			ft_test(env, i * 5, j * 5, (i + 1) * 5, j * 5, 0x00848484,
					(int)((env->data)->map)[i][j], (int)((env->data)->map)[i + 1][j]);
			ft_test(env, i * 5, j * 5, i * 5, (j + 1) * 5, 0x00848484,
					(int)((env->data)->map)[i][j], (int)((env->data)->map)[i][j + 1]);
			j++;
		}
		i++;
	}
	*/
	mlx_loop(env->mlx);
	return (0);
}
