/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 01:29:40 by apoisson          #+#    #+#             */
/*   Updated: 2017/02/06 01:38:14 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_fun_init(t_fun **tab)
{
	tab[0][0].f = &ft_va_arg_c;
	tab[0][0].type = 'c';
	tab[0][1].f = &ft_va_arg_s;
	tab[0][1].type = 's';
	tab[0][2].f = &ft_va_arg_d;
	tab[0][2].type = 'd';
	tab[0][3].f = &ft_va_arg_o;
	tab[0][3].type = 'o';
	tab[0][4].f = &ft_va_arg_u;
	tab[0][4].type = 'u';
	tab[0][5].f = &ft_va_arg_x;
	tab[0][5].type = 'x';
	tab[0][6].f = &ft_va_arg_x;
	tab[0][6].type = 'X';
	tab[0][7].f = &ft_va_arg_p;
	tab[0][7].type = 'p';
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		j;
	size_t	len;
	t_conv	*list;
	t_fun	*tab;
	char	*to_print;

	list = NULL;
	len = 0;
	if (!(tab = ft_memalloc(sizeof(t_fun) * 14))
			|| !(to_print = ft_memalloc(1)))
		return (-1);
	ft_fun_init(&tab);
	ft_get_conv(format, &list);
	va_start(ap, format);
	j = -1;
	while (format[++j])
	{
		if (format[j] == '%')
		{
			if (format[++j] != '%')
			{
				j += ft_get_len(format, j);
				i = 0;
				while (i < 8)
				{
					if (list->type == tab[i].type)
						len += tab[i].f(ap, list, &to_print);
					i++;
				}
				if (i == 8 && list->type == '%')
				{
					i = 0;
					if (list->left)
					{
						to_print = ft_straddchar(to_print, '%');
						len++;
					}
					while (++i < list->field)
					{
						to_print = ft_straddchar(to_print, ' ');
						len++;
					}
					if (!list->left)
					{
						to_print = ft_straddchar(to_print, '%');
						len++;
					}
				}
				list = list->next;
			}
			else
			{
				to_print = ft_straddchar(to_print, '%');
				len++;
			}
		}
		else
		{
			to_print = ft_straddchar(to_print, format[j]);
			len++;
		}
	}
	va_end(ap);
	ft_putstr(to_print);
	return ((int)len);
}
