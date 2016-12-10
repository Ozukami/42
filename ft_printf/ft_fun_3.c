/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fun_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 09:10:17 by apoisson          #+#    #+#             */
/*   Updated: 2016/12/10 10:05:30 by apoisson         ###   ########.fr       */
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
	printf("%u\n", va_arg(ap, int));
}

void	ft_va_arg_umaj(va_list ap)
{
	printf("%U\n", va_arg(ap, unsigned int));
}
