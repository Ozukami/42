/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ncurses.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 08:09:50 by apoisson          #+#    #+#             */
/*   Updated: 2017/07/31 06:26:49 by qumaujea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <stdio.h>

void		init_arena(t_vm *vm, int nb_args, char **args)
{
	t_arena		*arena;
	t_proc		*curr_proc;
	int			i;

	if (!(arena = ft_memalloc(sizeof(t_arena))))
		ft_perror(strerror(errno));
	ARENA = arena;
	A_PROC = 0;
	A_CYCLE = 0;
	A_CURCYCLE = 0;
	A_CTD = CYCLE_TO_DIE;
	A_NBPLAYER = 0;
	A_NBCHECK = 0;
	A_MEMORY = ft_memalloc(MEM_SIZE);
	A_LPLAYER = get_player(nb_args, args);
	verif_nb_player(vm);
	lp_rev(vm);
	A_LPROC = init_proc(vm);
	curr_proc = A_LPROC;
	i = A_NBPLAYER - 1;
	while (curr_proc)
	{
		curr_proc->pc = (i-- * (MEM_SIZE / A_NBPLAYER)) % MEM_SIZE;
		curr_proc = curr_proc->next;
	}
}

void		set_opt(int *opt, char *n)
{
	int		opt_n;

	opt_n = ft_atoi(n);
	if (opt_n > -1)
		*opt = opt_n;
}

void		get_options(t_vm *vm, int ac, char **av, char **args)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (++i < ac)
	{
		if (ft_strequ(av[i], "-a"))
			OPT_A = 1;
		else if (ft_strequ(av[i], "-s"))
			(++i < ac) ? set_opt(&(vm->opt_s), av[i]) : ft_perror("Error");
		else if (ft_strequ(av[i], "-d"))
			(++i < ac) ? set_opt(&(vm->opt_d), av[i]) : ft_perror("Error");
		else if (ft_strequ(av[i], "-v"))
			(++i < ac) ? set_opt(&(vm->opt_v), av[i]) : ft_perror("Error");
		else if (ft_strequ(av[i], "-nc"))
			OPT_NC = 1;
		else if (ft_strequ(av[i], "--stealth"))
			OPT_STEALTH = 1;
		else
			args[j++] = ft_strdup(av[i]);
	}
	args[j] = 0;
}

t_vm		*init_vm(void)
{
	t_vm	*vm;

	if (!(vm = ft_memalloc(sizeof(t_vm))))
		ft_perror(strerror(errno));
	ARENA = NULL;
	OPT_NC = 0;
	OPT_D = -1;
	OPT_V = 0;
	OPT_A = 0;
	OPT_S = 0;
	OPT_STEALTH = 0;
	TOTAL_LIVE = 0;
	vm->end = 0;
	if (!(COLOR = ft_memalloc(sizeof(int) * MEM_SIZE)))
		ft_perror(strerror(errno));
	return (vm);
}

void		ftcor_args_error(t_vm *vm)
{
	if (OPT_NC == 1)
	{
		OPT_V = 0;
		OPT_D = -1;
	}
}
