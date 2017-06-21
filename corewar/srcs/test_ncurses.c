/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ncurses.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 05:38:42 by apoisson          #+#    #+#             */
/*   Updated: 2017/06/22 01:49:06 by qumaujea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	init_mem(WINDOW *memory)
{
	int		line;
	int		col;
	char	*str;

	str = strdup(" 00");
	line = 1;
	while (line < 65)
	{
		col = 1;
		while (col < 191)
		{
			mvwprintw(memory, line, col, str);
			col += 3;
		}
		line++;
	}
}

void	win(void)
{
	WINDOW *memory;
	WINDOW *info;

	initscr();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);
	while (1)
	{
		memory = subwin(stdscr, 64 + 2, (64 * 2) + 63 + 4, 0, 0);
		init_mem(memory);
		info = subwin(stdscr, 64 + 2, 56, 0, (64 * 2) + 63 + 4);
		box(memory, ACS_VLINE, ACS_HLINE);
		box(info, ACS_VLINE, ACS_HLINE);
		refresh();
	}
	endwin();
	free(memory);
	free(info);
}

void	ft_usage(void)
{
	// print usage
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

t_proc			*new_proc(void)
{
	t_proc		*proc;

	if (!(proc = ft_memalloc(sizeof(t_proc))))
		ft_perror(strerror(errno));
	PR_PC = 0;
	PR_CARRY = 0;
	PR_WAIT = 0;
	PR_NEXT = NULL;
	return (proc);
}

t_player		*read_file(int fd, int id)
{
	t_player	*player;
	static int	static_id = -1;

	if (!(player = ft_memalloc(sizeof(t_player))))
		ft_perror(strerror(errno));
	P_LPROC = new_proc();
	P_CHAMP = read_champ(fd);
	P_ID = (id != -1) ? id : static_id--;
	P_PROC = 1;
	P_LIVE = 0;
	if (!(P_REG = ft_memalloc(sizeof(int) * REG_NUMBER)))
		ft_perror(strerror(errno));
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
	i = 0;
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

void		init_arena(t_vm *vm, int nb_args, char **args)
{
	t_arena		*arena;

	if (!(arena = ft_memalloc(sizeof(t_arena))))
		ft_perror(strerror(errno));
	ARENA = arena;
	A_PROC = 0;
	A_CYCLE = 0;
	A_NBPLAYER = 0;
	A_MEMORY = ft_memalloc(MEM_SIZE);
	A_LPLAYER = get_player(nb_args, args);
	verif_nb_player(vm);
}

/*
** load champ of each players in the memory of the vm
** at the good position
** and set the PC of the first proc of each players
** at this position
*/

void		init_memory(t_vm *vm)
{
	t_player	*current;
	int			i;
	int			j;

	current = A_LPLAYER;
	j = -1;
	while (current)
	{
		i = -1;
		while (++i < current->champ->prog_size)
		{
			printf("%02x ", current->champ->prog[i]);
			A_MEMORY[++j] = current->champ->prog[i];
		}
		j += MEM_SIZE / A_NBPLAYER - current->champ->prog_size;
		A_NBPLAYER++;
		current = current->next;
	}
	j = -1;
	while (++j < MEM_SIZE)
	   printf("%02x ", A_MEMORY[j]);	
	printf("\n\n%d\n", j);
}

void		load_champ(t_vm *vm)
{
	init_memory(vm);
}

/*
** run the vm with the champs
** use the implementation of op
** display with ncurses
*/

void		process(t_vm *vm)
{

}

int			main(int ac, char **av)
{
	t_vm	*vm;

	if (ac < 2)
		ft_usage();
	if (!(vm = ft_memalloc(sizeof(t_vm))))
		ft_perror(strerror(errno));
	init_arena(vm, ac, av);
	load_champ(vm);
	process(vm);
	return (1);
}
