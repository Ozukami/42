/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_va_arg_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 10:39:31 by apoisson          #+#    #+#             */
/*   Updated: 2017/02/06 09:38:43 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_va_arg_p(va_list ap, t_conv *list, char **str)
{
	char	*arg;
	char	*to_print;
	size_t	len;

	arg = ft_ulltoa_base(va_arg(ap, unsigned long long int), 16, 0);
	/*
	if (ft_strequ(arg, "0"))
	{
		len = ft_fp_x(ft_strlen(arg), list);
		printf("{}", );
		*str = ft_strjoin(*str, ft_strdup("0x0"));
		return (3);
	}
	*/
	if (!ft_strequ(arg, "0"))
	{
		list->type = 'x';
		list->prefix = 1;
		list->mod = "ll";
	}
	else if (list->p == -1 && list->field == -1 && !list->point)
	{
		*str = ft_strjoin(*str, ft_strdup("0x0"));
		return (3);
	}
	len = ft_fp_x(ft_strlen(arg), list, arg);
	if (len > 1)
		to_print = ft_strspace(len);
	else
		to_print = ft_memalloc(len);
	if (!ft_left_x(arg, len, &to_print, list))
	{
		if (!(ft_strequ(arg, "0") && list->point))
			ft_sub_x1(list, to_print, arg, len);
		if (list->prefix && (list->field == -1 || (list->p == -1
						&& list->field < (int)ft_strlen(arg))))
		{
			*str = ft_strjoin(*str, to_print);
			//ft_putstr(ft_strjoin("0x", to_print));
			return (ft_strlen(to_print));
		}
	}
	if (list->left && ft_strequ(arg, "0"))
		*str = ft_strjoin(*str, ft_strncpy(to_print + 1, "x0", 2) - 1);
	else if (ft_strequ(arg, "0") && !list->point)
		*str = ft_strjoin(*str, ft_strncpy(to_print + len - 3, "0x", 2) - len + 3);
	else if (list->point && ft_strequ(arg, "0"))
		*str = ft_strjoin(*str, ft_strjoin("0x", to_print));
	else
		*str = ft_strjoin(*str, to_print);
	//ft_putstr(to_print);
	return (ft_strlen(*str));
}
