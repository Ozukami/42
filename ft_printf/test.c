/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumaujea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 06:18:25 by qumaujea          #+#    #+#             */
/*   Updated: 2017/02/02 10:49:16 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>

#define SUCCESS "\033[32mSUCCESS  \033[0m"
#define FAILLURE "\033[31mFAILLURE \033[0m"

int		debug = 1;
int		detail = 1;
int		fails = 0;
int		tests = 0;
int		error = 0;

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
		s2 = ft_sprintf(s, arg);
	}
	else if (type == 1)
	{
		int	arg = va_arg(ap, int);
		sprintf(s1, s, &arg);
		s2 = ft_sprintf(s, &arg);
	}
	else if (type == 2)
	{
		char	*arg = va_arg(ap, char*);
		sprintf(s1, s, arg);
		s2 = ft_sprintf(s, arg);
	}
	if (type == 3)
	{
		long	arg = va_arg(ap, long);
		sprintf(s1, s, arg);
		s2 = ft_sprintf(s, arg);
	}
	if (type == 4)
	{
		short	arg = (short)va_arg(ap, int);
		sprintf(s1, s, arg);
		s2 = ft_sprintf(s, arg);
	}
	if (ft_strcmp(s1, s2))
	{
		printf(FAILLURE);
		printf("Test %d : %s\n", i++, s);
		printf("	s{%s}\n	f{%s}\n", s1, s2);
		fails++;
		error++;
	}
	else
	{
		if (!debug)
		{
			printf(SUCCESS);
			printf("Test %d : %s\n", i++, s);
			if (detail)
				printf("	s{%s}\n	f{%s}\n", s1, s2);
		}
	}
	tests++;
	free(s1);
}

int		main(int ac, char **av)
{
	setlocale(LC_ALL, "");
	int	k = -1;
	int	d[10] = {0};
	int	x[10] = {0};
	int	xmaj[10] = {0};
	int	u[10] = {0};
	int	o[10] = {0};
	int	p = 0;
	int	c[10] = {0};
	int	s[10] = {0};
	int	h[10] = {0};
	int	hh[10] = {0};
	int	l[10] = {0};
	int	ll[10] = {0};
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
		h[0] = 1;
		hh[0] = 1;
		l[0] = 1;
		ll[0] = 1;
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
		else if (av[1][0] == 'h' && av[1][1] == '\0')
			h[0] = 1;
		else if (av[1][0] == 'h' && av[1][1] == 'h')
			hh[0] = 1;
		else if (av[1][0] == 'l' && av[1][1] == '\0')
			l[0] = 1;
		else if (av[1][0] == 'l' && av[1][1] == 'l')
			ll[0] = 1;
	}

	if (d[0] || d[1])
	{
		error = 0;
		error = 0;
		printf("\033[36m{d} 1 - CLASSICO\n\033[0m");
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
		ft_test("%8.6d", 0, 512);
		ft_test("%8.6d", 0, -512);
		ft_test("%8.3d", 0, 52);
		ft_test("%8.3d", 0, -52);
		if (debug && !error)
			printf("\033[33mOK ! :)\n\033[0m");
		if (debug && error)
			printf("\033[31m%d Erreurs\n\033[0m", error);
	}

	if (d[0] || d[2])
	{
		error = 0;
		printf("\033[36m{d} 2 - CLASSICO SPACE\n\033[0m");
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
		ft_test("% 8.6d", 0, 512);
		ft_test("% 8.6d", 0, -512);
		ft_test("% 8.3d", 0, 52);
		ft_test("% 8.3d", 0, -52);
		if (debug && !error)
			printf("\033[33mOK ! :)\n\033[0m");
		if (debug && error)
			printf("\033[31m%d Erreurs\n\033[0m", error);
	}

	if (d[0] || d[3])
	{
		error = 0;
		printf("\033[36m{d} 3 - CLASSICO LEFT\n\033[0m");
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
		ft_test("%-8.6d", 0, 512);
		ft_test("%-8.6d", 0, -512);
		ft_test("%-8.3d", 0, 52);
		ft_test("%-8.3d", 0, -52);
		if (debug && !error)
			printf("\033[33mOK ! :)\n\033[0m");
		if (debug && error)
			printf("\033[31m%d Erreurs\n\033[0m", error);
	}

	if (d[0] || d[4])
	{
		error = 0;
		printf("\033[36m{d} 4 - CLASSICO LEFT SPACE\n\033[0m");
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
		ft_test("% -8.6d", 0, 512);
		ft_test("% -8.6d", 0, -512);
		ft_test("% -8.3d", 0, 52);
		ft_test("% -8.3d", 0, -52);
		if (debug && !error)
			printf("\033[33mOK ! :)\n\033[0m");
		if (debug && error)
			printf("\033[31m%d Erreurs\n\033[0m", error);
	}

	if (d[0] || d[5])
	{
		error = 0;
		printf("\033[36m{d} 5 - CLASSICO0000000000\n\033[0m");
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
		ft_test("%08.6d", 0, 512);
		ft_test("%08.6d", 0, -512);
		ft_test("%08.3d", 0, 52);
		ft_test("%08.3d", 0, -52);
		if (debug && !error)
			printf("\033[33mOK ! :)\n\033[0m");
		if (debug && error)
			printf("\033[31m%d Erreurs\n\033[0m", error);
	}

	if (d[0] || d[6])
	{
		error = 0;
		printf("\033[36m{d} 6 - CLASSICO QUINTE +\n\033[0m");
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
		ft_test("%+8.6d", 0, 512);
		ft_test("%+8.6d", 0, -512);
		ft_test("%+8.3d", 0, 52);
		ft_test("%+8.3d", 0, -52);
		if (debug && !error)
			printf("\033[33mOK ! :)\n\033[0m");
		if (debug && error)
			printf("\033[31m%d Erreurs\n\033[0m", error);
	}

	if (d[0] || d[7])
	{
		error = 0;
		printf("\033[36m{d} 7 - CLASSICO0000000000 +\n\033[0m");
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
		ft_test("%+08.6d", 0, 512);
		ft_test("%+08.6d", 0, -512);
		ft_test("%+08.3d", 0, 52);
		ft_test("%+08.3d", 0, -52);
		if (debug && !error)
			printf("\033[33mOK ! :)\n\033[0m");
		if (debug && error)
			printf("\033[31m%d Erreurs\n\033[0m", error);
	}

	if (d[0] || d[8])
	{
		error = 0;
		printf("\033[36m{d} 8 - CLASSICO QUINTE LEFT +\n\033[0m");
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
		ft_test("%+-8.6d", 0, 512);
		ft_test("%+-8.6d", 0, -512);
		ft_test("%+-8.3d", 0, 52);
		ft_test("%+-8.3d", 0, -52);
		if (debug && !error)
			printf("\033[33mOK ! :)\n\033[0m");
		if (debug && error)
			printf("\033[31m%d Erreurs\n\033[0m", error);
	}

	if (x[0] || x[1])
	{
		error = 0;
		printf("\033[36m{x} 1 - CLASSICO\n\033[0m");
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
		ft_test("%8.6x", 0, 512);
		ft_test("%8.6x", 0, -512);
		ft_test("%8.3x", 0, 52);
		ft_test("%8.3x", 0, -52);
		if (debug && !error)
			printf("\033[33mOK ! :)\n\033[0m");
		if (debug && error)
			printf("\033[31m%d Erreurs\n\033[0m", error);
	}

	if (x[0] || x[2])
	{
		error = 0;
		printf("\033[36m{x} 2 - CLASSICO PREFIX\n\033[0m");
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
		ft_test("%#8.6x", 0, 512);
		ft_test("%#8.6x", 0, -512);
		ft_test("%#8.3x", 0, 52);
		ft_test("%#8.3x", 0, -52);
		if (debug && !error)
			printf("\033[33mOK ! :)\n\033[0m");
		if (debug && error)
			printf("\033[31m%d Erreurs\n\033[0m", error);
	}

	if (x[0] || x[3])
	{
		error = 0;
		printf("\033[36m{x} 3 - CLASSICO LEFT\n\033[0m");
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
		ft_test("%-8.6x", 0, 512);
		ft_test("%-8.6x", 0, -512);
		ft_test("%-8.3x", 0, 52);
		ft_test("%-8.3x", 0, -52);
		if (debug && !error)
			printf("\033[33mOK ! :)\n\033[0m");
		if (debug && error)
			printf("\033[31m%d Erreurs\n\033[0m", error);
	}

	if (x[0] || x[4])
	{
		error = 0;
		printf("\033[36m{x} 4 - CLASSICO PREFIX LEFT\n\033[0m");
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
		ft_test("%#-8.6x", 0, 512);
		ft_test("%#-8.6x", 0, -512);
		ft_test("%#-8.3x", 0, 52);
		ft_test("%#-8.3x", 0, -52);
		if (debug && !error)
			printf("\033[33mOK ! :)\n\033[0m");
		if (debug && error)
			printf("\033[31m%d Erreurs\n\033[0m", error);
	}

	if (x[0] || x[5])
	{
		error = 0;
		printf("\033[36m{x} 5 - CLASSICO000000\n\033[0m");
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
		ft_test("%08.6x", 0, 512);
		ft_test("%08.6x", 0, -512);
		ft_test("%08.3x", 0, 52);
		ft_test("%08.3x", 0, -52);
		if (debug && !error)
			printf("\033[33mOK ! :)\n\033[0m");
		if (debug && error)
			printf("\033[31m%d Erreurs\n\033[0m", error);
	}

	if (x[0] || x[6])
	{
		error = 0;
		printf("\033[36m{x} 6 - CLASSICO0000000 PREFIX\n\033[0m");
		ft_test("%#0x", 0, 512);
		ft_test("%#0x", 0, -512);
		ft_test("%#08x", 0, 512);
		ft_test("%#08x", 0, -512);
		ft_test("%#06x", 0, 512);
		ft_test("%#06x", 0, -512);
		ft_test("%#06x", 0, 51);
		ft_test("%#06x", 0, -51);
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
		ft_test("%#08.6x", 0, 512);
		ft_test("%#08.6x", 0, -512);
		ft_test("%#08.3x", 0, 52);
		ft_test("%#08.3x", 0, -52);
		if (debug && !error)
			printf("\033[33mOK ! :)\n\033[0m");
		if (debug && error)
			printf("\033[31m%d Erreurs\n\033[0m", error);
	}

	if (xmaj[0] || xmaj[1])
	{
		error = 0;
		printf("\033[36m{X} 1 - CLASSICO\n\033[0m");
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
		ft_test("%8.6X", 0, 512);
		ft_test("%8.6X", 0, -512);
		ft_test("%8.3X", 0, 52);
		ft_test("%8.3X", 0, -52);
		if (debug && !error)
			printf("\033[33mOK ! :)\n\033[0m");
		if (debug && error)
			printf("\033[31m%d Erreurs\n\033[0m", error);
	}

	if (xmaj[0] || xmaj[2])
	{
		error = 0;
		printf("\033[36m{X} 2 - CLASSICO PREFIX\n\033[0m");
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
		ft_test("%#8.6X", 0, 512);
		ft_test("%#8.6X", 0, -512);
		ft_test("%#8.3X", 0, 52);
		ft_test("%#8.3X", 0, -52);
		if (debug && !error)
			printf("\033[33mOK ! :)\n\033[0m");
		if (debug && error)
			printf("\033[31m%d Erreurs\n\033[0m", error);
	}

	if (xmaj[0] || xmaj[3])
	{
		error = 0;
		printf("\033[36m{X} 3 - CLASSICO LEFT\n\033[0m");
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
		ft_test("%-8.6X", 0, 512);
		ft_test("%-8.6X", 0, -512);
		ft_test("%-8.3X", 0, 52);
		ft_test("%-8.3X", 0, -52);
		if (debug && !error)
			printf("\033[33mOK ! :)\n\033[0m");
		if (debug && error)
			printf("\033[31m%d Erreurs\n\033[0m", error);
	}

	if (xmaj[0] || xmaj[4])
	{
		error = 0;
		printf("\033[36m{X} 4 - CLASSICO PREFIX LEFT\n\033[0m");
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
		ft_test("%#-8.6X", 0, 512);
		ft_test("%#-8.6X", 0, -512);
		ft_test("%#-8.3X", 0, 52);
		ft_test("%#-8.3X", 0, -52);
		if (debug && !error)
			printf("\033[33mOK ! :)\n\033[0m");
		if (debug && error)
			printf("\033[31m%d Erreurs\n\033[0m", error);
	}

	if (xmaj[0] || xmaj[5])
	{
		error = 0;
		printf("\033[36m{X} 5 - CLASSICO000000\n\033[0m");
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
		ft_test("%08.6X", 0, 512);
		ft_test("%08.6X", 0, -512);
		ft_test("%08.3X", 0, 52);
		ft_test("%08.3X", 0, -52);
		if (debug && !error)
			printf("\033[33mOK ! :)\n\033[0m");
		if (debug && error)
			printf("\033[31m%d Erreurs\n\033[0m", error);
	}

	if (xmaj[0] || xmaj[6])
	{
		error = 0;
		printf("\033[36m{X} 6 - CLASSICO0000000 PREFIX\n\033[0m");
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
		ft_test("%#08.6X", 0, 512);
		ft_test("%#08.6X", 0, -512);
		ft_test("%#08.3X", 0, 52);
		ft_test("%#08.3X", 0, -52);
		if (debug && !error)
			printf("\033[33mOK ! :)\n\033[0m");
		if (debug && error)
			printf("\033[31m%d Erreurs\n\033[0m", error);
	}

	if (u[0] || u[1])
	{
		error = 0;
		printf("\033[36m{u} 1 - CLASSICO\n\033[0m");
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
		ft_test("%8.6u", 0, 512);
		ft_test("%8.6u", 0, -512);
		ft_test("%8.3u", 0, 52);
		ft_test("%8.3u", 0, -52);
		if (debug && !error)
			printf("\033[33mOK ! :)\n\033[0m");
		if (debug && error)
			printf("\033[31m%d Erreurs\n\033[0m", error);
	}

	if (u[0] || u[2])
	{
		error = 0;
		printf("\033[36m{u} 2 - CLASSICO LEFT\n\033[0m");
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
		ft_test("%-8.6u", 0, 512);
		ft_test("%-8.6u", 0, -512);
		ft_test("%-8.3u", 0, 52);
		ft_test("%-8.3u", 0, -52);
		if (debug && !error)
			printf("\033[33mOK ! :)\n\033[0m");
		if (debug && error)
			printf("\033[31m%d Erreurs\n\033[0m", error);
	}

	if (u[0] || u[3])
	{
		error = 0;
		printf("\033[36m{u} 3 - CLASSICO000000\n\033[0m");
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
		ft_test("%08.6u", 0, 512);
		ft_test("%08.6u", 0, -512);
		ft_test("%08.3u", 0, 52);
		ft_test("%08.3u", 0, -52);
		if (debug && !error)
			printf("\033[33mOK ! :)\n\033[0m");
		if (debug && error)
			printf("\033[31m%d Erreurs\n\033[0m", error);
	}

	if (o[0] || o[1])
	{
		error = 0;
		printf("\033[36m{o} 1 - CLASSICO\n\033[0m");
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
		ft_test("%8.6o", 0, 512);
		ft_test("%8.6o", 0, -512);
		ft_test("%8.3o", 0, 52);
		ft_test("%8.3o", 0, -52);
		if (debug && !error)
			printf("\033[33mOK ! :)\n\033[0m");
		if (debug && error)
			printf("\033[31m%d Erreurs\n\033[0m", error);
	}

	if (o[0] || o[2])
	{
		error = 0;
		printf("\033[36m{o} 2 - CLASSICO PREFIX\n\033[0m");
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
		ft_test("%#8.6o", 0, 512);
		ft_test("%#8.6o", 0, -512);
		ft_test("%#8.3o", 0, 52);
		ft_test("%#8.3o", 0, -52);
		if (debug && !error)
			printf("\033[33mOK ! :)\n\033[0m");
		if (debug && error)
			printf("\033[31m%d Erreurs\n\033[0m", error);
	}

	if (o[0] || o[3])
	{
		error = 0;
		printf("\033[36m{o} 3 - CLASSICO LEFT\n\033[0m");
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
		ft_test("%-8.6o", 0, 512);
		ft_test("%-8.6o", 0, -512);
		ft_test("%-8.3o", 0, 52);
		ft_test("%-8.3o", 0, -52);
		if (debug && !error)
			printf("\033[33mOK ! :)\n\033[0m");
		if (debug && error)
			printf("\033[31m%d Erreurs\n\033[0m", error);
	}

	if (o[0] || o[4])
	{
		error = 0;
		printf("\033[36m{o} 4 - CLASSICO PREFIX LEFT\n\033[0m");
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
		ft_test("%#-8.6o", 0, 512);
		ft_test("%#-8.6o", 0, -512);
		ft_test("%#-8.3o", 0, 52);
		ft_test("%#-8.3o", 0, -52);
		if (debug && !error)
			printf("\033[33mOK ! :)\n\033[0m");
		if (debug && error)
			printf("\033[31m%d Erreurs\n\033[0m", error);
	}

	if (o[0] || o[5])
	{
		error = 0;
		printf("\033[36m{o} 5 - CLASSICO000000\n\033[0m");
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
		ft_test("%08.6o", 0, 512);
		ft_test("%08.6o", 0, -512);
		ft_test("%08.3o", 0, 52);
		ft_test("%08.3o", 0, -52);
		if (debug && !error)
			printf("\033[33mOK ! :)\n\033[0m");
		if (debug && error)
			printf("\033[31m%d Erreurs\n\033[0m", error);
	}

	if (o[0] || o[6])
	{
		error = 0;
		printf("\033[36m{o} 6 - CLASSICO0000000 PREFIX\n\033[0m");
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
		ft_test("%#08.6o", 0, 512);
		ft_test("%#08.6o", 0, -512);
		ft_test("%#08.3o", 0, 52);
		ft_test("%#08.3o", 0, -52);
		if (debug && !error)
			printf("\033[33mOK ! :)\n\033[0m");
		if (debug && error)
			printf("\033[31m%d Erreurs\n\033[0m", error);
	}

	if (p)
	{
		error = 0;
		printf("\033[36m{p} 1 - CLASSICO\n\033[0m");
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
		if (debug && !error)
			printf("\033[33mOK ! :)\n\033[0m");
		if (debug && error)
			printf("\033[31m%d Erreurs\n\033[0m", error);
	}

	if (c[0] || c[1])
	{
		error = 0;
		printf("\033[36m{c} 1 - CLASSICO\n\033[0m");
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
		if (debug && !error)
			printf("\033[33mOK ! :)\n\033[0m");
		if (debug && error)
			printf("\033[31m%d Erreurs\n\033[0m", error);
	}

	if (c[0] || c[2])
	{
		error = 0;
		printf("\033[36m{c} 2 - CLASSICO MAJ\n\033[0m");
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
		if (debug && !error)
			printf("\033[33mOK ! :)\n\033[0m");
		if (debug && error)
			printf("\033[31m%d Erreurs\n\033[0m", error);
	}

	if (c[0] || c[3])
	{
		error = 0;
		printf("\033[36m{c} 3 - CLASSICO NUMERIK\n\033[0m");
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
		if (debug && !error)
			printf("\033[33mOK ! :)\n\033[0m");
		if (debug && error)
			printf("\033[31m%d Erreurs\n\033[0m", error);
	}

	if (c[0] || c[4])
	{
		error = 0;
		printf("\033[36m{c} 4 - CLASSICO SYMBOLES\n\033[0m");
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
		if (debug && !error)
			printf("\033[33mOK ! :)\n\033[0m");
		if (debug && error)
			printf("\033[31m%d Erreurs\n\033[0m", error);
	}

	if (s[0] || s[1])
	{
		error = 0;
		printf("\033[36m{s} 1 - CLASSICO + CLASSICO JUSTIFY\n\033[0m");
		ft_test("%s", 2, str);
		ft_test("%-s", 2, str);
		if (debug && !error)
			printf("\033[33mOK ! :)\n\033[0m");
		if (debug && error)
			printf("\033[31m%d Erreurs\n\033[0m", error);
	}

	if (s[0] || s[2])
	{
		error = 0;
		printf("\033[36m{s} 2 - CLASSICO FIELD ONLY + JUSTIFY\n\033[0m");
		ft_test("%25s", 2, str);
		ft_test("%17s", 2, str);
		ft_test("%8s", 2, str);
		ft_test("%-25s", 2, str);
		ft_test("%-17s", 2, str);
		ft_test("%-8s", 2, str);
		if (debug && !error)
			printf("\033[33mOK ! :)\n\033[0m");
		if (debug && error)
			printf("\033[31m%d Erreurs\n\033[0m", error);
	}

	if (s[0] || s[3])
	{
		error = 0;
		printf("\033[36m{s} 3 - CLASSICO PREC ONLY + JUSTIFY\n\033[0m");
		ft_test("%.25s", 2, str);
		ft_test("%.17s", 2, str);
		ft_test("%.8s", 2, str);
		ft_test("%-.25s", 2, str);
		ft_test("%-.17s", 2, str);
		ft_test("%-.8s", 2, str);
		if (debug && !error)
			printf("\033[33mOK ! :)\n\033[0m");
		if (debug && error)
			printf("\033[31m%d Erreurs\n\033[0m", error);
	}

	if (s[0] || s[4])
	{
		error = 0;
		printf("\033[36m{s} 4 - CLASSICO FIELD PREC\n\033[0m");
		ft_test("%25.6s", 2, str);
		ft_test("%17.6s", 2, str);
		ft_test("%8.6s", 2, str);
		ft_test("%25.17s", 2, str);
		ft_test("%17.17s", 2, str);
		ft_test("%8.17s", 2, str);
		ft_test("%25.26s", 2, str);
		ft_test("%17.26s", 2, str);
		ft_test("%17.26s", 2, str);
		if (debug && !error)
			printf("\033[33mOK ! :)\n\033[0m");
		if (debug && error)
			printf("\033[31m%d Erreurs\n\033[0m", error);
	}

	if (s[0] || s[5])
	{
		error = 0;
		printf("\033[36m{s} 5 - CLASSICO FIELD PREC JUSTIFY\n\033[0m");
		ft_test("%-25.6s", 2, str);
		ft_test("%-17.6s", 2, str);
		ft_test("%-8.6s", 2, str);
		ft_test("%-25.17s", 2, str);
		ft_test("%-17.17s", 2, str);
		ft_test("%-8.17s", 2, str);
		ft_test("%-25.26s", 2, str);
		ft_test("%-17.26s", 2, str);
		ft_test("%-17.26s", 2, str);
		if (debug && !error)
			printf("\033[33mOK ! :)\n\033[0m");
		if (debug && error)
			printf("\033[31m%d Erreurs\n\033[0m", error);
	}

	if (hh[0])
	{
		error = 0;
		char my_c1 = 'a';
		char my_c2 = 130;

		printf("\033[36m{hhd} 1 - SOME TESTS\n\033[0m");
		ft_test("%hhd", 0, 12);
		ft_test("%hhd", 0, my_c1);
		ft_test("%hhd", 0, my_c2);
		ft_test("%8.3hhd", 0, 12);
		ft_test("%8.3hhd", 0, my_c1);
		ft_test("%8.3hhd", 0, my_c2);
		ft_test("%8.3c", 0, 12);
		ft_test("%8.3c", 0, my_c1);
		ft_test("%8.3c", 0, my_c2);
		if (debug && !error)
			printf("\033[33mOK ! :)\n\033[0m");
		if (debug && error)
			printf("\033[31m%d Erreurs\n\033[0m", error);
	}

	if (l[0])
	{
		printf("\033[36m{ld} 1 - SOME TESTS\n\033[0m");
		ft_test("%ld", 3, (long)(INT_MAX) + 10);
		ft_test("%ld", 3, -512);
		ft_test("%lo", 3, (long)(INT_MAX) + 10);
		ft_test("%lo", 3, -512);
		ft_test("%lu", 3, (long)(INT_MAX) + 10);
		ft_test("%lu", 3, -512);
		ft_test("%lx", 3, (long)(INT_MAX) + 10);
		ft_test("%lx", 3, -512);
		if (debug && !error)
			printf("\033[33mOK ! :)\n\033[0m");
		if (debug && error)
			printf("\033[31m%d Erreurs\n\033[0m", error);
	}

	if (ll[0])
	{
		printf("\033[36m{lld} 1 - SOME TESTS\n\033[0m");
		ft_test("%lld", 3, (long long)(INT_MAX) + 10);
		ft_test("%lld", 3, -512);
		ft_test("%llo", 3, (long long)(INT_MAX) + 10);
		ft_test("%llo", 3, -512);
		ft_test("%llu", 3, (long long)(INT_MAX) + 10);
		ft_test("%llu", 3, -512);
		ft_test("%llx", 3, (long long)(INT_MAX) + 10);
		ft_test("%llx", 3, -512);
		if (debug && !error)
			printf("\033[33mOK ! :)\n\033[0m");
		if (debug && error)
			printf("\033[31m%d Erreurs\n\033[0m", error);
	}

	if (h[0])
	{
		printf("\033[36m{hd} 1 - SOME TESTS\n\033[0m");
		ft_test("%hd", 4, (short)(INT_MAX) + 10);
		ft_test("%hd", 4, -512);
		ft_test("%hd", 4, 52);
		ft_test("%hu", 4, (short)(INT_MAX) + 10);
		ft_test("%hu", 4, -512);
		ft_test("%hu", 4, 52);
		ft_test("%ho", 4, (short)(INT_MAX) + 10);
		ft_test("%ho", 4, -512);
		ft_test("%ho", 4, 52);
		ft_test("%hx", 4, (short)(INT_MAX) + 10);
		ft_test("%hx", 4, -512);
		ft_test("%hx", 4, 52);
		if (debug && !error)
			printf("\033[33mOK ! :)\n\033[0m");
		if (debug && error)
			printf("\033[31m%d Erreurs\n\033[0m", error);
	}

	if (l[0])
	{
		printf("\033[36m{DOU} 1 - SOME TESTS\n\033[0m");
		ft_test("%D", 0, 512);
		ft_test("%D", 0, -512);
		ft_test("%O", 0, 512);
		ft_test("%O", 0, -512);
		ft_test("%U", 0, 512);
		ft_test("%U", 0, -512);
		if (debug && !error)
			printf("\033[33mOK ! :)\n\033[0m");
		if (debug && error)
			printf("\033[31m%d Erreurs\n\033[0m", error);
	}

	if (l[0])
	{
		ft_test("%jd", 0, (intmax_t)512); 
		ft_test("%ju", 0, (uintmax_t)512); 
		ft_test("%jo", 0, (uintmax_t)512); 
		ft_test("%jx", 0, (uintmax_t)512); 
		ft_test("%jX", 0, (uintmax_t)512); 
		ft_test("%jd", 0, (intmax_t)(-512)); 
		ft_test("%ju", 0, (uintmax_t)-512); 
		ft_test("%jo", 0, (uintmax_t)-512); 
		ft_test("%jx", 0, (uintmax_t)-512); 
		ft_test("%jX", 0, (uintmax_t)-512); 

		ft_test("%zd", 0, (size_t)512); 
		ft_test("%zu", 0, (size_t)512); 
		ft_test("%zo", 0, (size_t)512); 
		ft_test("%zx", 0, (size_t)512); 
		ft_test("%zX", 0, (size_t)512); 
		ft_test("%zd", 0, (size_t)(-512)); 
		ft_test("%zu", 0, (size_t)-512); 
		ft_test("%zo", 0, (size_t)-512); 
		ft_test("%zx", 0, (size_t)-512); 
		ft_test("%zX", 0, (size_t)-512); 
	}

	/*
	   printf("@moulitest: [%#10.5x] [%#10.x] [%#.0x]", 0, 0, 512);
	   printf("\n");
	   printf("@moulitest: [%#1.x] [%#.x] [%#.0x]", 0, 0, 512);
	   printf("\n");
	   printf("@moulitest: [%#.x] [%#x] [%#.0x]", 0, 0, 512);
	   printf("\n\n");
	   */

	/*
	// 0175 (int)
	ft_printf("@moulitest: [%.d] [%.0d]", 0, 0);
	printf("\n");
	printf("@moulitest: [%.d] [%.0d]", 0, 0);
	printf("\n\n");
	*/

	/*
	   printf("TEST: [%0.d] [%0.0d]\n", 0, 0);
	   printf("TEST: [%-.d] [%-.0d]\n", 0, 0);
	   printf("TEST: [%+.d] [%+.0d]\n", 0, 0);
	   printf("TEST: [%0-.d] [%0-.0d]\n", 0, 0);
	   printf("TEST: [% .d] [% .0d]\n", 0, 0);
	   printf("TEST: [% d] [% 0d]\n", 0, 0);
	   printf("TEST: [%d] [%0d]\n", 0, 0);
	   */

	/*
	// 0176 (int)
	ft_printf("@moulitest: [%5.d] [%5.0d]", 0, 0);
	printf("\n");
	printf("@moulitest: [%5.d] [%5.0d]", 0, 0);
	printf("\n\n");
	*/

	/*
	// 0105 (int)
	printf("%d\n", -2147483648);
	ft_printf("%d\n\n", -2147483648);

	// 0106 (int)
	printf("%d\n", -2147483649);
	ft_printf("%d\n\n", -2147483649);

	// 0138 (short)
	printf("%hd\n", -32768);
	ft_printf("%hd\n\n", -32768);

	// 0140 (short)
	printf("%hd\n", -32769);
	ft_printf("%hd\n\n", -32769);
	*/

	/*
	// 0146 (long)
	printf("%ld\n", -2147483648);
	ft_printf("%ld\n\n", -2147483648);

	// 0148 (long)
	printf("%ld\n", -2147483649);
	ft_printf("%ld\n\n", -2147483649);
	*/

	/*
	// 0152 (intmax_t)
	printf("%jd\n", -9223372036854775808);
	ft_printf("%jd\n\n", -9223372036854775808);
	*/

	/*
	// 0155 (ssize_t)
	printf("[%zd]\n", -0);
	ft_printf("[%zd]\n\n", -0);

	// 0156 (ssize_t)
	printf("%zd\n", -1);
	ft_printf("%zd\n\n", -1);
	*/

	// 05
	/*
	   printf("%");
	   printf("% Zoooo");
	   printf("{%}");
	   */

	// 07
	/*
	   printf("%S", L"米");
	   printf("\n");
	   ft_printf("%S", L"米");
	   printf("\n\n");
	   printf("%S", L"我是一只猫。");
	   printf("\n");
	   ft_printf("%S", L"我是一只猫。");
	   printf("\n\n");
	   printf("%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S", L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ", L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L"");
	   printf("\n");
	   ft_printf("%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S", L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ", L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L"");
	   printf("\n\n");
	   printf("a%Sb%sc%S", L"我", "42", L"猫");
	   printf("\n");
	   ft_printf("a%Sb%sc%S", L"我", "42", L"猫");
	   printf("\n\n");
	   */

	// 08
	/*
	   printf("%D", -1L);
	   printf("\n");
	   ft_printf("%D", -1L);
	   printf("\n");
	   ft_printf("%D", -1);
	   printf("\n\n");
	   printf("%D", LONG_MIN);
	   printf("\n");
	   ft_printf("%D", LONG_MIN);
	   printf("\n\n");
	   */

	// 17
	/*
	   assert_printf("%C%C", '4', '2');
	   assert_printf("%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C \
	   %C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C\
	   %C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C",
	   ' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-',
	   '.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';',
	   '<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
	   'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
	   'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e',
	   'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
	   't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}');

	   assert_printf("%C", L'猫');
	   assert_printf("%C", L'δ');
	   assert_printf("%C", L'요');
	   assert_printf("%C", L'莨');
	   assert_printf("%C", L'ي');
	   */

	// 40
	/*
	ft_printf("%ld", (long)INT_MIN - 1);
	   printf("\n");
	printf("%ld", (long)INT_MIN - 1);
	   printf("\n");
	   printf("\n");
	   */
	ft_printf("%ld", LONG_MIN);
	   printf("\n");
	printf("%ld", LONG_MIN);
	   printf("\n");
	   printf("\n");

	ft_printf("%ld", LONG_MIN + 1);
	   printf("\n");
	printf("%ld", LONG_MIN + 1);
	   printf("\n");
	   printf("\n");
	   /*
	ft_printf("%li", (long)INT_MIN - 1);
	   printf("\n");
	printf("%li", (long)INT_MIN - 1);
	   printf("\n");
	   printf("\n");
	   */
	ft_printf("%li", LONG_MIN);
	   printf("\n");
	printf("%li", LONG_MIN);
	   printf("\n");
	   printf("\n");

	// 41
	ft_printf("%llo", ULLONG_MAX);
	   printf("\n");
	printf("%llo", ULLONG_MAX);
	   printf("\n");
	   printf("\n");
	ft_printf("%llx", ULLONG_MAX);
	   printf("\n");
	printf("%llx", ULLONG_MAX);
	   printf("\n");
	   printf("\n");
	ft_printf("%llX", ULLONG_MAX);
	   printf("\n");
	printf("%llX", ULLONG_MAX);
	   printf("\n");
	   printf("\n");

	   /*
	// 43
	ft_printf("%hhd", CHAR_MAX + 42);
	   printf("\n");
	printf("%hhd", CHAR_MAX + 42);
	   printf("\n");
	   printf("\n");
	ft_printf("%hhd", CHAR_MIN - 42);
	   printf("\n");
	printf("%hhd", CHAR_MIN - 42);
	   printf("\n");
	   printf("\n");
	ft_printf("%hhi", CHAR_MAX + 42);
	   printf("\n");
	printf("%hhi", CHAR_MAX + 42);
	   printf("\n");
	   printf("\n");
	ft_printf("%hhi", CHAR_MIN - 42);
	   printf("\n");
	printf("%hhi", CHAR_MIN - 42);
	   printf("\n");
	   printf("\n");
	ft_printf("%hhu", CHAR_MAX + 42);
	   printf("\n");
	printf("%hhu", CHAR_MAX + 42);
	   printf("\n");
	   printf("\n");
	ft_printf("%hho", CHAR_MAX + 42);
	   printf("\n");
	printf("%hho", CHAR_MAX + 42);
	   printf("\n");
	   printf("\n");
	ft_printf("%hhx", CHAR_MAX + 42);
	   printf("\n");
	printf("%hhx", CHAR_MAX + 42);
	   printf("\n");
	   printf("\n");
	ft_printf("%hhX", CHAR_MAX + 42);
	   printf("\n");
	printf("%hhX", CHAR_MAX + 42);
	   printf("\n");
	   printf("\n");
	   */

	   /*
	// 43 bis
	ft_printf("%jd", LLONG_MIN);
	   printf("\n");
	printf("%jd", LLONG_MIN);
	   printf("\n");
	   printf("\n");
	ft_printf("%ji", LLONG_MIN);
	   printf("\n");
	printf("%ji", LLONG_MIN);
	   printf("\n");
	   printf("\n");
	ft_printf("%jo", ULLONG_MAX);
	   printf("\n");
	printf("%jo", ULLONG_MAX);
	   printf("\n");
	   printf("\n");
	   */

	   /*
	// 44
	ft_printf("%zo", ULLONG_MAX);
	   printf("\n");
	printf("%zo", ULLONG_MAX);
	   printf("\n");
	   printf("\n");
	   */

	/*
	// 50
	printf("{%3c}", 0);
	printf("{%-15p}", 0);
	printf("{%-12p}", &k); //SEGFAULT 

	// 52
	printf("{%03c}", 0);
	printf("{%05s}", "abc");

	// 53
	printf("{%-15Z}", 123);

	// 60
	printf("%#o", 42);
	printf("%#o", 0);	
	printf("%#o", INT_MAX); //OCTAL VALEUR DE RETOUR A CHECK
	printf("%#X", 0);
	*/


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
