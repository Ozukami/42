/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ncurses.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 08:09:50 by apoisson          #+#    #+#             */
/*   Updated: 2017/07/31 02:55:28 by qumaujea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_sti(t_vm *vm, t_proc *proc)
{
	int		args[4];
	int		ocp;

	if ((ocp = get_ocp_args(vm, proc, args, 11)) == -1)
		return ;
	if (!verif_reg(vm, proc, ocp, args[0]))
		return ;
	if (!verif_args(vm, proc, ocp << 2, &(args[1])))
		return ;
	if (((ocp << 4) & 0b01000000))
	{
		if (!verif_reg(vm, proc, ocp, args[2]))
			return ;
		args[2] = PR_REG[args[2]];
	}
	write_in_mem(vm, PR_REG[args[0]], verif_value(PR_PC, args[1] + args[2]),
				get_player_from_id(vm, proc->id_player)->color);
	move_pc(vm, proc, ocp);
}

void	op_fork(t_vm *vm, t_proc *proc)
{
	int		value;
	int		i;
	t_proc	*clone;

	v_op(vm, "fork", proc, 0);
	value = get_value(vm, 2, proc, (PR_PC + 1) % MEM_SIZE);
	value %= IDX_MOD;
	value %= MEM_SIZE;
	clone = new_proc(PR_IDP);
	clone->carry = proc->carry;
	clone->alive = proc->alive;
	if (PR_PC + value < 0)
		clone->pc = (PR_PC + MEM_SIZE + value) % MEM_SIZE;
	else
		clone->pc = (PR_PC + value) % MEM_SIZE;
	A_PROC++;
	i = 0;
	while (++i < 17)
		(clone->reg)[i] = PR_REG[i];
	clone->next = A_LPROC;
	A_LPROC = clone;
	move_pc(vm, proc, 0);
}

void	op_lld(t_vm *vm, t_proc *proc)
{
	int		args[4];
	int		ocp;

	if ((ocp = get_ocp_args(vm, proc, args, 13)) == -1)
		return ;
	if ((ocp & 0b11000000) == 0b11000000)
		args[0] = get_value(vm, 2, proc, verif_value(PR_PC, args[0]));
	if (!verif_reg(vm, proc, ocp, args[1]))
		return ;
	PR_REG[args[1]] = args[0];
	PR_CARRY = (PR_REG[args[1]] == 0) ? 1 : 0;
	move_pc(vm, proc, ocp);
}

void	op_lldi(t_vm *vm, t_proc *proc)
{
	int		args[4];
	int		ocp;

	if ((ocp = get_ocp_args(vm, proc, args, 14)) == -1)
		return ;
	if (!verif_reg(vm, proc, ocp, args[2]))
		return ;
	if (!verif_args(vm, proc, ocp, &(args[0]))
			|| !verif_args(vm, proc, ocp << 2, &(args[1])))
		return ;
	PR_REG[args[2]] = get_value(vm, REG_SIZE, proc,
			(PR_PC + args[0] + args[1]) % MEM_SIZE);
	PR_CARRY = (PR_REG[args[1]] == 0) ? 1 : 0;
	move_pc(vm, proc, ocp);
}

void	op_lfork(t_vm *vm, t_proc *proc)
{
	int		value;
	t_proc	*clone;
	int		i;

	v_op(vm, "lfork", proc, 0);
	value = get_value(vm, 2, proc, (PR_PC + 1) % MEM_SIZE);
	value %= MEM_SIZE;
	clone = new_proc(PR_IDP);
	clone->carry = proc->carry;
	clone->alive = proc->alive;
	if (PR_PC + value < 0)
		clone->pc = (PR_PC + MEM_SIZE + value) % MEM_SIZE;
	else
		clone->pc = (PR_PC + value) % MEM_SIZE;
	A_PROC++;
	i = 0;
	while (++i < 17)
		(clone->reg)[i] = PR_REG[i];
	clone->next = A_LPROC;
	A_LPROC = clone;
	move_pc(vm, proc, 0);
}
