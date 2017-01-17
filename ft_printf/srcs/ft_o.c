/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 05:23:16 by apoisson          #+#    #+#             */
/*   Updated: 2017/01/17 08:47:23 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_va_arg_o(va_list ap, t_conv *list, char **str)
{
	printf("{TODO !}%o\n", va_arg(ap, int));
	(void)list;
	(void)str;
	return (0);
}
