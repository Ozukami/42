/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftncu_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 00:13:23 by lcharbon          #+#    #+#             */
/*   Updated: 2017/07/31 07:17:28 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ncurse.h"
#include "corewar.h"
#include <time.h>
#include <fcntl.h>

void				ftncu_init_pair(void)
{
	start_color();
	init_color(13, 500, 500, 500);
	init_color(14, 800, 800, 800);
	init_color(15, 0, 800, 0);
	init_color(16, 0, 0, 800);
	init_color(17, 800, 0, 0);
	init_color(18, 800, 800, 0);
	init_color(19, 1000, 1000, 1000);
	init_color(20, 0, 0, 0);
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, 13, COLOR_BLACK);
	init_pair(6, COLOR_CYAN, COLOR_BLACK);
	init_pair(7, COLOR_BLACK, 14);
	init_pair(9, COLOR_WHITE, COLOR_BLACK);
	init_pair(10, 20, 15);
	init_pair(11, 20, 16);
	init_pair(12, 20, 17);
	init_pair(13, 20, 18);
	init_pair(14, 19, COLOR_BLACK);
	init_pair(15, 20, 20);
}

static int			ftncu_mem_proc(t_gb *g, int i)
{
	t_proc	*tmp;

	tmp = g->v->arena->l_proc;
	while (tmp)
	{
		if (tmp->pc == i)
		{
			attron(COLOR_PAIR((tmp->color) + 10));
			g->col = tmp->color + 10;
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

static void			ftncu_act_attron(t_gb *g, int i)
{
	if (g->v->color_tab[i] == 1)
		attron(COLOR_PAIR(1));
	if (g->v->color_tab[i] == 2)
		attron(COLOR_PAIR(2));
	if (g->v->color_tab[i] == 3)
		attron(COLOR_PAIR(3));
	if (g->v->color_tab[i] == 4)
		attron(COLOR_PAIR(4));
	if (g->v->color_tab[i] == 0)
		attron(COLOR_PAIR(5));
}

static void			ftncu_print_memory(t_gb *g, unsigned char *memory)
{
	int		i;
	int		n;
	int		a;

	i = -1;
	n = 3;
	a = 1;
	move(1, 1);
	ftncu_init_pair();
	while (++i < MEM_SIZE)
	{
		ftncu_act_attron(g, i);
		ftncu_mem_proc(g, i);
		printw("%.2X", ((g->v->opt_stealth) ? 255 : memory[i]));
		printw(" ");
		if (n >= 192)
		{
			n = 0;
			a++;
			move(a, 1);
		}
		n += 3;
	}
	attron(A_NORMAL);
}

void				ftncu_main(t_vm *vm)
{
	t_gb			g;
	static int		n;

	ft_memset(&g, 0, sizeof(g));
	g.t = ftncu_normalize_time(vm->opt_s);
	g.v = vm;
	if (vm->arena->nb_proc < 1000 && g.t > 0)
		usleep(100 * g.t);
	if (n == 0)
		n = g.v->arena->nb_player;
	g.n_players = n;
	if (COLS > 242 && LINES > 50)
		ftncu_print_info(&g);
	if (COLS > 192 && LINES > 50)
		ftncu_print_memory(&g, vm->arena->memory);
	else
	{
		move(LINES / 2, COLS / 2);
		printw("Window too small");
	}
	refresh();
}
