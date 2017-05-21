/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 04:27:41 by apoisson          #+#    #+#             */
/*   Updated: 2017/05/21 04:27:50 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_ant		*new_ant(int id, int turn, char *path)
{
	t_ant	*ant;

	if (!(ant = ft_memalloc(sizeof(t_ant))))
		ft_perror("Error: Malloc Failed");
	ant->id = id;
	ant->pos = 0;
	ant->turn = turn;
	ant->way = ft_strsplit(path, '_');
	ant->next = NULL;
	return (ant);
}

void		add_ant(t_lemin *lemin, int id, int turn, char *path)
{
	t_ant	*current;

	if (!L_ANT)
	{
		L_ANT = new_ant(id, turn, path);
		return ;
	}
	current = L_ANT;
	while (current->next)
		current = current->next;
	current->next = new_ant(id, turn, path);
}

int			current_at_end(t_lemin *lemin)
{
	t_ant	*current;
	t_ant	*tmp;

	current = L_ANT;
	while (ft_atoi((current->way)[current->pos + 1]) == ID_END)
	{
		ANT_END++;
		ft_my_printf("L%d-%s ", current->id,
				(T_ROOM[ft_atoi((current->way)
								[current->pos + 1])])->name);
		if (!current->next)
		{
			ft_my_printf("\n");
			return (0);
		}
		tmp = current;
		current = current->next;
		L_ANT = current;
		free_map(tmp->way);
		free(tmp);
	}
	return (1);
}

int			next_at_end(t_lemin *lemin, t_ant *current)
{
	t_ant	*tmp;

	while (ft_atoi((current->next->way)[current->next->pos + 1]) == ID_END)
	{
		ANT_END++;
		ft_my_printf("L%d-%s ", current->next->id,
				(T_ROOM[ft_atoi((current->next->way)
								[current->next->pos + 1])])->name);
		if (!current->next->next)
		{
			ft_my_printf("\n");
			return (0);
		}
		tmp = current->next;
		current->next = current->next->next;
		free_map(tmp->way);
		free(tmp);
	}
	return (1);
}

void		ant_per_way(t_lemin *lemin)
{
	while (get_pgt(lemin) > get_ppt(lemin) + 1)
	{
		(get_pgt_way(lemin))->ant_to_send--;
		(get_ppt_way(lemin))->ant_to_send++;
	}
}
