/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 00:13:23 by lcharbon          #+#    #+#             */
/*   Updated: 2017/07/23 00:02:10 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ncurse.h"
#include <fcntl.h>

void		ftncu_init_pair(void)
{
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_color(COLOR_CYAN, 500, 500, 500);
	init_pair(5, COLOR_CYAN, COLOR_BLACK);
}

static void	ftncu_print_memory(char *memory)
{
	int		i;
	int		n;
	int		a;

	i = 0;
	n = 3;
	a = 1;
	move(1, 1);
	ftncu_init_pair();
	attron(COLOR_PAIR(5));
	while (i < ft_strlen(memory))
	{
		printw("%c%c ", memory[i], memory[i + 1]);
		if (n >= 198)
		{
			n = 0;
			a++;
			move(a, 1);
		}
		n += 3;
		i += 2;
	}
	attroff(COLOR_PAIR(5));
}

static char	*get_str(int fd)
{
	char	*str;
	char	*line;

	line = NULL;
	str = ft_strdup("");
	while (ft_line_reader(fd, &line))
		str = ft_strjoindel(str, line, 3);
	return (str);
}

void		ftncu_main(t_gb *g)
{
	char	*str;
	int		fd;
//	WINDOW	*one;
//	WINDOW	*two;

	fd = open("test", O_RDONLY);
	str = get_str(fd);
	initscr();
//	one = subwin(stdscr, LINES, 200, 0, 0);
//	two = subwin(stdscr, LINES, 50, 0, 200);
//	box(one, ACS_VLINE, ACS_HLINE);
//	box(two, ACS_VLINE, ACS_HLINE);
	ftncu_print_memory(str);
	ftncu_print_info(g);
	while (42)
		getch();
//	endwin();
//	free(one);
//	free(two);
	ft_strdel(&str);
	close(fd);
}

int			main(void)
{
	t_gb	g;

	ft_memset(&g, 0, sizeof(g));
	g.n_players = 4;
	g.player[0].id = 1;
	g.player[0].s = ft_strdup("manger");
	g.player[0].ll = 0;
	g.player[0].licp = 0;
	g.player[1].id = -1;
	g.player[1].s = ft_strdup("yolokadeau");
	g.player[1].ll = 0;
	g.player[1].licp = 0;
	g.player[2].id = -7;
	g.player[2].s = ft_strdup("Kaboul");
	g.player[2].ll = 0;
	g.player[2].licp = 0;
	g.player[3].id = 12;
	g.player[3].s = ft_strdup("Pas la");
	g.player[3].ll = 0;
	g.player[3].licp = 0;
	ftncu_main(&g);
	free(g.player[0].s);
	free(g.player[1].s);
	free(g.player[2].s);
	free(g.player[3].s);
//	while (1);
	return (1);
}
