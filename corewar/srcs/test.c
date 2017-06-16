/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumaujea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 00:34:46 by qumaujea          #+#    #+#             */
/*   Updated: 2017/06/16 06:25:41 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "sys/types.h"

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

void	add_label(t_champ *champ, char *str, int id)
{
	t_label_list	*label;

	if (!(label = ft_memalloc(sizeof(t_label_list))))
		ft_perror("Error: malloc failed");
	label->label = ft_strdup(str);
	label->next = L_LABEL;
	label->id = id;
	L_LABEL = label;
}

int		get_label(char *str, t_instruction *instruction, t_champ *champ)
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
			I_LABEL = ft_strsub(str, 0, i);
			add_label(champ, I_LABEL, I_ID);
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
		ft_perror("Error: syntax error 1");
	if (STATUS == FINAL && (str[i] == ' ' || str[i] == DIRECT_CHAR))
		return (ID);
	if (!ft_strchr(TRANSITION, str[i]))
		ft_perror("Error: syntax error 2");
	return (check_op(T_NEXT[get_i_next(TRANSITION, str[i])], str, i + 1));
}

/*
** Verify if the op using the automaton
** and stock it into instruction
*/

int		get_op(char *str, t_instruction *instruction, t_champ *champ)
{
	instruction->op = check_op(AUTOMATON, str, 0);
	PROG_SIZE += 1 + (g_op_tab[I_OP - 1]).ocp;
	I_WEIGHT += 1 + (g_op_tab[I_OP - 1]).ocp;
	return (ft_strlen(g_op_tab[I_OP - 1].op));
}

/*
** T_REG 1 or 2 digits after 'r'
*/

int		check_reg(t_champ *champ, char *str, t_instruction *instruction)
{
	int		i;

	i = 0;
	while (str[++i])
		if (!ft_isdigit(str[i++]) || i > 2)
			ft_perror("Error: syntax error 3");
	if (i < 2)
		ft_perror("Error: syntax error 4");
	PROG_SIZE += 1;
	I_WEIGHT++;
	return (1);
}

void	add_labcheck(t_champ *champ, char *str)
{
	t_label_list	*label;
	int				i;

	if (!(label = ft_memalloc(sizeof(t_label_list))))
		ft_perror("Error: malloc failed");
	i = (str[0] == DIRECT_CHAR) ? 2 : 1;
	label->label = ft_strsub(str, i, ft_strlen(str) - i);
	label->next = L_LABCHECK;
	L_LABCHECK = label;
}

void	update_weight(t_instruction *instruction, t_champ *champ, int add)
{
	PROG_SIZE += add;
	I_WEIGHT += add;
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
	return ((str[0] == DIRECT_CHAR) ? T_DIR : T_IND);
}

/*
** Verify if the params match with the op
** and stock it into instruction
*/

void	get_args(t_champ *champ, char *str, t_instruction *instruction)
{
	int		i;
	int		arg;

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

int		get_name(t_champ *champ, char **split, int verif)
{
	if (!split[1])
	{
		(HEADER->prog_name)[0] = '\0';
		free_map(split);
		return (1);
	}
	if (split[2])
		ft_perror("Error: lexical error 1");
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
	if (!split[1])
	{
		(HEADER->comment)[0] = '\0';
		free_map(split);
		return (3);
	}
	if (split[2])
		ft_perror("Error: lexical error ici");
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
	if (line[0] == COMMENT_CHAR || line[0] == ';')
		return (0);
	if (line[0] == '.')
	{
		if (ft_strequf_l(ft_strsub(line, 0, 8), COMMENT_CMD_STRING))
			return (get_comment(champ, ft_strsplitf(line, '\"'), verif += 3));
		else if (ft_strequf_l(ft_strsub(line, 0, 5), NAME_CMD_STRING))
			return (get_name(champ, ft_strsplitf(line, '\"'), verif += 1));
		else
			ft_perror("Error: lexical error 2");
	}
	else if (verif != 4)
		ft_perror("Error: lexical error 3");
	return (0);
}

void	build_instruction_list(t_champ *champ)
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

void	parse_file(t_champ *champ)
{
	int			r;
	char		*line;

	r = 0;
	while (r != 4 && get_next_line(FD, &line))
		r += check_header(champ, str_epur(line));
	while (get_next_line(FD, &line))
	{
		if ((line = str_epur(line)) && line[0] != COMMENT_CHAR
				&& line[0] != ';')
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
	L_LABCHECK = NULL;
	PROG_SIZE = 0;
	return (champ);
}

char		*set_name(char *str)
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

void	write_binary(t_champ *champ)
{
	write_header(champ);
	write_champ(champ);
	ft_putstr("\033[32mWriting output program to ");
	ft_putendl(NAME);
	ft_putstr("\033[0m");
}

int		main(int ac, char **av)
{
	t_champ		*champ;
	int			i;

	if (ac < 2)
		ft_perror("usage: ./asm champ.s");
	champ = init_champ();
	i = 0;
	while (i < ac - 1)
		i++;
	if ((FD = open(av[i], O_RDONLY)) == -1)
		ft_perror("Error: open failed");
	parse_file(champ);
	NAME = set_name(av[i]);
	if (close(FD) == -1)
		ft_perror("Error: close failed");
	if ((FD = open(NAME, O_CREAT | O_WRONLY | O_TRUNC,
					S_IRUSR | S_IWUSR)) == -1)
		ft_perror("Error: open failed");
	write_binary(champ);
	if (close(FD) == -1)
		ft_perror("Error: close failed");
	return (0);
}
