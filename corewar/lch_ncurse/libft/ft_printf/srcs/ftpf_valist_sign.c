/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_sign_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 15:09:25 by lcharbon          #+#    #+#             */
/*   Updated: 2017/06/10 05:49:17 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t			ftpf_valist_sign(t_data *data, va_list ap, char c)
{
	intmax_t		ret;

	if (data->data[9] == 1)
		ret = (intmax_t)va_arg(ap, long long);
	else if (data->data[10] == 1 || c == 'D')
		ret = (intmax_t)va_arg(ap, long);
	else if (data->data[11] == 1)
		ret = (intmax_t)va_arg(ap, intmax_t);
	else if (data->data[12] == 1)
		ret = (intmax_t)va_arg(ap, ssize_t);
	else if (data->data[7] == 1)
		ret = (intmax_t)(char)va_arg(ap, int);
	else if (data->data[8] == 1 || c == 'D')
		ret = (intmax_t)(short)va_arg(ap, int);
	else
		ret = (intmax_t)va_arg(ap, int);
	return (ret);
}
