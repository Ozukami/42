/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumaujea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 03:21:32 by qumaujea          #+#    #+#             */
/*   Updated: 2017/06/12 01:50:26 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

#include "op.h"
#include "libft.h"
#include <stdio.h>
#include <fcntl.h>

# define INITIAL	1
# define FINAL		2

# define I_ARGS		(instruction->args)
# define I_OP		(instruction->op)

# define ID			(state->id)
# define STATUS		(state->status)
# define TRANSITION	(state->transitions)
# define T_NEXT		(state->next)

# define FD			(champ->fd)
# define HEADER		(champ->header)
# define AUTOMATON	(champ->automaton)
# define OP_TAB		(champ->op_tab)
# define L_INST		(champ->l_instruction)

typedef struct s_instruction	t_instruction;
typedef struct s_state			t_state;
typedef struct s_champ			t_champ;

struct				s_instruction
{
	char			*label;
	int				op;
	char			**args;
	t_instruction	*next;
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
	int				fd;
	t_header		*header;
	t_state			*automaton;
	t_instruction	*l_instruction;
	t_op			*op_tab;
};

t_state				*init_automaton(void);
void				init_op_tab(t_champ *champ);

#endif
