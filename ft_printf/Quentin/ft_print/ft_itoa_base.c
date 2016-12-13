/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 13:01:22 by exam              #+#    #+#             */
/*   Updated: 2016/12/10 10:03:12 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		get_size(int value, int base)
{
	if (value >= 0 && value < base)
		return (1);
	if (value > -base && value < -1)
		return (1);
	if (value < 0)
		return (1 + get_size(-value / base, base));
	return (1 + get_size(value / base, base));
}

char	*ft_strdup(char *s)
{
	char	*dup;
	int		i;

	i = 0;
	while (s[i])
		i++;
	dup = malloc(i + 1);
	dup[i] = '\0';
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	return (dup);
}

char	*ft_itoa_base(int value, int base, int maj)
{
	char	*rep;
	int		size;

	if (value == 0)
		return (ft_strdup("0"));
	if (value == -2147483648 && base == 10)
		return (ft_strdup("-2147483648"));
	size = get_size(value, base);
	if (value < 0 && base == 10)
		size++;
	rep = malloc(size + 1);
	rep[size] = '\0';
	size--;
	if (value < 0 && base == 10)
	{
		rep[0] = '-';
		value = -value;
	}
	while (value != 0)
	{
		if (value % base > 9 && maj)
			rep[size] = '7' + (value % base);
		else if (value % base > 9 && !maj)
			rep[size] = '7' + 32 + (value % base);
		else
			rep[size] = '0' + (value % base);
		value = value / base;
		size--;
	}
	return (rep);
}
