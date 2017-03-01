/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 23:54:04 by apoisson          #+#    #+#             */
/*   Updated: 2017/03/01 04:35:10 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define AP		(data->ap)

#define FORMAT	(data->format)
#define BUFFER	(data->buff)
#define LEN		(data->len)

#define FLAG	(data->flag)
#define F_P		(data->f_p)
#define MOD		(data->mod)
#define DELIM	(data->delim)

#define ARG 	((data->conv)->arg)
#define SPACE	((data->conv)->space)
#define PREFIX	((data->conv)->prefix)
#define ZERO	((data->conv)->zero)
#define LEFT	((data->conv)->left)
#define SIGN	((data->conv)->sign)
#define STAR	((data->conv)->star)
#define FIELD	((data->conv)->field)
#define POINT	((data->conv)->point)
#define PREC	((data->conv)->prec)
#define MODIF	((data->conv)->mod)
#define DELI	((data->conv)->delim)

/*
static void	ft_init(t_fun **tab)
{
	tab[0][0].f = &ft_va_arg_s;
	tab[0][1].f = &ft_va_arg_d;
	tab[0][2].f = &ft_va_arg_o;
	tab[0][3].f = &ft_va_arg_u;
	tab[0][4].f = &ft_va_arg_x;
	tab[0][5].f = &ft_va_arg_p;
}
*/

void		ft_get_arg(t_data *data, int i)
{
	if (FORMAT[i + LEN] == 's')
		ARG = va_arg(AP, char *);
	if (FORMAT[i + LEN] == 'd')
		ARG = ft_itoa(va_arg(AP, int));
}

void		ft_add_spaces(char *s, int n)
{
	while (n-- > 0)
		ft_straddchar(s, ' ');
}

void		ft_get_flag(t_data *data, int i)
{
	if (FORMAT[i + LEN] == ' ')
		SPACE = 1;
	if (FORMAT[i + LEN] == '#')
		PREFIX = 1;
	if (FORMAT[i + LEN] == '-')
		LEFT = 1;
	if (FORMAT[i + LEN] == '+')
		SIGN = 1;
	if (FORMAT[i + LEN] == '0')
		ZERO = 1;
	if (FORMAT[i + LEN] == '*')
		STAR = 1;
	LEN++;
}

void		ft_get_f_p(t_data *data, int i)
{
	if (FORMAT[i + LEN] == '.')
	{
		PREC = ft_atoi(&(FORMAT[i + LEN + 1]));
		LEN += ft_count_digit(PREC) + 1;
	}
	else
	{
		FIELD = ft_atoi(&(FORMAT[i + LEN]));
		LEN += ft_count_digit(FIELD);
	}
}

void		ft_get_mod(t_data *data, int i)
{
	if (FORMAT[i + LEN] == 'l' && FORMAT[i + LEN + 1] == 'l')
	{
		MODIF = ft_strdup("ll");
		LEN++;
	}
	else if (FORMAT[i + LEN] == 'h' && FORMAT[i + LEN + 1] == 'h')
	{
		MODIF = ft_strdup("hh");
		LEN++;
	}
	else if (FORMAT[i + LEN] == 'l')
		MODIF = ft_strdup("l");
	else if (FORMAT[i + LEN] == 'h')
		MODIF = ft_strdup("h");
	else if (FORMAT[i + LEN] == 'j')
		MODIF = ft_strdup("j");
	else if (FORMAT[i + LEN] == 'z')
		MODIF = ft_strdup("z");
	LEN++;
}

void		ft_get_conv(t_data *data, int i)
{
	LEN = 0;
	while (ft_strchr((const char *)FLAG, FORMAT[i + LEN])
			|| ft_strchr((const char *)F_P, FORMAT[i + LEN])
			|| ft_strchr((const char *)MOD, FORMAT[i + LEN]))
	{
		if (ft_strchr((const char *)FLAG, FORMAT[i + LEN]))
			ft_get_flag(data, i);
		if (ft_strchr((const char *)F_P, FORMAT[i + LEN]))
			ft_get_f_p(data, i);
		if (ft_strchr((const char *)MOD, FORMAT[i + LEN]))
			ft_get_mod(data, i);
		LEN++;
	}
	if (!(ft_strchr((const char *)DELIM, FORMAT[i + LEN])))
	{
		if (FIELD > 0)
			ft_add_spaces(BUFFER, FIELD - 1);
		BUFFER = ft_straddchar(BUFFER, FORMAT[i + LEN]);
	}
	else
		ft_get_arg(data, i);
}

/*
** Ne pas oublier de free les struct si mem leaks au filechecker !!!
*/

int			ft_printf(const char *format, ...)
{
	t_data		*data;
	va_list		ap;
	int			i;

	va_start(ap, format);
	data = ft_init_data((char *)format, ap);
	i = -1;
	while (FORMAT[++i])
	{
		if (FORMAT[i] != '%')
			BUFFER = ft_straddchar(BUFFER, FORMAT[i]);
		else
		{
			ft_get_conv(data, ++i);
			i += LEN;
		}
	}
	va_end(ap);
	ft_putstr(BUFFER);
	return ((int)ft_strlen(BUFFER));
}
