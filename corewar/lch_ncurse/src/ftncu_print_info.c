/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftncu_print_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 19:56:26 by lcharbon          #+#    #+#             */
/*   Updated: 2017/07/22 21:44:30 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ncurse.h"

static void	ftncu_print_players(t_gb *g)
{
	int		np;

	np = -1;
	ftncu_init_pair();
	while (++np < g->n_players)
	{
		move(10 * (np + 1) - (5 * np) + 1, 205);
		printw("Player %d : ", g->player[np].id);
		attron(COLOR_PAIR(np + 1));
		printw("%s", g->player[np].s);
		attroff(COLOR_PAIR(np + 1));
		move(10 * (np + 1) - (5 * np) + 2, 210);
		printw("Last live : %13.0d %d", 0, g->player[np].ll);
		move(10 * (np + 1) - (5 * np) + 3, 210);
		printw("Lives in current period : %d", g->player[np].licp);
	}
}

void		ftncu_print_info(t_gb *g)
{
	attron(A_DIM);
	attron(A_BOLD);
	move(1, 205);
	printw("**  %s  **", "PAUSED");
	move(3, 205);
	printw("Cycles/second limit : %d", 50);
	move(7, 205);
	printw("Cycle : %d", 0);
	move(9, 205);
	printw("Processes : %d", 2);
	move(g->n_players * 5 + 10, 205);
	printw("CYCLE_TO_DIE : %d", g->cycle_to_die);
	move(g->n_players * 5 + 12, 205);
	printw("CYCLE_DELTA : %d", g->cycle_delta);
	move(g->n_players * 5 + 14, 205);
	printw("NBR_LIVE : %d", g->nbr_live);
	move(g->n_players * 5 + 16, 205);
	printw("MAX_CHECKS : %d", g->max_checks);
	ftncu_print_players(g);
	attron(A_NORMAL);
}
