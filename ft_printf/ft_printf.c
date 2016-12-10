/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 01:29:40 by apoisson          #+#    #+#             */
/*   Updated: 2016/12/10 09:03:31 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_va_arg_d(va_list ap)
{
	printf("%d\n", va_arg(ap, int));
}

void	ft_va_arg_c(va_list ap)
{
	printf("%c\n", va_arg(ap, int));
}

void	ft_va_arg_C(va_list ap)
{
	printf("%C\n", va_arg(ap, long));
}

void	ft_va_arg_s(va_list ap)
{
	printf("%s\n", va_arg(ap, char *));
}

void	ft_va_arg_S(va_list ap)
{
	printf("%S\n", va_arg(ap, wchar_t *));
}

t_fun	*ft_fun_init(void)
{
	t_fun	*tab;

	tab = malloc(sizeof(t_fun) * 2);
	tab[0].f = &ft_va_arg_int;
	tab[0].type = 'd';
	tab[1].f = &ft_va_arg_char;
	tab[1].type = 'c';
	return (tab);
}

int		ft_printf(const char *restrict format, ...)
{
	va_list	ap;
	t_conv	*list;
	t_fun	*tab;
	int		i;

	list = NULL;
	tab = ft_fun_init();
	ft_get_conv(format, &list);
	va_start(ap, format);
	while (list)
	{
		i = 0;
		while (i < 2)
		{
			if (list->type == tab[i].type)
				tab[i].f(ap);
			i++;
		}
		list = list->next;
	}
	return (0);
}
