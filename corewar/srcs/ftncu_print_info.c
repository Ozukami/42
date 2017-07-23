/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftncu_print_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 19:56:26 by lcharbon          #+#    #+#             */
/*   Updated: 2017/07/23 20:13:28 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ncurse.h"

static void		ftncu_print_players(t_gb *g)
{
	int			np;
	t_player	*player;

	np = -1;
	player = g->v->arena->l_player;
	ftncu_init_pair();
	while (++np < g->n_players)
	{
		move(10 * (np + 1) - (5 * np) + 1, 205);
		printw("Player %d : ", player->id);
		attron(COLOR_PAIR(np + 1));
		printw("%s", player->champ->name);
		attroff(COLOR_PAIR(np + 1));
		move(10 * (np + 1) - (5 * np) + 2, 210);
		printw("Last live : %13.0d %d", 0, 58786);
		move(10 * (np + 1) - (5 * np) + 3, 210);
		printw("Lives in current period : %d", player->nb_live);
		player = player->next;
	}
}

void		ftncu_print_info(t_gb *g)
{
	attron(A_DIM);
	attron(A_BOLD);
	move(1, 205);
	printw("**  %s  **", "PLAYING");
	move(3, 205);
	printw("Cycles/second limit : NONE");
	move(7, 205);
	printw("Cycle : %5d", g->v->arena->nb_cycle);
	move(9, 205);
	printw("Processes : %5d", g->v->arena->nb_proc);
	move(g->n_players * 5 + 10, 205);
	printw("CYCLE_TO_DIE :%0.0d %-7d", 0, g->v->arena->cycle_to_die);
	move(g->n_players * 5 + 12, 205);
	printw("CYCLE_DELTA : %5d", CYCLE_DELTA);
	move(g->n_players * 5 + 14, 205);
	printw("NBR_LIVE : %8d", g->v->total_live);
	move(g->n_players * 5 + 16, 205);
	printw("MAX_CHECKS : %6d", MAX_CHECKS);
	ftncu_print_players(g);
	attron(A_NORMAL);
}
