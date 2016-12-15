/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_to_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 10:04:43 by apoisson          #+#    #+#             */
/*   Updated: 2016/12/15 10:05:04 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
