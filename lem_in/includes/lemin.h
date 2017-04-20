/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumaujea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 00:15:38 by qumaujea          #+#    #+#             */
/*   Updated: 2017/04/20 04:54:49 by qumaujea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"

# define NB_ANT 	(lemin->nb_ant)

# define ROOM_NAME	(room->name)

typedef struct	s_room
{
	char		*name;
	int			id;
	int			role;
	int			*links;
	int			nb_link;
	int			x;
	int			y;
}				t_room;

typedef struct	s_lemin;
{
	t_room		*tab;
	char		**index;
	int			nb_ant;
}				t_lemin;

#endif
