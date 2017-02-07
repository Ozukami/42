/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 02:27:04 by apoisson          #+#    #+#             */
/*   Updated: 2017/02/07 09:51:40 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

typedef struct	s_info
{
	char		player;
	char		**map;
	int			x_map;
	int			y_map;
	char		**map_prev;
	int			x_map_prev;
	int			y_map_prev;
	char		**piece;
	int			x_piece;
	int			y_piece;
	int			x_side;
	int			y_side;
}				t_info;

typedef struct	s_place
{
//	int		value;
	struct s_place	*next;
	struct s_place	*prev;
	int				x;
	int				y;	
}				t_place;

t_info			*ft_new_info(char p);
t_place			*ft_new_place(int x, int y);
void			ft_add_place(t_place **list, t_place *new);

int				ft_check_place(t_info *info, int x, int y, int fd);
void			ft_get_place(t_info *info, int fd);
void			ft_get_value(t_info *info, t_place place, int fd);

#endif
