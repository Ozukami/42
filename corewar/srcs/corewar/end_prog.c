/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ncurses.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 08:09:50 by apoisson          #+#    #+#             */
/*   Updated: 2017/07/31 07:17:11 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <stdio.h>

void		ft_usage(void)
{
	ft_putendl("usage: ./corewar [-a] [-d N -v N | -nc -s N --stealth] \
<[-n N] champ.cor> <...>");
	ft_putendl("#### TEXT OUTPUT MODE #######");
	ft_putendl(" -a  	: Prints output from \"aff\" (Default is to hide it)");
	ft_putendl(" -d N	: Dumps memory after N cycles then exits");
	ft_putendl(" -v N	: Verbosity levels, can be added together \
to enable several");
	ft_putendl("		- 1 : Show lives");
	ft_putendl("		- 2 : Show cycles");
	ft_putendl("		- 4 : Show operations");
	ft_putendl("		- 8 : Show deaths");
	ft_putendl("		- 16 : Show PC movements ");
	ft_putendl("		- 32 : Show CTD check");
	ft_putendl("#### NCURSES OUTPUT MODE ####");
	ft_putendl(" -nc		: Ncurses output mode");
	ft_putendl(" -s  		: Set visual actualisation speed");
	ft_putendl(" --stealth	: Hides the real contents of the memory");
	ft_putendl("#############################");
	exit(0);
}

void		dump_mem(t_vm *vm)
{
	int	i;

	if (OPT_V)
		ft_putendl("");
	i = -1;
	while (++i < MEM_SIZE)
	{
		if (COLOR[i] == 1)
			ft_printf(GREEN);
		else if (COLOR[i] == 2)
			ft_printf(BLUE);
		else if (COLOR[i] == 3)
			ft_printf(RED);
		else if (COLOR[i] == 4)
			ft_printf(CYAN);
		else
			ft_printf(DEFAULT);
		if (i != 0 && i % 64 == 0)
			ft_printf("\n%02x ", A_MEMORY[i]);
		else
			ft_printf("%02x ", A_MEMORY[i]);
	}
	ft_printf("%s\n", DEFAULT);
	if (OPT_D > -1)
		exit(0);
}

void		display_end(t_vm *vm)
{
	t_proc	*proc;

	vm->end = get_player_from_id(vm, A_WINNER)->color;
	vm->winner = get_player_from_id(vm, A_WINNER)->champ->name;
	if (!OPT_NC && A_CTD <= 0)
		ft_printf("%sCycle to die is now %d\n%sIt is now cycle %d%s\n",
				RED, A_CTD, GREY, ++A_CYCLE, DEFAULT);
	if (!OPT_NC)
		ft_printf("le joueur %d (%s) a gagne\n", A_WINNER,
				get_player_from_id(vm, A_WINNER)->champ->name);
	else
		ftncu_main(vm);
	proc = A_LPROC;
	while (proc)
	{
		kill_proc(vm, PR_ID);
		proc = A_LPROC;
	}
}

void		free_player(t_player *player)
{
	free(C_NAME);
	free(C_COM);
	free(C_PROG);
	free(P_CHAMP);
	free(player);
}

void		free_corewar(t_vm *vm, char **args)
{
	t_player	*player;
	t_player	*tmp;

	player = A_LPLAYER;
	while (player)
	{
		tmp = player;
		player = P_NEXT;
		free_player(tmp);
	}
	free(COLOR);
	free(A_MEMORY);
	free(ARENA);
	free(vm);
	free_map(args);
}
