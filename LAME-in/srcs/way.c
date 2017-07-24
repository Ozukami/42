/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 04:35:25 by apoisson          #+#    #+#             */
/*   Updated: 2017/05/21 05:03:40 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		get_ways(t_lemin *lemin, t_room *current)
{
	int		i;

	if (NB_WAY > 200 || current->visited == TRUE)
		return ;
	current->visited = TRUE;
	CURR_PATH = ft_strjoinf(CURR_PATH, ft_strjoinf(ft_itoa(current->id),
				ft_strdup("_")));
	CURR_WEIGHT++;
	if (current->role == END)
	{
		CURR_WEIGHT--;
		add_new_way(lemin, CURR_PATH, CURR_WEIGHT);
		current->visited = FALSE;
		CURR_PATH = ft_strsubf(CURR_PATH, 0, (int)ft_strlen(CURR_PATH)
				- ft_count_digit(current->id) - 1);
		return ;
	}
	i = -1;
	while (++i < current->nb_link)
		get_ways(lemin, T_ROOM[current->links[i]]);
	current->visited = FALSE;
	CURR_PATH = ft_strsubf(CURR_PATH, 0, (int)ft_strlen(CURR_PATH)
			- ft_count_digit(current->id) - 1);
	CURR_WEIGHT--;
}

int			backtrack_ways(t_lemin *lemin, char *comp, int n)
{
	int		i;

	if (n == MAX_WAY)
	{
		ft_strdel(&comp);
		return (1);
	}
	i = -1;
	while (T_WAYS[++i])
	{
		if (is_overcross(comp, (T_WAYS[i])->path))
		{
			S_WAYS[n] = T_WAYS[i];
			if (backtrack_ways(lemin, ft_strjoin(comp, (S_WAYS[n])->path),
						n + 1))
			{
				ft_strdel(&comp);
				return (1);
			}
			S_WAYS[n] = NULL;
		}
	}
	ft_strdel(&comp);
	return (0);
}

void		select_ways(t_lemin *lemin)
{
	int		i;

	while (MAX_WAY > 0)
	{
		if (!backtrack_ways(lemin, ft_strdup("_"), 0))
			MAX_WAY--;
		else
			break ;
	}
	i = -1;
	while (++i < MAX_WAY)
		SW_A(i) = NB_ANT / MAX_WAY;
	i = -1;
	while (++i < NB_ANT % MAX_WAY)
		SW_A(i) += 1;
}

void		l_to_t_ways(t_lemin *lemin)
{
	int		i;
	t_way	*current;

	if (!L_WAYS)
		ft_perror("Error: no way found");
	current = L_WAYS;
	i = 0;
	while (current)
	{
		T_WAYS[i++] = current;
		current = current->next;
	}
}
