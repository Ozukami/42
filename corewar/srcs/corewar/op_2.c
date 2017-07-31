/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumaujea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 02:52:36 by qumaujea          #+#    #+#             */
/*   Updated: 2017/07/31 02:52:57 by qumaujea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_and(t_vm *vm, t_proc *proc)
{
	int		args[4];
	int		ocp;

	if ((ocp = get_ocp_args(vm, proc, args, 6)) == -1)
		return ;
	if (!verif_args(vm, proc, ocp, &(args[0]))
			|| !verif_args(vm, proc, ocp << 2, &(args[1])))
		return ;
	if (!verif_reg(vm, proc, ocp, args[2]))
		return ;
	PR_REG[args[2]] = args[0] & args[1];
	PR_CARRY = (PR_REG[args[2]] == 0) ? 1 : 0;
	move_pc(vm, proc, ocp);
}

void	op_or(t_vm *vm, t_proc *proc)
{
	int		args[4];
	int		ocp;

	if ((ocp = get_ocp_args(vm, proc, args, 7)) == -1)
		return ;
	if (!verif_args(vm, proc, ocp, &(args[0]))
			|| !verif_args(vm, proc, ocp << 2, &(args[1])))
		return ;
	if (!verif_reg(vm, proc, ocp, args[2]))
		return ;
	PR_REG[args[2]] = args[0] | args[1];
	PR_CARRY = (PR_REG[args[2]] == 0) ? 1 : 0;
	move_pc(vm, proc, ocp);
}

void	op_xor(t_vm *vm, t_proc *proc)
{
	int		args[4];
	int		ocp;

	if ((ocp = get_ocp_args(vm, proc, args, 8)) == -1)
		return ;
	if (!verif_args(vm, proc, ocp, &(args[0]))
			|| !verif_args(vm, proc, ocp << 2, &(args[1])))
		return ;
	if (!verif_reg(vm, proc, ocp, args[2]))
		return ;
	PR_REG[args[2]] = args[0] ^ args[1];
	PR_CARRY = (PR_REG[args[2]] == 0) ? 1 : 0;
	move_pc(vm, proc, ocp);
}

void	op_zjmp(t_vm *vm, t_proc *proc)
{
	int	value;

	v_op(vm, "zjmp", proc, 0);
	value = get_value(vm, 2, proc, (PR_PC + 1) % MEM_SIZE);
	if (PR_CARRY == 1)
	{
		if (OPT_V & V_OP)
			ft_printf("%s	OK%s\n", GREEN, DEFAULT);
		if (OPT_V & V_PC)
			ft_printf("\033[2;3;36mADV %d (0x%04x -> ", ((short)value), PR_PC);
		PR_PC += ((short)value);
		PR_PC %= MEM_SIZE;
		if (PR_PC < 0)
			PR_PC += MEM_SIZE;
		if (OPT_V & V_PC)
			ft_printf("0x%04x)%s\n", PR_PC, DEFAULT);
		PR_WAIT = 1;
		PR_LOP = -1;
		return ;
	}
	else
		if (OPT_V & V_OP)
			ft_printf("%s	ZJMP FAILLED%s\n", RED, DEFAULT);
	move_pc(vm, proc, 0);
}

void	op_ldi(t_vm *vm, t_proc *proc)
{
	int		args[4];
	int		ocp;

	if ((ocp = get_ocp_args(vm, proc, args, 10)) == -1)
		return ;
	if (!verif_reg(vm, proc, ocp, args[2]))
		return ;
	if (!verif_args(vm, proc, ocp, &(args[0]))
			|| !verif_args(vm, proc, ocp << 2, &(args[1])))
		return ;
	PR_REG[args[2]] = get_value(vm, REG_SIZE, proc,
			(PR_PC + args[0] + args[1]) % MEM_SIZE);
	move_pc(vm, proc, ocp);
}
