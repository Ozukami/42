/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumaujea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 23:04:32 by qumaujea          #+#    #+#             */
/*   Updated: 2017/02/23 04:32:44 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_rework_location(int *x, int *y, int *x2, int *y2)
{
	int		tmp;

	tmp = 0;
	if (*x > *x2)
	{
		tmp = *x;
		*x = *x2;
		*x2 = tmp;

		tmp = *y;
		*y = *y2;
		*y2 = *y;
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

void		bres(t_env *env, int x, int y, int x2, int y2, int color);

void		ft_test(t_env *env, int x, int y, int x2, int y2, int color, int z, int z2)
{
	int x_tmp = (x-y);
	int y_tmp = (x+y) / 1.5;
	int x2_tmp = (x2-y2);
	int y2_tmp = (x2+y2) / 1.5;

	bres(env, x_tmp + ((env->win_x * env->win_size) / 2),
			y_tmp + (env->win_y * env->win_size / 3) - z,
			x2_tmp + ((env->win_x * env->win_size) / 2),
			y2_tmp + (env->win_y * env->win_size / 3) - z2, color);
}

int			main(int ac, char **av)
{
	int		i;
	int		fd; 
	t_env	*env;

	if (ac < 2)
		return (0);
	env = ft_new_env(av[1], 50);
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
	/*
	env->win_x = 1020;
	env->win_y = 1020;
	*/
	env->win = mlx_new_window(env->mlx,
			env->win_x * env->win_size,
			env->win_y * env->win_size,
			"FdF");
	
	//int	c0 = 0, c1 = 0, c2 = 0, c3 = 0, c4 = 10, c5 = 0, c6 = 0, c7 = 0, c8 = 0;
	//int		tab[4][4] = {{0,0,0,0}, {0,100,0,0}, {0,100,0,0}, {0,0,0,0}};

	i = 0;
	int	j = 0;

	while (i < env->win_y - 1)
	{
		j = 0;
		while (j < env->win_x - 1)
		{
			ft_test(env, i * 15, j * 15, (i + 1) * 15, j * 15, 0x00ff0000,
					(int)((env->data)->map)[i][j], (int)((env->data)->map)[i + 1][j]);
			ft_test(env, i * 15, j * 15, i * 15, (j + 1) * 15, 0x00ff0000,
					(int)((env->data)->map)[i][j], (int)((env->data)->map)[i][j + 1]);
			j++;
		}
		printf("OK\n");
		i++;
	}

	/*
	ft_test(env, 0, 0, 500, 0, 0x00ff0000);
	ft_test(env, 0, 50, 500, 50, 0x00ff0000);
	ft_test(env, 0, 100, 500, 100, 0x00ff0000);
	ft_test(env, 0, 150, 500, 150, 0x00ff0000);
	ft_test(env, 0, 200, 500, 200, 0x00ff0000);
	ft_test(env, 0, 250, 500, 250, 0x00ff0000);
	ft_test(env, 0, 300, 500, 300, 0x00ff0000);
	ft_test(env, 0, 350, 500, 350, 0x00ff0000);
	ft_test(env, 0, 400, 500, 400, 0x00ff0000);
	ft_test(env, 0, 450, 500, 450, 0x00ff0000);
	ft_test(env, 0, 500, 500, 500, 0x00ff0000);

	ft_test(env, 0, 0, 0, 500, 0x00ff0000);
	ft_test(env, 50, 0, 50, 500, 0x00ff0000);
	ft_test(env, 100, 0, 100, 500, 0x00ff0000);
	ft_test(env, 150, 0, 150, 500, 0x00ff0000);
	ft_test(env, 200, 0, 200, 500, 0x00ff0000);
	ft_test(env, 250, 0, 250, 500, 0x00ff0000);
	ft_test(env, 300, 0, 300, 500, 0x00ff0000);
	ft_test(env, 350, 0, 350, 500, 0x00ff0000);
	ft_test(env, 400, 0, 400, 500, 0x00ff0000);
	ft_test(env, 450, 0, 450, 500, 0x00ff0000);
	ft_test(env, 500, 0, 500, 500, 0x00ff0000);
	*/

	/*
	   mlx_do_sync(env->mlx);

	   bres(env, 250, 225, 250, 150, 0x00ff0000);
	   bres(env, 263, 225, 300, 150, 0x0000FF00);
	   bres(env, 275, 225, 350, 150, 0x000000ff);
	   bres(env, 275, 237, 350, 200, 0x00ff00ff);

	   bres(env, 275, 250, 350, 250, 0x00ff0000);
	   bres(env, 275, 263, 350, 300, 0x0000ff00);
	   bres(env, 275, 275, 350, 350, 0x000000ff);
	   bres(env, 263, 275, 300, 350, 0x00FF00ff);

	   bres(env, 250, 275, 250, 350, 0x00ff0000);
	   bres(env, 237, 275, 200, 350, 0x0000FF00);
	   bres(env, 225, 275, 150, 350, 0x000000ff);
	   bres(env, 225, 263, 150, 300, 0x00ff00ff);

	   bres(env, 225, 250, 150, 250, 0x00ff0000);
	   bres(env, 225, 237, 150, 200, 0x0000ff00);
	   bres(env, 225, 225, 150, 150, 0x000000ff);
	   bres(env, 237, 225, 200, 150, 0x00FF00FF);

	   mlx_do_sync(env->mlx);
	   */

	mlx_loop(env->mlx);
	return (0);
}
