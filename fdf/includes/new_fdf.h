/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumaujea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 23:15:20 by qumaujea          #+#    #+#             */
/*   Updated: 2017/04/12 01:09:49 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h> // !!
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>

# define LEFT		123
# define RIGHT		124
# define DOWN		125
# define UP			126

# define R			(rect)
# define L_C1		(line->coord1)
# define L_X1		(line->coord1->x)
# define L_Y1		(line->coord1->y)
# define L_C2		(line->coord2)
# define L_X2		(line->coord2->x)
# define L_Y2		(line->coord2->y)
# define L_COLOR	(line->color)

# define C_X		(coord->x)
# define C_Y		(coord->y)

# define DIFF_1		(diff->x)
# define DIFF_2		(diff->y)

# define ADJUST_1	(adjust->x)
# define ADJUST_2	(adjust->y)

# define MLX		(env->mlx_data->mlx)
# define WIN		(env->mlx_data->win)
# define WIN_X		(env->mlx_data->win_x)
# define WIN_Y		(env->mlx_data->win_y)
# define WIN_SIZE	(env->mlx_data->scale)
# define X			(env->mlx_data->off_x)
# define Y			(env->mlx_data->off_y)
# define Z			(env->mlx_data->zoom)

# define CONTENT	(env->fdf_data->content_file)
# define MAP		(env->fdf_data->map)
# define D_X		(env->fdf_data->x)
# define D_Y		(env->fdf_data->y)

# define MLX_DATA	(env->mlx_data)
# define FDF_DATA	(env->fdf_data)

typedef struct	s_fdf_data
{
	char 		**content_file;
	int			**map;
	int			x;
	int			y;
}				t_fdf_data;

typedef struct s_mlx_data
{
	void		*mlx;
	void		*win;
	int			win_x;
	int			win_y;
	int			scale;
	int			off_x;
	int			off_y;
	int			zoom;
}				t_mlx_data;

typedef struct s_env
{
	t_mlx_data	*mlx_data;
	t_fdf_data	*fdf_data;
}				t_env;

void			ft_draw_line(t_env *env, t_rect *line);
void			free_map(char **map);
void			free_map_int(int **map);

#endif
