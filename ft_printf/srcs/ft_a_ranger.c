/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_a_ranger.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 01:31:58 by apoisson          #+#    #+#             */
/*   Updated: 2016/12/14 10:04:14 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_putchar_wchar_t(wchar_t c)
{
	write(1, &c, 1);
}

void			ft_putstr_wchar_t(wchar_t *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}

unsigned int	ft_int_to_unsigned(int nb)
{
	long	rep;

	rep = (2147483648 * 2) - 1;
	if (nb < 0)
		rep = rep + (unsigned int)nb;
	else
		rep = (unsigned int)nb;
	return (rep);
}

short			ft_int_to_short(int nb)
{
	return ((short)nb);
}

void	ft_putnbr_long(long n)
{
	long	min;

	min = -9223372036854775807;
	if (n == min)
		ft_putstr("-9223372036854775807");
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr_long(-n);
	}
	else if (n < 10)
		ft_putchar('0' + n);
	else
	{
		ft_putnbr_long(n / 10);
		ft_putchar('0' + n % 10);
	}
}

void	ft_putnbr_unsigned(unsigned int n)
{
	(void)n;
	// TODO
}
