/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompilo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 06:14:46 by apoisson          #+#    #+#             */
/*   Updated: 2017/07/31 07:41:56 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decompilo.h"

int			get_inst_length(int ocp, int op)
{
	int		label_size;
	int		size;
	int		i;
	int		r;

	r = (g_op_tab[op].nb_arg * 2);
	if (ocp == -1 && (op == 0 || op == 8 || op == 11 || op == 14))
		return ((g_op_tab[op]).label_size);
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
	return (size - 1);
}

int			get_value(t_decomp *decomp, int nb_octet, int pc)
{
	int		value;
	int		i;

	value = PROG[pc];
	i = 1;
	while (i < nb_octet)
	{
		value = value << 8;
		value += PROG[pc + i++];
	}
	if (nb_octet < 4)
		value = (short)value;
	return (value);
}

void		get_args(t_decomp *decomp, int ocp, int args[4], int pc)
{
	int		label_size;
	int		size;
	int		i;

	label_size = (!(g_op_tab[PROG[pc] - 1]).label_size) ?
		4 : (g_op_tab[PROG[pc] - 1]).label_size;
	size = 2;
	i = 0;
	while (i <= 6)
	{
		if (((ocp << i) & 0b11000000) == 0b11000000)
		{
			args[i / 2] = get_value(decomp, 2, pc + size);
			size += 2;
		}
		else if (((ocp << i) & 0b01000000))
			args[i / 2] = get_value(decomp, 1, pc + size++);
		else if ((ocp << i) & 0b10000000)
		{
			args[i / 2] = get_value(decomp, label_size, pc + size);
			size += label_size;
		}
		i += 2;
	}
}

int			verif_ocp(int op, int ocp)
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
	return (0);
}

int			get_ocp(t_decomp *decomp, int i)
{
	int		ocp;

	if (PROG[i] == 1 || PROG[i] == 9 || PROG[i] == 12 || PROG[i] == 15)
		return (-1);
	else
		ocp = PROG[i + 1];
	if (!verif_ocp(PROG[i], ocp))
		ft_perror("Champ error");
	return (ocp);
}
