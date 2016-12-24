/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 09:04:59 by apoisson          #+#    #+#             */
/*   Updated: 2016/12/24 12:04:46 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_va_arg_c(va_list ap, t_conv *list)
{
	size_t	i;
	char	*cpy;

	i = 0;
	cpy = (list->field > 1) ? ft_memalloc(list->field + 1) : ft_memalloc(2);
	if (list->field > 1)
		while ((int)i < list->field)
			cpy[i++] = ' ';
	if (i > 0)
		i--;
	if (list->left)
		i = 0;
	cpy[i] = va_arg(ap, int);
	ft_putstr(cpy);
	return (ft_strlen(cpy));
}
