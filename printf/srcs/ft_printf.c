/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 23:54:04 by apoisson          #+#    #+#             */
/*   Updated: 2017/03/02 05:26:02 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_get_arg_2(t_data *data)
{
	if (ft_strequ(MODIF, ""))
		ARG = ft_lltoa_base(LL(va_arg(AP, int)),
				BASE, ((TYPE == 'X') ? 1 : 0));
	else if (ft_strequ(MODIF, "hh"))
		ARG = ft_lltoa_base(LL((char)va_arg(AP, int)),
				BASE, ((TYPE == 'X') ? 1 : 0));
	else if (ft_strequ(MODIF, "h"))
		ARG = ft_lltoa_base(LL((short)va_arg(AP, int)),
				BASE, ((TYPE == 'X') ? 1 : 0));
	else if (ft_strequ(MODIF, "l"))
		ARG = ft_lltoa_base(LL(va_arg(AP, long)),
				BASE, ((TYPE == 'X') ? 1 : 0));
	else if (ft_strequ(MODIF, "ll"))
		ARG = ft_lltoa_base(va_arg(AP, long long),
				BASE, ((TYPE == 'X') ? 1 : 0));
	else if (TYPE == 'd'
			&& (ft_strequ(MODIF, "j") || ft_strequ(MODIF, "z")))
		ARG = ft_lltoa_base(LL((char)va_arg(AP, int)),
				BASE, ((TYPE == 'X') ? 1 : 0));
	else
		ARG = ft_ulltoa_base(LL((char)va_arg(AP, int)),
				BASE, ((TYPE == 'X') ? 1 : 0));
}

void		ft_get_arg_1(t_data *data)
{
	char	c;

	if (TYPE == 's')
		ARG = va_arg(AP, char *);
	else if (TYPE == 'c')
	{
		c = va_arg(AP, int);
		ARG = ft_strdup(&c);
	}
	else if (TYPE == 'p')
		ARG = ft_ulltoa_base(va_arg(AP, unsigned long long int), 16, 0);
	else
		ft_get_arg_2(data);
	L_ARG = ft_strlen(ARG);
}

/*
** Adds n spaces to the string s
*/

char		*ft_add_spaces(char *s, int n)
{
	while (n-- > 0)
		s = ft_straddchar(s, ' ');
	return (s);
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

void		ft_set_base(t_data *data)
{
	if (TYPE == 'x' || TYPE == 'X' || TYPE == 'p')
		BASE = 16;
	else if (TYPE == 'o')
		BASE = 8;
}

void		ft_set_size(t_data *data)
{
	L_ARG = ((PREC > -1) ?
			(size_t)ft_min((int)L_ARG, PREC) : L_ARG);
	if (LEFT && (L_FARG > L_ARG))
	{
		L_RARG = L_FARG - L_ARG;
		RARG = ft_strspace(L_RARG);
	}
	else if (L_FARG > L_ARG)
	{
		L_LARG = L_FARG - L_ARG;
		LARG = ft_strspace(L_LARG);
	}
}

void		ft_process(t_data *data)
{
	ft_set_size(data);
	if (PREC > -1)
		ARG = ft_strsub(ARG, 0, PREC);
	if (LEFT)
		BUFFER = ft_strjoinf(BUFFER,
				ft_strjoin(ARG, RARG));
	else
		BUFFER = ft_strjoinf(BUFFER,
				ft_strjoin(LARG, ARG));
}

/*
** Dispatch the process depending of the type
** String VS Numbers
*/

void		ft_dispatch(t_data *data)
{
	if (TYPE == 's' || TYPE == 'c')
	{
		if (ARG == NULL)
		{
			ARG = ft_strdup("(null)");
			return ;
		}
		if (FIELD == -1 && PREC == -1)
			L_FARG = L_ARG;
		else if ((FIELD == -1) || (FIELD < PREC && PREC < (int)L_ARG))
			L_FARG = (size_t)ft_min(PREC, (int)L_ARG);
		else if ((PREC == -1) || (FIELD < (int)L_ARG && (int)L_ARG <= PREC))
			L_FARG = (size_t)ft_max(FIELD, (int)L_ARG);
		else
			L_FARG = (size_t)FIELD;
	}
	else
		L_FARG = (size_t)ft_max(ft_max(FIELD, PREC), (int)L_ARG);
	ft_process(data);
}

/*
** Get the flags, the field, the precision, the modifiers
** Verify if the delimiter is OK, treat directly if not
** If delim OK : get the arg and call the process
*/

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
	}
	if (!(ft_strchr((const char *)DELIM, FORMAT[i + LEN])))
	{
		if (FIELD > 0)
			BUFFER = ft_add_spaces(BUFFER, FIELD - 1);
		BUFFER = ft_straddchar(BUFFER, FORMAT[i + LEN]);
	}
	else
	{
		TYPE = FORMAT[i + LEN];
		ft_set_base(data);
		ft_get_arg_1(data);
		ft_dispatch(data);
	}
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
