/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 04:05:02 by apoisson          #+#    #+#             */
/*   Updated: 2017/03/02 06:41:48 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	if (0)
	{
		printf("{%15.2d}\n", -158);
		printf("{%+-15.2d}\n", 158);
		printf("{%+-15.8d}\n", 158);
		printf("{%-15.8d}\n", 158);
		printf("{%#15.8x}\n\n", 158);

		printf("{% d}\n", -158);
		ft_printf("{% d}\n\n", -158);

		printf("{% 5d}\n", -158);
		ft_printf("{% 5d}\n\n", -158);
	}

	if (0)
	{
		printf("[%12s]\n", "123456789");
		ft_printf("[%12s]\n\n", "123456789");

		printf("[%-12s]\n", "123456789");
		ft_printf("[%-12s]\n\n", "123456789");

		printf("[%12.5s]\n", "123456789");
		ft_printf("[%12.5s]\n\n", "123456789");

		printf("[%-12.5s]\n", "123456789");
		ft_printf("[%-12.5s]\n\n", "123456789");

		printf("[%12.11s]\n", "123456789");
		ft_printf("[%12.11s]\n\n", "123456789");

		printf("[%-12.11s]\n", "123456789");
		ft_printf("[%-12.11s]\n\n", "123456789");

		printf("[%6.5s]\n", "123456789");
		ft_printf("[%6.5s]\n\n", "123456789");

		printf("[%-6.5s]\n", "123456789");
		ft_printf("[%-6.5s]\n\n", "123456789");

		printf("[%.5s]\n", "123456789");
		ft_printf("[%.5s]\n\n", "123456789");

		printf("[%-.5s]\n", "123456789");
		ft_printf("[%-.5s]\n\n", "123456789");
	}

	if (1)
	{
		printf("[%#+12d]\n", 1234);
		ft_printf("[%#+12d]\n\n", 1234);

		printf("[%#+-12d]\n", 1234);
		ft_printf("[%#+-12d]\n\n", 1234);

		printf("[%#+12.5d]\n", 1234);
		ft_printf("[%#+12.5d]\n\n", 1234);

		printf("[%#+-12.5d]\n", 1234);
		ft_printf("[%#+-12.5d]\n\n", 1234);

		printf("[%#+12.11d]\n", 1234);
		ft_printf("[%#+12.11d]\n\n", 1234);

		printf("[%#+-12.11d]\n", 1234);
		ft_printf("[%#+-12.11d]\n\n", 1234);

		printf("[%#+6.5d]\n", 1234);
		ft_printf("[%#+6.5d]\n\n", 1234);

		printf("[%#+-6.5d]\n", 1234);
		ft_printf("[%#+-6.5d]\n\n", 1234);

		printf("[%#+.5d]\n", 1234);
		ft_printf("[%#+.5d]\n\n", 1234);

		printf("[%#+-.5d]\n", 1234);
		ft_printf("[%#+-.5d]\n\n", 1234);
	}

	if (0)
	{
		ft_printf("Bad delimiter test : {%5k}\n");

		ft_printf("Bonjour [%s], moi j'ai [%d] ans !\n",
				"Quentin", 23);
		ft_printf("Bonjour [%10s], moi j'ai [%04d] ans !\n",
				"Quentin", 23);
	}
	return (0);
}
