/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 02:47:48 by apoisson          #+#    #+#             */
/*   Updated: 2017/06/20 03:20:01 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

typedef struct s_arena		t_arena;
typedef struct s_player		t_player;
typedef struct s_proc		t_proc;

struct						s_proc
{
	int						pc;
	int						carry;
	int						cycle_to_wait;
	t_proc					*next;
};

struct						s_player
{
	t_proc					*l_proc;
	char					*name;
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

#endif
