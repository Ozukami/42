/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_get_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 15:09:25 by lcharbon          #+#    #+#             */
/*   Updated: 2017/06/08 05:40:42 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ftpf_modifier(char c)
{
	if (c == 'h' || c == 'l' || c == 'j' || c == 'z')
		return (1);
	return (0);
}

int			ftpf_flags(char c)
{
	if (c == '#' || c == '0' || c == ' ' || c == '-' || c == '+' || c == 39)
		return (1);
	return (0);
}

void		ftpf_get_data(const char **format, t_data *data, va_list ap)
{
	(*format)++;
	while (ftpf_flags(**format) == 1 || ftpf_modifier(**format) == 1
	|| ft_isdigit(**format) == 1 || **format == '.' || **format == '*')
	{
		if (ftpf_flags(**format) == 1)
			ftpf_get_flags(format, data);
		else if (ft_isdigit(**format) == 1 || **format == '*')
			ftpf_get_width(format, data, ap);
		else if (**format == '.')
			ftpf_get_prec(format, data, ap);
		else if (ftpf_modifier(**format) == 1)
			ftpf_get_modifier(format, data);
	}
	ftpf_get_conv(format, data);
	data->data[13] = 50 + data->data[0] + data->data[1];
}
