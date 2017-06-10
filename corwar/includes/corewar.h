/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumaujea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 03:21:32 by qumaujea          #+#    #+#             */
/*   Updated: 2017/06/10 02:47:20 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# define INITIAL	1
# define FINAL		2

typedef struct s_instruction	t_instruction;
typedef struct s_state			t_state;

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

#endif
