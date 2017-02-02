/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumaujea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 09:09:47 by qumaujea          #+#    #+#             */
/*   Updated: 2017/01/31 11:28:01 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		get_size(unsigned long long value, unsigned long long base)
{
	if (value < base)
		return (1);
	return (1 + get_size(value / base, base));
}

char			*ft_ltoa_base(long value, int base, int maj)
{
	char				*itoa;
	int					size;
	unsigned long long	nb;

	nb = (unsigned long long)value;
	size = get_size(nb, (unsigned long long)base);
	if (!(itoa = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	itoa[size--] = '\0';
	while (size >= 0)
	{
		if (nb % (unsigned long long)base > 9 && maj)
			itoa[size--] = '7' + nb % (unsigned long long)base;
		else if (nb % (long)base > 9)
			itoa[size--] = '7' + 32 + nb % (unsigned long long)base;
		else
			itoa[size--] = '0' + nb % (unsigned long long)base;
		nb = nb / (unsigned long long)base;
	}
	return (itoa);
}
