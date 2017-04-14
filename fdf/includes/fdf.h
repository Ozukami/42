/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumaujea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 23:15:20 by qumaujea          #+#    #+#             */
/*   Updated: 2017/04/14 01:54:48 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h> // !!
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <errno.h>

# define SIZE		10

# define LEFT		123
# define RIGHT		124
# define DOWN		125
# define UP			126

# define NR(a,b,c)	ft_new_rect(a, b, c)
# define NC(a,b)	ft_new_coord(a, b)

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

# define MLX		(env->mlx)
# define WIN		(env->win)
# define WIN_X		(env->win_x)
# define WIN_Y		(env->win_y)
# define WIN_SIZE	(env->win_size)
# define X			(env->offset_x)
# define Y			(env->offset_y)
# define Z			(env->zoom)

# define DATA		(env->data)
# define CONTENT	(env->data->content_file)
# define MAP		(env->data->map)

typedef struct	s_data
{
	char		**content_file;
	int			**map;
}				t_data;

t_data			*ft_new_data();

typedef struct	s_env
{
	t_data		*data;
	void		*mlx;
	void		*win;
	int			win_size;
	int			win_y;
	int			win_x;
	int			zoom;
	int			offset_x;
	int			offset_y;
}				t_env;

t_data			*ft_new_data(int y);
t_env			*ft_new_env(char *file, int size);
void			ft_draw_line(t_env *env, t_rect *line);
void			free_map(char **map);
void			free_map_int(int **map);
void			exit_error(char *err);

int				tab_size(char **tab);
void			moulisplit(t_env *env);
void			draw_iso(t_env *env, t_rect *line, t_coord *z);
void			process(t_env *env);
int				ft_exit(t_env *env);
void			refresh(t_env *env);
void			adjust_win_size(t_env *env);
int				key_handler(int key, t_env *env);

#endif
