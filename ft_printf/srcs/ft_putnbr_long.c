/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 10:05:38 by apoisson          #+#    #+#             */
/*   Updated: 2016/12/15 10:05:52 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
