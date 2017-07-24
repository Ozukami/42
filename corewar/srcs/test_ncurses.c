/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ncurses.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 05:38:42 by apoisson          #+#    #+#             */
/*   Updated: 2017/07/24 07:42:03 by apoisson         ###   ########.fr       */
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
	static int	color = 1;

	if (!(player = ft_memalloc(sizeof(t_player))))
		ft_perror(strerror(errno));
	P_CHAMP = read_champ(fd);
	P_ID = (id != -1) ? id : static_id--;
	P_PROC = 1;
	P_LIVE = 0;
	P_COLOR = color++;
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
	PR_LOP = -1;
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
//		ft_printf("%sNEW (%d)%s\n", GREEN, A_PROC, DEFAULT);
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
		{
			A_MEMORY[++j] = current->champ->prog[i];
			COLOR[j] = current->color;
		}
		j += MEM_SIZE / A_NBPLAYER - current->champ->prog_size;
		current = current->next;
	}
}

void		cycle_verif(t_vm *vm)
{
	t_player	*player;

	player = A_LPLAYER;
	while (player)
	{
		P_LIVE = 0;
		player = player->next;
	}
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
	curr = A_LPROC;
	if (curr->id == id)
	{
		if (OPT_V & V_DEATH)
			ft_printf("%sProcess %d has died (CTD %d)%s\n",
					RED, curr->id, A_CTD, DEFAULT);
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
			if (OPT_V & V_DEATH)
				ft_printf("%sKILL proc %d (CTD %d)%s\n", RED, curr->id,
						A_CTD, DEFAULT);
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

	if (OPT_V & V_CHECK)
		ft_printf("%sCHECK (CTD %d)%s\n", RED, A_CTD, DEFAULT);
	curr_proc = A_LPROC;
	while (curr_proc)
	{
		if (!curr_proc->alive)
		{
			ft_printf("	Kill proc at pc %d\n", curr_proc->pc);
			kill_proc(vm, curr_proc->id);
		}
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

	if (!ocp && (op == 0 || op == 8 || op == 11 || op == 14))
		return ((g_op_tab[op]).label_size + 1);
	else if (ocp < 64)
		return (2);
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
	int		i;

	i = -1;
	size = get_inst_length(ocp, A_MEMORY[PR_PC] - 1);
	if (OPT_V & V_PC)
	{
		ft_printf("\033[2;3;36mADV %d (0x%04x -> ", size, PR_PC);
		ft_printf("0x%04x)", PR_PC + size);
		while (++i < size)
			ft_printf(" %02x", A_MEMORY[PR_PC + i]);
		ft_printf("%s\n", DEFAULT);
	}
	PR_PC += size;
	PR_PC %= MEM_SIZE;
	PR_WAIT = 1;
	PR_LOP = -1;
}

void	move_failed_op(t_vm *vm, t_proc *proc, int len)
{
	int		i;

	i = -1;
	if (OPT_V & V_PC)
	{
		ft_printf("\033[2;3;36mADV %d (0x%04x -> ", len, PR_PC);
		ft_printf("0x%04x)", PR_PC + len);
		while (++i < len)
			ft_printf(" %02x", A_MEMORY[PR_PC + i]);
		ft_printf("%s\n", DEFAULT);
	}
	PR_PC += len;
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
//	ft_printf("%s[get_value : %d]%s\n", GREEN, value, DEFAULT);
	if (nb_octet < 4)
		value = (short)value;
	return (value);
}

void		get_args(t_vm *vm, t_proc *proc, int ocp, int args[4])
{
	int		label_size;
	int		size;
	int		i;

	label_size = (g_op_tab[A_MEMORY[PR_PC] - 1]).label_size;
	size = 2;
	i = 0;
	while (i <= 6)
	{
		if (((ocp << i) & 0b11000000) == 0b11000000)
		{
//			ft_printf("T_IND (11)\n");
			args[i / 2] = get_value(vm, 2, (PR_PC + size) % MEM_SIZE);
			size += 2;
		}
		else if (((ocp << i) & 0b01000000))
		{
//			ft_printf("T_REG (01)\n");
			args[i / 2] = get_value(vm, 1, (PR_PC + size) % MEM_SIZE);
			size++;
		}
		else if ((ocp << i) & 0b10000000)
		{
//			ft_printf("T_DIR (10)\n");
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

void	write_in_mem(t_vm *vm, int value, int pc, int color)
{
	/*
	t_proc		*proc;

	proc = A_LPROC;
	while (proc)
	{
		printf("	id = %d\n", PR_ID);
		printf("	p_id = %d\n", PR_IDP);
		printf("	alive = %d\n", PR_ALIVE);
		printf("	pc = %d\n", PR_PC);
		printf("	carry = %d\n", PR_CARRY);
		printf("	ctw = %d\n\n", PR_WAIT);
		proc = proc->next;
	}
	*/
	A_MEMORY[pc] = value >> 24;
	COLOR[pc] = color;
	A_MEMORY[(pc + 1) % MEM_SIZE] = (value >> 16) & 0b11111111;
	COLOR[(pc + 1) % MEM_SIZE] = color;
	ft_printf("%x\n", A_MEMORY[(pc + 2) % MEM_SIZE]);
	A_MEMORY[(pc + 2) % MEM_SIZE] = (value >> 8) & 0b11111111;
	ft_printf("%x\n", A_MEMORY[(pc + 2) % MEM_SIZE]);
	COLOR[(pc + 2) % MEM_SIZE] = color;
	A_MEMORY[(pc + 3) % MEM_SIZE] = value & 0b11111111;
	COLOR[(pc + 3) % MEM_SIZE] = color;
	/*
	proc = A_LPROC;
	while (proc)
	{
		printf("	id = %d\n", PR_ID);
		printf("	p_id = %d\n", PR_IDP);
		printf("	alive = %d\n", PR_ALIVE);
		printf("	pc = %d\n", PR_PC);
		printf("	carry = %d\n", PR_CARRY);
		printf("	ctw = %d\n\n", PR_WAIT);
		proc = proc->next;
	}
	*/
}

void		v_op(t_vm *vm, char *name, t_proc *proc, int ocp)
{
	int		color;

	if (!(OPT_V & V_OP))
		return ;
	color = get_player_from_id(vm, PR_IDP)->color;
	if (color == 1)
		ft_printf(GREEN);
	else if (color == 2)
		ft_printf(BLUE);
	else if (color == 3)
		ft_printf(RED);
	else if (color == 4)
		ft_printf(YELLOW);
	ft_printf("%s (proc %d)%s | ",
			get_player_from_id(vm, PR_IDP)->champ->name, PR_ID, WHITE);
	ft_printf("%s%s%s", CYAN, name, DEFAULT);
	ft_printf("%s (PC %d)%s\n", YELLOW, PR_PC, DEFAULT);
	if (ocp)
		ft_printf("%s	OCP = %d%s\n", PURPLE, ocp, DEFAULT);
}

int		verif_ocp(t_vm *vm, t_proc *proc, int op, int ocp)
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
			|| (op == 14 && (ocp == 64)))
		return (1);
	ft_printf("	%sOP %d (%d) FAILED%s\n", RED, op, ocp, DEFAULT);
	PR_WAIT = 1;
	PR_LOP = -1;
	/*
	if (op == 4 || op == 5)
		move_failed_op(vm, proc, 6);
	else
	*/
		move_pc(vm, proc, ocp);
	return (0);
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

	v_op(vm, "live", proc, 0);
	PR_ALIVE = 1;
	TOTAL_LIVE++;
	value = get_value(vm, 4, (PR_PC + 1) % MEM_SIZE);
	if ((player = get_player_from_id(vm, value)))
	{
		player->nb_live++;
		A_WINNER = P_ID;
		P_LASTLIVE = A_CYCLE;
		if (OPT_V & V_LIVE)
			ft_printf("%sPlayer %d %s is said to be alive%s\n",
					GREEN, P_COLOR, C_NAME, DEFAULT);
	}
	move_pc(vm, proc, 0);
}

void	op_ld(t_vm *vm, t_proc *proc)
{
	int		args[4];
	int		ocp;
	int		j;

	ocp = A_MEMORY[(PR_PC + 1) % MEM_SIZE];
	if (!verif_ocp(vm, proc, 2, ocp))
		return ;
	v_op(vm, "ld", proc, ocp);
	get_args(vm, proc, ocp, args);
	if ((ocp & 0b11000000) == 0b11000000)
	{
		j = (PR_PC + (args[0] % IDX_MOD)) % MEM_SIZE;
		if (j < 0)
			j += MEM_SIZE;
		PR_REG[args[1]] = get_value(vm, 4, j);
	}
	else
		PR_REG[args[1]] = args[0];
	PR_CARRY = (PR_REG[args[1]] == 0) ? 1 : 0;
	move_pc(vm, proc, ocp);
}

void	op_st(t_vm *vm, t_proc *proc)
{
	int		args[4];
	int		ocp;
	int		j;

	ocp = A_MEMORY[(PR_PC + 1) % MEM_SIZE];
	if (!verif_ocp(vm, proc, 3, ocp))
		return ;
	v_op(vm, "st", proc, ocp);
	get_args(vm, proc, ocp, args);
	j = (PR_PC + (args[1] % IDX_MOD)) % MEM_SIZE;
	if (j < 0)
		j += MEM_SIZE;
	if (((ocp << 2) & 0b11000000) == 0b11000000)
		write_in_mem(vm, PR_REG[args[0]], j,
				get_player_from_id(vm, proc->id_player)->color);
	else if ((ocp << 2) & 0b01000000)
		PR_REG[args[1]] = PR_REG[args[0]];
	move_pc(vm, proc, ocp);
}

void	op_add(t_vm *vm, t_proc *proc)
{
	int		args[4];
	int		ocp;

	ocp = A_MEMORY[(PR_PC + 1) % MEM_SIZE];
	if (!verif_ocp(vm, proc, 4, ocp))
		return ;
	v_op(vm, "add", proc, ocp);
	get_args(vm, proc, ocp, args);
	args[0] = PR_REG[args[0]];
	args[1] = PR_REG[args[1]];
	PR_REG[args[2]] = args[0] + args[1];
	PR_CARRY = (PR_REG[args[2]] == 0) ? 1 : 0;
	move_pc(vm, proc, ocp);
}

void	op_sub(t_vm *vm, t_proc *proc)
{
	int		args[4];
	int		ocp;

	ocp = A_MEMORY[(PR_PC + 1) % MEM_SIZE];
	if (!verif_ocp(vm, proc, 5, ocp))
		return ;
	v_op(vm, "sub", proc, ocp);
	get_args(vm, proc, ocp, args);
	args[0] = PR_REG[args[0]];
	args[1] = PR_REG[args[1]];
	PR_REG[args[2]] = args[0] - args[1];
	PR_CARRY = (PR_REG[args[2]] == 0) ? 1 : 0;
	move_pc(vm, proc, ocp);
}

void	op_and(t_vm *vm, t_proc *proc)
{
	int		args[4];
	int		ocp;

	ocp = A_MEMORY[(PR_PC + 1) % MEM_SIZE];
	if (!verif_ocp(vm, proc, 6, ocp))
		return ;
	v_op(vm, "and", proc, ocp);
	get_args(vm, proc, ocp, args);
	if (((ocp & 0b11000000)) == 0b11000000)
		args[0] = get_value(vm, 4, (PR_PC + (args[0] % IDX_MOD)) % MEM_SIZE);
	else if ((ocp & 0b01000000))
		args[0] = PR_REG[args[0]];
	if ((((ocp << 2) & 0b11000000)) == 0b11000000)
		args[1] = get_value(vm, 4, (PR_PC + (args[1] % IDX_MOD)) % MEM_SIZE);
	else if (((ocp << 2) & 0b01000000))
		args[1] = PR_REG[args[1]];
	PR_REG[args[2]] = args[0] & args[1];
	PR_CARRY = (PR_REG[args[2]] == 0) ? 1 : 0;
	move_pc(vm, proc, ocp);
}

void	op_or(t_vm *vm, t_proc *proc)
{
	int		args[4];
	int		ocp;

	ocp = A_MEMORY[(PR_PC + 1) % MEM_SIZE];
	if (!verif_ocp(vm, proc, 7, ocp))
		return ;
	v_op(vm, "or", proc, ocp);
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
	PR_CARRY = (PR_REG[args[2]] == 0) ? 1 : 0;
	move_pc(vm, proc, ocp);
}

void	op_xor(t_vm *vm, t_proc *proc)
{
	int		args[4];
	int		ocp;

	ocp = A_MEMORY[(PR_PC + 1) % MEM_SIZE];
	if (!verif_ocp(vm, proc, 8, ocp))
		return ;
	v_op(vm, "xor", proc, ocp);
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
	PR_CARRY = (PR_REG[args[2]] == 0) ? 1 : 0;
	move_pc(vm, proc, ocp);
}

void	op_zjmp(t_vm *vm, t_proc *proc)
{
	int	value;

	v_op(vm, "zjmp", proc, 0);
	value = get_value(vm, 2, (PR_PC + 1) % MEM_SIZE);
	if (PR_CARRY == 1)
	{
		// IDX_MOD ??
		PR_PC += ((short)value) % MEM_SIZE;
		if (PR_PC < 0)
			PR_PC += MEM_SIZE;
		ft_printf("%sZjmp at %d%s\n", YELLOW, PR_PC, DEFAULT);
		PR_WAIT = 1;
	}
	else
	{
		ft_printf("%s	ZJMP FAILLED%s\n", RED, DEFAULT);
		move_pc(vm, proc, 0);
	}
	ft_printf("	PC after zjmp = %d\n", PR_PC);
}

void	op_ldi(t_vm *vm, t_proc *proc)
{
	int		args[4];
	int		ocp;

	ocp = A_MEMORY[(PR_PC + 1) % MEM_SIZE];
	if (!verif_ocp(vm, proc, 10, ocp))
		return ;
	v_op(vm, "ldi", proc, ocp);
	get_args(vm, proc, ocp, args);
	if (((ocp & 0b11000000)) == 0b11000000)
		args[0] = get_value(vm, 4, (PR_PC + (args[0] % IDX_MOD)) % MEM_SIZE);
	else if ((ocp & 0b01000000))
		args[0] = PR_REG[args[0]];
	if ((((ocp << 2) & 0b11000000)) == 0b11000000)
		args[1] = get_value(vm, 4, (PR_PC + (args[1] % IDX_MOD)) % MEM_SIZE);
	else if (((ocp << 2) & 0b01000000))
		args[1] = PR_REG[args[1]];
	PR_REG[args[2]] = get_value(vm, REG_SIZE,
			(PR_PC + args[0] + args[1]) % MEM_SIZE);
	move_pc(vm, proc, ocp);
}

void	op_sti(t_vm *vm, t_proc *proc)
{
	int		args[4];
	int		ocp;
	int		j;

	ocp = A_MEMORY[(PR_PC + 1) % MEM_SIZE];
	if (!verif_ocp(vm, proc, 11, ocp))
		return ;
	v_op(vm, "sti", proc, ocp);
	get_args(vm, proc, ocp, args);
	if ((((ocp << 2) & 0b11000000)) == 0b11000000)
		args[1] = get_value(vm, 4, (PR_PC + (args[1] % IDX_MOD)) % MEM_SIZE);
	else if (((ocp << 2) & 0b01000000))
		args[1] = PR_REG[args[1]];
	if (((ocp << 4) & 0b01000000))
		args[2] = PR_REG[args[2]];
	j = (PR_PC + ((args[1] + args[2])) % IDX_MOD) % MEM_SIZE;
	if (j < 0)
		j += MEM_SIZE;
	write_in_mem(vm, PR_REG[args[0]], j,
				get_player_from_id(vm, proc->id_player)->color);
	move_pc(vm, proc, ocp);
}

void	op_fork(t_vm *vm, t_proc *proc)
{
	int		value;
	int		i;
	t_proc	*clone;

	v_op(vm, "fork", proc, 0);
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

	ocp = A_MEMORY[(PR_PC + 1) % MEM_SIZE];
	if (!verif_ocp(vm, proc, 13, ocp))
		return ;
	v_op(vm, "lld", proc, ocp);
	get_args(vm, proc, ocp, args);
	if ((ocp & 0b11000000) == 0b11000000)
	{
		j = (PR_PC + args[0]) % MEM_SIZE;
		if (j < 0)
			j += MEM_SIZE;
		PR_REG[args[1]] = get_value(vm, 2, j);
	}
	else
		PR_REG[args[1]] = args[0];
	PR_CARRY = (PR_REG[args[1]] == 0) ? 1 : 0;
	move_pc(vm, proc, ocp);
}

void	op_lldi(t_vm *vm, t_proc *proc)
{
	int		args[4];
	int		ocp;

	ocp = A_MEMORY[(PR_PC + 1) % MEM_SIZE];
	if (!verif_ocp(vm, proc, 14, ocp))
		return ;
	v_op(vm, "lldi", proc, ocp);
	get_args(vm, proc, ocp, args);
	if (((ocp & 0b11000000)) == 0b11000000)
		args[0] = get_value(vm, 4, (PR_PC + args[0]) % MEM_SIZE);
	else if ((ocp & 0b01000000))
		args[0] = PR_REG[args[0]];
	if ((((ocp << 2) & 0b11000000)) == 0b11000000)
		args[1] = get_value(vm, 4, (PR_PC + args[1]) % MEM_SIZE);
	else if (((ocp << 2) & 0b01000000))
		args[1] = PR_REG[args[1]];
	PR_REG[args[2]] = get_value(vm, REG_SIZE,
			(PR_PC + args[0] + args[1]) % MEM_SIZE);
	PR_CARRY = (PR_REG[args[1]] == 0) ? 1 : 0;
	move_pc(vm, proc, ocp);
}

void	op_lfork(t_vm *vm, t_proc *proc)
{
	int		value;
	t_proc	*clone;
	int		i;

	v_op(vm, "lfork", proc, 0);
	value = get_value(vm, 2, (PR_PC + 1) % MEM_SIZE);
	value %= MEM_SIZE;
	clone = new_proc(PR_IDP);
	clone->carry = proc->carry;
	if (PR_PC + value < 0)
		clone->pc = (PR_PC + MEM_SIZE + value) % MEM_SIZE;
	else
		clone->pc = (PR_PC + value) % MEM_SIZE;
	A_PROC++;
	i = 0;
	while (++i < 17)
		(clone->reg)[i] = PR_REG[i];
	clone->next = A_LPROC;
	A_LPROC = clone;
	move_pc(vm, proc, 0);
}

void	op_aff(t_vm *vm, t_proc *proc)
{
	int		value;
	int		ocp;
	char	aff;

	if (OPT_NC)
		return ;
	ocp = A_MEMORY[(PR_PC + 1) % MEM_SIZE];
	if (!verif_ocp(vm, proc, 16, ocp))
		return ;
	v_op(vm, "aff", proc, ocp);
	value = get_value(vm, 1, (PR_PC + 2) % MEM_SIZE);
	aff = PR_REG[value] % 256;
	ft_printf("aff: %c\n", aff);
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
		if (COLOR[i] == 1)
			ft_printf(GREEN);
		else if (COLOR[i] == 2)
			ft_printf(BLUE);
		else if (COLOR[i] == 3)
			ft_printf(RED);
		else if (COLOR[i] == 4)
			ft_printf(CYAN);
		else
			ft_printf(DEFAULT);
		if (i != 0 && i % 64 == 0)
			ft_printf("\n%02x ", A_MEMORY[i]);
		else
			ft_printf("%02x ", A_MEMORY[i]);
	}
	ft_printf("\n");
	ft_printf(DEFAULT);
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
		if (OPT_D > -1 && A_CYCLE > (OPT_D - 1))
			dump_mem(vm);
		++A_CYCLE;
		if (OPT_V & V_CYCLE)
			ft_printf("%sIt is now cycle %d%s\n", GREY, A_CYCLE, DEFAULT);
		cycle++;
		curr = A_LPROC;
		while (curr)
		{
			if ((curr->loaded_op == -1) &&
					(A_MEMORY[curr->pc] <= 0 || A_MEMORY[curr->pc] > 16))
				curr->pc = ((curr->pc) + 1) % MEM_SIZE;
			else if (curr->cycle_to_wait >=
					(g_op_tab[curr->loaded_op - 1]).cycles)
				(op_tab[curr->loaded_op - 1])(vm, curr);
			else
			{
				if (curr->loaded_op == -1)
					curr->loaded_op = A_MEMORY[curr->pc];
				(curr->cycle_to_wait)++;
			}
			curr = curr->next;
		}
		if (cycle == A_CTD)
		{
			cycle = 0;
			check_alive(vm);
		}
		if (!A_PROC)
			break ;
		if (OPT_NC > 0)
			ftncu_main(vm);
	}
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
		else if (ft_strequ(av[i], "-v"))
			(++i < ac) ? set_opt(&(vm->opt_v), av[i]) : ft_perror("Error");
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
	ARENA = NULL;
	OPT_NC = 0;
	OPT_D = -1;
	OPT_V = 0;
	TOTAL_LIVE = 0;
	if (!(COLOR = ft_memalloc(sizeof(int) * MEM_SIZE)))
		ft_perror(strerror(errno));
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
	init_arena(vm, tab_size(args), args); // faudra penser a free args
	load_champ(vm);
	if (OPT_NC > 0)
	{
		initscr();
		ftncu_main(vm);
	}
	process(vm);
	if (A_CTD <= 0)
		ft_printf("%sCycle to die is now %d\n%sIt is now cycle %d%s\n",
				RED, A_CTD, GREY, ++A_CYCLE, DEFAULT);
	if (!OPT_NC)
		ft_printf("le joueur %d (%s) a gagne\n", A_WINNER,
				get_player_from_id(vm, A_WINNER)->champ->name);
	return (1);
}
