/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 07:01:04 by apoisson          #+#    #+#             */
/*   Updated: 2017/06/17 00:35:52 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "sys/types.h"

int				get_label(char *str, t_instruction *instruction, t_champ *champ)
{
	int				i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
	{
		if ((!ft_strchr(LABEL_CHARS, str[i]) && str[i] != LABEL_CHAR)
				|| str[i] == DIRECT_CHAR)
			return (0);
		if (str[i] == LABEL_CHAR)
		{
			I_LABEL = ft_strsub(str, 0, i);
			add_label(champ, I_LABEL, I_ID);
			return (i);
		}
	}
	return (0);
}

/*
** Verify if the op using the automaton
** and stock it into instruction
*/

int				get_op(char *str, t_instruction *instruction, t_champ *champ)
{
	instruction->op = check_op(AUTOMATON, str, 0);
	PROG_SIZE += 1 + (g_op_tab[I_OP - 1]).ocp;
	I_WEIGHT += 1 + (g_op_tab[I_OP - 1]).ocp;
	return (ft_strlen(g_op_tab[I_OP - 1].op));
}

/*
** Verify if the params match with the op
** and stock it into instruction
*/

void			get_args(t_champ *champ, char *str, t_instruction *instruction)
{
	int				i;
	int				arg;

	I_OCP = 0;
	I_ARGS = ft_strsplitf(str, SEPARATOR_CHAR);
	if (tab_size(I_ARGS) != g_op_tab[I_OP - 1].nb_arg)
		ft_perror("Error: syntax error 7");
	i = -1;
	while (I_ARGS[++i])
	{
		I_ARGS[i] = str_epur(I_ARGS[i]);
		if (I_ARGS[i][0] == 'r')
			arg = check_reg(champ, I_ARGS[i], instruction);
		else
			arg = check_ind_dir(instruction, champ, I_ARGS[i]);
		if (!arg || !(arg & g_op_tab[I_OP - 1].args[i]))
			ft_perror("Error: syntax error 8");
		I_OCP = I_OCP | arg;
		I_OCP = I_OCP << 2;
	}
	while (i++ < 3)
		I_OCP = I_OCP << 2;
}

t_instruction	*get_instruction(char *line, t_champ *champ)
{
	t_instruction	*instruction;
	int				i;
	static int		id = 0;

	if (!(instruction = ft_memalloc(sizeof(t_instruction))))
		ft_perror("Error: malloc failed");
	I_ID = id++;
	if ((i = get_label(line, instruction, champ)) > 0)
		line = str_epur(ft_strsubf(line, i + 1, ft_strlen(line) - i));
	if (!line || line[0] == COMMENT_CHAR || line[0] == ';')
	{
		if (line && line[0])
			ft_strdel(&line);
		return (instruction);
	}
	if ((i = get_op(line, instruction, champ)) < 1)
		ft_perror("Error: syntax error 9");
	line = str_epur(ft_strsubf(line, i, ft_strlen(line) - i));
	line = str_epur(check_com_arg(line));
	get_args(champ, line, instruction);
	return (instruction);
}

void			build_instruction_list(t_champ *champ)
{
	char			*line;
	t_instruction	*current;

	current = L_INST;
	while (get_next_line(FD, &line))
	{
		line = str_epur(line);
		if (line && (ft_strequf_l(ft_strsub(line, 0, 8), ".comment")
				|| ft_strequf_l(ft_strsub(line, 0, 5), ".name")))
			break ;
		if (line && line[0] && line[0] != COMMENT_CHAR)
		{
			current->next = get_instruction(line, champ);
			current = current->next;
		}
		else
			ft_strdel(&line);
	}
	ft_strdel(&line);
}
