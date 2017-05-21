/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 04:31:04 by apoisson          #+#    #+#             */
/*   Updated: 2017/05/21 04:48:19 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			list_len(t_room_list *list)
{
	int		len;

	len = 0;
	while (list)
	{
		len++;
		list = list->next;
	}
	return (len);
}

void		room_list_to_tab(t_lemin *lemin)
{
	int			nb_room;
	t_room_list	*current;

	if (!V_START || !V_END)
		ft_perror(ft_strjoin("Error: ", ((!V_START) ? "no start found"
						: "no end found")));
	current = L_ROOM;
	nb_room = list_len(L_ROOM);
	if (!(T_ROOM = ft_memalloc(sizeof(t_room_list) * (nb_room + 1)))
			|| !(INDEX = ft_memalloc(sizeof(char *) * (nb_room + 1)))
			|| !(ID_NAME = ft_memalloc(sizeof(char *) * (nb_room + 1))))
		ft_perror("Error: Malloc Failed");
	while (--nb_room != -1)
		INDEX[nb_room] = ft_strdup("");
	while (current)
	{
		T_ROOM[current->room->id] = current->room;
		ID_NAME[current->room->id] = ft_strdup(current->room->name);
		current = current->next;
	}
}

void		verif_room(t_lemin *lemin, char *name, int x, int y)
{
	t_room_list	*current;

	current = L_ROOM;
	while (current)
	{
		if (ft_strequ(name, current->room->name))
			ft_perror("Error: room with same name");
		if (x == current->room->x && y == current->room->y)
			ft_perror("Error: room with same coords");
		current = current->next;
	}
}

t_room		*create_room(t_lemin *lemin, char *line, int id, int role)
{
	t_room		*room;
	char		**split;

	if (!(room = ft_memalloc(sizeof(t_room))))
		ft_perror("Error: Malloc Failed");
	split = ft_strsplit(line, ' ');
	verif_room(lemin, split[0], ft_atoi(split[1]), ft_atoi(split[2]));
	room->name = ft_strdup(split[0]);
	room->id = id;
	room->role = role;
	room->links = NULL;
	room->nb_link = -1;
	room->x = ft_atoi(split[1]);
	room->y = ft_atoi(split[2]);
	room->empty = TRUE;
	room->visited = FALSE;
	free_map(split);
	return (room);
}

void		add_room_list(t_lemin *lemin, char *line, int id, int role)
{
	t_room_list	*room_list;

	if (role == START && !V_START)
	{
		V_START++;
		ID_START = id;
	}
	else if (role == END && !V_END)
	{
		V_END++;
		ID_END = id;
	}
	else if (role == START || role == END)
		ft_perror(ft_strjoin("Error: ", ((role == START) ? "too many start room"
						: "too many end room")));
	if (!(room_list = ft_memalloc(sizeof(t_room_list))))
		ft_perror("Error: Malloc Failed");
	room_list->room = create_room(lemin, line, id, role);
	room_list->next = L_ROOM;
	L_ROOM = room_list;
	NB_ROOM++;
}
