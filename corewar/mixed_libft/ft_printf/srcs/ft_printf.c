/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 15:09:25 by lcharbon          #+#    #+#             */
/*   Updated: 2017/06/10 11:18:56 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ftpf_init_data(t_data *data)
{
	int			i;

	i = 0;
	while (i++ < 14)
		data->data[i] = 0;
	data->data[0] = -1;
	data->conv = '\0';
}

static int		ftpf_va(const char **format, va_list ap, t_data *data)
{
	int			n;

	n = 0;
	ftpf_init_data(data);
	ftpf_get_data(format, data, ap);
	n = ftpf_convert(data, ap);
	return (n);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	t_data		data;

	data.n_char = 0;
	data.fd = 1;
	data.opfd = -1;
	ft_test_memory();
	va_start(ap, format);
	while (*format)
	{
		if (*format != '%' && *format != '{')
		{
			ft_putchar_fd(*format++, data.fd);
			data.n_char++;
		}
		else if (*format == '%')
			data.n_char += ftpf_va(&format, ap, &data);
		else
			ftpf_get_special(&format, &data, ap);
	}
	va_end(ap);
	if (data.opfd == 1)
		close(data.fd);
	return (data.n_char);
}
