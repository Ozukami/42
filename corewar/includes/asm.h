/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 03:22:57 by apoisson          #+#    #+#             */
/*   Updated: 2017/06/20 03:23:00 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "op.h"
# include "libft.h"
# include <stdio.h>
# include <fcntl.h>

# define INITIAL	1
# define FINAL		2

# define I_LABEL	(instruction->label)
# define I_ARGS		(instruction->args)
# define I_OP		(instruction->op)
# define I_OCP		(instruction->ocp)
# define I_ID		(instruction->id)
# define I_WEIGHT	(instruction->weight)
# define I_NEXT		(instruction->next)

# define ID			(state->id)
# define STATUS		(state->status)
# define TRANSITION	(state->transitions)
# define T_NEXT		(state->next)

# define NAME		(champ->name)
# define FD			(champ->fd)
# define HEADER		(champ->header)
# define AUTOMATON	(champ->automaton)
# define OP_TAB		(champ->op_tab)
# define L_INST		(champ->l_instruction)
# define L_LABCHECK	(champ->l_label_check)
# define L_LABEL	(champ->l_label)

# define PROG_SIZE	(champ->header->prog_size)

extern t_op						g_op_tab[17];

typedef struct s_instruction	t_instruction;
typedef struct s_label_list		t_label_list;
typedef struct s_state			t_state;
typedef struct s_champ			t_champ;

struct				s_instruction
{
	char			*label;
	int				op;
	int				ocp;
	char			**args;
	int				id;
	int				weight;
	t_instruction	*next;
};

struct				s_label_list
{
	int				id;
	char			*label;
	t_label_list	*next;
};

struct				s_state
{
	int				id;
	int				status;
	char			*transitions;
	t_state			**next;
};

struct				s_champ
{
	char			*name;
	int				fd;
	t_header		*header;
	t_state			*automaton;
	t_instruction	*l_instruction;
	t_label_list	*l_label_check;
	t_label_list	*l_label;
	t_op			*op_tab;
};

t_state				*init_automaton(void);
void				init_op_tab(t_champ *champ);

void				write_value(char *prog, int value, int size);
void				write_label(char *prog, t_champ *champ,
					t_instruction *instruction, char *arg);
void				write_args(t_instruction *current, char *prog,
		int *i, t_champ *champ);
void				write_champ(t_champ *champ);
void				write_prog_name(t_champ *champ);
void				write_comment(t_champ *champ);
void				write_prog_size(t_champ *champ);
void				write_header(t_champ *champ);

int					get_value(t_champ *champ, int id_label,
		t_instruction *instruction);
int					get_id_label(t_champ *champ, char *arg);

int					get_name(t_champ *champ, char **split, int verif);
int					get_comment(t_champ *champ, char **split, int verif);
int					check_header(t_champ *champ, char *line, char *line_epur);

int					get_label(char *str, t_instruction *instruction,
		t_champ *champ);
int					get_op(char *str, t_instruction *instruction,
		t_champ *champ);
void				get_args(t_champ *champ, char *str,
		t_instruction *instruction);
t_instruction		*get_instruction(char *line, t_champ *champ);
void				build_instruction_list(t_champ *champ);

int					check_op(t_state *state, char *str, int i);
int					check_reg(t_champ *champ, char *str,
		t_instruction *instruction);
int					check_ind_dir(t_instruction *instruction,
		t_champ *champ, char *str);
char				*check_com_arg(char *str);
void				check_label(t_champ *champ);

void				add_label(t_champ *champ, char *str, int id);
void				add_labcheck(t_champ *champ, char *str);

void				update_weight(t_instruction *instruction,
		t_champ *champ, int add);
int					get_i_next(char *str, char c);
int					get_value(t_champ *champ, int id_label,
		t_instruction *instruction);
int					get_id_label(t_champ *champ, char *arg);
char				*set_name(char *str);

#endif
