/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ncurses.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 08:09:50 by apoisson          #+#    #+#             */
/*   Updated: 2017/07/31 06:15:11 by qumaujea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <stdio.h>

int		verif_ocp(t_vm *vm, t_proc *proc, int op, int ocp)
{
	if (((op == 2 || op == 13) && (ocp == 144 || ocp == 208))
			|| (op == 3 && (ocp == 80 || ocp == 112))
			|| ((op == 4 || op == 5) && (ocp == 84))
			|| ((op == 6 || op == 7 || op == 8) &&
					(ocp == 84 || ocp == 100 || ocp == 116 ||
					ocp == 148 || ocp == 164 || ocp == 180 ||
					ocp == 212 || ocp == 228 || ocp == 244))
			|| ((op == 10 || op == 14) &&
					(ocp == 84 || ocp == 100 || ocp == 148 ||
					ocp == 164 || ocp == 212 || ocp == 228))
			|| (op == 11 && (ocp == 84 || ocp == 88 || ocp == 100 ||
					ocp == 104 || ocp == 116 || ocp == 120))
			|| (op == 16 && (ocp == 64)))
		return (1);
	if (OPT_V & V_OP)
		ft_printf("	%sPROC (%d) OP %d (%d) FAILED%s\n",
				RED, proc->id, op, ocp, DEFAULT);
	PR_WAIT = 1;
	move_pc(vm, proc, ocp);
	return (0);
}

int		verif_value(int pc, int value)
{
	value = (pc + (value % IDX_MOD)) % MEM_SIZE;
	return ((value < 0) ? value += MEM_SIZE : value);
}

int		verif_reg(t_vm *vm, t_proc *proc, int ocp, int args)
{
	if (args < 1 || args > 16)
	{
		move_pc(vm, proc, ocp);
		return (0);
	}
	return (1);
}

int		verif_args(t_vm *vm, t_proc *proc, int ocp, int *args)
{
	if (((ocp & 0b11000000)) == 0b11000000)
		*args = get_value(vm, 4, proc, verif_value(PR_PC, *args));
	else if ((ocp & 0b01000000))
	{
		if (!verif_reg(vm, proc, ocp, *args))
			return (0);
		*args = PR_REG[*args];
	}
	return (1);
}

void	op_aff(t_vm *vm, t_proc *proc)
{
	int		value;
	int		ocp;
	char	aff;

	ocp = A_MEMORY[(PR_PC + 1) % MEM_SIZE];
	if (!verif_ocp(vm, proc, 16, ocp))
		return ;
	v_op(vm, "aff", proc, ocp);
	value = get_value(vm, 1, proc, (PR_PC + 2) % MEM_SIZE);
	if (value < 1 || value > 16)
	{
		move_pc(vm, proc, ocp);
		return ;
	}
	aff = PR_REG[value] % 256;
	if (OPT_A && !OPT_NC)
		ft_printf("aff: %c\n", aff);
	system("afplay ressources/trolololo.aiff &");
	move_pc(vm, proc, ocp);
}
