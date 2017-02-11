/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumaujea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 23:04:32 by qumaujea          #+#    #+#             */
/*   Updated: 2017/02/11 08:00:07 by qumaujea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_brensenham(t_env *env, int y, int x, int y2, int x2)
{
	double		dy;
	double		dx;
	double	error_value;
	double	error_inc;
	double	error_dec;

	error_value = 0;
	dy = (double)y2 - (double)y;
	dx = (double)x2 - (double)x;
	error_inc = dy / dx;
	error_dec = -1.0;
	while (x < x2)
	{
		mlx_pixel_put(env->mlx, env->win, x, y, 0x00FF0000);
		error_value = error_value + (dy / dx);
		printf("[%f]\n", error_value);
		if (error_value >= 0.5)
		{
			y++;
			error_value = error_value + error_dec;
			printf("2[%f]\n", error_value);
		}
		x++;
	}
}

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
	env->win = mlx_new_window(env->mlx, env->win_x * env->win_size,
			env->win_y * env->win_size, "FdF");
	ft_brensenham(env, 20, 20, 35, 235);
	mlx_loop(env->mlx);
	return (0);
}
