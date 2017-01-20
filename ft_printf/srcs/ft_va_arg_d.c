/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_va_arg_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 09:29:44 by apoisson          #+#    #+#             */
/*   Updated: 2017/01/20 13:01:57 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_va_arg_d(va_list ap, t_conv *list, char **str)
{
	char	*arg;
	char	*to_print;
	size_t	len;

	//arg = ft_ltoa_base(va_arg(ap, long int), 10, 0); pour ld
	arg = ft_itoa(va_arg(ap, int));
	if (list->sign && arg[0] != '-')
		arg = ft_strjoin("+", arg);
	len = ft_fp_d(ft_strlen(arg), list, arg, 0);
	to_print = ft_strspace(len);
	if (!ft_left_d(arg, len, &to_print, list))
	{
		ft_sub_1(list, to_print, arg, len);
		if (list->space && list->field == -1 && list->p == -1 && arg[0] != '-')
		{
			*str = ft_strjoin(*str, ft_strjoin(" ", to_print));
			//ft_putstr(ft_strjoin(" ", to_print));
			return (ft_strlen(to_print) + 1);
		}
	}
	ft_sub_2(list, &to_print, arg);
	*str = ft_strjoin(*str, to_print);
	//ft_putstr(to_print);
	return (ft_strlen(to_print));
}
