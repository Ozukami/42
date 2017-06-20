/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ncurses.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 04:50:28 by apoisson          #+#    #+#             */
/*   Updated: 2017/06/20 05:58:26 by apoisson         ###   ########.fr       */
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

void			read_player(t_player *l_player, int fd)
{
	t_player	*player;
	char		*line;
	int			i;

	if (!(player = ft_memalloc(sizeof(t_player))))
		perror("");
	read_binary();
}

t_player		*get_player(int nb_args, char **args)
{
	t_player		*l_player;
	int				fd;
	int				i;

	if (!(l_player = ft_memalloc(sizeof(t_player))))
		perror("");
	i = 0;
	while (++i < nb_args)
	{
		if ((fd = open(args[i], O_RDONLY)) < 0)
			perror("");
		read_player(l_player, fd);
		if (close(fd))
			perror("");
	}
	return (l_player);
}

void		init_arena(t_vm *vm, int nb_args, char **args)
{
	t_arena		*arena;

	if (!(arena = ft_memalloc(sizeof(t_arena))))
		perror("");
	A_PROC = 0;
	A_CYCLE = 0;
	A_MEMORY = ft_strnew(MEM_SIZE);
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
	process(vm);
	return (1);
}
