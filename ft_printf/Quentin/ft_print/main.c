/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 23:45:58 by apoisson          #+#    #+#             */
/*   Updated: 2016/12/14 06:57:53 by qumaujea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	int		i;
	//int		number;
	char	c;

	c = '8';
	i = -512;
//	printf("%5.2d\n", 6);
	if (ac < 1)
	{
		printf("%s", av[0]);
		return (0);
	}
//	printf("  %    #0-+8.3hhd   %  -.5ld   %x %X\n", 30, 512, 255, 255);
	printf("%10.3d\n", i);
	ft_printf("%d", i);
	return (0);
}
