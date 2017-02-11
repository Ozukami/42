/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumaujea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 23:04:32 by qumaujea          #+#    #+#             */
/*   Updated: 2017/02/11 04:19:06 by qumaujea         ###   ########.fr       */
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
		((env->data)->map)[i] = ft_memalloc(sizeof(int) * env->win_x);
		while (split[j])
		{
			((env->data)->map)[i][j] = ft_atoi(split[j]);
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

	env = ft_new_env(av[1], 20);
	if (!(fd = open(av[1], O_RDONLY)))
		exit(0);
	(env->data)->content_file = malloc(sizeof(char *) * (i + 1));
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
			printf("%2d |", ((env->data)->map)[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
	mlx_loop(env->mlx);
	return (0);
}
