/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftncu_print_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 19:56:26 by lcharbon          #+#    #+#             */
/*   Updated: 2017/07/31 01:51:07 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ncurse.h"

int				ftncu_normalize_time(int s)
{
	if (s < 0)
		return (0);
	else if (s >= 0 && s <= 100)
		return (s);
	else
		while (s >= 100)
			s /= 10;
	return (s);
}

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
		printw("Last live : %13.0d %d", 0, player->last_live);
		move(10 * (np + 1) - (5 * np) + 3, 210);
		printw("Lives in current period : %d", player->nb_live);
		player = player->next;
	}
}

void			ftncu_print_info(t_gb *g)
{
	attron(A_DIM);
	attron(A_BOLD);
	attron(COLOR_PAIR(9));
	mvprintw(1, 205, "**  %s  **", "PLAYING");
	mvprintw(3, 205, "Slow percent : %5d%%", g->t);
	mvprintw(7, 205, "Cycle : %5d", g->v->arena->nb_cycle);
	mvprintw(9 ,205, "Processes : %5d", g->v->arena->nb_proc);
	mvprintw(g->n_players * 5 + 10, 205,"CYCLE_TO_DIE :%0.0d %-7d",
			0, g->v->arena->cycle_to_die);
	mvprintw(g->n_players * 5 + 12, 205,"CYCLE_DELTA : %5d", CYCLE_DELTA);
	mvprintw(g->n_players * 5 + 14, 205,"NBR_LIVE : %8d", NBR_LIVE);
	mvprintw(g->n_players * 5 + 16, 205,"MAX_CHECKS : %6d", MAX_CHECKS);
	ftncu_print_players(g);
	attron(A_NORMAL);
	if (g->v->end)
		mvprintw(LINES / 2, 205, "WINNER : %s", g->v->winner);
}
