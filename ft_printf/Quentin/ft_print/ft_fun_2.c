/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fun_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 09:08:40 by apoisson          #+#    #+#             */
/*   Updated: 2016/12/13 09:49:46 by qumaujea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_va_arg_d(va_list ap)
{
	printf("%d\n", va_arg(ap, int));
}

size_t	ft_va_arg_dmaj(va_list ap)
{
	printf("%D\n", va_arg(ap, int));
}

size_t	ft_va_arg_i(va_list ap)
{
	printf("%i\n", va_arg(ap, int));
}

size_t	ft_va_arg_o(va_list ap)
{
	printf("%o\n", va_arg(ap, int));
}

size_t	ft_va_arg_omaj(va_list ap)
{
	printf("%O\n", va_arg(ap, unsigned int));
}
