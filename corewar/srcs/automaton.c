/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automaton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 06:08:07 by apoisson          #+#    #+#             */
/*   Updated: 2017/06/12 01:33:58 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_state			*new_state(int id, int status, char *transitions)
{
	t_state		*state;

	if (!(state = ft_memalloc(sizeof(t_state))))
		ft_perror("Malloc failled !");
	state->id = id;
	state->status = status;
	state->transitions = transitions;
	if (!(state->next = ft_memalloc(sizeof(t_state) *
					(ft_strlen(transitions) + 1))))
		ft_perror("Malloc failled !");
	return (state);
}

t_state			*init_automaton()
{
	t_state		*automaton;

	automaton = new_state(0, INITIAL, "aflosxz");

	(automaton->next)[0] = new_state(17, 0, "dfn");

	((automaton->next)[0]->next)[0] = new_state(18, 0, "d");
	(((automaton->next)[0]->next)[0]->next)[0] = new_state(4, FINAL, "");

	((automaton->next)[0]->next)[1] = new_state(19, 0, "f");
	(((automaton->next)[0]->next)[1]->next)[0] = new_state(16, FINAL, "");

	((automaton->next)[0]->next)[2] = new_state(20, 0, "d");
	(((automaton->next)[0]->next)[2]->next)[0] = new_state(6, FINAL, "");

	(automaton->next)[1] = new_state(21, 0, "o");
	((automaton->next)[1]->next)[0] = new_state(22, 0, "r");
	(((automaton->next)[1]->next)[0]->next)[0] = new_state(23, 0, "k");
	((((automaton->next)[1]->next)[0]->next)[0]->next)[0] = new_state(12, FINAL, "");

	(automaton->next)[2] = new_state(24, 0, "dfil");

	((automaton->next)[2]->next)[0] = new_state(2, FINAL, "i");
	(((automaton->next)[2]->next)[0]->next)[0] = new_state(10, FINAL, "");

	((automaton->next)[2]->next)[1] = new_state(25, 0, "o");
	(((automaton->next)[2]->next)[1]->next)[0] = new_state(26, 0, "r");
	((((automaton->next)[2]->next)[1]->next)[0]->next)[0] = new_state(27, 0, "k");
	(((((automaton->next)[2]->next)[1]->next)[0]->next)[0]->next)[0] = new_state(15, FINAL, "");

	((automaton->next)[2]->next)[2] = new_state(28, 0, "v");
	(((automaton->next)[2]->next)[2]->next)[0] = new_state(29, 0, "e");
	((((automaton->next)[2]->next)[2]->next)[0]->next)[0] = new_state(1, FINAL, "");

	((automaton->next)[2]->next)[3] = new_state(30, 0, "d");
	(((automaton->next)[2]->next)[3]->next)[0] = new_state(13, FINAL, "i");
	((((automaton->next)[2]->next)[3]->next)[0]->next)[0] = new_state(14, FINAL, "");

	(automaton->next)[3] = new_state(31, 0, "r");
	((automaton->next)[3]->next)[0] = new_state(7, FINAL, "");

	(automaton->next)[4] = new_state(32, 0, "ut");

	((automaton->next)[4]->next)[0] = new_state(33, 0, "b");
	(((automaton->next)[4]->next)[0]->next)[0] = new_state(5, FINAL, "");

	((automaton->next)[4]->next)[1] = new_state(3, FINAL, "i");
	(((automaton->next)[4]->next)[1]->next)[0] = new_state(11, FINAL, "");

	(automaton->next)[5] = new_state(34, 0, "o");
	((automaton->next)[5]->next)[0] = new_state(35, 0, "r");
	(((automaton->next)[5]->next)[0]->next)[0] = new_state(8, FINAL, "");

	(automaton->next)[6] = new_state(36, 0, "j");
	((automaton->next)[6]->next)[0] = new_state(37, 0, "m");
	(((automaton->next)[6]->next)[0]->next)[0] = new_state(38, 0, "p");
	((((automaton->next)[6]->next)[0]->next)[0]->next)[0] = new_state(9, FINAL, "");
	return (automaton);
}
