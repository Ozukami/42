/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumaujea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 23:15:20 by qumaujea          #+#    #+#             */
/*   Updated: 2017/02/11 04:48:59 by qumaujea         ###   ########.fr       */
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
	int			**map;
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
