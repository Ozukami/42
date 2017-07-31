/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 06:38:13 by apoisson          #+#    #+#             */
/*   Updated: 2017/07/29 00:19:43 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "sys/types.h"

int		check_op(t_state *state, char *str, int i)
{
	if (!str || !str[i])
		ft_perror("Error: syntax error 1");
	if (STATUS == FINAL && (str[i] == ' ' || str[i] == DIRECT_CHAR))
		return (ID);
	if (!ft_strchr(TRANSITION, str[i]))
		ft_perror("Error: syntax error 2");
	return (check_op(T_NEXT[get_i_next(TRANSITION, str[i])], str, i + 1));
}

/*
** T_REG 1 or 2 digits after 'r'
*/

int		check_reg(t_champ *champ, char *str, t_instruction *instruction)
{
	int		i;

	i = 0;
	while (str[++i])
		if ((str[i + 1] && !ft_isdigit(str[i++])) || i > 2)
			ft_perror("Error: syntax error 3");
	if (i < 2)
		ft_perror("Error: syntax error 4");
	PROG_SIZE += 1;
	I_WEIGHT++;
	return (1);
}

/*
** T_DIR
** starts with '%'
** then have ':' (for label) or digits
** can't overflow, max is ff ff
** can be negative
** T_IND can overflow
** can be negative
*/

int		check_ind_dir(t_instruction *instruction, t_champ *champ, char *str)
{
	int		i;
	int		label;

	i = 0;
	if (str[i] == DIRECT_CHAR)
		i++;
	i += (str[i] == '-') ? 1 : 0;
	label = (str[i] == LABEL_CHAR) ? 1 : 0;
	if (label)
	{
		while (str[++i])
			if (!ft_strchr(LABEL_CHARS, str[i]))
				ft_perror("Error: syntax error 5");
		add_labcheck(champ, str);
	}
	else
		while (str[i])
			if (!ft_isdigit(str[i++]))
				ft_perror("Error: syntax error 6");
	if (str[0] == DIRECT_CHAR)
		update_weight(instruction, champ, (g_op_tab[I_OP - 1]).label_size);
	else
		update_weight(instruction, champ, 2);
	return ((str[0] == DIRECT_CHAR) ? T_DIR : T_IND - 1);
}

char	*check_com_arg(char *str)
{
	int		i;
	char	**split;
	char	*line;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '#' || str[i] == ';')
		{
			split = (str[i] == '#') ? ft_strsplit(str, '#') :
				ft_strsplit(str, ';');
			ft_strdel(&str);
			line = ft_strdup(split[0]);
			free_map(split);
			return (line);
		}
	}
	return (str);
}

void	check_label(t_champ *champ)
{
	t_label_list	*curr_label;
	t_instruction	*curr_instruction;

	curr_label = L_LABCHECK;
	while (curr_label)
	{
		curr_instruction = L_INST;
		while (curr_instruction)
		{
			if (ft_strequ(curr_label->label, curr_instruction->label))
				break ;
			if (!curr_instruction->next)
				ft_perror("Error: syntax error 11");
			curr_instruction = curr_instruction->next;
		}
		curr_label = curr_label->next;
	}
}
