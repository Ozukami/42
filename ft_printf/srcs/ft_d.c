/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 09:08:40 by apoisson          #+#    #+#             */
/*   Updated: 2016/12/18 08:02:37 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_va_arg_d_old(va_list ap, t_conv *list)
{
	char	*cpy;
	char	*cpy2;
	size_t	i;
	size_t	j;
	int		val;

	i = 0;
	j = 0;
	val = va_arg(ap, int);
	cpy2 = ft_itoa_base(val, 10, 0);
	if (list->left)
		list->zero = 0;
	if (list->field < (int)ft_strlen(cpy2) || list->p < (int)ft_strlen(cpy2))
	{
		ft_putchar('{');
		ft_putstr(cpy2);
		ft_putchar('}');
		return (ft_strlen(cpy2));
	}
	else
	{
		cpy = ft_memalloc((!(list->left) ? list->field : ft_strlen(cpy2)));
		while ((int)i < list->field - 1 && (!(list->left)))
		{
			cpy[i] = ' ';
			if (list->zero)
				cpy[i] = '0';
			i++;
		}
	}
	i = 0;
	if (val < 0)
	{
		cpy[i] = '-';
		i++;
		j = 1;
	}
	while (i < (list->field - ft_strlen(cpy2)) && (!(list->left)))
		i++;
	if (list->p == -1)
		i++;
	while (cpy2[j])
	{
		cpy[i] = cpy2[j];
		i++;
		j++;
	}
	ft_putchar('{');
	ft_putstr(cpy);
	ft_putchar('}');
	return (ft_strlen(cpy));
}
