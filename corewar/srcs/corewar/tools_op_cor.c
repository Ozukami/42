/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ncurses.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 08:09:50 by apoisson          #+#    #+#             */
/*   Updated: 2017/07/31 02:59:36 by qumaujea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <stdio.h>

/*
** Returns the number of bytes of the current instruction
*/

int		get_inst_length(int ocp, int op)
{
	int		label_size;
	int		size;
	int		i;
	int		r;

	r = (g_op_tab[op].nb_arg * 2);
	if (!ocp && (op == 0 || op == 8 || op == 11 || op == 14))
		return ((g_op_tab[op]).label_size + 1);
	label_size = (!(g_op_tab[op]).label_size) ? 4 : (g_op_tab[op]).label_size;
	size = 2;
	i = 0;
	while (i < (g_op_tab[op].nb_arg * 2))
	{
		if (((ocp << i) & 0b11000000) == 0b11000000)
			size += 2;
		else if ((ocp << i) & 0b01000000)
			size++;
		else if ((ocp << i) & 0b10000000)
			size += label_size;
		i += 2;
	}
	return (size);
}

int		get_value(t_vm *vm, int nb_octet, t_proc *proc, int pc)
{
	int				value;
	int				i;

	(void)proc;
	value = A_MEMORY[pc];
	i = 1;
	while (i < nb_octet)
	{
		value = value << 8;
		value += A_MEMORY[(pc + i++) % MEM_SIZE];
	}
	if (nb_octet < 4)
		value = (short)value;
	if (nb_octet == 1 && (value < 1 || value > 16))
		return (0);
	return (value);
}

void		get_args(t_vm *vm, t_proc *proc, int ocp, int args[4])
{
	int		label_size;
	int		size;
	int		i;

	label_size = (!(g_op_tab[PR_LOP - 1]).label_size) ?
		4 : (g_op_tab[PR_LOP - 1]).label_size;
	size = 2;
	i = 0;
	while (i <= 6)
	{
		if (((ocp << i) & 0b11000000) == 0b11000000)
		{
			args[i / 2] = get_value(vm, 2, proc, (PR_PC + size) % MEM_SIZE);
			size += 2;
		}
		else if (((ocp << i) & 0b01000000))
			args[i / 2] = get_value(vm, 1, proc, (PR_PC + size++) % MEM_SIZE);
		else if ((ocp << i) & 0b10000000)
		{
			args[i / 2] = get_value(vm, label_size, proc,
					(PR_PC + size) % MEM_SIZE);
			size += label_size;
		}
		i += 2;
	}
}

void		v_op(t_vm *vm, char *name, t_proc *proc, int ocp)
{
	int		color;

	if (!(OPT_V & V_OP))
		return ;
	color = get_player_from_id(vm, PR_IDP)->color;
	if (color == 1)
		ft_printf(GREEN);
	else if (color == 2)
		ft_printf(BLUE);
	else if (color == 3)
		ft_printf(RED);
	else if (color == 4)
		ft_printf(YELLOW);
	ft_printf("%s(proc %d)%s | ",
			get_player_from_id(vm, PR_IDP)->champ->name, PR_ID, WHITE);
	ft_printf("%s%s%s", CYAN, name, DEFAULT);
	if (ocp)
		ft_printf("%s (OCP %d)%s", PURPLE, ocp, DEFAULT);
	ft_printf("%s (PC %d)%s", YELLOW, PR_PC, DEFAULT);
	if (PR_LOP == 1 || PR_LOP == 12 || PR_LOP == 15)
		ft_printf("\n");
}

int		get_ocp_args(t_vm *vm, t_proc *proc, int *args, int op)
{
	int		ocp;
	int		i;

	ocp = A_MEMORY[(PR_PC + 1) % MEM_SIZE];
	if (!verif_ocp(vm, proc, op, ocp))
		return (-1);
	v_op(vm, g_op_tab[op - 1].op, proc, ocp);
	get_args(vm, proc, ocp, args);
	if (OPT_V & V_OP)
	{
		i = -1;
		while (++i < g_op_tab[op - 1].nb_arg)
			printf(" [%d]", args[i]);
		printf("\n");
	}
	return (ocp);
}
