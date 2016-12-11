/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fun_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 09:04:59 by apoisson          #+#    #+#             */
/*   Updated: 2016/12/11 03:05:11 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_va_arg_p(va_list ap)
{
	ft_putstr(ft_itoa_base((int)va_arg(ap, void *), 16, 0));
}

void	ft_va_arg_c(va_list ap)
{
	ft_putchar(va_arg(ap, int));
}

void	ft_va_arg_cmaj(va_list ap)
{
	ft_putchar_wchar_t(va_arg(ap, wchar_t));
}

void	ft_va_arg_s(va_list ap)
{
	ft_putstr(va_arg(ap, char *));
}

void	ft_va_arg_smaj(va_list ap)
{
	ft_putstr_wchar_t(va_arg(ap, wchar_t *));
}
