/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_va_arg_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumaujea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 11:47:18 by qumaujea          #+#    #+#             */
/*   Updated: 2017/02/06 07:15:10 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_va_arg_o(va_list ap, t_conv *list, char **str)
{
	char	*arg;
	char	*to_print;
	size_t	len;

	if (ft_strequ(list->mod, "l") || ft_strequ(list->mod, "j")
			|| ft_strequ(list->mod, "z"))
		arg = ft_ulltoa_base(va_arg(ap, unsigned long long int), 8, 0);
	else if (ft_strequ(list->mod, "h"))
		arg = ft_stoa_base((short)va_arg(ap, int), 8, 0);
	else if (ft_strequ(list->mod, "ll"))
		arg = ft_ulltoa_base(va_arg(ap, unsigned long long int), 8, 0);
	else if (ft_strequ(list->mod, "hh"))
		arg = ft_usstoa_base((unsigned char)va_arg(ap, int), 8, 0);
	else
		arg = ft_itoa_base(va_arg(ap, int), 8, 0);
	len = ft_fp_o(ft_strlen(arg), list, arg);
	if (len > 1)
		to_print = ft_strspace(len);
	else
		to_print = ft_memalloc(len);
	if (!ft_left_o(arg, len, &to_print, list))
	{
		ft_sub_o1(list, to_print, arg, len);
		if (list->prefix && (list->field == -1 || (list->p == -1
						&& list->field < (int)ft_strlen(arg))))
		{
			*str = ft_strjoin(*str, to_print);
			//ft_putstr(ft_strjoin("0x", to_print));
			return (ft_strlen(to_print));
		}
	}
	*str = ft_strjoin(*str, to_print);
	//ft_putstr(to_print);
	return (ft_strlen(to_print));
}
