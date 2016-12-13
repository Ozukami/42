/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 10:48:38 by exam              #+#    #+#             */
/*   Updated: 2016/12/13 12:24:12 by qumaujea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		get_size(long value, long base)
{
	if (value > -base && value <= -1)
		return (2);
	if (value >= 0 && value < base)
		return (1);
	if (value < -base)
		return (2 + get_size(-value / base, base));
	return (1 + get_size(value / base, base));
}

char	*ft_itoa_base(int value, int base)
{
	char	*itoa;
	int		size;
	long	nb;

	nb = (long)value;
	if (nb < 0 && base != 10)
		nb = -nb;
	size = get_size(nb, (long)base);
	if (!(itoa = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	itoa[size--] = '\0';
	if (nb < 0 && base == 10)
	{
		itoa[0] = '-';
		nb = -nb;
	}
	while (size >= 0)
	{
		if (nb % (long)base > 9)
			itoa[size--] = '7' + nb % (long)base;
		else
			itoa[size--] = '0' + nb % (long)base;
		nb = nb / (long)base;
	}
	return (itoa);
}
