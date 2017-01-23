/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_va_arg_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumaujea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 11:47:18 by qumaujea          #+#    #+#             */
/*   Updated: 2017/01/19 12:09:26 by qumaujea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_va_arg_o(va_list ap, t_conv *list, char **str)
{
	char	*arg;
	char	*to_print;
	size_t	len;

	if (ft_strequ(list->mod, "l"))
		arg = ft_ltoa_base(va_arg(ap, long int), 8, 0);
	else if (ft_strequ(list->mod, "ll"))
		arg = ft_lltoa_base(va_arg(ap, long long int), 8, 0);
	else
		arg = ft_itoa_base(va_arg(ap, int), 8, 0);
	len = ft_fp_o(ft_strlen(arg), list);
	to_print = ft_strspace(len);
	if (!ft_left_o(arg, len, &to_print, list))
	{
		ft_sub_o1(list, to_print, arg, len);
		if (list->prefix && (list->field == -1 || (list->p == -1
						&& list->field < (int)ft_strlen(arg))))
		{
			*str = ft_strjoin(*str, to_print);
			//ft_putstr(ft_strjoin("0x", to_print));
			return (ft_strlen(to_print) + 2);
		}
	}
	*str = ft_strjoin(*str, to_print);
	//ft_putstr(to_print);
	return (ft_strlen(to_print));
}
