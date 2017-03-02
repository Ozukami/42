/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 04:05:02 by apoisson          #+#    #+#             */
/*   Updated: 2017/03/02 08:32:46 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	if (1)
	{
		printf("{% 2.4d} 2 - 4 - 5\n", 13579);
		ft_printf("{% 2.4d} 2 - 4 - 5\n\n", 13579);

		printf("{% -2.4d} 2 - 4 - 5\n", -3579);
		ft_printf("{% -2.4d} 2 - 4 - 5\n\n", -3579);

		printf("{% 2.7d} 2 - 7 - 5\n", 13579);
		ft_printf("{% 2.7d} 2 - 7 - 5\n\n", 13579);

		printf("{% 2.7d} 2 - 7 - 5\n", -3579);
		ft_printf("{% 2.7d} 2 - 7 - 5\n\n", -3579);

		printf("{% 4.2d} 4 - 2 - 5\n", 13579);
		ft_printf("{% 4.2d} 4 - 2 - 5\n\n", 13579);

		printf("{% 4.2d} 4 - 2 - 5\n", -3579);
		ft_printf("{% 4.2d} 4 - 2 - 5\n\n", -3579);

		printf("{% 7.2d} 7 - 2 - 5\n", 13579);
		ft_printf("{% 7.2d} 7 - 2 - 5\n\n", 13579);

		printf("{% 7.2d} 7 - 2 - 5\n", -3579);
		ft_printf("{% 7.2d} 7 - 2 - 5\n\n", -3579);

		printf("{% 10.7d} 10 - 7 - 5\n", 13579);
		ft_printf("{% 10.7d} 10 - 7 - 5\n\n", 13579);

		printf("{% 10.7d} 10 - 7 - 5\n", -3579);
		ft_printf("{% 10.7d} 10 - 7 - 5\n\n", -3579);

		printf("{% 7.10d} 7 - 10 - 5\n", 13579);
		ft_printf("{% 7.10d} 7 - 10 - 5\n\n", 13579);

		printf("{% 7.10d} 7 - 10 - 5\n", -3579);
		ft_printf("{% 7.10d} 7 - 10 - 5\n\n", -3579);

		printf("{% -10.4d} 10 - 4 - 5\n", -3579);
		ft_printf("{% -10.4d} 10 - 4 - 5\n\n", -3579);
	}

	if (1)
	{
		printf("{%d}\n", -158);
		ft_printf("{%d}\n\n", -158);

		printf("{%2d}\n", -158);
		ft_printf("{%2d}\n\n", -158);

		printf("{%6d}\n", -158);
		ft_printf("{%6d}\n\n", -158);
		printf("{%2.3d}\n", -158);
		ft_printf("{%2.3d}\n\n", -158);

		printf("{%6.2d}\n", -158);
		ft_printf("{%6.2d}\n\n", -158);

		printf("{%2.8d}\n", -158);
		ft_printf("{%2.8d}\n\n", -158);

		printf("{%6.8d}\n", -158);
		ft_printf("{%6.8d}\n\n", -158);

		printf("{% 15.2d}\n", -158);
		ft_printf("{% 15.2d}\n\n", -158);

		printf("{% +-15.2d}\n", 158);
		ft_printf("{% +-15.2d}\n\n", 158);

		printf("{% -15.8d} LEFT 15 8 3\n", 158);
		ft_printf("{% -15.8d} LEFT 15 8 3\n\n", 158);

		printf("{% #15.8x}\n", 158);
		ft_printf("{% #15.8x}\n\n", 158);

		printf("{% +-15.8d}\n", 158);
		ft_printf("{% +-15.8d}\n\n", 158);

		printf("{% d}\n", -158);
		ft_printf("{% d}\n\n", -158);

		printf("{% 7d}\n", -158);
		ft_printf("{% 7d}\n\n", -158);
	}

	if (1)
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
		printf("[%#+12d]\n", -123);
		ft_printf("[%#+12d]\n\n", -123);

		printf("[%#+-12d]\n", -123);
		ft_printf("[%#+-12d]\n\n", -123);

		printf("[%#+12.5d]\n", -123);
		ft_printf("[%#+12.5d]\n\n", -123);

		printf("[%#+-12.5d]\n", -123);
		ft_printf("[%#+-12.5d]\n\n", -123);

		printf("[%#+12.11d]\n", -123);
		ft_printf("[%#+12.11d]\n\n", -123);

		printf("[%#+-12.11d]\n", -123);
		ft_printf("[%#+-12.11d]\n\n", -123);

		printf("[%#+6.5d]\n", -123);
		ft_printf("[%#+6.5d]\n\n", -123);

		printf("[%#+-6.5d]\n", -123);
		ft_printf("[%#+-6.5d]\n\n", -123);

		printf("[%#+.5d]\n", -123);
		ft_printf("[%#+.5d]\n\n", -123);

		printf("[%#+-.5d]\n", -123);
		ft_printf("[%#+-.5d]\n\n", -123);
	}

	if (1)
	{
		printf("[%#+12d]\n", 123);
		ft_printf("[%#+12d]\n\n", 123);

		printf("[%#+12d]\n", 123);
		ft_printf("[%#+12d]\n\n", 123);

		printf("[%#+12.5d]\n", 123);
		ft_printf("[%#+12.5d]\n\n", 123);

		printf("[%#+12.5d]\n", 123);
		ft_printf("[%#+12.5d]\n\n", 123);

		printf("[%#+12.11d]\n", 123);
		ft_printf("[%#+12.11d]\n\n", 123);

		printf("[%#+12.11d]\n", 123);
		ft_printf("[%#+12.11d]\n\n", 123);

		printf("[%#+6.5d]\n", 123);
		ft_printf("[%#+6.5d]\n\n", 123);

		printf("[%#+-6.5d]\n", 123);
		ft_printf("[%#+-6.5d]\n\n", 123);

		printf("[%#+.5d]\n", 123);
		ft_printf("[%#+.5d]\n\n", 123);

		printf("[%#+-.5d]\n", 123);
		ft_printf("[%#+-.5d]\n\n", 123);
	}

	if (1)
	{
		ft_printf("Bad delimiter test : {%5k}\n");

		ft_printf("Bonjour [%s], moi j'ai [%d] ans !\n",
				"Quentin", 23);
		ft_printf("[%10s] [%04d] [% -0+12x] [% -0+12o] [% -0+12u]\n",
				"Quentin", 23, 23, 23, 23);
		printf("[%10s] [%04d] [% -0+12x] [% -0+12o] [% -0+12u]\n",
				"Quentin", 23, 23, 23, 23);
	}
	return (0);
}
