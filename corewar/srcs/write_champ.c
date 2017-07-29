/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_champ.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 06:10:10 by apoisson          #+#    #+#             */
/*   Updated: 2017/07/29 03:54:30 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "op.h"

void	write_value(char *prog, int value, int size)
{
	size = (size) ? size : 2;
	if (size == 4)
	{
		prog[3] = value & 0xff;
		prog[2] = (value >> 8) & 0xff;
		prog[1] = (value >> 16) & 0xff;
		prog[0] = (value >> 24) & 0xff;
	}
	else
	{
		prog[1] = value & 0xff;
		prog[0] = (value >> 8) & 0xff;
	}
}

void	write_label(char *prog, t_champ *champ,
		t_instruction *instruction, char *arg)
{
	int				value;
	int				id_label;
	int				dir;
	char			*tmp;

	dir = (arg[0] == DIRECT_CHAR) ? 1 : 0;
	tmp = ft_strsub(arg, dir + 1, ft_strlen(arg) - dir - 1);
	id_label = get_id_label(champ, tmp);
	free(tmp);
	value = get_value(champ, id_label, instruction);
	if (dir && g_op_tab[instruction->op - 1].label_size == 4)
	{
		prog[3] = value & 0xff;
		prog[2] = (value >> 8) & 0xff;
		prog[1] = (value >> 16) & 0xff;
		prog[0] = (value >> 24) & 0xff;
	}
	else
	{
		prog[1] = value & 0xff;
		prog[0] = (value >> 8) & 0xff;
	}
}

void	write_args(t_instruction *current, char *prog, int *i, t_champ *champ)
{
	int				j;
	int				dir;

	j = -1;
	while (++j < g_op_tab[current->op - 1].nb_arg)
	{
		if (current->args[j][0] == 'r')
			prog[(*i)++] = ft_atoi((current->args[j]) + 1);
		else
		{
			dir = (current->args[j][0] == DIRECT_CHAR) ? 1 : 0;
			if (current->args[j][dir] == LABEL_CHAR)
				write_label(&(prog[*i]), champ, current,
						current->args[j]);
			else
				write_value(&(prog[*i]), ft_atoi(current->args[j] + dir),
						g_op_tab[current->op - 1].label_size * dir);
			*i += (dir) ? g_op_tab[current->op - 1].label_size : 2;
		}
	}
}

void	write_champ(t_champ *champ)
{
	t_instruction	*current;
	char			*prog;
	int				i;

	if (!(prog = ft_memalloc(PROG_SIZE + 1)))
		ft_perror("Error: malloc failed");
	i = 0;
	current = L_INST;
	while (current)
	{
		if (current->op)
		{
			prog[i++] = g_op_tab[current->op - 1].opcode;
			if (g_op_tab[current->op - 1].ocp)
				prog[i++] = current->ocp;
			write_args(current, prog, &i, champ);
		}
		current = current->next;
	}
	lseek(FD, 0x890, SEEK_SET);
	write(FD, prog, PROG_SIZE);
	ft_strdel(&prog);
}
