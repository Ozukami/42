/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumaujea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 00:34:46 by qumaujea          #+#    #+#             */
/*   Updated: 2017/06/12 05:17:23 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_op	g_op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0, 4},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 1, 4},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 1, 4},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 1, 4},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 1, 4},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 0, 2},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 0, 2},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 0, 2},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 0, 2},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 1, 4},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1, 2},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 0, 2},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0, 0}
};

int		get_label(char *str, t_instruction *instruction)
{
	int			i;

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
			instruction->label = ft_strsub(str, 0, i);
			return (i);
		}
	}
	return (0);
}

int		get_i_next(char *str, char c)
{
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (i);
	return (0);
}

int		check_op(t_state *state, char *str, int i)
{
	if (!str || !str[i])
		ft_perror("Error: syntax error");
	if (STATUS == FINAL && (str[i] == ' ' || str[i] == DIRECT_CHAR))
		return (ID);
	if (!ft_strchr(TRANSITION, str[i]))
		ft_perror("Error: syntax error");
	return (check_op(T_NEXT[get_i_next(TRANSITION, str[i])], str, i + 1));
}

/*
** Verify if the op using the automaton
** and stock it into instruction
*/

int		get_op(char *str, t_instruction *instruction, t_champ *champ)
{
	instruction->op = check_op(AUTOMATON, str, 0);
	return (ft_strlen(g_op_tab[instruction->op - 1].op));
}

/*
** T_REG 1 or 2 digits after 'r'
*/

int		check_reg(char *str)
{
	int		i;

	i = 0;
	while (str[++i])
		if (!ft_isdigit(str[i++]) || i > 2)
			ft_perror("Error: syntax error");
	if (i < 2)
		ft_perror("Error: syntax error");
	return (1);
}

void	add_label(t_champ *champ, char *str)
{
	t_label_list	*label;
	int				i;

	if (!(label = ft_memalloc(sizeof(t_label_list))))
		ft_perror("Error: malloc failed");
	i = (str[0] == DIRECT_CHAR) ? 2 : 1;
	label->label = ft_strsub(str, i, ft_strlen(str) - i);
	label->next = L_LABEL;
	L_LABEL = label;
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

int		check_ind_dir(t_champ *champ, char *str)
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
				ft_perror("Error: syntax error");
		add_label(champ, str);
	}
	else
		while (str[i])
			if (!ft_isdigit(str[i++]))
				ft_perror("Error: syntax error");
	return ((str[0] == DIRECT_CHAR) ? 2 : 4);
}

/*
** Verify if the params match with the op
** and stock it into instruction
*/

int		get_args(t_champ *champ, char *str, t_instruction *instruction)
{
	int		i;
	int		arg;

	I_ARGS = ft_strsplitf(str, SEPARATOR_CHAR);
	if (tab_size(I_ARGS) != g_op_tab[I_OP - 1].nb_arg)
		ft_perror("Error: syntax error");
	i = -1;
	while (I_ARGS[++i])
	{
		I_ARGS[i] = str_epur(I_ARGS[i]);
		if (I_ARGS[i][0] == 'r')
			arg = check_reg(I_ARGS[i]);
		else
			arg = check_ind_dir(champ, I_ARGS[i]);
		if (!arg || !(arg & g_op_tab[I_OP - 1].args[i]))
			ft_perror("Error: syntax error");
	}
	return (1);
}

t_instruction	*get_instruction(char *line, t_champ *champ)
{
	t_instruction	*instruction;
	int				i;

	if (!(instruction = ft_memalloc(sizeof(t_instruction))))
		ft_perror("Error: malloc failed");
	instruction->label = NULL;
	instruction->next = NULL;
	if ((i = get_label(line, instruction)) > 0)
		line = str_epur(ft_strsubf(line, i + 1, ft_strlen(line) - i));
	if ((i = get_op(line, instruction, champ)) < 1)
		ft_perror("Error: syntax error");
	line = str_epur(ft_strsubf(line, i, ft_strlen(line) - i));
	if ((i = get_args(champ, line, instruction)) < 1)
		ft_perror("Error: syntax error");
	return (instruction);
}

int		get_name(t_champ *champ, char **split, int verif)
{
	if (split[2])
		ft_perror("Error: lexical error");
	if (verif == 2)
		ft_perror("Error: too many .name");
	if (ft_strlen(split[1]) > PROG_NAME_LENGTH)
		ft_perror("Error: name is too large");
	ft_strcpy(HEADER->prog_name, split[1]);
	free_map(split);
	return (1);
}

int		get_comment(t_champ *champ, char **split, int verif)
{
	if (split[2])
		ft_perror("Error: lexical error");
	if (verif == 6)
		ft_perror("Error: too many .comment");
	if (ft_strlen(split[1]) > COMMENT_LENGTH)
		ft_perror("Error: comment is too large");
	ft_strcpy(HEADER->comment, split[1]);
	free_map(split);
	return (3);
}

int		check_header(t_champ *champ, char *line)
{
	static int	verif = 0;

	if (!line)
		return (0);
	if (line[0] == COMMENT_CHAR)
		return (0);
	if (line[0] == '.')
	{
		if (ft_strequf_l(ft_strsub(line, 0, 8), COMMENT_CMD_STRING))
			return (get_comment(champ, ft_strsplitf(line, '\"'), verif += 3));
		else if (ft_strequf_l(ft_strsub(line, 0, 5), NAME_CMD_STRING))
			return (get_name(champ, ft_strsplitf(line, '\"'), verif += 1));
		else
			ft_perror("Error: lexical error");
	}
	else if (verif != 4)
		ft_perror("Error: lexical error");
	return (0);
}

void	build_instruction_list(t_champ *champ)
{
	char		*line;
	t_instruction	*current;

	current = L_INST;
	while (get_next_line(FD, &line))
	{
		line = str_epur(line);
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

void	check_label(t_champ *champ)
{
	t_label_list	*curr_label;
	t_instruction	*curr_instruction;

	curr_label = L_LABEL;
	while (curr_label)
	{
		curr_instruction = L_INST;
		while (curr_instruction)
		{
			if (ft_strequ(curr_label->label, curr_instruction->label))
				break ;
			curr_instruction = curr_instruction->next;
			if (!curr_instruction->next)
				ft_perror("Error: syntax error");
		}
		curr_label = curr_label->next;
	}
}

void	parse_file(t_champ *champ)
{
	int			r;
	char		*line;

	r = 0;
	while (r != 4 && get_next_line(FD, &line))
		r += check_header(champ, str_epur(line));
	while (get_next_line(FD, &line))
	{
		if ((line = str_epur(line)) && line[0] != COMMENT_CHAR)
			break ;
		ft_strdel(&line);
	}
	L_INST = get_instruction(line, champ);
	build_instruction_list(champ);
	check_label(champ);
}

t_champ	*init_champ(void)
{
	t_champ	*champ;

	if (!(champ = ft_memalloc(sizeof(t_champ))))
		ft_perror("Error: malloc failed");
	FD = 0;
	if (!(HEADER = ft_memalloc(sizeof(t_header))))
		ft_perror("Error: malloc failed");
	AUTOMATON = init_automaton();
	L_INST = NULL;
	L_LABEL = NULL;
	return (champ);
}

int		main(int ac, char **av)
{
	t_champ		*champ;

	if (ac < 2)
		ft_perror("usage: ./asm champ.s");
	champ = init_champ();
	if ((FD = open(av[1], O_RDONLY)) == -1)
		ft_perror("Error: open failed");
	parse_file(champ);
	if (close(FD) == -1)
		ft_perror("Error: close failed");
	return (0);
}
