/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ncurses.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 05:38:42 by apoisson          #+#    #+#             */
/*   Updated: 2017/07/23 05:14:28 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void	init_mem(t_vm *vm)
{
	char	*line;
	int		i;
	int		x;
	int		y;

	start_color();

	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_BLACK, COLOR_GREEN);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_BLACK, COLOR_BLUE);
	init_pair(5, COLOR_RED, COLOR_BLACK);
	init_pair(6, COLOR_BLACK, COLOR_RED);
	init_pair(7, COLOR_CYAN, COLOR_BLACK);
	init_pair(8, COLOR_BLACK, COLOR_CYAN);
	init_pair(9, COLOR_WHITE, COLOR_BLACK);

	if (!(line = ft_memalloc(MEM_SIZE)))
		ft_perror(strerror(errno));
	i = -1;
	while (++i < MEM_SIZE)
	{
		x = i % 64;
		y = i / 64;
		if (i < 2048)
			wattron(W_MEMORY, COLOR_PAIR(1));
		else
			wattron(W_MEMORY, COLOR_PAIR(3));
		mvwprintw(W_MEMORY, y + 1, x + 2 + (x * 3),
				"%02x", A_MEMORY[i]);
	}
	wattron(W_MEMORY, COLOR_PAIR(9));
}

void	ft_usage(void)
{
	ft_putendl("usage: ./corewar [-d N | -nc --stealth] \
<[-n N] champ.cor> <...>");
	ft_putendl("#### TEXT OUTPUT MODE #######");
	ft_putendl("	-d N		: Dumps memory after N cycles then exits");
	ft_putendl("#### NCURSES OUTPUT MODE ####");
	ft_putendl("	 -nc		: Ncurses output mode");
	ft_putendl("	--stealth	: Hides the real contents of the memory");
	ft_putendl("#############################");
	exit(0);
}

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

t_champ			*read_champ(int fd)
{
	t_champ		*champ;

	if (!(champ = ft_memalloc(sizeof(t_champ))))
		ft_perror(strerror(errno));
	champ->name = get_champ_name(fd);
	champ->prog_size = get_champ_size(fd);
	champ->comment = get_champ_comment(fd);
	champ->prog = get_champ_prog(fd, champ->prog_size);
	return (champ);
}

t_player		*read_file(int fd, int id)
{
	t_player	*player;
	static int	static_id = -1;

	if (!(player = ft_memalloc(sizeof(t_player))))
		ft_perror(strerror(errno));
	P_CHAMP = read_champ(fd);
	P_ID = (id != -1) ? id : static_id--;
	P_PROC = 1;
	P_LIVE = 0;
	P_NEXT = NULL;
	return (player);
}

void			verif_file(int fd)
{
	unsigned char	*magic_number;

	if (!(magic_number = ft_memalloc(4)))
		ft_perror(strerror(errno));
	if (read(fd, magic_number, 4) < 1)
		ft_perror(strerror(errno));
	if (magic_number[0] != 0x00 || magic_number[1] != 0xea
			|| magic_number[2] != 0x83 || magic_number[3] != 0xf3)
		ft_perror("Error: bad magic number");
}

int				get_id(int nb_args, char **args, int *i)
{
	int		id;

	if (++(*i) == nb_args)
		ft_perror("Error: option -n missing number");
	if ((id = ft_atoi(args[(*i)])) < 0 && id > -5)
		ft_perror("Error: option -n invalid number");
	if (++(*i) == nb_args)
		ft_perror("Error: option -n missing number or champ");
	return (id);
}

t_player		*get_player(int nb_args, char **args)
{
	t_player		*l_player;
	t_player		*tmp;
	int				fd;
	int				i;
	int				id;

	if (!(l_player = ft_memalloc(sizeof(t_player))))
		ft_perror(strerror(errno));
	tmp = NULL;
	i = -1;
	while (++i < nb_args)
	{
		id = -1;
		if (ft_strequ(args[i], "-n"))
			id = get_id(nb_args, args, &i);
		if ((fd = open(args[i], O_RDONLY)) < 0)
			ft_perror(strerror(errno));
		verif_file(fd);
		l_player = read_file(fd, id);
		l_player->next = tmp;
		tmp = l_player;
		if (close(fd == -1))
			ft_perror(strerror(errno));
	}
	return (l_player);
}

void		verif_nb_player(t_vm *vm)
{
	t_player	*current;

	current = A_LPLAYER;
	while (current)
	{
		A_NBPLAYER++;
		current = current->next;
	}
	if (A_NBPLAYER > MAX_PLAYERS)
		ft_perror("Error: too many players");
}

t_proc			*new_proc(int id_player)
{
	t_proc		*proc;
	static int	id = 1;

	if (!(proc = ft_memalloc(sizeof(t_proc))))
		ft_perror(strerror(errno));
	PR_ID = id++;
	PR_IDP = id_player;
	PR_ALIVE = 0;
	proc->test = 1;
	PR_PC = 0;
	PR_CARRY = 0;
	PR_WAIT = 1;
	PR_NEXT = NULL;
	if (!(PR_REG = ft_memalloc(sizeof(int) * (REG_NUMBER + 2))))
		ft_perror(strerror(errno));
	PR_REG[1] = PR_IDP;
	return (proc);
}

t_proc		*init_proc(t_vm *vm)
{
	t_proc		*proc;
	t_proc		*curr_proc;
	t_player	*curr_player;

	curr_player = A_LPLAYER;
	curr_proc = NULL;
	while (curr_player)
	{
		proc = new_proc(curr_player->id);
		A_WINNER = curr_player->id;
		A_PROC++;
		printf("%sNEW (%d)%s\n", GREEN, A_PROC, DEFAULT);
		proc->next = curr_proc;
		curr_proc = proc;
		curr_player = curr_player->next;
	}
	return (proc);
}

void		lp_rev(t_vm *vm)
{
	t_player	*curr;
	t_player	*tmp1;
	t_player	*tmp2;

	curr = A_LPLAYER;
	tmp1 = NULL;
	tmp2 = NULL;
	while (curr)
	{
		tmp1 = curr;
		curr = curr->next;
		tmp1->next = tmp2;
		tmp2 = tmp1;
	}
	A_LPLAYER = tmp1;
}

void		init_arena(t_vm *vm, int nb_args, char **args)
{
	t_arena		*arena;
	t_proc		*curr_proc;
	int			i;

	if (!(arena = ft_memalloc(sizeof(t_arena))))
		ft_perror(strerror(errno));
	ARENA = arena;
	A_PROC = 0;
	A_CYCLE = 0;
	A_CTD = CYCLE_TO_DIE;
	A_NBPLAYER = 0;
	A_NBCHECK = 0;
	A_MEMORY = ft_memalloc(MEM_SIZE);
	A_LPLAYER = get_player(nb_args, args);
	verif_nb_player(vm);
	lp_rev(vm);
	A_LPROC = init_proc(vm);
	curr_proc = A_LPROC;
	i = A_NBPLAYER - 1;
	while (curr_proc)
	{
		curr_proc->pc = (i-- * (MEM_SIZE / A_NBPLAYER)) % MEM_SIZE;
		curr_proc = curr_proc->next;
	}
}

/*
** load champ of each players in the memory of the vm
** at the good position
** and set the PC of the first proc of each players
** at this position
*/

void		load_champ(t_vm *vm)
{
	t_player	*current;
	int			i;
	int			j;

	current = A_LPLAYER;
	j = -1;
	while (current)
	{
		i = -1;
		while (++i < (int)current->champ->prog_size)
			A_MEMORY[++j] = current->champ->prog[i];
		j += MEM_SIZE / A_NBPLAYER - current->champ->prog_size;
		current = current->next;
	}
}

void		cycle_verif(t_vm *vm)
{
	printf("	%sCYCLE_VERIF (%d)%s\n", RED, A_CTD, DEFAULT);
	if (TOTAL_LIVE >= NBR_LIVE || A_NBCHECK == MAX_CHECKS)
	{
	 	A_CTD -= CYCLE_DELTA;
	 	A_NBCHECK = 1;
	}
	else
		A_NBCHECK++;
	TOTAL_LIVE = 0;
}

void		update_nb_proc(t_vm *vm, int id_player)
{
	t_player	*curr;

	curr = A_LPLAYER;
	while (curr)
	{
		if (curr->id == id_player)
			(curr->nb_proc)--;
		curr = curr->next;
	}
}

/*
** BONUS : jouer un son quand on kill un process
** genre le "FATALITY" de Mortal Kombat
*/

void		kill_proc(t_vm *vm, int id)
{
	t_proc	*curr;
	t_proc	*tmp;

	A_PROC--;
	printf("%s[Cycle = %d]%s\n", YELLOW, A_CYCLE, DEFAULT);
	curr = A_LPROC;
	if (curr->id == id)
	{
	printf("%sKILL (%d/%d) [ctd %d]%s\n", RED, curr->id,
			A_PROC, A_CTD, DEFAULT);
		tmp = curr;
		A_LPROC = tmp->next;
		update_nb_proc(vm, tmp->id_player);
		free(tmp);
		return ;
	}
	while (curr->next)
	{
		if (curr->next->id == id)
		{
	printf("%sKILL (%d/%d) [ctd %d]%s\n", RED, curr->id,
			A_PROC, A_CTD, DEFAULT);
			tmp = curr->next;
			curr->next = tmp->next;
			update_nb_proc(vm, tmp->id_player);
			free(tmp);
			return ;
		}
		curr = curr->next;
	}
}

void		check_alive(t_vm *vm)
{
	t_player	*curr_player;
	t_proc		*curr_proc;

	curr_proc = A_LPROC;
	while (curr_proc)
	{
		if (!curr_proc->alive)
			kill_proc(vm, curr_proc->id);
		curr_proc->alive = 0;
		curr_proc = curr_proc->next;
	}
	curr_player = A_LPLAYER;
	while (curr_player)
	{
		if (curr_player->nb_proc == 0)
			A_NBPLAYER--;
		curr_player = curr_player->next;
	}
	cycle_verif(vm);
}

/*
** Returns the number of bytes of the current instruction
*/

int		get_inst_length(int ocp, int op)
{
	int		label_size;
	int		size;
	int		i;

	if (!ocp)
		return ((g_op_tab[op]).label_size + 1);
	// T_REG | T_DIR | T_IND
	label_size = (g_op_tab[op]).label_size;
	size = 2;
	i = 0;
	while (i <= 6)
	{
		if (((ocp << i) & 0b11000000) == 0b11000000)
			size += 2;
		else if ((ocp << i) & 0b01000000)
			size++;
		else if ((ocp << i) & 0b10000000)
			size += label_size;
		i += 2;
	}
	return (size);
}

void	move_pc(t_vm *vm, t_proc *proc, int ocp)
{
	int		size;

	size = get_inst_length(ocp, A_MEMORY[PR_PC] - 1);
	printf("%s	ocp = %d [%x]\n	inst size = %d%s\n\n",
			PURPLE, ocp, ocp, size, DEFAULT);
	PR_PC += size;
	PR_PC %= MEM_SIZE;
	proc->cycle_to_wait = 0;
}

// 0 < nb_octet < 5
int		get_value(t_vm *vm, int nb_octet, int pc)
{
	int				value;
	int				i;

	value = A_MEMORY[pc];
	i = 1;
	while (i < nb_octet)
	{
		value = value << 8;
		value += A_MEMORY[(pc + i++) % MEM_SIZE];
	}
	printf("%s[get_value : %d]%s\n", GREEN, value, DEFAULT);
	if (nb_octet < 4)
		value = (short)value;
	return (value);
}

void		get_args(t_vm *vm, t_proc *proc, int ocp, int args[4])
{
	int		label_size;
	int		size;
	int		i;

	// T_REG | T_DIR | T_IND
	label_size = (g_op_tab[A_MEMORY[PR_PC] - 1]).label_size;
	size = 2;
	i = 0;
	while (i <= 6)
	{
		if (((ocp << i) & 0b11000000) == 0b11000000)
		{
			printf("T_IND (11)\n");
			/*
			// attention neg
			j = get_value(vm, 2, (PR_PC + size)) % MEM_SIZE;
			if (j < 0)
				j += MEM_SIZE;
			printf("%d\n", j);
			args[i / 2] = get_value(vm, 4, j);
			*/
			args[i / 2] = get_value(vm, 2, (PR_PC + size) % MEM_SIZE);
			size += 2;
		}
		else if (((ocp << i) & 0b01000000))
		{
			printf("T_REG (01)\n");
			args[i / 2] = get_value(vm, 1, (PR_PC + size) % MEM_SIZE);
			size++;
		}
		else if ((ocp << i) & 0b10000000)
		{
			printf("T_DIR (10)\n");
			args[i / 2] = get_value(vm, label_size, (PR_PC + size) % MEM_SIZE);
			size += label_size;
		}
		i += 2;
	}
}

t_player	*get_player_from_id(t_vm *vm, int id)
{
	t_player	*curr;

	curr = A_LPLAYER;
	while (curr)
	{
		if (curr->id == id)
			return (curr);
		curr = curr->next;
	}
	return (NULL);
}

void	write_in_mem(t_vm *vm, int value, int pc)
{
	A_MEMORY[pc] = value >> 24;
	A_MEMORY[(pc + 1) % MEM_SIZE] = (value >> 16) & 0b11111111;
	A_MEMORY[(pc + 2) % MEM_SIZE] = (value >> 8) & 0b11111111;
	A_MEMORY[(pc + 3) % MEM_SIZE] = value & 0b11111111;
}

//------Les fonctions d'operation ASM-------

/*
** Op live
** pas d'OCP, 1 param sur 4 octets
** fait vivre le proc
** ajoute 1 vie au joueur dont l'id est en param
*/

void	op_live(t_vm *vm, t_proc *proc)
{
	int			value;
	t_player	*player;

	printf("op_live\n");
	PR_ALIVE = 1;
	TOTAL_LIVE++;
	value = get_value(vm, 4, (PR_PC + 1) % MEM_SIZE);
	if ((player = get_player_from_id(vm, value)))
	{
		player->nb_live++;
		A_WINNER = P_ID; // op_live actualise le winner a chaque execution
		printf("%s%s->nb_live++%s\n", GREEN, C_NAME, DEFAULT);
	}
	printf("%sP(%d) IS ALIVE ! [c %d]%s\n", GREEN, PR_IDP, A_CYCLE, DEFAULT);
	move_pc(vm, proc, 0);
}

void	op_ld(t_vm *vm, t_proc *proc)
{
	int		args[4];
	int		ocp;
	int		j;

	printf("op_ld\n");
	ocp = A_MEMORY[(PR_PC + 1) % MEM_SIZE];
	if (ocp < 64)
		return ;
	get_args(vm, proc, ocp, args);
	printf("%sargs[1] = %d%s\n", RED, args[1], DEFAULT);
	printf("%sargs[0] = %d%s\n", RED, args[0], DEFAULT);
	if ((ocp & 0b11000000) == 0b11000000)
	{
		j = (PR_PC + (args[0] % IDX_MOD)) % MEM_SIZE;
		if (j < 0)
			j += MEM_SIZE;
		printf("%d\n", j);
		PR_REG[args[1]] = get_value(vm, 4, j);
	}
	else
		PR_REG[args[1]] = args[0];
	printf("%sreg_val = %d%s\n", RED, PR_REG[args[1]], DEFAULT);
	if (PR_REG[args[1]] == 0)
		PR_CARRY = 1;
	else
		PR_CARRY = 0;
	move_pc(vm, proc, ocp);
	printf("%sreg_val = %u%s\n", RED, (unsigned int)(PR_REG[args[1]]), DEFAULT);
}

void	op_st(t_vm *vm, t_proc *proc)
{
	int		args[4];
	int		ocp;
	int		j;

	printf("op_st\n");
	ocp = A_MEMORY[(PR_PC + 1) % MEM_SIZE];
	if (ocp < 64)
		return ;
	get_args(vm, proc, ocp, args);
	//printf("%d %d\n", args[0], args[1]);
	printf("%sj = %d%s\n", CYAN, args[1], DEFAULT);
	j = (PR_PC + (args[1] % IDX_MOD)) % MEM_SIZE;
	if (j < 0)
		j += MEM_SIZE;
	printf("%sargs[0] = %d, reg_val = %d%s\n", RED, args[0],
			PR_REG[args[0]], DEFAULT);
	if (((ocp << 2) & 0b11000000) == 0b11000000)
		write_in_mem(vm, PR_REG[args[0]], j);
	else if ((ocp << 2) & 0b01000000)
		PR_REG[args[1]] = PR_REG[args[0]];
	printf("%s%d%s\n", CYAN, j, DEFAULT);
	move_pc(vm, proc, ocp);
}

void	op_add(t_vm *vm, t_proc *proc)
{
	int		args[4];
	int		ocp;

	printf("op_add\n");
	ocp = A_MEMORY[(PR_PC + 1) % MEM_SIZE];
	if (ocp < 64)
		return ;
	get_args(vm, proc, ocp, args);
	args[0] = PR_REG[args[0]];
	args[1] = PR_REG[args[1]];
	PR_REG[args[2]] = args[0] + args[1];
	if (PR_REG[args[2]] == 0)
		PR_CARRY = 1;
	else
		PR_CARRY = 0;
	move_pc(vm, proc, ocp);
}

void	op_sub(t_vm *vm, t_proc *proc)
{
	int		args[4];
	int		ocp;

	printf("op_sub\n");
	ocp = A_MEMORY[(PR_PC + 1) % MEM_SIZE];
	if (ocp < 64)
		return ;
	get_args(vm, proc, ocp, args);
	args[0] = PR_REG[args[0]];
	args[1] = PR_REG[args[1]];
	PR_REG[args[2]] = args[0] - args[1];
	if (PR_REG[args[2]] == 0)
		PR_CARRY = 1;
	else
		PR_CARRY = 0;
	move_pc(vm, proc, ocp);
}

void	op_and(t_vm *vm, t_proc *proc)
{
	int		args[4];
	int		ocp;

	printf("op_and\n");
	ocp = A_MEMORY[(PR_PC + 1) % MEM_SIZE];
	if (ocp < 64)
		return ;
	get_args(vm, proc, ocp, args);
	if (((ocp & 0b11000000)) == 0b11000000)
		args[0] = get_value(vm, 4, (PR_PC + (args[0] % IDX_MOD)) % MEM_SIZE);
	else if ((ocp & 0b01000000))
		args[0] = PR_REG[args[0]];
	if ((((ocp << 2) & 0b11000000)) == 0b11000000)
		args[1] = get_value(vm, 4, (PR_PC + (args[1] % IDX_MOD)) % MEM_SIZE);
	else if (((ocp << 2) & 0b01000000))
		args[1] = PR_REG[args[1]];
	//printf("%d, %d, %d\n", args[0], args[1], args[2]);
	PR_REG[args[2]] = args[0] & args[1];
	if (PR_REG[args[2]] == 0)
		PR_CARRY = 1;
	else
		PR_CARRY = 0;
	move_pc(vm, proc, ocp);
	//printf("%sCarry = %d%s\n", RED, PR_CARRY, DEFAULT);
}

void	op_or(t_vm *vm, t_proc *proc)
{
	int		args[4];
	int		ocp;

	printf("op_or\n");
	ocp = A_MEMORY[(PR_PC + 1) % MEM_SIZE];
	if (ocp < 64)
		return ;
	get_args(vm, proc, ocp, args);
	if (((ocp & 0b11000000)) == 0b11000000)
		args[0] = get_value(vm, 4, (PR_PC + (args[0] % IDX_MOD)) % MEM_SIZE);
	else if ((ocp & 0b01000000))
		args[0] = PR_REG[args[0]];
	if ((((ocp << 2) & 0b11000000)) == 0b11000000)
		args[1] = get_value(vm, 4, (PR_PC + (args[1] % IDX_MOD)) % MEM_SIZE);
	else if (((ocp << 2) & 0b01000000))
		args[1] = PR_REG[args[1]];
	PR_REG[args[2]] = args[0] | args[1];
	if (PR_REG[args[2]] == 0)
		PR_CARRY = 1;
	else
		PR_CARRY = 0;
	move_pc(vm, proc, ocp);
}

void	op_xor(t_vm *vm, t_proc *proc)
{
	int		args[4];
	int		ocp;

	printf("op_xor\n");
	ocp = A_MEMORY[(PR_PC + 1) % MEM_SIZE];
	if (ocp < 64)
		return ;
	get_args(vm, proc, ocp, args);
	if (((ocp & 0b11000000)) == 0b11000000)
		args[0] = get_value(vm, 4, (PR_PC + (args[0] % IDX_MOD)) % MEM_SIZE);
	else if ((ocp & 0b01000000))
		args[0] = PR_REG[args[0]];
	if ((((ocp << 2) & 0b11000000)) == 0b11000000)
		args[1] = get_value(vm, 4, (PR_PC + (args[1] % IDX_MOD)) % MEM_SIZE);
	else if (((ocp << 2) & 0b01000000))
		args[1] = PR_REG[args[1]];
	PR_REG[args[2]] = args[0] ^ args[1];
	if (PR_REG[args[2]] == 0)
		PR_CARRY = 1;
	move_pc(vm, proc, ocp);
}

void	op_zjmp(t_vm *vm, t_proc *proc)
{
	int	value;

	printf("op_zjmp (%d)\n", PR_PC);
	value = get_value(vm, 2, (PR_PC + 1) % MEM_SIZE);
	if (PR_CARRY == 1)
	{
		// IDX_MOD ??
		/*
		PR_PC = value % IDX_MOD;
		if (PR_PC < 0)
			PR_PC += MEM_SIZE;
		printf("%sZjmp at %d%s\n", YELLOW, PR_PC, DEFAULT);
		*/
		//PR_WAIT = (g_op_tab[A_MEMORY[PR_PC] - 1]).cycles;
		PR_PC += ((short)value) % MEM_SIZE;
		printf("%sZjmp at %d%s\n", YELLOW, PR_PC, DEFAULT);
		PR_WAIT = 0;
	//	printf("%s[Loading OP] (cycle %d)%s\n", GREEN, A_CYCLE, RED);
	//	printf("	{%d Cycle to Wait}%s\n", PR_WAIT, DEFAULT);
	}
	else
	{
		printf("%s	ZJMP FAILLED%s\n", RED, DEFAULT);
		move_pc(vm, proc, 0);
	}
	printf("%s%d%s\n", RED, PR_ID, DEFAULT);
}

void	op_ldi(t_vm *vm, t_proc *proc)
{
	int		args[4];
	int		ocp;

	printf("op_ldi\n");
	ocp = A_MEMORY[(PR_PC + 1) % MEM_SIZE];
	if (ocp < 64)
		return ;
	get_args(vm, proc, ocp, args);
	PR_REG[args[2]] = get_value(vm, REG_SIZE, args[0] + args[1]);
	move_pc(vm, proc, ocp);
}

void	op_sti(t_vm *vm, t_proc *proc)
{
	int		args[4];
	int		ocp;
	int		j;

	printf("op_sti\n");
	ocp = A_MEMORY[(PR_PC + 1) % MEM_SIZE];
	if (ocp < 64)
		return ;
	get_args(vm, proc, ocp, args);
	if (((ocp << 2) & 0b01000000))
		args[1] = PR_REG[args[1]];
	if (((ocp << 4) & 0b01000000))
		args[2] = PR_REG[args[2]];
	printf("sti : %d <- %d + %d\n", args[0], args[1], args[2]);
	j = (PR_PC + ((args[1] + args[2] + args[2])) % IDX_MOD) % MEM_SIZE;
	if (j < 0)
		j += MEM_SIZE;
	printf("%sj = %d%s\n", CYAN, args[1], DEFAULT);
	write_in_mem(vm, PR_REG[args[0]], j);
	/*
	write_in_mem(vm, PR_REG[args[0]],
			((PR_PC + args[1] + args[2]) % IDX_MOD) % MEM_SIZE);
			*/
	printf("%s%d%s\n", CYAN, j, DEFAULT);
	move_pc(vm, proc, ocp);
}

void	op_fork(t_vm *vm, t_proc *proc)
{
	int		value;
	int		i;
	t_proc	*clone;

	printf("op_fork\n");
	value = get_value(vm, 2, (PR_PC + 1) % MEM_SIZE);
	value %= IDX_MOD;
	value %= MEM_SIZE;
	clone = new_proc(PR_IDP);
	clone->carry = proc->carry;
	if (PR_PC + value < 0)
		clone->pc = (PR_PC + MEM_SIZE + value) % MEM_SIZE;
	else
		clone->pc = (PR_PC + value) % MEM_SIZE;
	A_PROC++;
	printf("%sCLONE (%d) pc -> %d%s\n", GREEN, A_PROC, clone->pc, DEFAULT);
	// copie du reg pere dans le reg fils ? A priori Oui
	i = 0;
	while (++i < 17)
		(clone->reg)[i] = PR_REG[i];
	clone->next = A_LPROC;
	A_LPROC = clone;
	move_pc(vm, proc, 0);
}

void	op_lld(t_vm *vm, t_proc *proc)
{
	int		args[4];
	int		ocp;
	int		j;

	printf("op_lld\n");
	ocp = A_MEMORY[(PR_PC + 1) % MEM_SIZE];
	printf("OCP = %d\n", ocp);
	if (ocp < 64)
		return ;
	get_args(vm, proc, ocp, args);
	printf("%sargs[1] = %d%s\n", RED, args[1], DEFAULT);
	printf("%sargs[0] = %d%s\n", RED, args[0], DEFAULT);
	if ((ocp & 0b11000000) == 0b11000000)
	{
		j = (PR_PC + args[0]) % MEM_SIZE;
		if (j < 0)
			j += MEM_SIZE;
		printf("%d\n", j);
		PR_REG[args[1]] = get_value(vm, 2, j);
	}
	else
		PR_REG[args[1]] = args[0];
	printf("%sreg_val = %d%s\n", RED, PR_REG[args[1]], DEFAULT);
	//PR_REG[args[1]] = args[0];
	if (PR_REG[args[1]] == 0)
		PR_CARRY = 1;
	else
		PR_CARRY = 0;
	move_pc(vm, proc, ocp);
}

void	op_lldi(t_vm *vm, t_proc *proc)
{
	int		args[4];
	int		ocp;

	printf("op_lldi\n");
	ocp = A_MEMORY[(PR_PC + 1) % MEM_SIZE];
	if (ocp < 64)
		return ;
	get_args(vm, proc, ocp, args);
	PR_REG[args[2]] = get_value(vm, REG_SIZE, args[0] + args[1]);
	if (PR_REG[args[1]] == 0)
		PR_CARRY = 1;
	else
		PR_CARRY = 0;
	move_pc(vm, proc, ocp);
}

void	op_lfork(t_vm *vm, t_proc *proc)
{
	int		value;
	t_proc	*clone;

	printf("op_lfork\n");
	value = get_value(vm, 2, (PR_PC + 1) % MEM_SIZE);
	value %= MEM_SIZE;
	clone = new_proc(PR_IDP);
	clone->carry = proc->carry;
	clone->pc = (PR_PC + value) % MEM_SIZE;
	A_PROC++;
	//printf("%sCLONE (%d)%s\n", GREEN, A_PROC, DEFAULT);
	// copie du reg pere dans le reg fils ?
	clone->next = proc;
	A_LPROC = clone;
	move_pc(vm, proc, 0);
}

void	op_aff(t_vm *vm, t_proc *proc)
{
	int		value;
	int		ocp;

	printf("op_aff\n");
	ocp = A_MEMORY[(PR_PC + 1) % MEM_SIZE];
	if (ocp < 64)
		return ;
	value = get_value(vm, 1, (PR_PC + 2) % MEM_SIZE);
	printf("%c\n", value % 256);
	move_pc(vm, proc, ocp);
}

//------Le tableau de pointeur sur fonctions (global)------
void	(*op_tab[16])(t_vm *, t_proc *) = {op_live, op_ld, op_st,
	op_add, op_sub, op_and, op_or, op_xor, op_zjmp, op_ldi, op_sti,
	op_fork, op_lld, op_lldi, op_lfork, op_aff};

void		dump_mem(t_vm *vm)
{
	int	i;

//	exit(0);
	i = -1;
	while (++i < MEM_SIZE)
	{
		if (i != 0 && i % 64 == 0)
			printf("\n%02x ", A_MEMORY[i]);
		else
			printf("%02x ", A_MEMORY[i]);
	}
	printf("\n");
	if (OPT_D > -1)
		exit(0);
}

/*
** run the vm with the champs
** use the implementation of op
** display with ncurses
*/

void		process(t_vm *vm)
{
	t_proc		*curr;
	int			cycle;

	cycle = 0;
	while (A_CTD > 0)
	{
		if (OPT_D > -1 && A_CYCLE > OPT_D)
			dump_mem(vm);
		++A_CYCLE;
		cycle++;
		if (cycle == A_CTD)
		{
			cycle = 0;
			check_alive(vm);
		}
		curr = A_LPROC;
		while (curr)
		{
			if (!(curr->id))
				printf("%sWARNING ! (%d)%s\n", RED, A_CYCLE,DEFAULT);
			if (curr->pc < 0)
				printf("%s%d%s\n", RED, curr->pc, DEFAULT);
//			printf("PLAYER (%d - proc %d) PC = %d Cycle = %d\n", curr->id_player,
//					curr->id, curr->pc, A_CYCLE);
			if (A_MEMORY[curr->pc] <= 0 || A_MEMORY[curr->pc] > 16)
				curr->pc = ((curr->pc) + 1) % MEM_SIZE;
			else if (curr->cycle_to_wait ==
					(g_op_tab[A_MEMORY[curr->pc] - 1]).cycles)
			{
				printf("PLAYER (%d - proc %d / %d) PC = %d Cycle = %d [%p]\n",
						curr->id_player, curr->id, A_PROC,
						curr->pc, A_CYCLE, curr);
				printf("%s[Exec OP (%d)] (cycle %d)%s\n", YELLOW,
						A_MEMORY[curr->pc], A_CYCLE, CYAN);
				(op_tab[A_MEMORY[curr->pc] - 1])(vm, curr);
				//printf("%d\n", curr->cycle_to_wait);
				(curr->cycle_to_wait)++;
			}
			else
				(curr->cycle_to_wait)++;
//			printf("END PLAYER (%d)\n", curr->id_player);
			curr = curr->next;
		}
		if (!A_PROC)
		{
			printf("A_PROC = 0 (A_CTD = %d)\n", A_CTD);
			printf("%s[Cycle = %d]%s\n", YELLOW, A_CYCLE, DEFAULT);
			exit(0);
		}
	}
}

void		ncurses_process(t_vm *vm)
{
	if (!(NCURSES = ft_memalloc(sizeof(t_ncurses))))
		ft_perror(strerror(errno));
	initscr();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);
	//while (1)
	//{
		W_MEMORY = subwin(stdscr, 64 + 2, (64 * 3) + 2, 0, 0);
		W_INFO = subwin(stdscr, 64 + 2, 56, 0, (64 * 3) + 2);
		init_mem(vm);
		box(W_MEMORY, ACS_VLINE, ACS_HLINE);
		box(W_INFO, ACS_VLINE, ACS_HLINE);
		refresh();
	//}
	while (1);
	endwin();
}

void		set_opt(int *opt, char *n)
{
	int		opt_n;

	opt_n = ft_atoi(n);
	if (opt_n > -1)
		*opt = opt_n;
}

char		**get_options(t_vm *vm, int ac, char **av)
{
	char	**args;
	int		i;
	int		j;

	if (!(args = ft_memalloc(sizeof(char *) * (ac + 1))))
		ft_perror(strerror(errno));
	i = 0;
	j = 0;
	while (++i < ac)
	{
		if (ft_strequ(av[i], "-d"))
			(++i < ac) ? set_opt(&(vm->opt_d), av[i]) : ft_perror("Error");
		else if (ft_strequ(av[i], "-nc"))
			OPT_NC = 1;
		else
			args[j++] = ft_strdup(av[i]);
	}
	args[j] = 0;
	return (args);
}

t_vm		*init_vm(void)
{
	t_vm	*vm;

	if (!(vm = ft_memalloc(sizeof(t_vm))))
		ft_perror(strerror(errno));
	NCURSES = NULL;
	ARENA = NULL;
	OPT_NC = 0;
	OPT_D = -1;
	TOTAL_LIVE = 0;
	return (vm);
}

int			main(int ac, char **av)
{
	t_vm	*vm;
	char	**args;

	if (ac < 2)
		ft_usage();
	vm = init_vm();
	args = get_options(vm, ac, av);
	if (!(args[0]))
		ft_usage();

	/*
	int	i = 1536;
	int	rep = 0;

	while (i > 330)
	{
		rep += i;
		i -= 50;
	}
	printf("%d\n", rep);
	printf("%d\n", rep + 9660);
	exit(0);
	*/

	init_arena(vm, tab_size(args), args); // faudra penser a free args
	load_champ(vm);
	process(vm);
	printf("le joueur %d (%s) a gagne\n", A_WINNER,
			get_player_from_id(vm, A_WINNER)->champ->name);
	printf("A_CTD = %d\n", A_CTD);
	printf("%s[Cycle = %d]%s\n", YELLOW, A_CYCLE, DEFAULT);

	if (OPT_NC > 0)
		ncurses_process(vm);
	return (1);
}
