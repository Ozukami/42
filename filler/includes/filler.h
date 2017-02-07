/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 02:27:04 by apoisson          #+#    #+#             */
/*   Updated: 2017/02/07 06:16:12 by qumaujea         ###   ########.fr       */
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
	char		**piece;
	int			x_piece;
	int			y_piece;
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

int				ft_check_place(t_info *info, int x, int y);
void			ft_get_place(t_info *info);

#endif
