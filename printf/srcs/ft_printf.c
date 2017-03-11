/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 23:54:04 by apoisson          #+#    #+#             */
/*   Updated: 2017/03/11 06:04:55 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Adds n spaces to the string s
*/

char		*ft_add_space_or_zero(char *s, char c, int n)
{
	while (n-- > 0)
		s = ft_straddchar(s, c);
	return (s);
}

char		*ft_stradd_char(t_data *data, char *s, int n)
{
	while (n > 0)
	{
		if (LEFT && TYPE == 's')
		{
			PTR = s;
			s = ft_strjoin(s, " ");
			ft_strdel(&PTR);
		}
		else
		{
			PTR = s;
			s = ft_strjoin(((TYPE == 's') ? " " : "0"), s);
			ft_strdel(&PTR);
		}
		n--;
	}
	return (s);
}

void		ft_replace_neg(t_data *data)
{
	int		i;

	if (PREC >= (int)L_INIT)
	{
		PTR = ARG;
		ARG = ft_strjoin("-", ARG);
		ft_strdel(&PTR);
	}
	i = 0;
	if (PREC >= (int)L_INIT)
	{
		while (ARG[++i])
		{
			if (ARG[i] == '-')
			{
				ARG[i] = '0';
				return ;
			}
		}
	}
}

void		ft_neg_case(t_data *data)
{
	if (ARG[0] == '-')
	{
		SIGN = 0;
		NEG = 1;
		SPACE = 0;
	}
}

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

// A RENAME

int				ft_color_process(t_data *data, int i)
{
	int			len;
	char		*color_flag;
	t_color		*current;

	len = 0;
	while (FORMAT[i + len] != '}' && FORMAT[i + len] != '\0')
		len++;
	if (FORMAT[i + len] != '}')
		return (-1);
	color_flag = ft_strsub(FORMAT, i, len);
	current = COLOR;
	while (current)
	{
		if (ft_strequ(color_flag, current->name))
		{
			BUFFER = ft_strjoin(BUFFER, current->code);
			return (len + 1);
		}
		current = current->next;
	}
	return (0);
}

static void		ft_process_2(t_data *data)
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

	va_start(ap, format);
	data = ft_init_data((char *)format, ap);
	ft_process_2(data);
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
	ft_process_2(data);
	va_end(ap);
	if (ERR)
		return (ERROR);
	r = (int)ft_strlen(BUFFER) + L_ADJUST;
	s = ft_strcpy(s, BUFFER);
	ft_free_data(data);
	return (r);
}
