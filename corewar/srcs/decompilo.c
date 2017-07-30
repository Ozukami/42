/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompilo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 06:14:46 by apoisson          #+#    #+#             */
/*   Updated: 2017/07/30 09:45:42 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decompilo.h"

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

unsigned char	*get_champ_name(int fd)
{
	unsigned char	*name;

	if (!(name = ft_memalloc(PROG_NAME_LENGTH + 1)))
		ft_perror(strerror(errno));
	if (read(fd, name, PROG_NAME_LENGTH) < 1)
		ft_perror(strerror(errno));
	return (name);
}

int				get_champ_size(int fd)
{
	unsigned int	prog_size;
	unsigned char	*buff;

	if (!(buff = ft_memalloc(4)))
		ft_perror(strerror(errno));
	if (lseek(fd, 0x88, SEEK_SET) == -1)
		ft_perror(strerror(errno));
	if (read(fd, buff, 4) < 1)
		ft_perror(strerror(errno));
	prog_size = buff[3];
	prog_size += buff[2] << 8;
	prog_size += buff[1] << 16;
	prog_size += buff[0] << 24;
	return (prog_size);
}

unsigned char	*get_champ_comment(int fd)
{
	unsigned char	*comment;

	if (!(comment = ft_memalloc(COMMENT_LENGTH + 1)))
		ft_perror(strerror(errno));
	if (read(fd, comment, COMMENT_LENGTH) < 1)
		ft_perror(strerror(errno));
	return (comment);
}

unsigned char	*get_champ_prog(int fd, unsigned int size)
{
	unsigned char	*prog;
	unsigned int	r;

	if (lseek(fd, 0x890, SEEK_SET) == -1)
		ft_perror(strerror(errno));
	if (!(prog = ft_memalloc(CHAMP_MAX_SIZE + 1)))
		ft_perror(strerror(errno));
	if ((r = read(fd, prog, CHAMP_MAX_SIZE)) < 1)
		ft_perror(strerror(errno));
	if (r != size)
		ft_perror("Error: wrong champ size");
	return (prog);
}

void			verif_file(int fd)
{
	unsigned char	magic_number[4];

	if (read(fd, magic_number, 4) < 1)
		ft_perror(strerror(errno));
	if (magic_number[0] != 0x00 || magic_number[1] != 0xea
			|| magic_number[2] != 0x83 || magic_number[3] != 0xf3)
		ft_perror("Error: bad magic number");
}

int		get_inst_length(int ocp, int op)
{
	int		label_size;
	int		size;
	int		i;
	int		r;

	r = (g_op_tab[op].nb_arg * 2);
	if (ocp == -1 && (op == 0 || op == 8 || op == 11 || op == 14))
		return ((g_op_tab[op]).label_size);
	label_size = (!(g_op_tab[op]).label_size) ? 4 : (g_op_tab[op]).label_size;
	size = 2;
	i = 0;
	while (i < (g_op_tab[op].nb_arg * 2))
	{
		if (((ocp << i) & 0b11000000) == 0b11000000)
			size += 2;
		else if ((ocp << i) & 0b01000000)
			size++;
		else if ((ocp << i) & 0b10000000)
			size += label_size;
		i += 2;
	}
	return (size - 1);
}

int		get_value(t_decomp *decomp, int nb_octet, int pc)
{
	int				value;
	int				i;

	value = PROG[pc];
	i = 1;
	while (i < nb_octet)
	{
		value = value << 8;
		value += PROG[pc + i++];
	}
	if (nb_octet < 4)
		value = (short)value;
	return (value);
}

void		get_args(t_decomp *decomp, int ocp, int args[4], int pc)
{
	int		label_size;
	int		size;
	int		i;

	label_size = (!(g_op_tab[PROG[pc] - 1]).label_size) ?
		4 : (g_op_tab[PROG[pc] - 1]).label_size;
	size = 2;
	i = 0;
	while (i <= 6)
	{
		if (((ocp << i) & 0b11000000) == 0b11000000)
		{
			args[i / 2] = get_value(decomp, 2, pc + size);
			size += 2;
		}
		else if (((ocp << i) & 0b01000000))
			args[i / 2] = get_value(decomp, 1, pc + size++);
		else if ((ocp << i) & 0b10000000)
		{
			args[i / 2] = get_value(decomp, label_size, pc + size);
			size += label_size;
		}
		i += 2;
	}
}

int		verif_ocp(int op, int ocp)
{
	if (((op == 2 || op == 13) && (ocp == 144 || ocp == 208))
			|| (op == 3 && (ocp == 80 || ocp == 112))
			|| ((op == 4 || op == 5) && (ocp == 84))
			|| ((op == 6 || op == 7 || op == 8) &&
					(ocp == 84 || ocp == 100 || ocp == 116 ||
					ocp == 148 || ocp == 164 || ocp == 180 ||
					ocp == 212 || ocp == 228 || ocp == 244))
			|| ((op == 10 || op == 14) &&
					(ocp == 84 || ocp == 100 || ocp == 148 ||
					ocp == 164 || ocp == 212 || ocp == 228))
			|| (op == 11 && (ocp == 84 || ocp == 88 || ocp == 100 ||
					ocp == 104 || ocp == 116 || ocp == 120))
			|| (op == 16 && (ocp == 64)))
		return (1);
	return (0);
}

int		get_ocp(t_decomp *decomp, int i)
{
	int		ocp;

	if (PROG[i] == 1 || PROG[i] == 9 || PROG[i] == 12 || PROG[i] == 15)
		return (-1);
	else
		ocp = PROG[i + 1];
	if (!verif_ocp(PROG[i], ocp))
		ft_perror("Champ error");
	return (ocp);
}

int			write_op(t_decomp *decomp, int i)
{
	int		args[4];
	int		ocp;
	int		j;
	char	*to_write;

	((ocp = get_ocp(decomp, i)) != -1) ? (get_args(decomp, ocp, args, i)) :
		(args[0] = get_value(decomp, g_op_tab[PROG[i] - 1].label_size, i + 1));
	write(FD_S, g_op_tab[PROG[i] - 1].op, ft_strlen(g_op_tab[PROG[i] - 1].op));
	write(FD_S, "\t", 1);
	j = -1;
	while (++j < g_op_tab[PROG[i] - 1].nb_arg)
	{
		if ((ocp << (j * 2)) & 0b10000000)
			write(FD_S, "%", 1);
		else if ((ocp << (j * 2)) & 64 && ((ocp << (j * 2)) != 192))
			write(FD_S, "r", 1);
		to_write = ft_itoa(args[j]);
		write(FD_S, to_write, ft_strlen(to_write));
		ft_strdel(&to_write);
		if (j + 1 < g_op_tab[PROG[i] - 1].nb_arg)
			write(FD_S, ", ", 2);
	}
	write(FD_S, "\n", 1);
	return (get_inst_length(ocp, PROG[i] - 1));
}

void		write_s_header(t_decomp *decomp)
{
	char	*str;

	str = (char *)get_champ_name(FD_COR);
	write(FD_S, ".name \"", 7);
	write(FD_S, str, ft_strlen(str));
	ft_strdel(&str);
	str = (char *)get_champ_comment(FD_COR);
	write(FD_S, "\"\n.comment \"", 12);
	write(FD_S, str, ft_strlen(str));
	write(FD_S, "\"\n\n", 3);
	ft_strdel(&str);
}

void		process(t_decomp *decomp)
{
	int		i;

	write_s_header(decomp);
	PROGSIZE = get_champ_size(FD_COR);
	PROG = get_champ_prog(FD_COR, PROGSIZE);
	i = -1;
	while (++i < PROGSIZE)
	{
		if (PROG[i] < 1 || PROG[i] > 16)
			ft_perror("Invalid champ");
		i += write_op(decomp, i);
	}
}

char	*modif_extension(char *file, char *ext)
{
	char	*name;
	int		i;

	i = ft_strlen(file);
	name = NULL;
	while (file[--i])
	{
		if (file[i] == '.')
		{
			name = ft_strsub(file, 0, i);
			break ;
		}
	}
	if (name)
		return (ft_strjoinf_l(name, ext));
	else
		name = ft_strdup(ext);
	return (name);
}

int			main(int ac, char **av)
{
	t_decomp	*decomp;
	char		*name;

	if (ac < 2)
	{
		ft_putendl("usage: ./decompilo <file.cor>");
		return (0);
	}
	if (!(decomp = ft_memalloc(sizeof(t_decomp))))
		ft_perror(strerror(errno));
	if (!(FD_COR = open(av[1], O_RDONLY)))
		ft_perror(strerror(errno));
	verif_file(FD_COR);
	name = modif_extension(av[1], ".s");
	if (!(FD_S = open(name, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR)))
		ft_perror(strerror(errno));
	ft_strdel(&name);
	process(decomp);
	if (close(FD_COR) == -1 || close(FD_S) == -1)
		ft_perror(strerror(errno));
	return (1);
}
