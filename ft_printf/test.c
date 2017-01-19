/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Creates: 2016/12/09 23:45:58 by apoisson          #+#    #+#             */
/*   Upsated: 2016/12/14 14:04:23 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>

#define SUCCESS "\033[32mSUCCESS  \033[0m"
#define FAILLURE "\033[31mFAILLURE \033[0m"

int		fails = 0;

void	ft_test(char *s, int d)
{
	char	*s1;
	char	*s2;
	static int	i = 1;
	s1 = ft_memalloc(100);
	sprintf(s1, s, d);
	s2 = ft_printf(s, d);
	if (ft_strcmp(s1, s2))
	{
		printf(FAILLURE);
		printf("Test %d : %s\n", i++, s);
		printf("	s{%s}\n", s1);
		printf("	f{%s}\n", s2);
		fails++;
	}
	else
	{
		printf(SUCCESS);
		printf("Test %d : %s\n", i++, s);
	}
	free(s1);
}

int		main(int ac, char **av)
{
	setlocale(LC_ALL, "");
	int	k = -1;
	int	d[9] = {0};
	int	x[8] = {0};
	if (ac < 2)
		d[0] = 1;
	else
	{
		if (av[1][0] == 'd')
		{
			if (!av[1][1])
				d[0] = 1;
			while (av[1][++k])
			{
				d[0] = (av[1][k] == '0') ? 1 : d[0];
				d[1] = (av[1][k] == '1') ? 1 : d[1];
				d[2] = (av[1][k] == '2') ? 1 : d[2];
				d[3] = (av[1][k] == '3') ? 1 : d[3];
				d[4] = (av[1][k] == '4') ? 1 : d[4];
				d[5] = (av[1][k] == '5') ? 1 : d[5];
				d[6] = (av[1][k] == '6') ? 1 : d[6];
				d[7] = (av[1][k] == '7') ? 1 : d[7];
				d[8] = (av[1][k] == '8') ? 1 : d[8];
			}
		}
		else if (av[1][0] == 'x')
		{
			if (!av[1][1])
				x[0] = 1;
			while (av[1][++k])
			{
				x[0] = (av[1][k] == '0') ? 1 : x[0];
				x[1] = (av[1][k] == '1') ? 1 : x[1];
				x[2] = (av[1][k] == '2') ? 1 : x[2];
				x[3] = (av[1][k] == '3') ? 1 : x[3];
				x[4] = (av[1][k] == '4') ? 1 : x[4];
				x[5] = (av[1][k] == '5') ? 1 : x[5];
				x[6] = (av[1][k] == '6') ? 1 : x[6];
				x[7] = (av[1][k] == '7') ? 1 : x[7];
			}
		}
	}

	if (d[0] || d[1])
	{
		printf("\033[36m1 - CLASSICO\n\033[0m");
		ft_test("%d", 512);
		ft_test("%d", -512);
		ft_test("%6d", 512);
		ft_test("%6d", -512);
		ft_test("%1d", 512);
		ft_test("%1d", -512);
		ft_test("%6.2d", 512);
		ft_test("%6.2d", -512);
		ft_test("%1.2d", 512);
		ft_test("%1.2d", -512);
		ft_test("%6.8d", 512);
		ft_test("%6.8d", -512);
		ft_test("%1.8d", 512);
		ft_test("%1.8d", -512);
		ft_test("%.2d", 512);
		ft_test("%.2d", -512);
		ft_test("%.8d", 512);
		ft_test("%.8d", -512);
	}

	if (d[0] || d[2])
	{
		printf("\033[36m2 - CLASSICO SPACE\n\033[0m");
		ft_test("% d", 512);
		ft_test("% d", -512);
		ft_test("% 6d", 512);
		ft_test("% 6d", -512);
		ft_test("% 1d", 512);
		ft_test("% 1d", -512);
		ft_test("% 6.2d", 512);
		ft_test("% 6.2d", -512);
		ft_test("% 1.2d", 512);
		ft_test("% 1.2d", -512);
		ft_test("% 6.8d", 512);
		ft_test("% 6.8d", -512);
		ft_test("% 1.8d", 512);
		ft_test("% 1.8d", -512);
		ft_test("% .2d", 512);
		ft_test("% .2d", -512);
		ft_test("% .8d", 512);
		ft_test("% .8d", -512);
	}

	if (d[0] || d[3])
	{
		printf("\033[36m3 - CLASSICO LEFT\n\033[0m");
		ft_test("%-d", 512);
		ft_test("%-d", -512);
		ft_test("%-6d", 512);
		ft_test("%-6d", -512);
		ft_test("%-1d", 512);
		ft_test("%-1d", -512);
		ft_test("%-6.2d", 512);
		ft_test("%-6.2d", -512);
		ft_test("%-1.2d", 512);
		ft_test("%-1.2d", -512);
		ft_test("%-6.8d", 512);
		ft_test("%-6.8d", -512);
		ft_test("%-1.8d", 512);
		ft_test("%-1.8d", -512);
		ft_test("%-.2d", 512);
		ft_test("%-.2d", -512);
		ft_test("%-.8d", 512);
		ft_test("%-.8d", -512);
	}

	if (d[0] || d[4])
	{
		printf("\033[36m4 - CLASSICO LEFT SPACE\n\033[0m");
		ft_test("% -d", 512);
		ft_test("% -d", -512);
		ft_test("% -6d", 512);
		ft_test("% -6d", -512);
		ft_test("% -1d", 512);
		ft_test("% -1d", -512);
		ft_test("% -6.2d", 512);
		ft_test("% -6.2d", -512);
		ft_test("% -1.2d", 512);
		ft_test("% -1.2d", -512);
		ft_test("% -6.8d", 512);
		ft_test("% -6.8d", -512);
		ft_test("% -1.8d", 512);
		ft_test("% -1.8d", -512);
		ft_test("% -.2d", 512);
		ft_test("% -.2d", -512);
		ft_test("% -.8d", 512);
		ft_test("% -.8d", -512);
	}

	if (d[0] || d[5])
	{
		printf("\033[36m5 - CLASSICO0000000000\n\033[0m");
		ft_test("%0d", 512);
		ft_test("%0d", -512);
		ft_test("%06d", 512);
		ft_test("%06d", -512);
		ft_test("%01d", 512);
		ft_test("%01d", -512);
		ft_test("%06.2d", 512);
		ft_test("%06.2d", -512);
		ft_test("%01.2d", 512);
		ft_test("%01.2d", -512);
		ft_test("%06.8d", 512);
		ft_test("%06.8d", -512);
		ft_test("%01.8d", 512);
		ft_test("%01.8d", -512);
		ft_test("%0.2d", 512);
		ft_test("%0.2d", -512);
		ft_test("%0.8d", 512);
		ft_test("%0.8d", -512);
	}

	if (d[0] || d[6])
	{
		printf("\033[36m6 - CLASSICO QUINTE +\n\033[0m");
		ft_test("%+d", 512);
		ft_test("%+d", -512);
		ft_test("%+6d", 512);
		ft_test("%+6d", -512);
		ft_test("%+1d", 512);
		ft_test("%+1d", -512);
		ft_test("%+6.2d", 512);
		ft_test("%+6.2d", -512);
		ft_test("%+1.2d", 512);
		ft_test("%+1.2d", -512);
		ft_test("%+6.8d", 512);
		ft_test("%+6.8d", -512);
		ft_test("%+1.8d", 512);
		ft_test("%+1.8d", -512);
		ft_test("%+.2d", 512);
		ft_test("%+.2d", -512);
		ft_test("%+.8d", 512);
		ft_test("%+.8d", -512);
	}

	if (d[0] || d[7])
	{
		printf("\033[36m7 - CLASSICO0000000000 +\n\033[0m");
		ft_test("%+0d", 512);
		ft_test("%+0d", -512);
		ft_test("%+06d", 512);
		ft_test("%+06d", -512);
		ft_test("%+01d", 512);
		ft_test("%+01d", -512);
		ft_test("%+06.2d", 512);
		ft_test("%+06.2d", -512);
		ft_test("%+01.2d", 512);
		ft_test("%+01.2d", -512);
		ft_test("%+06.8d", 512);
		ft_test("%+06.8d", -512);
		ft_test("%+01.8d", 512);
		ft_test("%+01.8d", -512);
		ft_test("%+0.2d", 512);
		ft_test("%+0.2d", -512);
		ft_test("%+0.8d", 512);
		ft_test("%+0.8d", -512);
	}

	if (d[0] || d[8])
	{
		printf("\033[36m8 - CLASSICO QUINTE LEFT +\n\033[0m");
		ft_test("%+-d", 512);
		ft_test("%+-d", -512);
		ft_test("%+-6d", 512);
		ft_test("%+-6d", -512);
		ft_test("%+-1d", 512);
		ft_test("%+-1d", -512);
		ft_test("%+-6.2d", 512);
		ft_test("%+-6.2d", -512);
		ft_test("%+-1.2d", 512);
		ft_test("%+-1.2d", -512);
		ft_test("%+-6.8d", 512);
		ft_test("%+-6.8d", -512);
		ft_test("%+-1.8d", 512);
		ft_test("%+-1.8d", -512);
		ft_test("%+-.2d", 512);
		ft_test("%+-.2d", -512);
		ft_test("%+-.8d", 512);
		ft_test("%+-.8d", -512);
	}

	if (x[0] || x[1])
	{
		printf("\033[36m1 - CLASSICO\n\033[0m");
		ft_test("%x", 512);
		ft_test("%x", -512);
		ft_test("%6x", 512);
		ft_test("%6x", -512);
		ft_test("%1x", 512);
		ft_test("%1x", -512);
		ft_test("%6.2x", 512);
		ft_test("%6.2x", -512);
		ft_test("%1.2x", 512);
		ft_test("%1.2x", -512);
		ft_test("%6.8x", 512);
		ft_test("%6.8x", -512);
		ft_test("%1.8x", 512);
		ft_test("%1.8x", -512);
		ft_test("%.2x", 512);
		ft_test("%.2x", -512);
		ft_test("%.8x", 512);
		ft_test("%.8x", -512);
	}

	if (x[0] || x[2])
	{
		printf("\033[36m2 - CLASSICO PREFIX\n\033[0m");
		ft_test("%#x", 512);
		ft_test("%#x", -512);
		ft_test("%#6x", 512);
		ft_test("%#6x", -512);
		ft_test("%#1x", 512);
		ft_test("%#1x", -512);
		ft_test("%#6.2x", 512);
		ft_test("%#6.2x", -512);
		ft_test("%#1.2x", 512);
		ft_test("%#1.2x", -512);
		ft_test("%#6.8x", 512);
		ft_test("%#6.8x", -512);
		ft_test("%#1.8x", 512);
		ft_test("%#1.8x", -512);
		ft_test("%#.2x", 512);
		ft_test("%#.2x", -512);
		ft_test("%#.8x", 512);
		ft_test("%#.8x", -512);
	}

	if (x[0] || x[3])
	{
		printf("\033[36m3 - CLASSICO LEFT\n\033[0m");
		ft_test("%-x", 512);
		ft_test("%-x", -512);
		ft_test("%-6x", 512);
		ft_test("%-6x", -512);
		ft_test("%-1x", 512);
		ft_test("%-1x", -512);
		ft_test("%-6.2x", 512);
		ft_test("%-6.2x", -512);
		ft_test("%-1.2x", 512);
		ft_test("%-1.2x", -512);
		ft_test("%-6.8x", 512);
		ft_test("%-6.8x", -512);
		ft_test("%-1.8x", 512);
		ft_test("%-1.8x", -512);
		ft_test("%-.2x", 512);
		ft_test("%-.2x", -512);
		ft_test("%-.8x", 512);
		ft_test("%-.8x", -512);
	}

	if (x[0] || x[4])
	{
		printf("\033[36m4 - CLASSICO PREFIX LEFT\n\033[0m");
		ft_test("%#-x", 512);
		ft_test("%#-x", -512);
		ft_test("%#-6x", 512);
		ft_test("%#-6x", -512);
		ft_test("%#-1x", 512);
		ft_test("%#-1x", -512);
		ft_test("%#-6.2x", 512);
		ft_test("%#-6.2x", -512);
		ft_test("%#-1.2x", 512);
		ft_test("%#-1.2x", -512);
		ft_test("%#-6.8x", 512);
		ft_test("%#-6.8x", -512);
		ft_test("%#-1.8x", 512);
		ft_test("%#-1.8x", -512);
		ft_test("%#-.2x", 512);
		ft_test("%#-.2x", -512);
		ft_test("%#-.8x", 512);
		ft_test("%#-.8x", -512);
	}

	if (x[0] || x[5])
	{
		printf("\033[36m5 - CLASSICO000000\n\033[0m");
		ft_test("%0x", 512);
		ft_test("%0x", -512);
		ft_test("%06x", 512);
		ft_test("%06x", -512);
		ft_test("%01x", 512);
		ft_test("%01x", -512);
		ft_test("%06.2x", 512);
		ft_test("%06.2x", -512);
		ft_test("%01.2x", 512);
		ft_test("%01.2x", -512);
		ft_test("%06.8x", 512);
		ft_test("%06.8x", -512);
		ft_test("%01.8x", 512);
		ft_test("%01.8x", -512);
		ft_test("%0.2x", 512);
		ft_test("%0.2x", -512);
		ft_test("%0.8x", 512);
		ft_test("%0.8x", -512);
	}

	if (x[0] || x[6])
	{
		printf("\033[36m6 - CLASSICO0000000 PREFIX\n\033[0m");
		ft_test("%#0x", 512);
		ft_test("%#0x", -512);
		ft_test("%#06x", 512);
		ft_test("%#06x", -512);
		ft_test("%#01x", 512);
		ft_test("%#01x", -512);
		ft_test("%#06.2x", 512);
		ft_test("%#06.2x", -512);
		ft_test("%#01.2x", 512);
		ft_test("%#01.2x", -512);
		ft_test("%#06.8x", 512);
		ft_test("%#06.8x", -512);
		ft_test("%#01.8x", 512);
		ft_test("%#01.8x", -512);
		ft_test("%#0.2x", 512);
		ft_test("%#0.2x", -512);
		ft_test("%#0.8x", 512);
		ft_test("%#0.8x", -512);
	}

	if (fails)
		printf("Total : \033[31m%d fails\033[0m\n", fails);
	else
		printf("Total : \033[32m%d fails\033[0m\n", fails);
	return (0);
}
