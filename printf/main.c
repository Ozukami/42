/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 04:05:02 by apoisson          #+#    #+#             */
/*   Updated: 2017/03/05 23:59:22 by apoisson         ###   ########.fr       */
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

	s = malloc(100);
	s2 = malloc(100);

	r = printf("|%o, %ho, %hho|", -42, -42, -42);
	printf("	(%d)\n", r);
	r = ft_printf("|%o, %ho, %hho|", -42, -42, -42);
	printf("	(%d)\n", r);

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
