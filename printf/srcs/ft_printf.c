/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 23:54:04 by apoisson          #+#    #+#             */
/*   Updated: 2017/03/11 07:09:41 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_reset_conv(t_data *data)
{
	BASE = 10;
	SPACE = 0;
	PREFIX = 0;
	ZERO = 0;
	LEFT = 0;
	SIGN = 0;
	NEG = 0;
	STAR = 0;
	FIELD = -1;
	POINT = 0;
	PREC = -1;
	ft_strdel(&MODIF);
	MODIF = ft_strdup("");
}

#include <stdio.h>
static void	ft_process(t_data *data)
{
	int		i;
	int		r;

	i = -1;
	while (FORMAT[++i])
	{
		if (FORMAT[i] == '{')
		{
			if (!(r = ft_color_process(data, i + 1)))
				BUFFER = ft_straddchar(BUFFER, FORMAT[i]);
			else
				i += r;
		}
		else if (FORMAT[i] != '%')
			BUFFER = ft_straddchar(BUFFER, FORMAT[i]);
		else if (FORMAT[i] == '%' && !FORMAT[i + 1])
			return ;
		else
		{
			ft_reset_conv(data);
			ft_get_conv(data, ++i);
			i += LEN;
		}
		//printf("BUFFER = %c\n", BUFFER[i]);
	}
}

int			ft_printf(const char *format, ...)
{
	t_data		*data;
	va_list		ap;
	int			r;

	va_start(ap, format);
	data = ft_init_data((char *)format, ap);
	ft_process(data);
	va_end(ap);
	if (ERR)
		return (ERROR);
	ft_putstr(BUFFER);
	r = (int)ft_strlen(BUFFER) + L_ADJUST;
	ft_free_data(data);
	return (r);
}

int			ft_sprintf(char *s, const char *format, ...)
{
	t_data		*data;
	va_list		ap;
	int			r;

	va_start(ap, format);
	data = ft_init_data((char *)format, ap);
	ft_process(data);
	va_end(ap);
	if (ERR)
		return (ERROR);
	r = (int)ft_strlen(BUFFER) + L_ADJUST;
	s = ft_strcpy(s, BUFFER);
	ft_free_data(data);
	return (r);
}
