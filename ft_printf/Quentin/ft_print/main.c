/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 23:45:58 by apoisson          #+#    #+#             */
/*   Updated: 2016/12/13 11:22:36 by qumaujea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	int		i;
	//int		number;
	char	*s;

	s = "lolilul";
	i = 512;
//	printf("%5.2d\n", 6);
	if (ac < 1)
	{
		printf("%s", av[0]);
		return (0);
	}
//	printf("  %    #0-+8.3hhd   %  -.5ld   %x %X\n", 30, 512, 255, 255);
	printf("%0-4.6s!\n", s);
	ft_printf("%0-4.6s", s);
	return (0);
}
