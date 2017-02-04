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

int		main(int ac, char **av)
{
	setlocale(LC_ALL, "");
	//int		i;
	//int		number;
	//char	c;

	//c = '8';
	//i = -512;
	//	printf("%-5.2s\n", 6);
	if (ac < 1)
	{
		printf("%-s", av[0]);
		return (0);
	}
	char	*s;

	s = "[%5.2d]";
	printf(s, 512);
	s = "[%-5.3d]";
	printf(s, 512);
	//	printf("  %-    #0-+8.3hhs   %-  -.5ld   %-x %-X\n", 30, 512, 255, 255);
	/*
	   char	*s;
	   printf("[%p]\n", &s);
	   printf("[%#llx]\n", &s);

	   printf("{%-2.4s}[2|4|5]\n", "12345");
	   printf("{%-4.2s}[4|2|5]\n", "12345");
	   printf("{%-3.4s}[3|4|2]\n", "12");
	   printf("{%-4.3s}[4|3|2]\n", "12");
	   printf("{%-10.5s}[10|5|7]\n", "1234567");
	   printf("{%-5.10s}[5|10|7]\n", "1234567");
	   printf("{%-.5s}[0|5|2]\n", "12");
	   printf("{%-.5s}[0|5|6]\n", "123456");
	   printf("{%-5s}[5|-1|2]\n", "12");
	   printf("{%-5s}[5|-1|6]\n", "123456");
	   printf("{%-5.0s}[5|0|2]\n", "12");
	   printf("{%-5.0s}[5|0|6]\n", "123456");
	   printf("{%-5.4s}[5|4|5]\n", "12345");
	   printf("{%-5.5s}[5|5|6]\n", "123456");
	   printf("{%-5.5s}[5|5|4]\n", "1234");
	   printf("{%-5.4s}[5|4|4]\n", "1234");
	   printf("{%-5s}[5|0|5]\n", "12345");
	   printf("{%-.5s}[0|5|5]\n", "12345");

	   printf("\n");

	   ft_printf("{%-2.4s}[2|4|5]\n", "12345");
	   ft_printf("{%-4.2s}[4|2|5]\n", "12345");
	   ft_printf("{%-3.4s}[3|4|2]\n", "12");
	   ft_printf("{%-4.3s}[4|3|2]\n", "12");
	   ft_printf("{%-10.5s}[10|5|7]\n", "1234567");
	   ft_printf("{%-5.10s}[5|10|7]\n", "1234567");
	   ft_printf("{%-.5s}[0|5|2]\n", "12");
	   ft_printf("{%-.5s}[0|5|6]\n", "123456");
	   ft_printf("{%-5s}[5|-1|2]\n", "12");
	   ft_printf("{%-5s}[5|-1|6]\n", "123456");
	   ft_printf("{%-5.0s}[5|0|2]\n", "12");
	   ft_printf("{%-5.0s}[5|0|6]\n", "123456");
	   ft_printf("{%-5.4s}[5|4|5]\n", "12345");
	   ft_printf("{%-5.5s}[5|5|6]\n", "123456");
	   ft_printf("{%-5.5s}[5|5|4]\n", "1234");
	   ft_printf("{%-5.4s}[5|4|4]\n", "1234");
	   ft_printf("{%-5s}[5|0|5]\n", "12345");
	   ft_printf("{%-.5s}[0|5|5]\n", "12345");

	   ft_printf("{%-0.5s}[0|5|5]\n", "12345");

		ft_printf("bonjour %-6s est un %10.2s %d !\n", "ceci", "test", 5);
		ft_printf("START %C%S%D%O%U%D END\n", 't', "est", 1, 1, 1, 1);	
		ft_printf("START %S END\n", "salut");	

	   */

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

	// x
	printf("\nTest 1.1 : %%x\n");
	ft_printf("{%x}\n", 512);
	printf("{%x}\n", 512);

	printf("\nTest 1.2 : %%#x\n");
	ft_printf("{%#x}\n", 512);
	printf("{%#x}\n", 512);

	printf("\nTest 2.1 : %%.2x\n");
	ft_printf("{%.2x}\n", 512);
	printf("{%.2x}\n", 512);

	printf("\nTest 2.2 : %%#.2x\n");
	ft_printf("{%#.2x}\n", 512);
	printf("{%#.2x}\n", 512);

	printf("\nTest 3.1 : %%.5x\n");
	ft_printf("{%.5x}\n", 512);
	printf("{%.5x}\n", 512);

	printf("\nTest 3.2 : %%#.5x\n");
	ft_printf("{%#.5x}\n", 512);
	printf("{%#.5x}\n", 512);

	printf("\nTest 4.1 : %%-.2x\n");
	ft_printf("{%-.2x}\n", 512);
	printf("{%-.2x}\n", 512);

	printf("\nTest 4.2 : %%#-.2x\n");
	ft_printf("{%#-.2x}\n", 512);
	printf("{%#-.2x}\n", 512);

	printf("\nTest 5.1 : %%-.6x\n");
	ft_printf("{%-.6x}\n", 512);
	printf("{%-.6x}\n", 512);

	printf("\nTest 5.2 : %%#-.6x\n");
	ft_printf("{%#-.6x}\n", 512);
	printf("{%#-.6x}\n", 512);

	printf("\nTest 6.1 : %%10.5x\n");
	ft_printf("{%10.5x}\n", 512);
	printf("{%10.5x}\n", 512);

	printf("\nTest 6.2 : %%#10.5x\n");
	ft_printf("{%#10.5x}\n", 512);
	printf("{%#10.5x}\n", 512);

	printf("\nTest 7.1 : %%-10.5x\n");
	ft_printf("{%-10.5x}\n", 512);
	printf("{%-10.5x}\n", 512);

	printf("\nTest 7.2 : %%#-10.5x\n");
	ft_printf("{%#-10.5x}\n", 512);
	printf("{%#-10.5x}\n", 512);

	printf("\nTest 8.1 : %%10.2x\n");
	ft_printf("{%10.2x}\n", 512);
	printf("{%10.2x}\n", 512);

	printf("\nTest 8.2 : %%#10.2x\n");
	ft_printf("{%#10.2x}\n", 512);
	printf("{%#10.2x}\n", 512);

	printf("\nTest 9.1 : %%-10.2x\n");
	ft_printf("{%-10.2x}\n", 512);
	printf("{%-10.2x}\n", 512);

	printf("\nTest 9.2 : %%#-10.2x\n");
	ft_printf("{%#-10.2x}\n", 512);
	printf("{%#-10.2x}\n", 512);

	printf("\nTest 10.1 : %%10x\n");
	ft_printf("{%10x}\n", 512);
	printf("{%10x}\n", 512);

	printf("\nTest 10.2 : %%#10x\n");
	ft_printf("{%#10x}\n", 512);
	printf("{%#10x}\n", 512);
	*/

	/*
	// X
	printf("\nTest 1.1 : %%X\n");
	ft_printf("{%X}\n", 512);
	printf("{%X}\n", 512);

	printf("\nTest 1.2 : %%#X\n");
	ft_printf("{%#X}\n", 512);
	printf("{%#X}\n", 512);

	printf("\nTest 2.1 : %%.2X\n");
	ft_printf("{%.2X}\n", 512);
	printf("{%.2X}\n", 512);

	printf("\nTest 2.2 : %%#.2X\n");
	ft_printf("{%#.2X}\n", 512);
	printf("{%#.2X}\n", 512);

	printf("\nTest 3.1 : %%.5X\n");
	ft_printf("{%.5X}\n", 512);
	printf("{%.5X}\n", 512);

	printf("\nTest 3.2 : %%#.5X\n");
	ft_printf("{%#.5X}\n", 512);
	printf("{%#.5X}\n", 512);

	printf("\nTest 4.1 : %%-.2X\n");
	ft_printf("{%-.2X}\n", 512);
	printf("{%-.2X}\n", 512);

	printf("\nTest 4.2 : %%#-.2X\n");
	ft_printf("{%#-.2X}\n", 512);
	printf("{%#-.2X}\n", 512);

	printf("\nTest 5.1 : %%-.6X\n");
	ft_printf("{%-.6X}\n", 512);
	printf("{%-.6X}\n", 512);

	printf("\nTest 5.2 : %%#-.6X\n");
	ft_printf("{%#-.6X}\n", 512);
	printf("{%#-.6X}\n", 512);

	printf("\nTest 6.1 : %%10.5X\n");
	ft_printf("{%10.5X}\n", 512);
	printf("{%10.5X}\n", 512);

	printf("\nTest 6.2 : %%#10.5X\n");
	ft_printf("{%#10.5X}\n", 512);
	printf("{%#10.5X}\n", 512);

	printf("\nTest 7.1 : %%-10.5X\n");
	ft_printf("{%-10.5X}\n", 512);
	printf("{%-10.5X}\n", 512);

	printf("\nTest 7.2 : %%#-10.5X\n");
	ft_printf("{%#-10.5X}\n", 512);
	printf("{%#-10.5X}\n", 512);
	*/

	printf("\nTest ft_putchar_v2 :\n");
	wchar_t	w;
	w = 65;
	write(1, "[ ", 2);
	ft_putchar_v2(w);
	write(1, " ]\n", 3);
	w = 161;
	write(1, "[ ", 2);
	ft_putchar_v2(w);
	write(1, " ]\n", 3);
	w = 643;
	write(1, "[ ", 2);
	ft_putchar_v2(w);
	write(1, " ]\n", 3);
	w = 4660;
	write(1, "[ ", 2);
	ft_putchar_v2(w);
	write(1, " ]\n", 3);
	w = 65590;
	write(1, "[ ", 2);
	ft_putchar_v2(w);
	write(1, " ]\n", 3);

	printf("\nTest avec printf :\n");
	printf("[%ls]\n", L"¡");
	ft_printf("[%ls]\n", L"¡");

	printf("\nTest c : %%c\n");
	ft_printf("{%3c} {%-3c}\n", 'A', 'B');
	printf("{%3c} {%-3c}\n", 'A', 'B');

	ft_printf("{%.48ls}\n", L"ο Δικαιοπολις εν αγρω εστιν");
	printf("{%.48ls}\n\n", L"ο Δικαιοπολις εν αγρω εστιν");

	ft_printf("{%.47ls}\n", L"ο Δικαιοπολις εν αγρω εστιν");
	printf("{%.47ls}\n\n", L"ο Δικαιοπολις εν αγρω εστιν");

	ft_printf("{%.46ls}\n", L"ο Δικαιοπολις εν αγρω εστιν");
	printf("{%.46ls}\n\n", L"ο Δικαιοπολις εν αγρω εστιν");

	ft_printf("{%.45ls}\n", L"ο Δικαιοπολις εν αγρω εστιν");
	printf("{%.45ls}\n\n", L"ο Δικαιοπολις εν αγρω εστιν");

	ft_printf("{%.44ls}\n", L"ο Δικαιοπολις εν αγρω εστιν");
	printf("{%.44ls}\n\n", L"ο Δικαιοπολις εν αγρω εστιν");

	ft_printf("{%.5ls}\n", L"ο Δικαιοπολις εν αγρω εστιν");
	printf("{%.5ls}\n\n", L"ο Δικαιοπολις εν αγρω εστιν");

	ft_printf("{%.4ls}\n", L"ο Δικαιοπολις εν αγρω εστιν");
	printf("{%.4ls}\n\n", L"ο Δικαιοπολις εν αγρω εστιν");

	ft_printf("[%c]\n", 'c');
	printf("[%c]\n", 'c');
	ft_printf("[%1c]\n", 'c');
	printf("[%1c]\n", 'c');
	ft_printf("[%2c]\n", 'c');
	printf("[%2c]\n", 'c');

	int r1;
	int r2;
	
	r1 = ft_printf("[%-3lc]\n", L'Δ');
	r2 = printf("[%-3lc]\n", L'Δ');
	if (r1 != r2)
		printf("erreur r val (%d|%d)\n", r1, r2);
	
	r1 = ft_printf("[%-5lc]\n", L'Δ');
	r2 = printf("[%-5lc]\n", L'Δ');
	if (r1 != r2)
		printf("erreur r val (%d|%d)\n", r1, r2);
	
	r1 = ft_printf("[%3lc]\n", L'Δ');
	r2 = printf("[%3lc]\n", L'Δ');
	if (r1 != r2)
		printf("erreur r val (%d|%d)\n", r1, r2);
	
	/*
	printf("\n");
	char test = 197;
	write(1, &test, 1);
	test = 164;
	write(1, &test, 1);
	printf("\n");
	*/
	
	return (0);
}
