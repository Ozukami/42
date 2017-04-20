/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumaujea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 00:15:38 by qumaujea          #+#    #+#             */
/*   Updated: 2017/04/20 09:48:27 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"
# include <stdio.h>

# define LIST 			(lemin->list)
# define TAB 			(lemin->tab)
# define INDEX 			(lemin->index)
# define NB_ANT 		(lemin->nb_ant)

# define T_LINKS(i) 	(((lemin->tab)[i])->links)
# define T_NBLINK(i) 	(((lemin->tab)[i])->nb_link)

# define ROOM_NAME		(room->name)

# define START			1
# define END			2

typedef struct		s_room
{
	char			*name;
	int				id;
	int				role;
	int				*links;
	int				nb_link;
	int				x;
	int				y;
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
	int				nb_ant;
}					t_lemin;

void				add_room_list(t_room_list **begin, char *line,
		int id, int role);

#endif
