/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumaujea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 23:04:32 by qumaujea          #+#    #+#             */
/*   Updated: 2017/02/23 04:47:04 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

	ft_draw_line(env, x_tmp + ((env->win_x * env->win_size) / 2),
			y_tmp + (env->win_y * env->win_size / 3) - z,
			x2_tmp + ((env->win_x * env->win_size) / 2),
			y2_tmp + (env->win_y * env->win_size / 3) - z2, color);
}

int			main(int ac, char **av)
{
	int		i;
	int		j;
	int		fd; 
	t_env	*env;

	if (ac < 2)
		return (0);
	env = ft_new_env(av[1], 5);
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
			ft_test(env, i * 5, j * 5, (i + 1) * 5, j * 5, 0x00ff0000,
					(int)((env->data)->map)[i][j], (int)((env->data)->map)[i + 1][j]);
			ft_test(env, i * 5, j * 5, i * 5, (j + 1) * 5, 0x00ff0000,
					(int)((env->data)->map)[i][j], (int)((env->data)->map)[i][j + 1]);
			j++;
		}
		i++;
	}
	mlx_loop(env->mlx);
	return (0);
}
