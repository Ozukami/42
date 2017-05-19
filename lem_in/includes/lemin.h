/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumaujea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 00:15:38 by qumaujea          #+#    #+#             */
/*   Updated: 2017/05/20 01:45:00 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"
# include <stdio.h>

# define BFS	 		(lemin->bfs)
# define L_ANT	 		(lemin->list_ant)
# define L_ROOM 		(lemin->list_room)
# define T_ROOM 		(lemin->tab_room)
# define L_WAYS 		(lemin->list_ways)
# define T_WAYS 		(lemin->tab_ways)
# define S_WAYS 		(lemin->selected_ways)
# define INDEX 			(lemin->index)
# define ID_NAME 		(lemin->id_name)
# define NB_ANT 		(lemin->nb_ant)
# define ANT_END 		(lemin->ant_end)
# define V_START 		(lemin->verif_start)
# define V_END 			(lemin->verif_end)
# define NB_WAY 		(lemin->nb_way)
# define MAX_WAY 		(lemin->nb_max_way)
# define ID_START 		(lemin->id_start)
# define ID_END 		(lemin->id_end)
# define CURR_WEIGHT	(lemin->current_weight)
# define CURR_PATH		(lemin->current_path)
# define NB_ROOM		(lemin->nb_room)

# define SW(i)			((lemin->selected_ways)[i])
# define SW_W(i)		(((lemin->selected_ways)[i])->weight)
# define SW_P(i)		(((lemin->selected_ways)[i])->path)
# define SW_A(i)		(((lemin->selected_ways)[i])->ant_to_send)

# define T_NAME(i) 		(((lemin->tab_room)[i])->name)
# define T_ID(i) 		(((lemin->tab_room)[i])->id)
# define T_ROLE(i) 		(((lemin->tab_room)[i])->role)
# define T_LINKS(i) 	(((lemin->tab_room)[i])->links)
# define T_NBLINK(i) 	(((lemin->tab_room)[i])->nb_link)
# define T_X(i) 		(((lemin->tab_room)[i])->x)
# define T_Y(i) 		(((lemin->tab_room)[i])->y)
# define T_EMPTY(i) 	(((lemin->tab_room)[i])->empty)

# define ROOM_NAME		(room->name)

# define START			1
# define END			2

# define TRUE			1
# define FALSE			0

int	bite = 0;

typedef struct		s_bfs
{
	int				id;
	char			*path;
	int				weight;
	int				id_father;
	struct s_bfs	*next;
}					t_bfs;

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
	int				visited;
}					t_room;

typedef struct		s_room_list
{
	t_room			*room;
	struct s_room_list	*next;
}					t_room_list;

typedef struct		s_way
{
	char			*path;
	int				weight;
	struct s_way	*next;
	int				ant_to_send;
}					t_way;

typedef struct		s_ant
{
	int				id;
	int				pos;
	int				turn;
	char			**way;
	struct s_ant	*next;
}					t_ant;

typedef struct		s_lemin
{
	t_bfs			*bfs;
	t_ant			*list_ant;
	t_room_list		*list_room;
	t_room			**tab_room;
	t_way			*list_ways;
	t_way			**tab_ways;
	t_way			**selected_ways;
	char			**index;
	char			**id_name;
	int				nb_ant;
	int				ant_end;
	int				verif_start;
	int				verif_end;
	int				nb_way;
	int				nb_max_way;
	int				id_start;
	int				id_end;
	int				current_weight;
	char			*current_path;
	int				nb_room;
}					t_lemin;

void				add_room_list(t_lemin *lemin, char *line,
		int id, int role);

#endif
