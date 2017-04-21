/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumaujea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 00:15:38 by qumaujea          #+#    #+#             */
/*   Updated: 2017/04/22 01:11:36 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"
# include <stdio.h>

# define LIST 			(lemin->list)
# define TAB 			(lemin->tab)
# define INDEX 			(lemin->index)
# define ID_NAME 		(lemin->id_name)
# define NB_ANT 		(lemin->nb_ant)
# define V_START 		(lemin->verif_start)
# define V_END 			(lemin->verif_end)

# define T_NAME(i) 		(((lemin->tab)[i])->name)
# define T_ID(i) 		(((lemin->tab)[i])->id)
# define T_ROLE(i) 		(((lemin->tab)[i])->role)
# define T_LINKS(i) 	(((lemin->tab)[i])->links)
# define T_NBLINK(i) 	(((lemin->tab)[i])->nb_link)
# define T_X(i) 		(((lemin->tab)[i])->x)
# define T_Y(i) 		(((lemin->tab)[i])->y)
# define T_EMPTY(i) 	(((lemin->tab)[i])->empty)

# define ROOM_NAME		(room->name)

# define START			1
# define END			2

# define TRUE			1
# define FALSE			0

typedef struct		s_room
{
	char			*name;
	int				id;
	int				role;
	int				*links;
	int				nb_link;
	int				x;
	int				y;
	int				empty;
}					t_room;

typedef struct		s_room_list
{
	t_room			*room;
	struct s_room_list	*next;
}					t_room_list;

typedef struct		s_lemin
{
	t_room_list		*list;
	t_room			**tab;
	char			**index;
	char			**id_name;
	int				nb_ant;
	int				verif_start;
	int				verif_end;
}					t_lemin;

void				add_room_list(t_lemin *lemin, char *line,
		int id, int role);

#endif
