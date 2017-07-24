/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_valist_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 15:09:25 by lcharbon          #+#    #+#             */
/*   Updated: 2017/06/08 01:46:53 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ftpf_unicode(wint_t c, char *ret)
{
	if (c <= 127)
		ret[0] = c;
	else if (c <= 2047)
	{
		ret[0] = (192 | (c & 1984) >> 6);
		ret[1] = (128 | (c & 63));
	}
	else if (c <= 65535)
	{
		ret[0] = (224 | (c >> 12));
		ret[1] = (128 | ((c >> 6) & 63));
		ret[2] = (128 | (c & 63));
	}
	else if (c <= 1114111)
	{
		ret[0] = (240 | (c >> 18));
		ret[1] = (128 | ((c >> 12) & 63));
		ret[2] = (128 | ((c >> 6) & 63));
		ret[3] = (128 | (c & 63));
	}
}

void				ftpf_valist_char(t_data *data, va_list ap, char *ret)
{
	wint_t			tmp;

	if (data->conv == 'C' || (data->conv == 'c' && data->data[10] == 1))
	{
		tmp = (wint_t)va_arg(ap, wint_t);
		ftpf_unicode(tmp, ret);
	}
	else if (data->conv == 'c')
		ret[0] = (char)va_arg(ap, int);
}
