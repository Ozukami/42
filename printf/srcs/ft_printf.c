/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 23:54:04 by apoisson          #+#    #+#             */
/*   Updated: 2017/03/26 00:14:08 by apoisson         ###   ########.fr       */
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
	STAR = 0;
	L_LARG = 0;
	L_RARG = 0;
	MODIF = ft_strdup("");
	LARG = ft_strdup("");
	RARG = ft_strdup("");
}

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
	}
}

int			ft_printf(const char *format, ...)
{
	t_data		*data;
	va_list		ap;
	int			r;
	int			i;

	va_start(ap, format);
	data = ft_init_data((char *)format, ap);
	ft_process(data);
	va_end(ap);
	if (ERR)
		return (-1);
	if (POS_C0 != -1)
	{
		i = 0;
		while (i < POS_C0)
			ft_putchar(BUFFER[i++]);
		ft_putchar('\0');
		while (i < (int)ft_strlen(BUFFER))
			ft_putchar(BUFFER[i++]);
	}
	else
		ft_putstr(BUFFER);
	r = (int)ft_strlen(BUFFER) + L_ADJUST;
	return (r);
}

int			ft_dprintf(int fd, const char *format, ...)
{
	t_data		*data;
	va_list		ap;
	int			r;
	int			i;

	va_start(ap, format);
	data = ft_init_data((char *)format, ap);
	ft_process(data);
	va_end(ap);
	if (ERR)
		return (-1);
	if (POS_C0 != -1)
	{
		i = 0;
		while (i < POS_C0)
			ft_putchar_fd(BUFFER[i++], fd);
		ft_putchar_fd('\0', fd);
		while (i < (int)ft_strlen(BUFFER))
			ft_putchar_fd(BUFFER[i++], fd);
	}
	else
		ft_putstr_fd(BUFFER, fd);
	r = (int)ft_strlen(BUFFER) + L_ADJUST;
	return (r);
}

int			ft_sprintf(char *s, const char *format, ...)
{
	t_data		*data;
	va_list		ap;
	int			r;
	int			i;

	va_start(ap, format);
	data = ft_init_data((char *)format, ap);
	ft_process(data);
	va_end(ap);
	if (ERR)
		return (-1);
	r = (int)ft_strlen(BUFFER) + L_ADJUST;
	if (POS_C0 != -1)
	{
		i = -1;
		while (++i < POS_C0)
			s[i] = BUFFER[i];
		s[i--] = '\0';
		while (++i < (int)ft_strlen(BUFFER))
			s[i + 1] = BUFFER[i];
	}
	else
		s = ft_strcpy(s, BUFFER);
	return (r);
}
