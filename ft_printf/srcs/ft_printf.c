/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 01:29:40 by apoisson          #+#    #+#             */
/*   Updated: 2016/12/15 09:44:14 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fun_init(t_fun **tab)
{
	tab[0][0].f = &ft_va_arg_p;
	tab[0][0].type = 'p';
	tab[0][1].f = &ft_va_arg_c;
	tab[0][1].type = 'c';
	tab[0][2].f = &ft_va_arg_cmaj;
	tab[0][2].type = 'C';
	tab[0][3].f = &ft_va_arg_s;
	tab[0][3].type = 's';
	tab[0][4].f = &ft_va_arg_smaj;
	tab[0][4].type = 'S';
	tab[0][5].f = &ft_va_arg_d;
	tab[0][5].type = 'd';
	tab[0][6].f = &ft_va_arg_dmaj;
	tab[0][6].type = 'D';
}

void	ft_fun_init2(t_fun **tab)
{
	tab[0][7].f = &ft_va_arg_d;
	tab[0][7].type = 'i';
	tab[0][8].f = &ft_va_arg_o;
	tab[0][8].type = 'o';
	tab[0][9].f = &ft_va_arg_omaj;
	tab[0][9].type = 'O';
	tab[0][10].f = &ft_va_arg_u;
	tab[0][10].type = 'u';
	tab[0][11].f = &ft_va_arg_umaj;
	tab[0][11].type = 'U';
	tab[0][12].f = &ft_va_arg_x;
	tab[0][12].type = 'x';
	tab[0][13].f = &ft_va_arg_xmaj;
	tab[0][13].type = 'X';
}

int		ft_printf(const char *restrict format, ...)
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
	if (!(tab = ft_memalloc(sizeof(t_fun) * 14)))
		return (-1);
	ft_fun_init(&tab);
	ft_fun_init2(&tab);
	to_print = ft_get_conv(format, &list);
	va_start(ap, format);
	j = -1;
	while (to_print[++j])
	{
		if (to_print[j] == '%' && to_print[++j] != '%')
		{
			i = 0;
			while (i < 15)
			{
				if (list->type == tab[i].type)
					len += tab[i].f(ap, list);
				i++;
			}
			list = list->next;
		}
		else
			ft_putchar(to_print[j]);
	}
	va_end(ap);
	return ((int)len);
}
