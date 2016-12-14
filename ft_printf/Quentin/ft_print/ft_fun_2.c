/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fun_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumaujea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 08:15:28 by qumaujea          #+#    #+#             */
/*   Updated: 2016/12/14 08:30:57 by qumaujea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fun_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 09:08:40 by apoisson          #+#    #+#             */
/*   Updated: 2016/12/14 08:14:48 by qumaujea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_va_arg_d(va_list ap, t_conv *list)
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
	if (list->p > -1)
		list->left = 0;
	if (list->left)
		list->zero = 0;
	if (list->field < (int)ft_strlen(cpy2) || list->p < (int)ft_strlen(cpy2))
	{
		ft_putendl(cpy2);
		return (ft_strlen(cpy2));
	}
	else
	{
		cpy = ft_memalloc((!(list->left) ? list->field : ft_strlen(cpy2)));
		while (i < list->field - 1 && (!(list->left)))
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
	ft_putendl(cpy);
	return (ft_strlen(cpy));
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
