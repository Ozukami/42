/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fun_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 09:10:17 by apoisson          #+#    #+#             */
/*   Updated: 2016/12/10 09:10:24 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_va_arg_x(va_list ap)
{
	printf("%x\n", va_arg(ap, int));
}

void	ft_va_arg_X(va_list ap)
{
	printf("%X\n", va_arg(ap, long));
}

void	ft_va_arg_u(va_list ap)
{
	printf("%u\n", va_arg(ap, int));
}

void	ft_va_arg_U(va_list ap)
{
	printf("%U\n", va_arg(ap, long));
}
