/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 09:04:59 by apoisson          #+#    #+#             */
/*   Updated: 2016/12/18 06:23:02 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_va_arg_c(va_list ap, t_conv *list)
{
	size_t	i;
	char	*cpy;

	i = 0;
	cpy = ft_memalloc(sizeof(char));
	if (list->field > 1)
	{
		free(cpy);
		cpy = ft_memalloc(list->field);
		while ((int)i < list->field)
		{
			cpy[i] = ' ';
			if (list->zero)
				cpy[i] = '0';
			i++;
		}
	}
	if (i > 0)
		i--;
	cpy[i] = va_arg(ap, int);
	ft_putchar('[');
	ft_putstr(cpy);
	ft_putchar(']');
	return (ft_strlen(cpy));
}
