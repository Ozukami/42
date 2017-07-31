/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ncurses.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 08:09:50 by apoisson          #+#    #+#             */
/*   Updated: 2017/07/31 06:26:27 by qumaujea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <stdio.h>

t_proc			*new_proc(int id_player)
{
	t_proc		*proc;
	static int	id = 1;

	if (!(proc = ft_memalloc(sizeof(t_proc))))
		ft_perror(strerror(errno));
	PR_ID = id++;
	PR_IDP = id_player;
	PR_ALIVE = 0;
	PR_LASTLIVE = 0;
	proc->test = 1;
	PR_PC = 0;
	PR_CARRY = 0;
	PR_WAIT = 1;
	PR_NEXT = NULL;
	if (!(PR_REG = ft_memalloc(sizeof(int) * (REG_NUMBER + 2))))
		ft_perror(strerror(errno));
	PR_REG[1] = PR_IDP;
	PR_LOP = -1;
	return (proc);
}

t_proc			*init_proc(t_vm *vm)
{
	t_proc		*proc;
	t_proc		*curr_proc;
	t_player	*curr_player;

	curr_player = A_LPLAYER;
	curr_proc = NULL;
	while (curr_player)
	{
		proc = new_proc(curr_player->id);
		proc->color = curr_player->color - 1;
		A_WINNER = curr_player->id;
		A_PROC++;
		proc->next = curr_proc;
		curr_proc = proc;
		curr_player = curr_player->next;
	}
	return (proc);
}

void			update_nb_proc(t_vm *vm, int id_player)
{
	t_player	*curr;

	curr = A_LPLAYER;
	while (curr)
	{
		if (curr->id == id_player)
			(curr->nb_proc)--;
		curr = curr->next;
	}
}

/*
** BONUS : jouer un son quand on kill un process
** genre le "FATALITY" de Mortal Kombat
*/

int				kill_first(t_vm *vm, t_proc *curr, int id)
{
	t_proc	*tmp;

	if (curr->id == id)
	{
		if (OPT_V & V_DEATH)
			ft_printf("%sProcess %d has died (CTD %d) %p%s\n",
					RED, curr->id, A_CTD, curr, DEFAULT);
		tmp = curr;
		A_LPROC = tmp->next;
		curr = A_LPROC;
		update_nb_proc(vm, tmp->id_player);
		free(tmp->reg);
		free(tmp);
		if (OPT_NC)
			system("afplay ressources/fatality.aiff &");
		return (1);
	}
	return (0);
}

void			kill_proc(t_vm *vm, int id)
{
	t_proc	*curr;
	t_proc	*tmp;

	A_PROC--;
	curr = A_LPROC;
	if (kill_first(vm, curr, id))
		return ;
	while (curr->next)
	{
		if (curr->next->id == id)
		{
			if (OPT_V & V_DEATH)
				ft_printf("%sProcess %d has died (CTD %d) %p%s\n",
						RED, curr->next->id, A_CTD, curr->next, DEFAULT);
			tmp = curr->next;
			curr->next = tmp->next;
			update_nb_proc(vm, tmp->id_player);
			free(tmp->reg);
			free(tmp);
			if (OPT_NC)
				system("afplay ressources/fatality.aiff &");
			return ;
		}
		curr = curr->next;
	}
}
