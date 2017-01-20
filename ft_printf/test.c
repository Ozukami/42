/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumaujea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 06:18:25 by qumaujea          #+#    #+#             */
/*   Updated: 2017/01/20 07:41:27 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>

#define SUCCESS "\033[32mSUCCESS  \033[0m"
#define FAILLURE "\033[31mFAILLURE \033[0m"

int		fails = 0;
int		tests = 0;

void	ft_test(char *s, int type, ...)
{
	va_list	ap;
	char	*s1;
	char	*s2;
	static int	i = 1;
	s1 = ft_memalloc(100);
	va_start(ap, type);
	if (type == 0)
	{
		int	arg = va_arg(ap, int);
		sprintf(s1, s, arg);
		s2 = ft_printf(s, arg);
	}
	else if (type == 1)
	{
		int	arg = va_arg(ap, int);
		sprintf(s1, s, arg);
		s2 = ft_printf(s, arg);
	}
	else if (type == 2)
	{
		char	*arg = va_arg(ap, char*);
		sprintf(s1, s, arg);
		s2 = ft_printf(s, arg);
	}
	if (ft_strcmp(s1, s2))
	{
		printf(FAILLURE);
		printf("Test %d : %s\n", i++, s);
		printf("	s{%s}\n	f{%s}\n", s1, s2);
		fails++;
	}
	else
	{
		printf(SUCCESS);
		printf("Test %d : %s\n", i++, s);
	}
	tests++;
	free(s1);
}

int		main(int ac, char **av)
{
	setlocale(LC_ALL, "");
	int	k = -1;
	int	d[9] = {0};
	int	x[8] = {0};
	int	xmaj[8] = {0};
	int	u[8] = {0};
	int	o[8] = {0};
	int	p = 0;
	int	c[8] = {0};
	int	s[8] = {0};
	int	i = 512;
	char	str[25] = "#@  	p% htyu(();;";
	if (ac < 2)
	{
		d[0] = 1;
		x[0] = 1;
		xmaj[0] = 1;
		u[0] = 1;
		o[0] = 1;
		p = 1;
		c[0] = 1;
		s[0] = 1;
	}
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
		else if (av[1][0] == 'X')
		{
			if (!av[1][1])
				xmaj[0] = 1;
			while (av[1][++k])
			{
				xmaj[0] = (av[1][k] == '0') ? 1 : xmaj[0];
				xmaj[1] = (av[1][k] == '1') ? 1 : xmaj[1];
				xmaj[2] = (av[1][k] == '2') ? 1 : xmaj[2];
				xmaj[3] = (av[1][k] == '3') ? 1 : xmaj[3];
				xmaj[4] = (av[1][k] == '4') ? 1 : xmaj[4];
				xmaj[5] = (av[1][k] == '5') ? 1 : xmaj[5];
				xmaj[6] = (av[1][k] == '6') ? 1 : xmaj[6];
				xmaj[7] = (av[1][k] == '7') ? 1 : xmaj[7];
			}
		}
		else if (av[1][0] == 'u')
		{
			if (!av[1][1])
				u[0] = 1;
			while (av[1][++k])
			{
				u[0] = (av[1][k] == '0') ? 1 : u[0];
				u[1] = (av[1][k] == '1') ? 1 : u[1];
				u[2] = (av[1][k] == '2') ? 1 : u[2];
				u[3] = (av[1][k] == '3') ? 1 : u[3];
			}
		}
		else if (av[1][0] == 'o')
		{
			if (!av[1][1])
				o[0] = 1;
			while (av[1][++k])
			{
				o[0] = (av[1][k] == '0') ? 1 : o[0];
				o[1] = (av[1][k] == '1') ? 1 : o[1];
				o[2] = (av[1][k] == '2') ? 1 : o[2];
				o[3] = (av[1][k] == '3') ? 1 : o[3];
				o[4] = (av[1][k] == '4') ? 1 : o[4];
				o[5] = (av[1][k] == '5') ? 1 : o[5];
				o[6] = (av[1][k] == '6') ? 1 : o[6];
				o[7] = (av[1][k] == '7') ? 1 : o[7];
			}
		}
		else if (av[1][0] == 'p')
		{
			if (!av[1][1])
				p = 1;
		}
		else if (av[1][0] == 'c')
		{
			if (!av[1][1])
				c[0] = 1;
			while (av[1][++k])
			{
				c[0] = (av[1][k] == '0') ? 1 : c[0];
				c[1] = (av[1][k] == '1') ? 1 : c[1];
				c[2] = (av[1][k] == '2') ? 1 : c[2];
				c[3] = (av[1][k] == '3') ? 1 : c[3];
			}
		}
		else if (av[1][0] == 's')
		{
			if (!av[1][1])
				s[0] = 1;
			while (av[1][++k])
			{
				s[0] = (av[1][k] == '0') ? 1 : s[0];
				s[1] = (av[1][k] == '1') ? 1 : s[1];
				s[2] = (av[1][k] == '2') ? 1 : s[2];
				s[3] = (av[1][k] == '3') ? 1 : s[3];
				s[4] = (av[1][k] == '4') ? 1 : s[4];
				s[5] = (av[1][k] == '5') ? 1 : s[5];
			}
		}
	}

	if (d[0] || d[1])
	{
		printf("\033[36m1 - CLASSICO\n\033[0m");
		ft_test("%d", 0, 512);
		ft_test("%d", 0, -512);
		ft_test("%6d", 0, 512);
		ft_test("%6d", 0, -512);
		ft_test("%1d", 0, 512);
		ft_test("%1d", 0, -512);
		ft_test("%6.2d", 0, 512);
		ft_test("%6.2d", 0, -512);
		ft_test("%1.2d", 0, 512);
		ft_test("%1.2d", 0, -512);
		ft_test("%6.8d", 0, 512);
		ft_test("%6.8d", 0, -512);
		ft_test("%1.8d", 0, 512);
		ft_test("%1.8d", 0, -512);
		ft_test("%.2d", 0, 512);
		ft_test("%.2d", 0, -512);
		ft_test("%.8d", 0, 512);
		ft_test("%.8d", 0, -512);
	}

	if (d[0] || d[2])
	{
		printf("\033[36m2 - CLASSICO SPACE\n\033[0m");
		ft_test("% d", 0, 512);
		ft_test("% d", 0, -512);
		ft_test("% 6d", 0, 512);
		ft_test("% 6d", 0, -512);
		ft_test("% 1d", 0, 512);
		ft_test("% 1d", 0, -512);
		ft_test("% 6.2d", 0, 512);
		ft_test("% 6.2d", 0, -512);
		ft_test("% 1.2d", 0, 512);
		ft_test("% 1.2d", 0, -512);
		ft_test("% 6.8d", 0, 512);
		ft_test("% 6.8d", 0, -512);
		ft_test("% 1.8d", 0, 512);
		ft_test("% 1.8d", 0, -512);
		ft_test("% .2d", 0, 512);
		ft_test("% .2d", 0, -512);
		ft_test("% .8d", 0, 512);
		ft_test("% .8d", 0, -512);
	}

	if (d[0] || d[3])
	{
		printf("\033[36m3 - CLASSICO LEFT\n\033[0m");
		ft_test("%-d", 0, 512);
		ft_test("%-d", 0, -512);
		ft_test("%-6d", 0, 512);
		ft_test("%-6d", 0, -512);
		ft_test("%-1d", 0, 512);
		ft_test("%-1d", 0, -512);
		ft_test("%-6.2d", 0, 512);
		ft_test("%-6.2d", 0, -512);
		ft_test("%-1.2d", 0, 512);
		ft_test("%-1.2d", 0, -512);
		ft_test("%-6.8d", 0, 512);
		ft_test("%-6.8d", 0, -512);
		ft_test("%-1.8d", 0, 512);
		ft_test("%-1.8d", 0, -512);
		ft_test("%-.2d", 0, 512);
		ft_test("%-.2d", 0, -512);
		ft_test("%-.8d", 0, 512);
		ft_test("%-.8d", 0, -512);
	}

	if (d[0] || d[4])
	{
		printf("\033[36m4 - CLASSICO LEFT SPACE\n\033[0m");
		ft_test("% -d", 0, 512);
		ft_test("% -d", 0, -512);
		ft_test("% -6d", 0, 512);
		ft_test("% -6d", 0, -512);
		ft_test("% -1d", 0, 512);
		ft_test("% -1d", 0, -512);
		ft_test("% -6.2d", 0, 512);
		ft_test("% -6.2d", 0, -512);
		ft_test("% -1.2d", 0, 512);
		ft_test("% -1.2d", 0, -512);
		ft_test("% -6.8d", 0, 512);
		ft_test("% -6.8d", 0, -512);
		ft_test("% -1.8d", 0, 512);
		ft_test("% -1.8d", 0, -512);
		ft_test("% -.2d", 0, 512);
		ft_test("% -.2d", 0, -512);
		ft_test("% -.8d", 0, 512);
		ft_test("% -.8d", 0, -512);
	}

	if (d[0] || d[5])
	{
		printf("\033[36m5 - CLASSICO0000000000\n\033[0m");
		ft_test("%0d", 0, 512);
		ft_test("%0d", 0, -512);
		ft_test("%06d", 0, 512);
		ft_test("%06d", 0, -512);
		ft_test("%01d", 0, 512);
		ft_test("%01d", 0, -512);
		ft_test("%06.2d", 0, 512);
		ft_test("%06.2d", 0, -512);
		ft_test("%01.2d", 0, 512);
		ft_test("%01.2d", 0, -512);
		ft_test("%06.8d", 0, 512);
		ft_test("%06.8d", 0, -512);
		ft_test("%01.8d", 0, 512);
		ft_test("%01.8d", 0, -512);
		ft_test("%0.2d", 0, 512);
		ft_test("%0.2d", 0, -512);
		ft_test("%0.8d", 0, 512);
		ft_test("%0.8d", 0, -512);
	}

	if (d[0] || d[6])
	{
		printf("\033[36m6 - CLASSICO QUINTE +\n\033[0m");
		ft_test("%+d", 0, 512);
		ft_test("%+d", 0, -512);
		ft_test("%+6d", 0, 512);
		ft_test("%+6d", 0, -512);
		ft_test("%+1d", 0, 512);
		ft_test("%+1d", 0, -512);
		ft_test("%+6.2d", 0, 512);
		ft_test("%+6.2d", 0, -512);
		ft_test("%+1.2d", 0, 512);
		ft_test("%+1.2d", 0, -512);
		ft_test("%+6.8d", 0, 512);
		ft_test("%+6.8d", 0, -512);
		ft_test("%+1.8d", 0, 512);
		ft_test("%+1.8d", 0, -512);
		ft_test("%+.2d", 0, 512);
		ft_test("%+.2d", 0, -512);
		ft_test("%+.8d", 0, 512);
		ft_test("%+.8d", 0, -512);
	}

	if (d[0] || d[7])
	{
		printf("\033[36m7 - CLASSICO0000000000 +\n\033[0m");
		ft_test("%+0d", 0, 512);
		ft_test("%+0d", 0, -512);
		ft_test("%+06d", 0, 512);
		ft_test("%+06d", 0, -512);
		ft_test("%+01d", 0, 512);
		ft_test("%+01d", 0, -512);
		ft_test("%+06.2d", 0, 512);
		ft_test("%+06.2d", 0, -512);
		ft_test("%+01.2d", 0, 512);
		ft_test("%+01.2d", 0, -512);
		ft_test("%+06.8d", 0, 512);
		ft_test("%+06.8d", 0, -512);
		ft_test("%+01.8d", 0, 512);
		ft_test("%+01.8d", 0, -512);
		ft_test("%+0.2d", 0, 512);
		ft_test("%+0.2d", 0, -512);
		ft_test("%+0.8d", 0, 512);
		ft_test("%+0.8d", 0, -512);
	}

	if (d[0] || d[8])
	{
		printf("\033[36m8 - CLASSICO QUINTE LEFT +\n\033[0m");
		ft_test("%+-d", 0, 512);
		ft_test("%+-d", 0, -512);
		ft_test("%+-6d", 0, 512);
		ft_test("%+-6d", 0, -512);
		ft_test("%+-1d", 0, 512);
		ft_test("%+-1d", 0, -512);
		ft_test("%+-6.2d", 0, 512);
		ft_test("%+-6.2d", 0, -512);
		ft_test("%+-1.2d", 0, 512);
		ft_test("%+-1.2d", 0, -512);
		ft_test("%+-6.8d", 0, 512);
		ft_test("%+-6.8d", 0, -512);
		ft_test("%+-1.8d", 0, 512);
		ft_test("%+-1.8d", 0, -512);
		ft_test("%+-.2d", 0, 512);
		ft_test("%+-.2d", 0, -512);
		ft_test("%+-.8d", 0, 512);
		ft_test("%+-.8d", 0, -512);
	}

	if (x[0] || x[1])
	{
		printf("\033[36m1 - CLASSICO\n\033[0m");
		ft_test("%x", 0, 512);
		ft_test("%x", 0, -512);
		ft_test("%6x", 0, 512);
		ft_test("%6x", 0, -512);
		ft_test("%1x", 0, 512);
		ft_test("%1x", 0, -512);
		ft_test("%6.2x", 0, 512);
		ft_test("%6.2x", 0, -512);
		ft_test("%1.2x", 0, 512);
		ft_test("%1.2x", 0, -512);
		ft_test("%6.8x", 0, 512);
		ft_test("%6.8x", 0, -512);
		ft_test("%1.8x", 0, 512);
		ft_test("%1.8x", 0, -512);
		ft_test("%.2x", 0, 512);
		ft_test("%.2x", 0, -512);
		ft_test("%.8x", 0, 512);
		ft_test("%.8x", 0, -512);
	}

	if (x[0] || x[2])
	{
		printf("\033[36m2 - CLASSICO PREFIX\n\033[0m");
		ft_test("%#x", 0, 512);
		ft_test("%#x", 0, -512);
		ft_test("%#6x", 0, 512);
		ft_test("%#6x", 0, -512);
		ft_test("%#1x", 0, 512);
		ft_test("%#1x", 0, -512);
		ft_test("%#6.2x", 0, 512);
		ft_test("%#6.2x", 0, -512);
		ft_test("%#1.2x", 0, 512);
		ft_test("%#1.2x", 0, -512);
		ft_test("%#6.8x", 0, 512);
		ft_test("%#6.8x", 0, -512);
		ft_test("%#1.8x", 0, 512);
		ft_test("%#1.8x", 0, -512);
		ft_test("%#.2x", 0, 512);
		ft_test("%#.2x", 0, -512);
		ft_test("%#.8x", 0, 512);
		ft_test("%#.8x", 0, -512);
	}

	if (x[0] || x[3])
	{
		printf("\033[36m3 - CLASSICO LEFT\n\033[0m");
		ft_test("%-x", 0, 512);
		ft_test("%-x", 0, -512);
		ft_test("%-6x", 0, 512);
		ft_test("%-6x", 0, -512);
		ft_test("%-1x", 0, 512);
		ft_test("%-1x", 0, -512);
		ft_test("%-6.2x", 0, 512);
		ft_test("%-6.2x", 0, -512);
		ft_test("%-1.2x", 0, 512);
		ft_test("%-1.2x", 0, -512);
		ft_test("%-6.8x", 0, 512);
		ft_test("%-6.8x", 0, -512);
		ft_test("%-1.8x", 0, 512);
		ft_test("%-1.8x", 0, -512);
		ft_test("%-.2x", 0, 512);
		ft_test("%-.2x", 0, -512);
		ft_test("%-.8x", 0, 512);
		ft_test("%-.8x", 0, -512);
	}

	if (x[0] || x[4])
	{
		printf("\033[36m4 - CLASSICO PREFIX LEFT\n\033[0m");
		ft_test("%#-x", 0, 512);
		ft_test("%#-x", 0, -512);
		ft_test("%#-6x", 0, 512);
		ft_test("%#-6x", 0, -512);
		ft_test("%#-1x", 0, 512);
		ft_test("%#-1x", 0, -512);
		ft_test("%#-6.2x", 0, 512);
		ft_test("%#-6.2x", 0, -512);
		ft_test("%#-1.2x", 0, 512);
		ft_test("%#-1.2x", 0, -512);
		ft_test("%#-6.8x", 0, 512);
		ft_test("%#-6.8x", 0, -512);
		ft_test("%#-1.8x", 0, 512);
		ft_test("%#-1.8x", 0, -512);
		ft_test("%#-.2x", 0, 512);
		ft_test("%#-.2x", 0, -512);
		ft_test("%#-.8x", 0, 512);
		ft_test("%#-.8x", 0, -512);
	}

	if (x[0] || x[5])
	{
		printf("\033[36m5 - CLASSICO000000\n\033[0m");
		ft_test("%0x", 0, 512);
		ft_test("%0x", 0, -512);
		ft_test("%06x", 0, 512);
		ft_test("%06x", 0, -512);
		ft_test("%01x", 0, 512);
		ft_test("%01x", 0, -512);
		ft_test("%06.2x", 0, 512);
		ft_test("%06.2x", 0, -512);
		ft_test("%01.2x", 0, 512);
		ft_test("%01.2x", 0, -512);
		ft_test("%06.8x", 0, 512);
		ft_test("%06.8x", 0, -512);
		ft_test("%01.8x", 0, 512);
		ft_test("%01.8x", 0, -512);
		ft_test("%0.2x", 0, 512);
		ft_test("%0.2x", 0, -512);
		ft_test("%0.8x", 0, 512);
		ft_test("%0.8x", 0, -512);
	}

	if (x[0] || x[6])
	{
		printf("\033[36m6 - CLASSICO0000000 PREFIX\n\033[0m");
		ft_test("%#0x", 0, 512);
		ft_test("%#0x", 0, -512);
		ft_test("%#06x", 0, 512);
		ft_test("%#06x", 0, -512);
		ft_test("%#01x", 0, 512);
		ft_test("%#01x", 0, -512);
		ft_test("%#06.2x", 0, 512);
		ft_test("%#06.2x", 0, -512);
		ft_test("%#01.2x", 0, 512);
		ft_test("%#01.2x", 0, -512);
		ft_test("%#06.8x", 0, 512);
		ft_test("%#06.8x", 0, -512);
		ft_test("%#01.8x", 0, 512);
		ft_test("%#01.8x", 0, -512);
		ft_test("%#0.2x", 0, 512);
		ft_test("%#0.2x", 0, -512);
		ft_test("%#0.8x", 0, 512);
		ft_test("%#0.8x", 0, -512);
	}

	if (xmaj[0] || xmaj[1])
	{
		printf("\033[36m1 - CLASSICO\n\033[0m");
		ft_test("%X", 0, 512);
		ft_test("%X", 0, -512);
		ft_test("%6X", 0, 512);
		ft_test("%6X", 0, -512);
		ft_test("%1X", 0, 512);
		ft_test("%1X", 0, -512);
		ft_test("%6.2X", 0, 512);
		ft_test("%6.2X", 0, -512);
		ft_test("%1.2X", 0, 512);
		ft_test("%1.2X", 0, -512);
		ft_test("%6.8X", 0, 512);
		ft_test("%6.8X", 0, -512);
		ft_test("%1.8X", 0, 512);
		ft_test("%1.8X", 0, -512);
		ft_test("%.2X", 0, 512);
		ft_test("%.2X", 0, -512);
		ft_test("%.8X", 0, 512);
		ft_test("%.8X", 0, -512);
	}

	if (xmaj[0] || xmaj[2])
	{
		printf("\033[36m2 - CLASSICO PREFIX\n\033[0m");
		ft_test("%#X", 0, 512);
		ft_test("%#X", 0, -512);
		ft_test("%#6X", 0, 512);
		ft_test("%#6X", 0, -512);
		ft_test("%#1X", 0, 512);
		ft_test("%#1X", 0, -512);
		ft_test("%#6.2X", 0, 512);
		ft_test("%#6.2X", 0, -512);
		ft_test("%#1.2X", 0, 512);
		ft_test("%#1.2X", 0, -512);
		ft_test("%#6.8X", 0, 512);
		ft_test("%#6.8X", 0, -512);
		ft_test("%#1.8X", 0, 512);
		ft_test("%#1.8X", 0, -512);
		ft_test("%#.2X", 0, 512);
		ft_test("%#.2X", 0, -512);
		ft_test("%#.8X", 0, 512);
		ft_test("%#.8X", 0, -512);
	}

	if (xmaj[0] || xmaj[3])
	{
		printf("\033[36m3 - CLASSICO LEFT\n\033[0m");
		ft_test("%-X", 0, 512);
		ft_test("%-X", 0, -512);
		ft_test("%-6X", 0, 512);
		ft_test("%-6X", 0, -512);
		ft_test("%-1X", 0, 512);
		ft_test("%-1X", 0, -512);
		ft_test("%-6.2X", 0, 512);
		ft_test("%-6.2X", 0, -512);
		ft_test("%-1.2X", 0, 512);
		ft_test("%-1.2X", 0, -512);
		ft_test("%-6.8X", 0, 512);
		ft_test("%-6.8X", 0, -512);
		ft_test("%-1.8X", 0, 512);
		ft_test("%-1.8X", 0, -512);
		ft_test("%-.2X", 0, 512);
		ft_test("%-.2X", 0, -512);
		ft_test("%-.8X", 0, 512);
		ft_test("%-.8X", 0, -512);
	}

	if (xmaj[0] || xmaj[4])
	{
		printf("\033[36m4 - CLASSICO PREFIX LEFT\n\033[0m");
		ft_test("%#-X", 0, 512);
		ft_test("%#-X", 0, -512);
		ft_test("%#-6X", 0, 512);
		ft_test("%#-6X", 0, -512);
		ft_test("%#-1X", 0, 512);
		ft_test("%#-1X", 0, -512);
		ft_test("%#-6.2X", 0, 512);
		ft_test("%#-6.2X", 0, -512);
		ft_test("%#-1.2X", 0, 512);
		ft_test("%#-1.2X", 0, -512);
		ft_test("%#-6.8X", 0, 512);
		ft_test("%#-6.8X", 0, -512);
		ft_test("%#-1.8X", 0, 512);
		ft_test("%#-1.8X", 0, -512);
		ft_test("%#-.2X", 0, 512);
		ft_test("%#-.2X", 0, -512);
		ft_test("%#-.8X", 0, 512);
		ft_test("%#-.8X", 0, -512);
	}

	if (xmaj[0] || xmaj[5])
	{
		printf("\033[36m5 - CLASSICO000000\n\033[0m");
		ft_test("%0X", 0, 512);
		ft_test("%0X", 0, -512);
		ft_test("%06X", 0, 512);
		ft_test("%06X", 0, -512);
		ft_test("%01X", 0, 512);
		ft_test("%01X", 0, -512);
		ft_test("%06.2X", 0, 512);
		ft_test("%06.2X", 0, -512);
		ft_test("%01.2X", 0, 512);
		ft_test("%01.2X", 0, -512);
		ft_test("%06.8X", 0, 512);
		ft_test("%06.8X", 0, -512);
		ft_test("%01.8X", 0, 512);
		ft_test("%01.8X", 0, -512);
		ft_test("%0.2X", 0, 512);
		ft_test("%0.2X", 0, -512);
		ft_test("%0.8X", 0, 512);
		ft_test("%0.8X", 0, -512);
	}

	if (xmaj[0] || xmaj[6])
	{
		printf("\033[36m6 - CLASSICO0000000 PREFIX\n\033[0m");
		ft_test("%#0X", 0, 512);
		ft_test("%#0X", 0, -512);
		ft_test("%#06X", 0, 512);
		ft_test("%#06X", 0, -512);
		ft_test("%#01X", 0, 512);
		ft_test("%#01X", 0, -512);
		ft_test("%#06.2X", 0, 512);
		ft_test("%#06.2X", 0, -512);
		ft_test("%#01.2X", 0, 512);
		ft_test("%#01.2X", 0, -512);
		ft_test("%#06.8X", 0, 512);
		ft_test("%#06.8X", 0, -512);
		ft_test("%#01.8X", 0, 512);
		ft_test("%#01.8X", 0, -512);
		ft_test("%#0.2X", 0, 512);
		ft_test("%#0.2X", 0, -512);
		ft_test("%#0.8X", 0, 512);
		ft_test("%#0.8X", 0, -512);
	}

	if (u[0] || u[1])
	{
		printf("\033[36m1 - CLASSICO\n\033[0m");
		ft_test("%u", 0, 512);
		ft_test("%u", 0, -512);
		ft_test("%6u", 0, 512);
		ft_test("%6u", 0, -512);
		ft_test("%1u", 0, 512);
		ft_test("%1u", 0, -512);
		ft_test("%6.2u", 0, 512);
		ft_test("%6.2u", 0, -512);
		ft_test("%1.2u", 0, 512);
		ft_test("%1.2u", 0, -512);
		ft_test("%6.8u", 0, 512);
		ft_test("%6.8u", 0, -512);
		ft_test("%1.8u", 0, 512);
		ft_test("%1.8u", 0, -512);
		ft_test("%.2u", 0, 512);
		ft_test("%.2u", 0, -512);
		ft_test("%.8u", 0, 512);
		ft_test("%.8u", 0, -512);
	}

	if (u[0] || u[2])
	{
		printf("\033[36m2 - CLASSICO LEFT\n\033[0m");
		ft_test("%-u", 0, 512);
		ft_test("%-u", 0, -512);
		ft_test("%-6u", 0, 512);
		ft_test("%-6u", 0, -512);
		ft_test("%-1u", 0, 512);
		ft_test("%-1u", 0, -512);
		ft_test("%-6.2u", 0, 512);
		ft_test("%-6.2u", 0, -512);
		ft_test("%-1.2u", 0, 512);
		ft_test("%-1.2u", 0, -512);
		ft_test("%-6.8u", 0, 512);
		ft_test("%-6.8u", 0, -512);
		ft_test("%-1.8u", 0, 512);
		ft_test("%-1.8u", 0, -512);
		ft_test("%-.2u", 0, 512);
		ft_test("%-.2u", 0, -512);
		ft_test("%-.8u", 0, 512);
		ft_test("%-.8u", 0, -512);
	}

	if (u[0] || u[3])
	{
		printf("\033[36m3 - CLASSICO000000\n\033[0m");
		ft_test("%0u", 0, 512);
		ft_test("%0u", 0, -512);
		ft_test("%06u", 0, 512);
		ft_test("%06u", 0, -512);
		ft_test("%01u", 0, 512);
		ft_test("%01u", 0, -512);
		ft_test("%06.2u", 0, 512);
		ft_test("%06.2u", 0, -512);
		ft_test("%01.2u", 0, 512);
		ft_test("%01.2u", 0, -512);
		ft_test("%06.8u", 0, 512);
		ft_test("%06.8u", 0, -512);
		ft_test("%01.8u", 0, 512);
		ft_test("%01.8u", 0, -512);
		ft_test("%0.2u", 0, 512);
		ft_test("%0.2u", 0, -512);
		ft_test("%0.8u", 0, 512);
		ft_test("%0.8u", 0, -512);
	}

	if (o[0] || o[1])
	{
		printf("\033[36m1 - CLASSICO\n\033[0m");
		ft_test("%o", 0, 512);
		ft_test("%o", 0, -512);
		ft_test("%6o", 0, 512);
		ft_test("%6o", 0, -512);
		ft_test("%1o", 0, 512);
		ft_test("%1o", 0, -512);
		ft_test("%6.2o", 0, 512);
		ft_test("%6.2o", 0, -512);
		ft_test("%1.2o", 0, 512);
		ft_test("%1.2o", 0, -512);
		ft_test("%6.8o", 0, 512);
		ft_test("%6.8o", 0, -512);
		ft_test("%1.8o", 0, 512);
		ft_test("%1.8o", 0, -512);
		ft_test("%.2o", 0, 512);
		ft_test("%.2o", 0, -512);
		ft_test("%.8o", 0, 512);
		ft_test("%.8o", 0, -512);
	}

	if (o[0] || o[2])
	{
		printf("\033[36m2 - CLASSICO PREFIX\n\033[0m");
		ft_test("%#o", 0, 512);
		ft_test("%#o", 0, -512);
		ft_test("%#6o", 0, 512);
		ft_test("%#6o", 0, -512);
		ft_test("%#1o", 0, 512);
		ft_test("%#1o", 0, -512);
		ft_test("%#6.2o", 0, 512);
		ft_test("%#6.2o", 0, -512);
		ft_test("%#1.2o", 0, 512);
		ft_test("%#1.2o", 0, -512);
		ft_test("%#6.8o", 0, 512);
		ft_test("%#6.8o", 0, -512);
		ft_test("%#1.8o", 0, 512);
		ft_test("%#1.8o", 0, -512);
		ft_test("%#.2o", 0, 512);
		ft_test("%#.2o", 0, -512);
		ft_test("%#.8o", 0, 512);
		ft_test("%#.8o", 0, -512);
	}

	if (o[0] || o[3])
	{
		printf("\033[36m3 - CLASSICO LEFT\n\033[0m");
		ft_test("%-o", 0, 512);
		ft_test("%-o", 0, -512);
		ft_test("%-6o", 0, 512);
		ft_test("%-6o", 0, -512);
		ft_test("%-1o", 0, 512);
		ft_test("%-1o", 0, -512);
		ft_test("%-6.2o", 0, 512);
		ft_test("%-6.2o", 0, -512);
		ft_test("%-1.2o", 0, 512);
		ft_test("%-1.2o", 0, -512);
		ft_test("%-6.8o", 0, 512);
		ft_test("%-6.8o", 0, -512);
		ft_test("%-1.8o", 0, 512);
		ft_test("%-1.8o", 0, -512);
		ft_test("%-.2o", 0, 512);
		ft_test("%-.2o", 0, -512);
		ft_test("%-.8o", 0, 512);
		ft_test("%-.8o", 0, -512);
	}

	if (o[0] || o[4])
	{
		printf("\033[36m4 - CLASSICO PREFIX LEFT\n\033[0m");
		ft_test("%#-o", 0, 512);
		ft_test("%#-o", 0, -512);
		ft_test("%#-6o", 0, 512);
		ft_test("%#-6o", 0, -512);
		ft_test("%#-1o", 0, 512);
		ft_test("%#-1o", 0, -512);
		ft_test("%#-6.2o", 0, 512);
		ft_test("%#-6.2o", 0, -512);
		ft_test("%#-1.2o", 0, 512);
		ft_test("%#-1.2o", 0, -512);
		ft_test("%#-6.8o", 0, 512);
		ft_test("%#-6.8o", 0, -512);
		ft_test("%#-1.8o", 0, 512);
		ft_test("%#-1.8o", 0, -512);
		ft_test("%#-.2o", 0, 512);
		ft_test("%#-.2o", 0, -512);
		ft_test("%#-.8o", 0, 512);
		ft_test("%#-.8o", 0, -512);
	}

	if (o[0] || o[5])
	{
		printf("\033[36m5 - CLASSICO000000\n\033[0m");
		ft_test("%0o", 0, 512);
		ft_test("%0o", 0, -512);
		ft_test("%06o", 0, 512);
		ft_test("%06o", 0, -512);
		ft_test("%01o", 0, 512);
		ft_test("%01o", 0, -512);
		ft_test("%06.2o", 0, 512);
		ft_test("%06.2o", 0, -512);
		ft_test("%01.2o", 0, 512);
		ft_test("%01.2o", 0, -512);
		ft_test("%06.8o", 0, 512);
		ft_test("%06.8o", 0, -512);
		ft_test("%01.8o", 0, 512);
		ft_test("%01.8o", 0, -512);
		ft_test("%0.2o", 0, 512);
		ft_test("%0.2o", 0, -512);
		ft_test("%0.8o", 0, 512);
		ft_test("%0.8o", 0, -512);
	}

	if (o[0] || o[6])
	{
		printf("\033[36m6 - CLASSICO0000000 PREFIX\n\033[0m");
		ft_test("%#0o", 0, 512);
		ft_test("%#0o", 0, -512);
		ft_test("%#06o", 0, 512);
		ft_test("%#06o", 0, -512);
		ft_test("%#01o", 0, 512);
		ft_test("%#01o", 0, -512);
		ft_test("%#06.2o", 0, 512);
		ft_test("%#06.2o", 0, -512);
		ft_test("%#01.2o", 0, 512);
		ft_test("%#01.2o", 0, -512);
		ft_test("%#06.8o", 0, 512);
		ft_test("%#06.8o", 0, -512);
		ft_test("%#01.8o", 0, 512);
		ft_test("%#01.8o", 0, -512);
		ft_test("%#0.2o", 0, 512);
		ft_test("%#0.2o", 0, -512);
		ft_test("%#0.8o", 0, 512);
		ft_test("%#0.8o", 0, -512);
	}

	if (p)
	{
		printf("\033[36m1 - CLASSICO\n\033[0m");
		ft_test("%p", 1, 512);
		ft_test("%p", 1, 512);
		ft_test("%6p", 1, 512);
		ft_test("%6p", 1, 512);
		ft_test("%1p", 1, 512);
		ft_test("%1p", 1, 512);
		ft_test("%-p", 1, 512);
		ft_test("%-p", 1, 512);
		ft_test("%-6p", 1, 512);
		ft_test("%-6p", 1, 512);
		ft_test("%-1p", 1, i);
		ft_test("%-1p", 1, i);
	}

	if (c[0] || c[1])
	{
		printf("\033[36m1 - CLASSICO\n\033[0m");
		ft_test("%c", 0, 's');
		ft_test("%6c", 0, 's');
		ft_test("%1c", 0, 's');
		ft_test("%2c", 0, 's');
		ft_test("%c", 0, 's');
		ft_test("%-c", 0, 's');
		ft_test("%-c", 0, 's');
		ft_test("%-6c", 0, 's');
		ft_test("%-6c", 0, 's');
		ft_test("%-1c", 0, 's');
		ft_test("%-1c", 0, 's');

	}

	if (c[0] || c[2])
	{
		printf("\033[36m2 - CLASSICO MAJ\n\033[0m");
		ft_test("%c", 0, 'S');
		ft_test("%6c", 0, 'S');
		ft_test("%1c", 0, 'S');
		ft_test("%2c", 0, 'S');
		ft_test("%c", 0, 'S');
		ft_test("%-c", 0, 'S');
		ft_test("%-c", 0, 'S');
		ft_test("%-6c", 0, 'S');
		ft_test("%-6c", 0, 'S');
		ft_test("%-1c", 0, 'S');
		ft_test("%-1c", 0, 'S');
	}

	if (c[0] || c[3])
	{
		printf("\033[36m3 - CLASSICO NUMERIK\n\033[0m");
		ft_test("%c", 0, '5');
		ft_test("%6c", 0, '4');
		ft_test("%1c", 0, '3');
		ft_test("%2c", 0, '2');
		ft_test("%c", 0, '1');
		ft_test("%-c", 0, '0');
		ft_test("%-c", 0, '6');
		ft_test("%-6c", 0, '7');
		ft_test("%-6c", 0, '8');
		ft_test("%-1c", 0, '9');
		ft_test("%-1c", 0, '1');
	}

	if (c[0] || c[4])
	{
		printf("\033[36m4 - CLASSICO SYMBOLES\n\033[0m");
		ft_test("%c", 0, ',');
		ft_test("%6c", 0, ' ');
		ft_test("%1c", 0, '	');
		ft_test("%2c", 0, '&');
		ft_test("%c", 0, '[');
		ft_test("%-c", 0, '/');
		ft_test("%-c", 0, '@');
		ft_test("%-6c", 0, '+');
		ft_test("%-6c", 0, '-');
		ft_test("%-1c", 0, '*');
		ft_test("%-1c", 0, '=');
	}

	if (s[0] || s[1])
	{
		printf("\033[36m1 - CLASSICO + CLASSICO JUSTIFY\n\033[0m");
		ft_test("%s", 2, str);
		ft_test("%-s", 2, str);
	}

	if (s[0] || s[2])
	{
		printf("\033[36m2 - CLASSICO FIELD ONLY + JUSTIFY\n\033[0m");
		ft_test("%25s", 2, str);
		ft_test("%17s", 2, str);
		ft_test("%8s", 2, str);
		ft_test("%-25s", 2, str);
		ft_test("%-17s", 2, str);
		ft_test("%-8s", 2, str);

	}

	if (s[0] || s[3])
	{
		printf("\033[36m3 - CLASSICO PREC ONLY + JUSTIFY\n\033[0m");
		ft_test("%.25s", 2, str);
		ft_test("%.17s", 2, str);
		ft_test("%.8s", 2, str);
		ft_test("%-.25s", 2, str);
		ft_test("%-.17s", 2, str);
		ft_test("%-.8s", 2, str);
	}

	if (s[0] || s[4])
	{
		printf("\033[36m4 - CLASSICO FIELD PREC\n\033[0m");
		ft_test("%25.6s", 2, str);
		ft_test("%17.6s", 2, str);
		ft_test("%8.6s", 2, str);
		ft_test("%25.17s", 2, str);
		ft_test("%17.17s", 2, str);
		ft_test("%8.17s", 2, str);
		ft_test("%25.26s", 2, str);
		ft_test("%17.26s", 2, str);
		ft_test("%17.26s", 2, str);
	}

	if (s[0] || s[5])
	{
		printf("\033[36m5 - CLASSICO FIELD PREC JUSTIFY\n\033[0m");
		ft_test("%-25.6s", 2, str);
		ft_test("%-17.6s", 2, str);
		ft_test("%-8.6s", 2, str);
		ft_test("%-25.17s", 2, str);
		ft_test("%-17.17s", 2, str);
		ft_test("%-8.17s", 2, str);
		ft_test("%-25.26s", 2, str);
		ft_test("%-17.26s", 2, str);
		ft_test("%-17.26s", 2, str);
	}

	if (fails)
	{
		printf("Total : \033[31m%d\033[0m/%d\033[31m fails\033[0m\n",
				fails, tests);
	}
	else
	{
		printf("Total : \033[32m%d\033[0m/%d\033[32m fails\033[0m\n",
				fails, tests);
	}
	return (0);
}
