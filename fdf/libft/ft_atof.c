/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 07:13:55 by apoisson          #+#    #+#             */
/*   Updated: 2017/02/11 10:14:15 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>
#include <stdio.h>

int		debug = 0;

int		ft_is_hex(char *str)
{
	int		i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i])
		if (str[i] == '0' && str[i + 1] == 'x')
			return (1);
	return (0);
}

int		ft_nb_digits(int nb, int base)
{
	if (nb > -base && nb <= -1)
		return (2);
	if (nb >= 0 && nb < base)
		return (1);
	if (nb < -base)
		return (2 + ft_nb_digits(-nb / base, base));
	return (1 + ft_nb_digits(nb / base, base));
}

double	ft_atof(const char *str)
{
	double	rep;
	char	**split;
	int		i;
	int		hex[2];

	if (debug)
		printf("\n	PART 1 : spliting if ',' or '.'\n\n");

	rep = 0;
	split = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ',' || str[i] == '.')
		{
			split = ft_strsplit(str, str[i]);

			if (debug)
			{
				printf("Found separator : '%c'", str[i]);
				printf(" >> spliting\n");
				printf("	OK\n");
				i = -1;
				while (split[++i])
					printf("	> split[%d] : %s\n", i, split[i]);
			}

			break ;
		}
		i++;
	}

	if (debug)
	{
		if (!split)
			printf("Nothing to split\n");
		printf("\n	PART 2 : init base \n\n");
	}

	hex[0] = ft_is_hex((char *)str);
	if (!split)
	{

		if (debug)
		{
			printf("%s (base = %d)\n", str, 10 + (hex[0] * 6));
			printf("	> rep = %f\n", (double)ft_atoi_base(str + (hex[0] * 2),
						10 + (hex[0] * 6)));
			printf("\nValue returned\n\n");
		}

		return ((double)ft_atoi_base(str + (hex[0] * 2), 10 + (hex[0] * 6)));
	}

	if (split[1])
		hex[1] = ((split[1][0] == '0' && split[1][1] == 'x') ? 1 : 0);

	if (debug)
		printf("hex[0] = %d, hex[1] = %d\n", hex[0], hex[1]);

	i = 0;
	while (split[i])
		i++;
	if (i < 2)
		return (ft_atoi_base(split[0], ((hex[0]) ? 16 : 10)));

	if (debug)
	{
		printf("\n	PART 3 : converting both parts\n\n");
		printf("Split[0] : %s (base = %d)\n", split[0], 10 + (hex[0] * 6));
	}

	rep += ft_atoi_base(split[0] + (hex[0] * 2), 10 + (hex[0] * 6));

	if (debug)
	{
		printf("	> rep + %d = %f\n", ft_atoi_base(split[0] + (hex[0] * 2),
					10 + (hex[0] * 6)), rep);
		printf("Split[1] : %s (base = %d)\n", split[1], 10 + (hex[1] * 6));
	}

	int tmp = (ft_atoi_base(split[1], 10 + (hex[1] * 6)));

	/*
	printf("%d\n", tmp);
	printf("%d\n", (1 / (double)tmp));
	printf("%f\n", 1 / tmp);
	*/

	if (debug)
	{
		printf("%d : %d\n", tmp, ft_nb_digits(tmp, 10 + (hex[1] *6)));
		printf("	> %d\n", (ft_recursive_power(10, ft_nb_digits(tmp, 10 + (hex[1] *6)))));
	}

	double tmp2 = tmp;
	//tmp2 = (double)(1 / tmp2);
	tmp2 = (tmp2 / (ft_recursive_power(10, ft_nb_digits(tmp, 10 + (hex[1] *6)))));
	rep += tmp2;

	if (debug)
	{
		printf("	> rep + %f = %f\n", tmp2, rep);
		printf("\nValue returned\n\n");
	}

	return (rep);
}
