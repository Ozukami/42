/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 23:45:58 by apoisson          #+#    #+#             */
/*   Updated: 2016/12/10 10:07:20 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	int		i;
	//int		number;

	i = 512;
	if (ac < 1)
	{
		printf("%s", av[0]);
		return (0);
	}
	//ft_printf("{%d %s %i %% %S}\n", 5, "Bonjour", 100, L"A");
	//ft_printf("[%p]\n", (void *)&i);
	//printf("[%p]\n", (void *)&i);
	//printf("[%ld]\n", 0x7fff50838b2c);
/*	number = 1024;
	printf(" %+d \n", 0);
	printf(" %10d \n", number);
	printf(" %10.3d \n", 1);
	printf(" %0+5d \n", 1111);
	printf(" %-#10x \n", number);  
	printf(" %#x \n", number);
	printf(" %x \n", number);
	printf("---%*d----\n", 2, number);
*/
	ft_printf("  %    #0-+8.3hhd   %  -.5ld   %x %X", 30, 512, 255, 255);
	return (0);
}
