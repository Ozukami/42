/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fun_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 09:08:40 by apoisson          #+#    #+#             */
/*   Updated: 2016/12/10 09:08:43 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_va_arg_d(va_list ap)
{
	printf("%d\n", va_arg(ap, int));
}

void	ft_va_arg_D(va_list ap)
{
	printf("%D\n", va_arg(ap, long));
}

void	ft_va_arg_i(va_list ap)
{
	printf("%i\n", va_arg(ap, int));
}

void	ft_va_arg_o(va_list ap)
{
	printf("%o\n", va_arg(ap, int));
}

void	ft_va_arg_O(va_list ap)
{
	printf("%O\n", va_arg(ap, long));
}
