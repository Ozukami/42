/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumaujea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 09:28:30 by qumaujea          #+#    #+#             */
/*   Updated: 2017/01/20 09:33:00 by qumaujea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_size(int value, int base)
{
	if (value > -base && value <= -1)
		return (2);
	if (value >= 0 && value < base)
		return (1);
	if (value < -base)
		return (2 + get_size(-value / base, base));
	return (1 + get_size(value / base, base));
}

static int		neg_case(int *nb, int base, char **itoa)
{
	if (*nb < 0 && base == 10)
	{
		*nb = -(*nb);
		itoa[0][0] = '-';
		return (1);
	}
	return (0);
}

char			*ft_ltoa_base(short short value, int base, int maj)
{
	char		*itoa;
	int			size;
	int			nb;
	int			neg;

	nb = (int)value;
	if (nb < 0 && base != 10)
		nb = 4294967296 + value;
	size = get_size(nb, base);
	if (!(itoa = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	itoa[size--] = '\0';
	neg = neg_case(&nb, base, &itoa);
	while (size >= neg)
	{
		if (nb % base > 9 && maj)
			itoa[size--] = '7' + nb % base;
		else if (nb % base > 9)
			itoa[size--] = '7' + 32 + nb % base;
		else
			itoa[size--] = '0' + nb % base;
		nb = nb / base;
	}
	return (itoa);
}
