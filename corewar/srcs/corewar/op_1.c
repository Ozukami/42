/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ncurses.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 08:09:50 by apoisson          #+#    #+#             */
/*   Updated: 2017/07/31 06:14:34 by qumaujea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <stdio.h>

/*
** Op live
** pas d'OCP, 1 param sur 4 octets
** fait vivre le proc
** ajoute 1 vie au joueur dont l'id est en param
*/

void	op_live(t_vm *vm, t_proc *proc)
{
	int			value;
	t_player	*player;

	v_op(vm, "live", proc, 0);
	PR_LASTLIVE = A_CURCYCLE;
	PR_ALIVE = 1;
	TOTAL_LIVE++;
	value = get_value(vm, 4, proc, (PR_PC + 1) % MEM_SIZE);
	if ((player = get_player_from_id(vm, value)))
	{
		player->nb_live++;
		A_WINNER = P_ID;
		P_LASTLIVE = A_CYCLE;
		if (OPT_V & V_LIVE)
			ft_printf("%sPlayer %d %s is said to be alive%s\n",
					GREEN, P_COLOR, C_NAME, DEFAULT);
	}
	move_pc(vm, proc, 0);
}

void	op_ld(t_vm *vm, t_proc *proc)
{
	int		args[4];
	int		ocp;

	if ((ocp = get_ocp_args(vm, proc, args, 2)) == -1)
		return ;
	if ((ocp & 0b11000000) == 0b11000000)
		PR_REG[args[1]] = get_value(vm, 4, proc, verif_value(PR_PC, args[0]));
	else
	{
		if (!verif_reg(vm, proc, ocp, args[1]))
			return ;
		PR_REG[args[1]] = args[0];
	}
	PR_CARRY = (PR_REG[args[1]] == 0) ? 1 : 0;
	move_pc(vm, proc, ocp);
}

void	op_st(t_vm *vm, t_proc *proc)
{
	int		args[4];
	int		ocp;

	if ((ocp = get_ocp_args(vm, proc, args, 3)) == -1)
		return ;
	if (((ocp << 2) & 0b11000000) == 0b11000000)
	{
		if (!verif_reg(vm, proc, ocp, args[0]))
			return ;
		write_in_mem(vm, PR_REG[args[0]], verif_value(PR_PC, args[1]),
				get_player_from_id(vm, proc->id_player)->color);
	}
	else if ((ocp << 2) & 0b01000000)
	{
		if (!verif_reg(vm, proc, ocp, args[1]))
			return ;
		PR_REG[args[1]] = PR_REG[args[0]];
	}
	move_pc(vm, proc, ocp);
}

void	op_add(t_vm *vm, t_proc *proc)
{
	int		args[4];
	int		ocp;

	if ((ocp = get_ocp_args(vm, proc, args, 4)) == -1)
		return ;
	if (!verif_reg(vm, proc, ocp, args[0])
			|| !verif_reg(vm, proc, ocp, args[1]))
		return ;
	args[0] = PR_REG[args[0]];
	args[1] = PR_REG[args[1]];
	PR_REG[args[2]] = args[0] + args[1];
	PR_CARRY = (PR_REG[args[2]] == 0) ? 1 : 0;
	move_pc(vm, proc, ocp);
}

void	op_sub(t_vm *vm, t_proc *proc)
{
	int		args[4];
	int		ocp;

	if ((ocp = get_ocp_args(vm, proc, args, 5)) == -1)
		return ;
	if (!verif_reg(vm, proc, ocp, args[0])
			|| !verif_reg(vm, proc, ocp, args[1]))
		return ;
	args[0] = PR_REG[args[0]];
	args[1] = PR_REG[args[1]];
	PR_REG[args[2]] = args[0] - args[1];
	PR_CARRY = (PR_REG[args[2]] == 0) ? 1 : 0;
	move_pc(vm, proc, ocp);
}
