/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ncurses.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 08:09:50 by apoisson          #+#    #+#             */
/*   Updated: 2017/07/31 05:12:30 by qumaujea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <stdio.h>

void		cycle_verif(t_vm *vm)
{
	t_player	*player;

	player = A_LPLAYER;
	while (player)
	{
		P_LIVE = 0;
		player = player->next;
	}
	if (TOTAL_LIVE >= NBR_LIVE || ++A_NBCHECK == MAX_CHECKS)
	{
	 	A_CTD -= CYCLE_DELTA;
	 	A_NBCHECK = 0;
	}
	TOTAL_LIVE = 0;
}

void		check_alive(t_vm *vm)
{
	t_player	*curr_player;
	t_proc		*curr_proc;
	t_proc		*tmp;

	A_CURCYCLE = 0;
	if (OPT_V & V_CHECK)
		ft_printf("%sCHECK (CTD %d)%s\n", RED, A_CTD, DEFAULT);
	curr_proc = A_LPROC;
	while (curr_proc)
	{
		tmp = curr_proc->next;
		if (!curr_proc->alive)
			kill_proc(vm, curr_proc->id);
		else
			curr_proc->alive = 0;
		curr_proc = tmp;
	}
	curr_player = A_LPLAYER;
	while (curr_player)
	{
		if (curr_player->nb_proc == 0)
			A_NBPLAYER--;
		curr_player = curr_player->next;
	}
	cycle_verif(vm);
}

void	move_pc(t_vm *vm, t_proc *proc, int ocp)
{
	int		size;
	int		i;

	size = get_inst_length(ocp, PR_LOP - 1);
	i = -1;
	if (OPT_V & V_PC)
	{
		ft_printf("\033[2;3;36mADV %d (0x%04x -> ", size, PR_PC);
		ft_printf("0x%04x)", PR_PC + size);
		while (++i < size)
			ft_printf(" %02x", A_MEMORY[(PR_PC + i) % MEM_SIZE]);
		ft_printf("%s\n", DEFAULT);
	}
	PR_PC += size;
	PR_PC %= MEM_SIZE;
	PR_WAIT = 1;
	PR_LOP = -1;
}

void	exec_proc(t_vm *vm, t_proc *proc)
{
	if ((PR_LOP == -1) &&
			(A_MEMORY[PR_PC] <= 0 || A_MEMORY[PR_PC] > 16))
		PR_PC = ((PR_PC) + 1) % MEM_SIZE;
	else if (PR_LOP != -1 && PR_WAIT >=
				(g_op_tab[PR_LOP - 1]).cycles) // EXEC OP
			(g_fun_op[PR_LOP - 1])(vm, proc);
	else
	{
		if (PR_LOP == -1)
			PR_LOP = A_MEMORY[PR_PC];
		PR_WAIT++;
	}
}
