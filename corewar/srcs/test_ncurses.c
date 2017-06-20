/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ncurses.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 04:50:28 by apoisson          #+#    #+#             */
/*   Updated: 2017/06/20 04:00:40 by apoisson         ###   ########.fr       */
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

int		main(void)
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
	return (0);
}
