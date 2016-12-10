/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fun_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 09:04:59 by apoisson          #+#    #+#             */
/*   Updated: 2016/12/10 09:08:59 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_va_arg_p(va_list ap)
{
	printf("%p\n", va_arg(ap, void *));
}

void	ft_va_arg_c(va_list ap)
{
	printf("%c\n", va_arg(ap, int));
}

void	ft_va_arg_C(va_list ap)
{
	printf("%C\n", va_arg(ap, long));
}

void	ft_va_arg_s(va_list ap)
{
	printf("%s\n", va_arg(ap, char *));
}

void	ft_va_arg_S(va_list ap)
{
	printf("%S\n", va_arg(ap, wchar_t *));
}
