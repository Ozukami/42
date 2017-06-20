/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 02:47:48 by apoisson          #+#    #+#             */
/*   Updated: 2017/06/20 05:29:00 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <ncurses.h>
# include <curses.h>
# include "op.h"

# define NCURSES			(vm->ncurses)
# define ARENA				(vm->arena)

# define W_INFO				(vm->ncurses->w_info)
# define W_MEMORY			(vm->ncurses->w_memory)
# define W_COL				64
# define W_LINE				64
# define W_BORDER			2

# define A_LPLAYER			(vm->arena->l_player)
# define A_MEMORY			(vm->arena->memory)
# define A_PROC				(vm->arena->nb_proc)
# define A_CYCLE			(vm->arena->nb_cycle)

# define P_LPROC			(player->l_proc)
# define P_ID				(player->id)
# define P_PROC				(player->nb_proc)
# define P_LIVE				(player->nb_live)
# define P_REG				(player->reg)
# define P_NEXT				(player->next)

# define C_NAME				(player->champ->name)
# define C_COM				(player->champ->comment)
# define C_PROG				(player->champ->prog)
# define C_PSIZE			(player->champ->prog_size)

# define PR_PC				(proc->pc)
# define PR_CARRY			(proc->carry)
# define PR_WAIT			(proc->cycle_to_wait)
# define PR_NEXT			(proc->next)

typedef struct s_vm			t_vm;
typedef struct s_ncurses	t_ncurses;
typedef struct s_arena		t_arena;
typedef struct s_player		t_player;
typedef struct s_champ		t_champ;
typedef struct s_proc		t_proc;

struct						s_proc
{
	int						pc;
	int						carry;
	int						cycle_to_wait;
	t_proc					*next;
};

struct						s_champ
{
	char					*name;
	char					*comment;
	char					*prog;
	int						prog_size;
};

struct						s_player
{
	t_proc					*l_proc;
	t_champ					*champ;
	int						id;
	int						nb_proc;
	int						nb_live;
	int						*reg;
	t_player				*next;
};

struct						s_arena
{
	t_player				*l_player;
	unsigned char			*memory;
	int						nb_proc;
	int						nb_cycle;
};

struct						s_ncurses
{
	WINDOW					*w_memory;
	WINDOW					*w_info;
};

struct						s_vm
{
	t_ncurses				*ncurses;
	t_arena					*arena;
};

#endif
