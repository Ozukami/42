/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 06:58:53 by apoisson          #+#    #+#             */
/*   Updated: 2017/06/16 07:02:02 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "sys/types.h"

int		get_i_next(char *str, char c)
{
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (i);
	return (0);
}

void	update_weight(t_instruction *instruction, t_champ *champ, int add)
{
	PROG_SIZE += add;
	I_WEIGHT += add;
}

char	*set_name(char *str)
{
	char	*name;
	int		i;

	i = ft_strlen(str);
	name = NULL;
	while (str[--i])
		if (str[i] == '.')
			name = ft_strsub(str, 0, i);
	if (name)
		return (ft_strjoinf_l(name, ".cor"));
	else
		name = ft_strdup(".cor");
	return (name);
}

int		get_value(t_champ *champ, int id_label, t_instruction *instruction)
{
	int				value;
	t_instruction	*current_inst;
	int				check;

	current_inst = L_INST;
	check = 0;
	value = 0;
	while (current_inst)
	{
		if (id_label == current_inst->id)
			check += 1;
		else if (instruction->id == current_inst->id)
			check += 2;
		if (check == 3)
			return (value);
		if (check == 1)
			value -= current_inst->weight;
		else if (check == 2)
			value += current_inst->weight;
		current_inst = current_inst->next;
	}
	return (value);
}

int		get_id_label(t_champ *champ, char *arg)
{
	int				id_label;
	t_label_list	*current_lab_list;

	id_label = 0;
	current_lab_list = L_LABEL;
	while (current_lab_list)
	{
		if (ft_strequ(current_lab_list->label, arg))
		{
			id_label = current_lab_list->id;
			return (id_label);
		}
		current_lab_list = current_lab_list->next;
	}
	return (id_label);
}
