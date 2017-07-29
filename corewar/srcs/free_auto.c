/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_auto.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumaujea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 03:58:19 by qumaujea          #+#    #+#             */
/*   Updated: 2017/07/29 04:11:29 by qumaujea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			init_automaton_2(t_state *automaton)
{
	free((((automaton->next)[6]->next)[0]->next)[0]->next)[0];
	free(((automaton->next)[6]->next)[0]->next)[0];
	free((automaton->next)[6]->next)[0];
	free(automaton->next)[6];
	free(((automaton->next)[5]->next)[0]->next)[0];
	free((automaton->next)[5]->next)[0];
	free(automaton->next)[5];
	free(((automaton->next)[4]->next)[1]->next)[0];
	free(((automaton->next)[4]->next)[0]->next)[0];
	free((automaton->next)[4]->next)[1];
	free((automaton->next)[4]->next)[0];
	free(automaton->next)[4];
	free((automaton->next)[3]->next)[0];
	free(automaton->next)[3];
	free(((((automaton->next)[2]->next)[1]->next)[0]->next)[0]->next)[0];
	free((((automaton->next)[2]->next)[3]->next)[0]->next)[0];
	free((((automaton->next)[2]->next)[2]->next)[0]->next)[0];
	free((((automaton->next)[2]->next)[1]->next)[0]->next)[0];
	free(((automaton->next)[2]->next)[3]->next)[0]
	free(((automaton->next)[2]->next)[2]->next)[0];
	free(((automaton->next)[2]->next)[1]->next)[0];
}

void		init_automaton(void)
{
	t_state		*automaton;

	free_automaton_2(automaton);
	free(((automaton->next)[2]->next)[0]->next)[0];
	free((automaton->next)[2]->next)[3];
	free((automaton->next)[2]->next)[2];
	free((automaton->next)[2]->next)[1];
	free((automaton->next)[2]->next)[0];
	free(automaton->next)[2];
	free((((automaton->next)[1]->next)[0]->next)[0]->next)[0];
	free(((automaton->next)[1]->next)[0]->next)[0];
	free((automaton->next)[1]->next)[0];
	free(automaton->next)[1];
	free(((automaton->next)[0]->next)[2]->next)[0];
	free(((automaton->next)[0]->next)[1]->next)[0];
	free(((automaton->next)[0]->next)[0]->next)[0];
	free((automaton->next)[0]->next)[2];
	free((automaton->next)[0]->next)[1];
	free((automaton->next)[0]->next)[0];
	free(automaton->next)[0];
	free(automaton);
}
