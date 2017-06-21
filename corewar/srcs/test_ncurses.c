/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ncurses.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 04:50:28 by apoisson          #+#    #+#             */
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
		perror("");
	if (read(fd, name, PROG_NAME_LENGTH) < 1)
		perror("");
	return (name);
}

int				get_champ_size(int fd)
{
	unsigned int	prog_size;
	unsigned char	*buff;

	if (!(buff = ft_memalloc(4)))
		perror("");
	if (lseek(fd, 0x88, SEEK_SET) == -1)
		perror("");
	if (read(fd, buff, 4) < 1)
		perror("");
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
		perror("");
	if (read(fd, comment, COMMENT_LENGTH) < 1)
		perror("");
	return (comment);
}

unsigned char	*get_champ_prog(int fd, unsigned int size)
{
	unsigned char	*prog;
	unsigned int	r;

	if (lseek(fd, 0x890, SEEK_SET) == -1)
		perror("");
	if (!(prog = ft_memalloc(CHAMP_MAX_SIZE + 1)))
		perror("");
	if ((r = read(fd, prog, CHAMP_MAX_SIZE)) < 1)
		perror("");
	if (r != size)
		ft_perror("Error: wrong champ size");
	return (prog);
}

t_champ			*read_champ(int fd)
{
	t_champ		*champ;

	if (!(champ = ft_memalloc(sizeof(t_champ))))
		perror("");
	champ->name = get_champ_name(fd);
	champ->prog_size = get_champ_size(fd);
	champ->comment = get_champ_comment(fd);
	champ->prog = get_champ_prog(fd, champ->prog_size);
	return (champ);
}

t_player		*read_file(int fd)
{
	t_player	*player;

	if (!(player = ft_memalloc(sizeof(t_player))))
		perror("");
	P_LPROC = NULL;
	P_CHAMP = read_champ(fd);
	P_ID = 0;
	P_PROC = 1;
	P_LIVE = 0;
	if (!(P_REG = ft_memalloc(sizeof(int) * REG_NUMBER)))
		perror("");
	P_NEXT = NULL;
	return (player);
}

void			verif_file(int fd)
{
	unsigned char	*magic_number;

	if (!(magic_number = ft_memalloc(4)))
		perror("");
	if (read(fd, magic_number, 4) < 1)
		perror("");
	if (magic_number[0] != 0x00 || magic_number[1] != 0xea
			|| magic_number[2] != 0x83 || magic_number[3] != 0xf3)
		ft_perror("Error: bad magic number");
}

t_player		*get_player(int nb_args, char **args)
{
	t_player		*l_player;
	t_player		*tmp;
	int				fd;
	int				i;

	if (!(l_player = ft_memalloc(sizeof(t_player))))
		perror("");
	tmp = NULL;
	i = 0;
	while (++i < nb_args)
	{
		if ((fd = open(args[i], O_RDONLY)) < 0)
			perror("");
		verif_file(fd);
		l_player = read_file(fd);
		l_player->next = tmp;
		tmp = l_player;
		if (close(fd == -1))
			perror("");
	}
	return (l_player);
}

void		init_arena(t_vm *vm, int nb_args, char **args)
{
	t_arena		*arena;

	if (!(arena = ft_memalloc(sizeof(t_arena))))
		perror("");
	ARENA = arena;
	A_PROC = 0;
	A_CYCLE = 0;
	A_MEMORY = ft_memalloc(MEM_SIZE);
	A_LPLAYER = get_player(nb_args, args);
}

int			main(int ac, char **av)
{
	t_vm	*vm;

	if (ac < 2)
		ft_usage();
	if (!(vm = ft_memalloc(sizeof(t_vm))))
		perror("");
	init_arena(vm, ac, av);
	//process(vm);
	return (1);
}
