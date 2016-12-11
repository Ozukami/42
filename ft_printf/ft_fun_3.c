/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fun_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 09:10:17 by apoisson          #+#    #+#             */
/*   Updated: 2016/12/11 06:10:19 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_va_arg_x(va_list ap)
{
	ft_putstr(ft_itoa_base(va_arg(ap, int), 16, 0));
}

void	ft_va_arg_xmaj(va_list ap)
{
	ft_putstr(ft_itoa_base(va_arg(ap, int), 16, 1));
}

void	ft_va_arg_u(va_list ap)
{
	ft_putnbr(ft_int_to_unsigned(va_arg(ap, int)));
}

void	ft_va_arg_umaj(va_list ap)
{
	ft_putnbr(ft_int_to_unsigned(va_arg(ap, int)));
}
