/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_unsign_conv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 15:09:25 by lcharbon          #+#    #+#             */
/*   Updated: 2017/06/06 22:39:03 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t			ftpf_valist_unsign(t_data *data, va_list ap, char c)
{
	uintmax_t		ret;

	if (data->conv == 'p')
		ret = (uintmax_t)va_arg(ap, void*);
	if (data->data[9] == 1)
		ret = (uintmax_t)va_arg(ap, unsigned long long);
	else if (data->data[10] == 1 || c == 'U' || c == 'O')
		ret = (uintmax_t)va_arg(ap, unsigned long);
	else if (data->data[11] == 1)
		ret = (uintmax_t)va_arg(ap, uintmax_t);
	else if (data->data[12] == 1)
		ret = (uintmax_t)va_arg(ap, size_t);
	else if (data->data[7] == 1)
		ret = (uintmax_t)(unsigned char)va_arg(ap, unsigned int);
	else if (data->data[8] == 1)
		ret = (uintmax_t)(unsigned short)va_arg(ap, unsigned int);
	else
		ret = (uintmax_t)va_arg(ap, unsigned int);
	return (ret);
}
