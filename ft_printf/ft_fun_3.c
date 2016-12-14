/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fun_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 09:10:17 by apoisson          #+#    #+#             */
/*   Updated: 2016/12/13 09:49:59 by qumaujea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_va_arg_x(va_list ap)
{
	ft_putstr(ft_itoa_base(va_arg(ap, int), 16, 0));
}

size_t	ft_va_arg_xmaj(va_list ap)
{
	ft_putstr(ft_itoa_base(va_arg(ap, int), 16, 1));
}

size_t	ft_va_arg_u(va_list ap)
{
	printf("%u\n", va_arg(ap, int));
}

size_t	ft_va_arg_umaj(va_list ap)
{
	printf("%U\n", va_arg(ap, unsigned int));
}
