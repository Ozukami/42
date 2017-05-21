/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumaujea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 00:18:21 by qumaujea          #+#    #+#             */
/*   Updated: 2017/05/21 04:49:46 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		send_ant(t_lemin *lemin)
{
	int		i;
	int		ant;
	int		turn;

	ant = 0;
	turn = 1;
	while (ant < NB_ANT)
	{
		i = -1;
		while (++i < MAX_WAY)
		{
			if (SW_A(i)-- > 0)
				add_ant(lemin, ++ant, turn, SW_P(i));
		}
		turn++;
	}
}

void		move_ant(t_lemin *lemin)
{
	t_ant	*current;
	int		turn;

	turn = 1;
	while (ANT_END < NB_ANT)
	{
		if (!current_at_end(lemin))
			return ;
		current = L_ANT;
		while (current)
		{
			ft_my_printf("L%d-%s ", current->id,
					(T_ROOM[ft_atoi((current->way)[current->pos + 1])])->name);
			current->pos++;
			if (!current->next || current->next->turn > turn)
				break ;
			if (!next_at_end(lemin, current))
				return ;
			current = current->next;
		}
		turn++;
		ft_my_printf("\n");
	}
}

void		process(t_lemin *lemin)
{
	MAX_WAY = ft_min(T_NBLINK(ID_START), T_NBLINK(ID_END));
	if (NB_ROOM > 100)
		shortest_way(lemin);
	else
		get_ways(lemin, T_ROOM[ID_START]);
	if (!(S_WAYS = ft_memalloc(sizeof(t_way) * (MAX_WAY + 1))) ||
			!(T_WAYS = ft_memalloc(sizeof(t_way) * (NB_WAY + 1))))
		ft_perror("Error: Malloc Failed");
	l_to_t_ways(lemin);
	select_ways(lemin);
	ant_per_way(lemin);
	display_data(lemin);
	send_ant(lemin);
	move_ant(lemin);
}

int			main(int ac, char **av)
{
	t_lemin	*lemin;

	(void)av;
	if (ac != 1)
		ft_perror("Usage : ./lem-in");
	lemin = init_lemin();
	if (!(NB_ANT = ft_absolute(get_nb_ant())) || NB_ANT < 0)
		ft_perror("Error: invalid number of ant");
	get_room(lemin);
	get_pipe(lemin);
	update_tab(lemin);
	process(lemin);
	return (0);
}
