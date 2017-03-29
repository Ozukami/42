/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumaujea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 23:15:20 by qumaujea          #+#    #+#             */
/*   Updated: 2017/03/29 03:29:02 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h> // !!
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>

# define R			(rect)
# define L_C1		(line->coord1)
# define L_C1_X		(line->coord1->x)
# define L_C1_Y		(line->coord1->y)
# define L_C2		(line->coord2)
# define L_C2_X		(line->coord2->x)
# define L_C2_Y		(line->coord2->y)
# define L_COLOR	(line->color)

# define C_X		(coord->x)
# define C_Y		(coord->y)

# define DIFF_1		(diff->x)
# define DIFF_2		(diff->y)

# define ADJUST_1	(adjust->x)
# define ADJUST_2	(adjust->y)

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


#endif
