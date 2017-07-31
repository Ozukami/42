/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumaujea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 04:47:24 by qumaujea          #+#    #+#             */
/*   Updated: 2017/07/31 05:10:19 by qumaujea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <stdio.h>

t_op	g_op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0, 4},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 1, 4},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 1, 4},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 1, 4},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 1, 4},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 0, 2},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 0, 2},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 0, 2},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 0, 2},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 1, 4},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1, 2},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 0, 2},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0, 0}
};

void	(*g_fun_op[16])(t_vm *, t_proc *) = {op_live, op_ld, op_st,
	op_add, op_sub, op_and, op_or, op_xor, op_zjmp, op_ldi, op_sti,
	op_fork, op_lld, op_lldi, op_lfork, op_aff};

/*
** run the vm with the champs
** use the implementation of op
** display with ncurses
*/

void		process(t_vm *vm)
{
	t_proc		*curr;

	while (A_CTD > 0)
	{
		if (OPT_D > -1 && A_CYCLE > (OPT_D - 1))
			dump_mem(vm);
		A_CYCLE++;
		A_CURCYCLE++;
		if (OPT_V & V_CYCLE)
			ft_printf("%sIt is now cycle %d%s\n", GREY, A_CYCLE, DEFAULT);
		curr = A_LPROC;
		while (curr)
		{
			exec_proc(vm, curr);
			curr = curr->next;
		}
		if (A_CURCYCLE >= A_CTD)
			check_alive(vm);
		if (OPT_NC > 0)
			ftncu_main(vm);
		if (!A_PROC)
			break ;
	}
}

int			main(int ac, char **av)
{
	t_vm	*vm;
	char	**args;

	if (ac < 2)
		ft_usage();
	vm = init_vm();
	if (!(args = ft_memalloc(sizeof(char *) * (ac + 1))))
		ft_perror(strerror(errno));
	get_options(vm, ac, av, args);
	ftcor_args_error(vm);
	if (!(args[0]))
		ft_usage();
	init_arena(vm, tab_size(args), args);
	load_champ(vm);
	if (OPT_NC > 0)
	{
		initscr();
		ftncu_main(vm);
	}
	process(vm);
	display_end(vm);
	free_corewar(vm, args);
	return (1);
}
