/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 04:54:51 by apoisson          #+#    #+#             */
/*   Updated: 2017/04/12 05:51:44 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "new_fdf.h"

void		get_content(t_env *env, char *line, int i)
{
	CONTENT[i] = ft_strdup(line);
}

void		get_size(t_env *env, char *line, int i)
{
	(void)i;
	if (WIN_Y == 0)
		WIN_X = (int)ft_strlen(line);
	WIN_Y++;
}

void		read_file(t_env *env, char *file, void (*f)(t_env *env,
			char *line, int i))
{
	int			i;
	int			fd;
	char		*line;

	if (!(fd = open(file, O_RDONLY)))
		exit(0);
	i = 0;
	while (get_next_line(fd, &line))
	{
		f(env, line, i++);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if (close(fd))
		exit(0);
}

t_fdf_data	*new_fdf_data(void)
{
	t_fdf_data	*fdf_data;

	if (!(fdf_data = ft_memalloc(sizeof(t_fdf_data))))
		exit(0);
	fdf_data->map = NULL;
	return (fdf_data);
}

t_mlx_data	*new_mlx_data(void *mlx)
{
	t_mlx_data	*mlx_data;

	if (!(mlx_data = ft_memalloc(sizeof(t_mlx_data))))
		exit(0);
	mlx_data->mlx = mlx;
	mlx_data->win = NULL;
	mlx_data->win_x = 0;
	mlx_data->win_y = 0;
	mlx_data->scale = 0;
	mlx_data->off_x = 0;
	mlx_data->off_y = 0;
	mlx_data->zoom = 0;
	return (mlx_data);
}

t_env		*new_env(void *mlx)
{
	t_env		*env;

	if (!(env = ft_memalloc(sizeof(t_env))))
		exit(0);
	MLX_DATA = new_mlx_data(mlx);
	FDF_DATA = new_fdf_data();
	return (env);
}

int			ft_exit(t_env *env)
{
	mlx_destroy_window(MLX, WIN);
	exit(1);
	return (1);
}

int			key_handler(int key, t_env *env)
{
	if (key == 53)
		ft_exit(env);
	return (1);
}

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

void		moulisplit(t_env *env)
{
	char	**split;
	int		i;
	int		j;
	int		k;

	i = -1;
	while (++i < WIN_Y)
	{
		if (!(split = ft_strsplit(CONTENT[i], ' ')))
			exit(0);
		WIN_X = ft_tab_size(split);
		k = WIN_X - 1;
		if (!(MAP[i] = ft_memalloc(sizeof(int) * WIN_X)))
			exit(0);
		j = 0;
		while (j < WIN_X)
		{
			MAP[i][k--] = atoi(split[j]);
			j++;
		}
		free_map(split);
		free(split);
	}
	free_map(CONTENT);
	free(CONTENT);
}

int			main(int ac, char **av)
{
	void		*mlx;
	t_env		*env;

	(void)av;
	if (ac != 2)
		return (0);
	env = new_env(NULL);
	read_file(env, av[1], get_size);
	if (!(CONTENT = ft_memalloc(sizeof(char *) * (WIN_Y + 1)))
			|| !(MAP = ft_memalloc(sizeof(char *) * (WIN_Y + 1))))
		return (0);
	read_file(env, av[1], get_content);
	printf("BEFORE\n");
	moulisplit(env);
	printf("AFTER\n");
	return (1);
}
