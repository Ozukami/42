/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 02:47:48 by apoisson          #+#    #+#             */
/*   Updated: 2017/07/23 23:14:01 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <ncurses.h>
# include <curses.h>
# include "ncurse.h"
# include "op.h"
# include "libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <errno.h>

extern int					errno;

# define DEFAULT			"\033[0m"
# define BLACK				"\033[30m"
# define RED				"\033[31m"
# define GREEN				"\033[32m"
# define YELLOW				"\033[33m"
# define BLUE				"\033[34m"
# define PURPLE				"\033[35m"
# define CYAN				"\033[36m"
# define WHITE				"\033[37m"

# define NCURSES			(vm->ncurses)
# define ARENA				(vm->arena)
# define OPT_NC				(vm->opt_ncurses)
# define OPT_D				(vm->opt_d)
# define TOTAL_LIVE			(vm->total_live)
# define COLOR				(vm->color_tab)

# define W_INFO				(vm->ncurses->w_info)
# define W_MEMORY			(vm->ncurses->w_memory)
# define W_COL				64
# define W_LINE				64
# define W_BORDER			2

# define A_LPLAYER			(vm->arena->l_player)
# define A_LPROC			(vm->arena->l_proc)
# define A_MEMORY			(vm->arena->memory)
# define A_PROC				(vm->arena->nb_proc)
# define A_CYCLE			(vm->arena->nb_cycle)
# define A_CTD				(vm->arena->cycle_to_die)
# define A_NBPLAYER			(vm->arena->nb_player)
# define A_NBCHECK			(vm->arena->nb_check)
# define A_WINNER			(vm->arena->last_alive)

# define P_CHAMP			(player->champ)
# define P_ID				(player->id)
# define P_PROC				(player->nb_proc)
# define P_LIVE				(player->nb_live)
# define P_COLOR			(player->color)
# define P_NEXT				(player->next)

# define C_NAME				(player->champ->name)
# define C_COM				(player->champ->comment)
# define C_PROG				(player->champ->prog)
# define C_PSIZE			(player->champ->prog_size)

# define PR_ID				(proc->id)
# define PR_IDP				(proc->id_player)
# define PR_ALIVE			(proc->alive)
# define PR_PC				(proc->pc)
# define PR_CARRY			(proc->carry)
# define PR_WAIT			(proc->cycle_to_wait)
# define PR_NEXT			(proc->next)
# define PR_REG				(proc->reg)

extern t_op					g_op_tab[17];

typedef struct s_vm			t_vm;
typedef struct s_ncurses	t_ncurses;
typedef struct s_arena		t_arena;
typedef struct s_player		t_player;
typedef struct s_champ		t_champ;
typedef struct s_proc		t_proc;

struct						s_proc
{
	int						id;
	int						id_player;
	int						alive;
	int						test;
	int						pc;
	int						carry;
	int						cycle_to_wait;
	int						*reg;
	t_proc					*next;
};

struct						s_champ
{
	unsigned char			*name;
	unsigned char			*comment;
	unsigned char			*prog;
	unsigned int			prog_size;
};

struct						s_player
{
	t_champ					*champ;
	int						id;
	int						nb_proc;
	int						nb_live;
	int						color;
	t_player				*next;
};

struct						s_arena
{
	t_player				*l_player;
	t_proc					*l_proc;
	unsigned char			*memory;
	int						nb_proc;
	int						nb_cycle;
	int						cycle_to_die;
	int						nb_player;
	int						nb_check;
	int						last_alive; // id player
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
	int						opt_ncurses;
	int						opt_d;
	int						total_live;
	int						*color_tab;
};

#endif
