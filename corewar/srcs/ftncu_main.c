/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftncu_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 00:13:23 by lcharbon          #+#    #+#             */
/*   Updated: 2017/07/23 23:14:53 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ncurse.h"
#include "corewar.h"
#include <fcntl.h>

void		ftncu_init_pair(void)
{
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_color(COLOR_CYAN, 500, 500, 500);
	init_pair(5, COLOR_BLACK, COLOR_BLACK);
	init_pair(6, COLOR_CYAN, COLOR_BLACK);
	init_pair(7, COLOR_BLACK, COLOR_MAGENTA);
}

static int	ftncu_mem_proc(t_gb *g, int i)
{
	t_proc	*tmp;

	tmp = g->v->arena->l_proc;
	while (tmp)
	{
		if (tmp->pc == i)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static void	ftncu_print_memory(t_gb *g, unsigned char *memory)
{
	int		i;
	int		n;
	int		a;

	i = 0;
	n = 3;
	a = 1;
	move(1, 1);
	ftncu_init_pair();
	attron(COLOR_PAIR(5));
	while (i < MEM_SIZE)
	{
		if (ftncu_mem_proc(g, i) == 1)
			attron(COLOR_PAIR(7));
		else if (memory[i] != 0)
			attron(COLOR_PAIR(6));
		printw("%.2X ", memory[i]);
		attron(COLOR_PAIR(5));
		if (n >= 192)
		{
			n = 0;
			a++;
			move(a, 1);
		}
		n += 3;
		i++;
	}
	attroff(COLOR_PAIR(5));
}

void		ftncu_main(t_vm *vm)
{
	t_gb		g;

//	clear();
	ft_memset(&g, 0, sizeof(g));
	g.v = vm;
	g.n_players = g.v->arena->nb_player;
	ftncu_print_info(&g);
	ftncu_print_memory(&g, vm->arena->memory);
	refresh();
	move(LINES, COLS);
//	while (42)
		getch();
}
