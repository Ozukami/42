/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 04:05:02 by apoisson          #+#    #+#             */
/*   Updated: 2017/03/05 23:07:55 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>

int		main(void)
{
	setlocale(LC_ALL, "");
	
	int		r;
	char	*s;

	s = malloc(100);

	printf("%.0p, %.p", 0, 0);
	printf("\n");
	ft_printf("%.0p, %.p", 0, 0);
	printf("\n\n");

	printf("%.5p", 0);
	printf("\n");
	ft_printf("%.5p", 0);
	printf("\n\n");

	/*
	**  SEGV
	*/	

	/*
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
