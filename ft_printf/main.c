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

int		main(int ac, char **av)
{
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
	   */

	ft_printf("bonjour %-6s est un %10.2s %d !\n", "ceci", "test", 5);
	ft_printf("START %C%S%D%O%U%D END\n", 't', "est", 1, 1, 1, 1);	
	ft_printf("START %S END\n", "salut");	

	printf("\nTest 1 : %%10d\n");
	ft_printf("%10d\n", 512);
	printf("{%10d}\n", 512);

	printf("\nTest 2 : %%10.5d\n");
	ft_printf("%10.5d\n", 512);
	printf("{%10.5d}\n", 512);

	printf("\nTest 3 : %%-10.5d\n");
	ft_printf("%-10.5d\n", 512);
	printf("{%-10.5d}\n", 512);

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

	printf("\nTest c : %%c\n");
	ft_printf(" {%3c} {%-3c} \n", 'A', 'B');
	printf(" {%3c} {%-3c} \n", 'A', 'B');
	return (0);
}
