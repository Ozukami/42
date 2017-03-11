/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 04:05:02 by apoisson          #+#    #+#             */
/*   Updated: 2017/03/11 00:56:11 by qumaujea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>

char	*ft_test(char *s)
{
	return (s);
}

int		main(void)
{
	setlocale(LC_ALL, "");

	int		r = 0;


	printf("{% 03o}\n", 0);
	ft_printf("{% 03o}\n\n", 0);

	printf("{% 03.5o}}\n\n", 0);
	printf("{% 3.5o}\n\n", 0);
	/*
	r = printf("[%.*s]\n", -5, "42");
	printf("{r = %d}\n", r);
	r = ft_printf("[%.*s]\n", -5, "42");
	printf("{r = %d}\n\n", r);
	r = printf("[%*d]\n", -5, 42);
	printf("{r = %d}\n", r);
	r = ft_printf("[%*d]\n", -5, 42);
	printf("{r = %d}\n\n", r);
	r = printf("[%.*c]\n", 0, 0);
	printf("{r = %d}\n", r);
	r = ft_printf("[%.*c]\n", 0, 0);
	printf("{r = %d}\n\n", r);
	r = printf("[%.*c]\n", -15, 0);
	printf("{r = %d}\n", r);
	r = ft_printf("[%.*c]\n", -15, 0);
	printf("{r = %d}\n", r);
*/
	/*
	printf("[%*.*d]\n", 25, 20, 512);
	ft_printf("[%*.*d]\n", 25, 20, 512);
	printf("[%*.8d]\n", 20, 512);
	ft_printf("[%*.8d]\n", 20, 512);
	ft_printf("[%llzjd, %zu]\n", 20, 15);
	printf("[%zjlld, %zu]\n", 20, 15);
	*/
	/*
	ft_printf("%C\n", 15000);
	ft_printf("%C %C %C\n", 15000, 14000, 2500);
	ft_printf("%b\n", -16);
	ft_printf("%lu\n", ULONG_MAX);
	*/	
	//while (1);

	/*
	int		r;
	char	*s;
	char	*s2;

	r = 0;
	s = ft_strdup("Hello");
	s2 = malloc(100);

	s = ft_test(ft_strdup("Coucou"));

	r = printf("[%.*s]\n", -5, "42");
	printf("{r = %d}\n", r);
	r = ft_printf("[%.*s]\n", -5, "42");
	printf("{r = %d}\n\n", r);
	r = printf("[%*d]\n", -5, "42");
	printf("{r = %d}\n", r);
	r = ft_printf("[%*d]\n", -5, "42");
	printf("{r = %d}\n\n", r);
	r = printf("[%.*c]\n", 0, 0);
	printf("{r = %d}\n", r);
	r = ft_printf("[%.*c]\n", 0, 0);
	printf("{r = %d}\n\n", r);
	r = printf("[%.*c]\n", -15, 0);
	printf("{r = %d}\n", r);
	r = ft_printf("[%.*c]\n", -15, 0);
	printf("{r = %d}\n", r);

	/*
	printf("[%*.*d]\n", 25, 20, 512);
	ft_printf("[%*.*d]\n", 25, 20, 512);
	printf("[%*.8d]\n", 20, 512);
	ft_printf("[%*.8d]\n", 20, 512);
	ft_printf("[%llzjd, %zu]\n", 20, 15);
	printf("[%zjlld, %zu]\n", 20, 15);
	*/
	/*
	ft_printf("%C\n", 15000);
	ft_printf("%C %C %C\n", 15000, 14000, 2500);
	ft_printf("%b\n", -16);
	ft_printf("%lu\n", ULONG_MAX);
	*/	
	//while (1);

	/*
	int		r;
	char	*s;
	char	*s2;

	r = 0;
	s = ft_strdup("Hello");
	s2 = malloc(100);

	s = ft_test(ft_strdup("Coucou"));

	while (1);
	*/

	/*
	char	*test;
	char	*ptr;

	test = NULL;
	ptr = NULL;
	printf("test = %p\n", test);
	test = ft_strdup("salut");
	printf("test = %p\n", test);
	printf("ptr = %p\n", ptr);
	ptr = test;
	printf("ptr = %p\n", ptr);
	test = ft_strdup("hello");
	printf("test = %p\n", test);
	printf("test = %s\n", test);
	//free(ptr);
	ft_strdel(&ptr);
	printf("ptr = %p\n", ptr);
	printf("ptr = %s\n", ptr);

	while(1);
	*/

	/*
	ft_printf("|%p|\n", s);
	ft_printf("%d%d%d\n", 512, NULL, 0);
	ft_printf("O%ls%ls\n", L"¶² Ý¥", NULL);
	ft_printf("O%k%%%m\n");
	*/

	/*
	r = printf("|%-05%|");
	printf("\nr = %d\n", r);
	r = ft_printf("|%-05%|");
	printf("\nr = %d\n\n", r);
	*/

	return (0);
}
