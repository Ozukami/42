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
	if (ac < 2)
		return (0);

	int	k = -1;
	int	a, b, c, d, e, f, g, h, i = 0;
	while (av[1][++k])
	{
		if (av[1][k] == '0')
			a = 1;
		if (av[1][k] == '1')
			b = 1;
		if (av[1][k] == '2')
			c = 1;
		if (av[1][k] == '3')
			d = 1;
		if (av[1][k] == '4')
			e = 1;
		if (av[1][k] == '5')
			f = 1;
		if (av[1][k] == '6')
			g = 1;
		if (av[1][k] == '7')
			h = 1;
		if (av[1][k] == '8')
			i = 1;
	}

	if (a || b)
	{
		printf("\033[36mCLASSICO\n\033[0m");
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

	if (a || c)
	{
		printf("\033[36mCLASSICO AVEC SPACE\n\033[0m");
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

	if (a || d)
	{
		printf("\033[36mCLASSICO LEFT\n\033[0m");
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

	if (a || e)
	{
		printf("\033[36mCLASSICO LEFT SPACE\n\033[0m");
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

	if (a || f)
	{
		printf("\033[36mCLASSICO000000000000000\n\033[0m");
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

	if (a || g)
	{
		printf("\033[36mCLASSICO QUINTE +\n\033[0m");
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

	if (a || h)
	{
		printf("\033[36mCLASSICO000000000000000 +\n\033[0m");
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

	if (a || i)
	{
		printf("\033[36mCLASSICO QUINTE LEFT +\n\033[0m");
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

	printf("Total : %d fails\n", fails);

	/*
	   printf("\nTest 1.1 : %%d\n");
	   ft_printf("{%d}\n", 512);
	   printf("{%d}\n", 512);

	   printf("\nTest 1.2 : %% d\n");
	   ft_printf("{% d}\n", 512);
	   printf("{% d}\n", 512);

	   printf("\nTest 2.1 : %%.2d\n");
	   ft_printf("{%.2d}\n", 512);
	   printf("{%.2d}\n", 512);

	   printf("\nTest 2.2 : %% .2d\n");
	   ft_printf("{% .2d}\n", 512);
	   printf("{% .2d}\n", 512);

	   printf("\nTest 3.1 : %%.5d\n");
	   ft_printf("{%.5d}\n", 512);
	   printf("{%.5d}\n", 512);

	   printf("\nTest 3.2 : %% .5d\n");
	   ft_printf("{% .5d}\n", 512);
	   printf("{% .5d}\n", 512);

	   printf("\nTest 4.1 : %%-.2d\n");
	   ft_printf("{%-.2d}\n", 512);
	   printf("{%-.2d}\n", 512);

	   printf("\nTest 4.2 : %% -.2d\n");
	   ft_printf("{% -.2d}\n", 512);
	   printf("{% -.2d}\n", 512);

	   printf("\nTest 5.1 : %%-.6d\n");
	   ft_printf("{%-.6d}\n", 512);
	   printf("{%-.6d}\n", 512);

	   printf("\nTest 5.2 : %% -.6d\n");
	   ft_printf("{% -.6d}\n", 512);
	   printf("{% -.6d}\n", 512);

	   printf("\nTest 6.1 : %%10.5d\n");
	   ft_printf("{%10.5d}\n", 512);
	   printf("{%10.5d}\n", 512);

	   printf("\nTest 6.2 : %% 10.5d\n");
	   ft_printf("{% 10.5d}\n", 512);
	   printf("{% 10.5d}\n", 512);

	   printf("\nTest 7.1 : %%-10.5d\n");
	   ft_printf("{%-10.5d}\n", 512);
	   printf("{%-10.5d}\n", 512);

	   printf("\nTest 7.2 : %% -10.5d\n");
	   ft_printf("{% -10.5d}\n", 512);
	   printf("{% -10.5d}\n", 512);

	   printf("\nTest 7.1 : %%-10d\n");
	   ft_printf("{%-10d}\n", 512);
	   printf("{%-10d}\n", 512);

	   printf("\nTest 7.2 : %% -10d\n");
	   ft_printf("{% -10d}\n", 512);
	   printf("{% -10d}\n", 512);

	   printf("\nTest 8.1 : %%10.2d\n");
	   ft_printf("{%10.2d}\n", 512);
	   printf("{%10.2d}\n", 512);

	   printf("\nTest 8.2 : %% 10.2d\n");
	   ft_printf("{% 10.2d}\n", 512);
	printf("{% 10.2d}\n", 512);

	printf("\nTest 9.1 : %%-10.2d\n");
	ft_printf("{%-10.2d}\n", 512);
	printf("{%-10.2d}\n", 512);

	printf("\nTest 9.2 : %% -10.2d\n");
	ft_printf("{% -10.2d}\n", 512);
	printf("{% -10.2d}\n", 512);

	printf("\nTest 10.1 : %%10d\n");
	ft_printf("{%10d}\n", 512);
	printf("{%10d}\n", 512);

	printf("\nTest 10.2 : %% 10d\n");
	ft_printf("{% 10d}\n", 512);
	printf("{% 10d}\n", 512);
	*/

	return (0);
}
