/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ncurses.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 08:09:50 by apoisson          #+#    #+#             */
/*   Updated: 2017/07/31 06:25:26 by qumaujea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <stdio.h>

void		lp_rev(t_vm *vm)
{
	t_player	*curr;
	t_player	*tmp1;
	t_player	*tmp2;

	curr = A_LPLAYER;
	tmp1 = NULL;
	tmp2 = NULL;
	while (curr)
	{
		tmp1 = curr;
		curr = curr->next;
		tmp1->next = tmp2;
		tmp2 = tmp1;
	}
	A_LPLAYER = tmp1;
}

void		introduce_contestant(t_vm *vm, t_player *player)
{
	if (OPT_NC)
		return ;
	if (P_COLOR == 1)
		ft_printf(GREEN);
	if (P_COLOR == 2)
		ft_printf(BLUE);
	if (P_COLOR == 3)
		ft_printf(RED);
	if (P_COLOR == 4)
		ft_printf(YELLOW);
	ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
		P_COLOR, C_PSIZE, C_NAME, C_COM);
	ft_printf(DEFAULT);
}

/*
** load champ of each players in the memory of the vm
** at the good position
** and set the PC of the first proc of each players
** at this position
*/

void		load_champ(t_vm *vm)
{
	t_player	*current;
	int			i;
	int			j;

	if (!OPT_NC)
		ft_printf("Introducing contestants...\n\n");
	current = A_LPLAYER;
	j = -1;
	while (current)
	{
		introduce_contestant(vm, current);
		i = -1;
		while (++i < (int)current->champ->prog_size)
		{
			A_MEMORY[++j] = current->champ->prog[i];
			COLOR[j] = current->color;
		}
		j += MEM_SIZE / A_NBPLAYER - current->champ->prog_size;
		current = current->next;
	}
	if (!OPT_NC)
		ft_putendl("");
}

t_player	*get_player_from_id(t_vm *vm, int id)
{
	t_player	*curr;

	curr = A_LPLAYER;
	while (curr)
	{
		if (curr->id == id)
			return (curr);
		curr = curr->next;
	}
	return (NULL);
}

void		write_in_mem(t_vm *vm, int value, int pc, int color)
{
	if (OPT_V & V_OP)
		ft_printf("%s			| store %x to %d%s\n",
				WHITE, value, pc, DEFAULT);
	A_MEMORY[pc] = value >> 24;
	COLOR[pc] = color;
	A_MEMORY[(pc + 1) % MEM_SIZE] = (value >> 16) & 0b11111111;
	COLOR[(pc + 1) % MEM_SIZE] = color;
	A_MEMORY[(pc + 2) % MEM_SIZE] = (value >> 8) & 0b11111111;
	COLOR[(pc + 2) % MEM_SIZE] = color;
	A_MEMORY[(pc + 3) % MEM_SIZE] = value & 0b11111111;
	COLOR[(pc + 3) % MEM_SIZE] = color;
}
