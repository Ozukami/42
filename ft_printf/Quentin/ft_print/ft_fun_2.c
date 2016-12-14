/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fun_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 09:08:40 by apoisson          #+#    #+#             */
/*   Updated: 2016/12/14 07:20:07 by qumaujea         ###   ########.fr       */
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
	size_t	len;

	i = 0;
	j = 0;
	val = va_arg(ap, int);
	len = ft_strlen(ft_int_to_str(val));
	printf("MA BITE1\n");
	printf("LEN %zu\n", len);
	cpy2 = ft_int_to_str(val);
	printf("MA BITE1\n");
	printf("%s\n", cpy2);
	if (list->field < ft_strlen(cpy2))
	{
		ft_putendl(cpy2);
		return (ft_strlen(cpy2));
	}
	else
	{
		printf("MA BITE2\n");
		cpy = ft_memalloc(list->field);
		while (i < list->field)
		{
			cpy[i] = ' ';
			if (list->zero)
				cpy[i] = '0';
			i++;
		}
		printf("MA BITE3\n");
	}
	printf("MA BITE2\n");
	i = 0;
	while (i < (list->field - ft_strlen(cpy2)))
		i++;
	while (cpy2[j])
	{	
		cpy[i] = cpy2[j];
		i++;
		j++;
	}
	printf("MA BITE4\n");
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
