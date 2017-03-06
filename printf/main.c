/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 04:05:02 by apoisson          #+#    #+#             */
/*   Updated: 2017/03/06 22:36:04 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>

int		main(void)
{
	setlocale(LC_ALL, "");

	int		r;
	char	*s;
	char	*s2;

	r = 0;
	s = malloc(100);
	s2 = malloc(100);

	ft_printf("%s\n", "bonjour");

	/*
	// 0007 
	r = printf("|%-05%|");
	printf("\nr = %d\n", r);
	r = ft_printf("|%-05%|");
	printf("\nr = %d\n\n", r);
	*/

	/*
	// 0014 (char *)
	r = printf("|%%   %|", "test");
	printf("\nr = %d\n", r);
	r = ft_printf("|%%   %|", "test");
	printf("\nr = %d\n", r);
	*/

	/*
	// 0030 (size_t)
	r = printf("%hzd", "4294967296");
	printf("\nr = %d\n", r);
	r = printf("%hd", "4294967296");
	printf("\nr = %d\n", r);
	r = printf("%zd", "4294967296");
	printf("\nr = %d\n", r);
	r = ft_printf("%zhd", "4294967296");
	printf("\nr = %d\n\n", r);

	// 0032 (unsigned long long)
	r = printf("%hjd", "9223372036854775807");
	printf("\nr = %d\n", r);
	r = printf("%hd", "9223372036854775807");
	printf("\nr = %d\n", r);
	r = printf("%jd", "9223372036854775807");
	printf("\nr = %d\n", r);
	r = ft_printf("%jhd", "9223372036854775807");
	printf("\nr = %d\n", r);
	*/

	/*
	   r = printf("% ");
	   printf("\nr = %d\n", r);
	   r = ft_printf("% ");
	   printf("\nr = %d\n", r);
	   */

	/*
	   printf("%lu\n", UCHAR_MAX - 1);
	   ft_printf("%lu\n\n", UCHAR_MAX - 1);

	   printf("%lu\n", UCHAR_MAX);
	   ft_printf("%lu\n\n", UCHAR_MAX);

	   printf("%lu\n", UCHAR_MAX + 1);
	   ft_printf("%lu\n", UCHAR_MAX + 1);
	   */

	/*
	   printf("%s\n", ft_lltoa_base((unsigned char)-42, 8, 0));
	   printf("%s\n\n", ft_ulltoa_base((unsigned char)-42, 8, 0));

	   r = printf("|%o, %ho, %hho|", -42, -42, -42);
	   printf("	(%d)\n", r);
	   r = ft_printf("|%o, %ho, %hho|", -42, -42, -42);
	   printf("	(%d)\n", r);
	   */

	/*
	   r = printf("|%zi|", LLONG_MIN);
	   printf("	(%d)\n", r);
	   r = ft_printf("|%zi|", LLONG_MIN);
	   printf("	(%d)\n", r);
	   */

	/*
	   r = printf("[% 3c] bonjour", 0);
	   printf("	(%d)\n", r);
	   r = ft_printf("[% 3c] bonjour", 0);
	   printf("	(%d)\n\n", r);

	   r = sprintf(s, "[% 3c] bonjour", 0);
	   printf("|%s|	(%d)\n", s, r);
	   r = ft_sprintf(s2, "[% 3c] bonjour", 0);
	   printf("|%s|	(%d)\n", s2, r);
	   */

	/*
	 **  SEGV
	 */	

	/*

	// 50
	r = sprintf(s, "[%3c]\n", 0);
	printf("|%s| %d\n", s, r);
	r = printf("[%3c]\n", 0);
	printf("%d\n", r);
	r = ft_printf("[%3c]\n", 0);
	printf("%d\n", r);

	// 52
	r = sprintf(s, "[%03c]\n", 0);
	printf("|%s| %d\n", s, r);
	r = printf("[%03c]\n", 0);
	printf("%d\n", r);
	r = ft_printf("[%03c]\n", 0);
	printf("%d\n", r);

	// 60
	r = sprintf(s, "[%#o]\n", 0);
	printf("|%s| %d\n", s, r);
	r = printf("[%#o]\n", 0);
	printf("%d\n", r);
	r = ft_printf("[%#o]\n", 0);
	printf("%d\n", r);

	// 62
	r = sprintf(s, "[% c]\n", 0);
	printf("|%s| %d\n", s, r);
	r = printf("[% c]\n", 0);
	printf("%d\n", r);
	r = ft_printf("[% c]\n", 0);
	printf("%d\n", r);

	r = sprintf(s, "[%hhC, %hhC]\n", 0, L'米');
	printf("|%s| %d\n", s, r);
	r = printf("[%hhC, %hhC]\n", 0, L'米');
	printf("%d\n", r);
	r = ft_printf("[%hhC, %hhC]\n", 0, L'米');
	printf("%d\n", r);

	printf("[%hho, %hho]\n", 0, UCHAR_MAX);
	ft_printf("[%lo, %lo]\n\n", 0, ULONG_MAX);
	*/

	/*
	   printf("[%jd]\n", LLONG_MIN);
	   ft_printf("[%jd]\n\n", LLONG_MIN);

	   printf("[%ji]\n", LLONG_MIN);
	   ft_printf("[%ji]\n\n", LLONG_MIN);
	   */

	return (0);
}
