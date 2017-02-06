/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_va_arg_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 10:39:31 by apoisson          #+#    #+#             */
/*   Updated: 2017/02/06 08:27:06 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_va_arg_u(va_list ap, t_conv *list, char **str)
{
	char	*arg;
	char	*to_print;
	size_t	len;

	if (ft_strequ(list->mod, "h"))
		arg = ft_stoa_unsigned((short)va_arg(ap, int));
	else if (ft_strequ(list->mod, "l") || ft_strequ(list->mod, "z")
			|| ft_strequ(list->mod, "j"))
		arg = ft_ltoa_unsigned(va_arg(ap, long int));
	else if (ft_strequ(list->mod, "ll"))
		arg = ft_lltoa_unsigned(va_arg(ap, long long int));
	else if (ft_strequ(list->mod, "hh"))
		arg = ft_usstoa_base((unsigned char)va_arg(ap, int), 10, 0);
	else
		arg = ft_itoa_unsigned(va_arg(ap, long long int));
	len = ft_fp_x(ft_strlen(arg), list, arg);
	to_print = ft_strspace(len);
	if (!ft_left_x(arg, len, &to_print, list))
	{
		ft_sub_x1(list, to_print, arg, len);
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
