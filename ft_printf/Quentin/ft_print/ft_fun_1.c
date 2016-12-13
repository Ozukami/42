/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fun_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 09:04:59 by apoisson          #+#    #+#             */
/*   Updated: 2016/12/13 12:41:53 by qumaujea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_va_arg_p(va_list ap)
{
	printf("%p\n", va_arg(ap, size_t *));
}

size_t	ft_va_arg_c(va_list ap)
{
	printf("%c\n", va_arg(ap, int));
}

size_t	ft_va_arg_cmaj(va_list ap)
{
	printf("%C\n", va_arg(ap, wchar_t));
}

size_t	ft_va_arg_s(va_list ap, t_conv *list)
{
	char	*cpy;
	char	*cpy2;
	size_t	i;
	size_t	j;
	size_t	len;

	j = 0;
	cpy2 = va_arg(ap, char *);
	len = ft_strlen(cpy2);
	i = 0;
	cpy = ft_memalloc(ft_max(list->field, len));
	if (list->left)
	{
		list->zero = 0;
	}
	if (list->field > 0)
	{
		while (i < list->field)
		{
			cpy[i] = ' ';
			if (list->zero)
				cpy[i] = '0';
			i++;
		}
	}
	if (list->p != -1 && list->p < len)
		i = 0;
	else
		(!(list->left)) ? (i = (list->field - len)) : (i = 0);
	if (list->space && !(list->zero))
	{
		cpy[i] = ' ';
		i++;
	}
	if (list->p != 0)
	{
		if (list->p != -1)
			while (i <= (list->field - list->p) && (list->field - list->p) > 0)
				i++;
		while (j < list->p && cpy2[j])
		{
			cpy[i] = cpy2[j];
			i++;
			j++;
		}
	}
	ft_putendl(cpy);
	return (ft_strlen(cpy));
}

size_t	ft_va_arg_smaj(va_list ap)
{
	printf("%S\n", va_arg(ap, wchar_t *));
}
