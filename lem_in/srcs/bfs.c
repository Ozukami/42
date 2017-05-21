/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 04:40:05 by apoisson          #+#    #+#             */
/*   Updated: 2017/05/21 04:43:06 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_bfs		*new_bfs(int id, char *path, int weight, int father)
{
	t_bfs	*bfs;

	if (!(bfs = ft_memalloc(sizeof(t_bfs))))
		ft_perror("Error: Malloc Failed");
	bfs->id = id;
	if (!path)
		bfs->path = ft_strjoin(ft_itoa(id), "_");
	else
		bfs->path = ft_strjoin(path, ft_strjoin(ft_itoa(id), "_"));
	bfs->weight = weight;
	bfs->id_father = father;
	return (bfs);
}

void		add_bfs(t_lemin *lemin, t_bfs *bfs, int id)
{
	t_bfs	*current;

	if (!bfs)
	{
		BFS = new_bfs(id, NULL, 0, ID_START);
		return ;
	}
	current = BFS;
	while (current)
	{
		if (!current->next)
		{
			current->next = new_bfs(id, bfs->path, bfs->weight + 1, bfs->id);
			return ;
		}
		current = current->next;
	}
}

void		shortest_way(t_lemin *lemin)
{
	t_bfs	*current;
	int		i;

	add_bfs(lemin, NULL, ID_START);
	current = BFS;
	while (current)
	{
		if (current->id == ID_END)
		{
			add_new_way(lemin, current->path, current->weight);
			return ;
		}
		i = -1;
		while (++i < (T_ROOM[current->id])->nb_link)
			if ((T_ROOM[current->id])->links[i] != current->id_father)
				add_bfs(lemin, current, (T_ROOM[current->id])->links[i]);
		current = current->next;
	}
}
