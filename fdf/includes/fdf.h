/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumaujea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 23:15:20 by qumaujea          #+#    #+#             */
/*   Updated: 2017/02/23 00:09:28 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h> // !!
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>

typedef struct	s_data
{
	char 		**content_file;
	char		*buf;
	double		**map;
}				t_data;

t_data			*ft_new_data();

typedef struct s_env
{
	t_data		*data;
	void		*mlx;
	void		*win;
	int			win_size;
	int			win_y; // NB LINES
	int			win_x; // NB COLUMNS
}				t_env;

t_env			*ft_new_env(char *file, int size);

/*
 *	Brenseham gauche droite
 */

void			ft_draw_shit_x(t_env *env, int x, int y, int x2, int y2, int color);
void			ft_draw_shit2_x(t_env *env, int x, int y, int x2, int y2, int color);
void			ft_draw_shit_y(t_env *env, int x, int y, int x2, int y2, int color);
void			ft_draw_shit2_y(t_env *env, int x, int y, int x2, int y2, int color);

#endif
