/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumaujea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 23:04:32 by qumaujea          #+#    #+#             */
/*   Updated: 2017/02/12 13:32:25 by qumaujea         ###   ########.fr       */
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

void		ft_moulisplit(t_env *env)
{
	char	**split;
	int		i;
	int		j;

	i = 0;
	while (i < env->win_y)
	{	
		j = 0;
		split = ft_strsplit(((env->data)->content_file)[i], ' ');
		env->win_x = ft_tab_size(split);
		((env->data)->map)[i] = ft_memalloc(sizeof(double) * env->win_x);
		while (split[j])
		{
			((env->data)->map)[i][j] = atof(split[j]);
			j++;	
		}
		i++;
	}
}

int			main(int ac, char **av)
{
	int		i;
	int		fd; 
	t_env	*env;

	if (ac < 2)
		return (0);
	env = ft_new_env(av[1], 20);
	if (!(fd = open(av[1], O_RDONLY)))
		exit(0);
	(env->data)->content_file = malloc(sizeof(char *) * (env->win_y + 1));
	i = 0;
	while (get_next_line(fd, &(env->data->buf)))
		((env->data)->content_file)[i++] = ft_strdup((env->data->buf));
	if (close(fd))
		exit(0);
	ft_moulisplit(env);
	int		y = 0;
	int		x = 0;
	while (y < env->win_y)
	{
		x = 0;
		printf("%2d |", y);
		while (x < env->win_x)
		{
			printf("%2f |", ((env->data)->map)[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
	env->win = mlx_new_window(env->mlx, 500, 500/*env->win_x * env->win_size,
			env->win_y * env->win_size*/, "FdF");
	ft_draw_shit2_x(env, 250, 250, 350, 300);
	ft_draw_shit2_x(env, 250, 250, 350, 350);
	ft_draw_shit2_x(env, 250, 250, 350, 250);
	ft_draw_shit2_x(env, 250, 250, 350, 200);
	ft_draw_shit2_x(env, 250, 250, 350, 150);

	ft_draw_shit_x(env, 250, 250, 150, 300);
	ft_draw_shit_x(env, 250, 250, 150, 350);
	ft_draw_shit_x(env, 250, 250, 150, 250);
	ft_draw_shit_x(env, 250, 250, 150, 200);
	ft_draw_shit_x(env, 250, 250, 150, 150);
	
//	ft_draw_shit2_y(env, 250, 250, 250, 150);
//	ft_draw_shit2_y(env, 250, 250, 200, 150);
//	ft_draw_shit2_y(env, 250, 250, 150, 150);
//	ft_draw_shit2_y(env, 250, 250, 300, 150);
//	ft_draw_shit2_y(env, 250, 250, 350, 150);

//	ft_draw_shit_y(env, 250, 250, 150, 350);
	ft_draw_shit_y(env, 250, 250, 200, 350);
//	ft_draw_shit_y(env, 250, 250, 250, 350);
//	ft_draw_shit_y(env, 250, 250, 300, 350);
//	ft_draw_shit_y(env, 250, 250, 350, 350);
	/*
	ft_brensenham(env, 100, 100, 100, 200, 0x00FF0000);
	ft_brensenham(env, 100, 100, 200, 100, 0x00FFFF00);
	ft_brensenham(env, 100, 100, 50, 0, 0x000000FF);
	ft_brensenham(env, 100, 100, 100, 0, 0x0000FF00);
	ft_brensenham(env, 100, 100, 0, 100, 0x00FF00FF);
	ft_brensenham(env, 100, 100, 0, 150, 0x0000FFFF);
	ft_brensenham(env, 100, 100, 150, 0, 0x00Fb4800);
	*/
	mlx_loop(env->mlx);
	return (0);
}
