/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_va_arg_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 10:39:31 by apoisson          #+#    #+#             */
/*   Updated: 2017/02/04 03:38:48 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_get_arg_x(va_list ap, t_conv *list)
{
	if (ft_strequ(list->mod, "j"))
		return (ft_ltoa_base(va_arg(ap, long int), 16,
					(list->type == 'x') ? 0 : 1));
	else if (ft_strequ(list->mod, "l") || ft_strequ(list->mod, "z"))
		return (ft_ultoa_base(va_arg(ap, long int), 16,
					(list->type == 'x') ? 0 : 1));
	else if (ft_strequ(list->mod, "ll"))
		return (ft_ulltoa_base(va_arg(ap, unsigned long long int), 16,
					(list->type == 'x') ? 0 : 1));
	else if (ft_strequ(list->mod, "h"))
		return (ft_stoa_base((short)va_arg(ap, int), 16,
					(list->type == 'x') ? 0 : 1));
	else
		return (ft_itoa_base(va_arg(ap, int), 16, (list->type == 'x') ? 0 : 1));
}

size_t		ft_va_arg_x(va_list ap, t_conv *list, char **str)
{
	char	*arg;
	char	*to_print;
	size_t	len;

	arg = ft_get_arg_x(ap, list);
	len = ft_fp_x(ft_strlen(arg), list);
	if (len > 1)
		to_print = ft_strspace(len);
	else
		to_print = ft_memalloc(len);
	if (!ft_left_x(arg, len, &to_print, list))
	{
		if (!(ft_strequ(arg, "0") && list->point))
		{
			ft_sub_x1(list, to_print, arg, len);
		}
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
