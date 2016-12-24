/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 06:27:02 by apoisson          #+#    #+#             */
/*   Updated: 2016/12/18 06:27:04 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_va_arg_x(va_list ap, t_conv *list)
{
	ft_putstr(ft_itoa_base(va_arg(ap, int), 16, 0));
	(void)list;
	return (0);
}