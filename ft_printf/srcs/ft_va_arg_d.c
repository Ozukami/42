/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_va_arg_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 09:29:44 by apoisson          #+#    #+#             */
/*   Updated: 2017/02/06 02:47:55 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_get_arg_d(va_list ap, t_conv *list)
{
	char	*arg;
	int		i;

	if (ft_strequ(list->mod, "j"))
		arg = (ft_ltoa_base(va_arg(ap, long int), 10, 0));
	else if (ft_strequ(list->mod, "l") || ft_strequ(list->mod, "z"))
		arg = (ft_ultoa_base(va_arg(ap, long int), 10, 0));
	else if (ft_strequ(list->mod, "h"))
		arg = (ft_stoa_base((short)va_arg(ap, int), 10, 0));
	else if (ft_strequ(list->mod, "ll"))
		arg = (ft_lltoa_base(va_arg(ap, long long int), 10, 0));
	else if (ft_strequ(list->mod, "hh"))
		arg = (ft_sstoa(va_arg(ap, int)));
	else
		arg = (ft_itoa_base(va_arg(ap, int), 10, 0));
	if (list->sign && arg[0] != '-')
	{
		if (list->p == (int)ft_strlen(arg) + 1)
			arg = ft_strjoin("+0", arg);
		else
			arg = ft_strjoin("+", arg);
	}
	if (list->p == (int)ft_strlen(arg) && arg[0] == '-')
	{
		i = -1;
		while (arg[++i])
			if (arg[i] == '-')
				arg[i] = '0';
		arg = ft_strjoin("-", arg);
	}
	return (arg);
}

size_t		ft_va_arg_d(va_list ap, t_conv *list, char **str)
{
	char	*arg;
	char	*to_print;
	size_t	len;

	arg = ft_get_arg_d(ap, list);
	if (ft_strequ(arg, "0") && list->field == -1 && !list->sign && list->point
			&& !list->space)
		return (0);
	else if (ft_strequ(arg, "0") && list->field == -1 && list->p == -1 &&
			!list->point && !list->space)
	{
		*str = ft_strjoin(*str, "0");
		return (1);
	}
	len = ft_fp_d(ft_strlen(arg), list, arg, 0);
	to_print = ft_strspace(len);
	if (!ft_left_d(arg, len, &to_print, list))
	{
		if (!ft_strequ(arg, "0"))
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
