/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 02:27:04 by apoisson          #+#    #+#             */
/*   Updated: 2017/02/07 04:14:04 by apoisson         ###   ########.fr       */
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

t_info			*ft_new_info(char p);

#endif
