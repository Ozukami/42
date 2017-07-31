/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftasm_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 02:33:27 by lcharbon          #+#    #+#             */
/*   Updated: 2017/07/29 06:00:49 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void			ftasm_free_args(t_instruction *l)
{
	int				i;

	i = -1;
	if (!l->args)
		return ;
	while (++i <= g_op_tab[l->op - 1].nb_arg - 1)
		free(l->args[i]);
	free(l->args);
}

static void			ftasm_free_inst(t_instruction *l)
{
	t_instruction	*tmp;

	while (l)
	{
		tmp = l->next;
		ft_strdel(&l->label);
		ftasm_free_args(l);
		free(l);
		l = tmp;
	}
}

static void			ftasm_free_label(t_label_list *l)
{
	t_label_list	*tmp;

	while (l)
	{
		tmp = l->next;
		free(l->label);
		free(l);
		l = tmp;
	}
}

static void			ftasm_free_automaton(void)
{
	t_state			*tmp;

	tmp = g_free_point;
	while (g_free_point)
	{
		tmp = g_free_point->nxt;
		free(g_free_point->f->next);
		free(g_free_point->f);
		free(g_free_point);
		g_free_point = tmp;
	}
}

void				ftasm_free(t_champ *ch)
{
	ft_strdel(&ch->name);
	ftasm_free_inst(ch->l_instruction);
	ftasm_free_label(ch->l_label_check);
	ftasm_free_label(ch->l_label);
	ftasm_free_automaton();
	free(ch);
	ch = NULL;
}
