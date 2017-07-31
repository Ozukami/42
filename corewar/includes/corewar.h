/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 02:47:48 by apoisson          #+#    #+#             */
/*   Updated: 2017/07/31 07:45:29 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "ncurse.h"
# include "op.h"
# include "libft.h"
# include "ft_printf.h"
# include <ncurses.h>
# include <curses.h>
# include <fcntl.h>
# include <errno.h>

# include <sys/time.h>

# define DEFAULT			"\033[0m"
# define BLACK				"\033[30m"
# define RED				"\033[31m"
# define GREEN				"\033[32m"
# define YELLOW				"\033[33m"
# define BLUE				"\033[34m"
# define PURPLE				"\033[35m"
# define CYAN				"\033[36m"
# define WHITE				"\033[37m"
# define GREY				"\033[2;37m"

# define V_LIVE				1
# define V_CYCLE			2
# define V_OP				4
# define V_DEATH			8
# define V_PC				16
# define V_CHECK			32

# define ARENA				(vm->arena)
# define OPT_NC				(vm->opt_ncurses)
# define OPT_D				(vm->opt_d)
# define OPT_V				(vm->opt_v)
# define OPT_A				(vm->opt_a)
# define OPT_S				(vm->opt_s)
# define OPT_STEALTH		(vm->opt_stealth)
# define TOTAL_LIVE			(vm->total_live)
# define COLOR				(vm->color_tab)

# define A_LPLAYER			(vm->arena->l_player)
# define A_LPROC			(vm->arena->l_proc)
# define A_MEMORY			(vm->arena->memory)
# define A_PROC				(vm->arena->nb_proc)
# define A_CYCLE			(vm->arena->nb_cycle)
# define A_CURCYCLE			(vm->arena->curr_cycle)
# define A_CTD				(vm->arena->cycle_to_die)
# define A_NBPLAYER			(vm->arena->nb_player)
# define A_NBCHECK			(vm->arena->nb_check)
# define A_WINNER			(vm->arena->last_alive)

# define P_CHAMP			(player->champ)
# define P_ID				(player->id)
# define P_PROC				(player->nb_proc)
# define P_LIVE				(player->nb_live)
# define P_LASTLIVE			(player->last_live)
# define P_COLOR			(player->color)
# define P_NEXT				(player->next)

# define C_NAME				(player->champ->name)
# define C_COM				(player->champ->comment)
# define C_PROG				(player->champ->prog)
# define C_PSIZE			(player->champ->prog_size)

# define PR_ID				(proc->id)
# define PR_IDP				(proc->id_player)
# define PR_LASTLIVE		(proc->last_live)
# define PR_ALIVE			(proc->alive)
# define PR_PC				(proc->pc)
# define PR_CARRY			(proc->carry)
# define PR_WAIT			(proc->cycle_to_wait)
# define PR_NEXT			(proc->next)
# define PR_REG				(proc->reg)
# define PR_LOP				(proc->loaded_op)

extern t_op					g_op_tab[17];

typedef struct s_vm			t_vm;
typedef struct s_ncurses	t_ncurses;
typedef struct s_arena		t_arena;
typedef struct s_player		t_player;
typedef struct s_champ		t_champ;
typedef struct s_proc		t_proc;

extern void					(*g_fun_op[16])(t_vm *, t_proc *);

struct						s_proc
{
	int						id;
	int						id_player;
	int						last_live;
	int						alive;
	int						test;
	int						pc;
	int						carry;
	int						cycle_to_wait;
	int						*reg;
	int						loaded_op;
	int						color;
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
	int						last_live;
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
	int						curr_cycle;
	int						cycle_to_die;
	int						nb_player;
	int						nb_check;
	int						last_alive;
};

struct						s_vm
{
	t_arena					*arena;
	int						opt_ncurses;
	int						opt_d;
	int						opt_v;
	int						opt_a;
	int						opt_s;
	int						opt_stealth;
	int						total_live;
	int						*color_tab;
	int						end;
	unsigned char			*winner;
};

void						process(t_vm *vm);
void						ft_usage(void);
void						dump_mem(t_vm *vm);
void						display_end(t_vm *vm);
void						free_player(t_player *player);
void						free_corewar(t_vm *vm, char **args);
void						ftasm_free(t_champ *ch);
void						ftncu_init_pair(void);
void						ftncu_main(t_vm *vm);
void						verif_nb_player(t_vm *vm);
void						update_nb_proc(t_vm *vm, int id_player);
void						kill_proc(t_vm *vm, int id);
void						cycle_verif(t_vm *vm);
void						update_nb_proc(t_vm *vm, int id_player);
void						check_alive(t_vm *vm);
void						move_pc(t_vm *vm, t_proc *proc, int ocp);
void						exec_proc(t_vm *vm, t_proc *proc);
void						init_arena(t_vm *vm, int nb_args, char **args);
void						set_opt(int *opt, char *n);
void						get_options(t_vm *vm, int ac, char **av,
		char **args);
void						ftcor_args_error(t_vm *vm);
void						lp_rev(t_vm *vm);
void						introduce_contestant(t_vm *vm, t_player *player);
void						load_champ(t_vm *vm);
void						write_in_mem(t_vm *vm, int value, int pc,
		int color);
void						get_args(t_vm *vm, t_proc *proc, int ocp,
		int args[4]);
void						v_op(t_vm *vm, char *name, t_proc *proc, int ocp);

t_vm						*init_vm(void);
t_player					*get_player_from_id(t_vm *vm, int id);
t_proc						*new_proc(int id_player);

int							get_champ_size(int fd);
int							ftncu_normalize_time(int s);
int							verif_ocp(t_vm *vm, t_proc *proc, int op, int ocp);
int							verif_value(int pc, int value);
int							verif_reg(t_vm *vm, t_proc *proc, int ocp,
		int args);
int							verif_args(t_vm *vm, t_proc *proc, int ocp,
		int *args);
int							get_ocp_args(t_vm *vm, t_proc *proc, int *args,
		int op);
int							get_id(int nb_args, char **args, int *i);
int							kill_first(t_vm *vm, t_proc *curr, int id);
int							get_inst_length(int ocp, int op);
int							get_value(t_vm *vm, int nb_octet, t_proc *proc,
		int pc);
int							get_ocp_args(t_vm *vm, t_proc *proc, int *args,
		int op);

unsigned char				*get_champ_name(int fd);
unsigned char				*get_champ_comment(int fd);
unsigned char				*get_champ_prog(int fd, unsigned int size);

/*
**	OPERATIONS
*/

void						op_live(t_vm *vm, t_proc *proc);
void						op_ld(t_vm *vm, t_proc *proc);
void						op_st(t_vm *vm, t_proc *proc);
void						op_add(t_vm *vm, t_proc *proc);
void						op_sub(t_vm *vm, t_proc *proc);
void						op_and(t_vm *vm, t_proc *proc);
void						op_or(t_vm *vm, t_proc *proc);
void						op_xor(t_vm *vm, t_proc *proc);
void						op_zjmp(t_vm *vm, t_proc *proc);
void						op_ldi(t_vm *vm, t_proc *proc);
void						op_sti(t_vm *vm, t_proc *proc);
void						op_fork(t_vm *vm, t_proc *proc);
void						op_lld(t_vm *vm, t_proc *proc);
void						op_lldi(t_vm *vm, t_proc *proc);
void						op_lfork(t_vm *vm, t_proc *proc);
void						op_aff(t_vm *vm, t_proc *proc);

t_player					*read_file(int fd, int id);
t_champ						*read_champ(int fd);
void						verif_file(int fd);
t_proc						*init_proc(t_vm *vm);
t_player					*get_player(int nb_args, char **args);

#endif
