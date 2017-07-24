/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 15:09:25 by lcharbon          #+#    #+#             */
/*   Updated: 2017/06/10 05:25:18 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ftpf_get_flags(char const **format, t_data *data)
{
	while (ftpf_flags(**format) == 1)
	{
		if (**format == '#')
			data->data[2] = 1;
		else if (**format == '0')
			data->data[3] = 1;
		else if (**format == '-')
			data->data[4] = 1;
		else if (**format == '+')
			data->data[5] = 1;
		else if (**format == ' ')
			data->data[6] = 1;
		else if (**format == 39)
			data->data[14] = 1;
		(*format)++;
	}
}

void		ftpf_get_modifier(char const **format, t_data *data)
{
	if (**format == 'L')
		data->data[13] = 1;
	if (**format == 'h')
		data->data[8]++;
	if (**format == 'l')
		data->data[10]++;
	if (**format == 'j')
		data->data[11] = 1;
	if (**format == 'z')
		data->data[12] = 1;
	if (data->data[8] > 1)
	{
		data->data[7] = 1;
		data->data[8] = -1;
	}
	if (data->data[10] > 1)
	{
		data->data[9] = 1;
		data->data[10] = -1;
	}
	(*format)++;
}

void		ftpf_get_width(char const **format, t_data *data, va_list ap)
{
	if (**format == '*')
	{
		data->data[1] = va_arg(ap, int);
		if (data->data[1] < 0)
		{
			data->data[1] = ft_abs(data->data[1]);
			data->data[4] = 1;
		}
		(*format)++;
	}
	if (ft_isdigit(**format) == 1)
		data->data[1] = ft_atoi(*format);
	while (ft_isdigit(**format))
		(*format)++;
}

void		ftpf_get_prec(char const **format, t_data *data, va_list ap)
{
	(*format)++;
	if (**format == '*')
	{
		data->data[0] = va_arg(ap, int);
		(*format)++;
	}
	else
		data->data[0] = ft_atoi(*format);
	while (ft_isdigit(**format))
		(*format)++;
}

void		ftpf_get_conv(char const **format, t_data *data)
{
	if (ft_isalpha(**format) == 1 || **format == '%')
	{
		data->conv = **format;
		(*format)++;
	}
}
