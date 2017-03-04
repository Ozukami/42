/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 04:05:02 by apoisson          #+#    #+#             */
/*   Updated: 2017/03/04 02:34:34 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>

int		main(void)
{
	setlocale(LC_ALL, "");

	/*
	ft_printf("{%.3S}\n",  L"Δικαιοπολις εν αγρω εστιν");
	printf("{%.3S}\n\n",  L"Δικαιοπολις εν αγρω εστιν");

	ft_printf("[%20.12ls]\n", L"ο Δικαιοπολις εν αγρω εστιν");
	printf("[%20.12ls]\n\n", L"ο Δικαιοπολις εν αγρω εστιν");

	ft_printf("[%15.46ls]\n", L"ο Δικαιοπολις εν αγρω εστιν");
	printf("[%15.46ls]\n\n", L"ο Δικαιοπολις εν αγρω εστιν");
	
	ft_printf("[%62.34ls]\n", L"ο Δικαιοπολις εν αγρω εστιν");
	printf("[%62.34ls]\n\n", L"ο Δικαιοπολις εν αγρω εστιν");
	*/

	/*
	printf("{%.1ls}\n", L"𐭂ф");
	printf("{%.2ls}\n", L"𐭂ф");
	printf("{%.3ls}\n", L"𐭂ф");
	printf("{%.4ls}\n", L"𐭂ф");
	printf("{%.5ls}\n", L"𐭂ф");
	printf("{%.6ls}\n", L"𐭂ф");
	printf("{%.7ls}\n", L"𐭂ф");
	printf("{%.8ls}\n", L"𐭂ф");
	printf("{%.20ls}\n\n", L"𐭂ф");

	printf("{%c}\n", L'𐭂');
	ft_printf("{%c}\n", L'𐭂');
	printf("{%C}\n", L'𐭂');
	ft_printf("{%C}\n", L'𐭂');
*/

	/*
	char	c = 160;
	char	*s1;
	int		r;

	s1 = malloc(100);

	r = sprintf(s1, "%C", c);
	printf("[%s] |  r value = {%d}\n", s1, r);

	r = ft_printf("[%C]\n", c);
	printf("{%d}\n", r);
	*/

	/*
	printf("[%d]\n", 2097153);

	r = printf("HE OH [%C]\n", 2097153);
	printf("{%d}\n", r);
	printf("HE OH [%C]\n", -96);
	r = ft_printf("[%C]\n", 2097153);
	printf("{%d}\n", r);
	ft_printf("[%C]\n", -96);
	*/

	/*
	printf("[%05C]\n", 65234);
	ft_printf("[%05C]\n", 65234);

	printf("[%s]\n", ft_lltoa_base(LL(512), 10, 0));
	*/

	/*
	printf("salut [%.2p] %p\n", &a, &z);
	ft_printf("salut [%.2p] %p\n", &a, &z);
	*/

	/*
	int	a = 12;
	int	z = 24;

	ft_printf("salut [%12p] les [%-8.4p] copains\n", &a, &z);
	*/

	/*
	printf("salut [%3.2p] les [%-5.2p] copains\n", &a, &z);
	ft_printf("salut [%3.2p] les [%-5.2p] copains\n", &a, &z);
	*/

	if (0)
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

	if (0)
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

	if (0)
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

	if (0)
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

	if (0)
	{
		ft_printf("Bad delimiter test : {%5k}\n");

		ft_printf("[%010s] [%#04d] [% 0+12x] [% -0+12o] [% -0+12u]\n",
				"Quentin", 23, 23, 23, 23);
		printf("[%010s] [%#04d] [% 0+12x] [% -0+12o] [% -0+12u]\n",
				"Quentin", 23, 23, 23, 23);
	}
	return (0);
}
