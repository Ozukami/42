/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 04:33:48 by apoisson          #+#    #+#             */
/*   Updated: 2017/05/21 04:33:50 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		insert_way(t_way *way, t_way *next)
{
	way->next = next->next;
	next->next = way;
}

void		add_last(t_way *way, t_way *next)
{
	way->next = NULL;
	next->next = way;
}

void		add_first(t_lemin *lemin, t_way *way, t_way *current)
{
	way->next = current;
	L_WAYS = way;
}

void		add_sort(t_lemin *lemin, t_way *way)
{
	t_way	*current;
	int		i;

	current = L_WAYS;
	i = -1;
	while (current && ++i > -1)
	{
		if (!(current->next) && way->weight > current->weight)
			return (add_last(way, current));
		else if (way->weight > current->weight &&
				way->weight <= current->next->weight)
			return (insert_way(way, current));
		else if (!current->next && current->weight < way->weight)
			return (insert_way(way, current));
		else if (!current->next && !i)
			return (add_first(lemin, way, current));
		else if (way->weight < current->next->weight && !i)
			return (add_first(lemin, way, current));
		else if (way->weight < current->next->weight)
			return (insert_way(way, current));
		current = current->next;
	}
}

void		add_new_way(t_lemin *lemin, char *path, int weight)
{
	t_way	*way;

	NB_WAY++;
	if (!(way = ft_memalloc(sizeof(t_way))))
		ft_perror("Error: Malloc Failed");
	way->path = ft_strdup(path);
	way->weight = weight;
	if (!L_WAYS)
	{
		way->next = L_WAYS;
		L_WAYS = way;
		return ;
	}
	else
		add_sort(lemin, way);
}
