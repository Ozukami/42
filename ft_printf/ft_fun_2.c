/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fun_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 09:08:40 by apoisson          #+#    #+#             */
/*   Updated: 2016/12/11 01:35:12 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_va_arg_d(va_list ap)
{
	ft_putnbr(va_arg(ap, int));
}

void	ft_va_arg_dmaj(va_list ap)
{
	ft_putnbr_long(va_arg(ap, long));
}

void	ft_va_arg_i(va_list ap)
{
	ft_putnbr(va_arg(ap, int));
}

void	ft_va_arg_o(va_list ap)
{
	ft_putstr(ft_itoa_base(va_arg(ap, int), 8, 0));
}

void	ft_va_arg_omaj(va_list ap)
{
	ft_putstr(ft_itoa_base(va_arg(ap, int), 8, 0));
}
