/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xmaj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 05:22:44 by apoisson          #+#    #+#             */
/*   Updated: 2016/12/18 05:22:55 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_va_arg_xmaj(va_list ap, t_conv *list)
{
	ft_putstr(ft_itoa_base(va_arg(ap, int), 16, 1));
	(void)list;
	return (0);
}
