/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 23:54:04 by apoisson          #+#    #+#             */
/*   Updated: 2017/03/02 08:24:08 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_debug(t_data *data)
{
	printf("|%s|%s|%s|\n", LARG, ARG, RARG);
}

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
	L_INIT = ft_strlen(ARG);
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

void		ft_adjust(t_data *data)
{
	if (TYPE == 'x' || TYPE == 'X' || TYPE == 'p')
		BASE = 16;
	else if (TYPE == 'o')
		BASE = 8;
	if (TYPE >= 'C' && TYPE <= 'U')
	{
		TYPE += 32;
		MODIF = "l";
	}
	if (TYPE == 'i')
		TYPE = 'd';
	if (LEFT)
		ZERO = 0;
	if (SIGN)
		SPACE = 0;
	if (TYPE == 's')
	{
		SIGN = 0;
		PREFIX = 0;
	}
}

char		*ft_stradd_char(t_data *data, char *s, int n)
{
	while (n > 0)
	{
		if (LEFT && TYPE == 's')
			s = ft_strjoin(s, " ");
		else
			s = ft_strjoin(((TYPE == 's') ? " " : "0"), s);
		n--;
	}
	return (s);
}

void		ft_replace_neg(t_data *data)
{
	int		i;

	if (PREC > (int)L_INIT)
		ARG = ft_strjoin("-", ARG);
	i = 0;
	if (PREC > (int)L_INIT)
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

void		ft_set_size(t_data *data)
{
	L_ARG = (((PREC > -1 && TYPE == 's') || PREC >= (int)L_ARG) ?
			(PREC + SIGN) : L_ARG + SIGN);
	if (L_ARG > ft_strlen(ARG))
		ARG = ft_stradd_char(data, ARG, L_ARG - ft_strlen(ARG));
	if (LEFT && (L_FARG > L_ARG))
	{
		L_RARG = L_FARG - L_ARG;
		L_RARG -= ((PREC > (int)L_INIT) ? NEG : 0);
		L_RARG -= ((FIELD > (int)L_INIT && FIELD > PREC && LEFT) ? SPACE : 0);
		RARG = ft_strspace(L_RARG);
	}
	else if (L_FARG > L_ARG)
	{
		L_LARG = L_FARG - L_ARG;
		L_LARG -= ((PREC > (int)L_INIT) ? NEG : 0);
		L_LARG -= ((FIELD > (int)L_INIT && FIELD > PREC && LEFT) ? SPACE : 0);
		LARG = ft_strspace(L_LARG);
	}
	if (NEG && PREC > 0)
		ft_replace_neg(data);
}

void		ft_set_sign(t_data *data)
{
	int		i;

	i = -1;
	while (ARG[++i])
	{
		if (ARG[i] == '0' || (ARG[i] == ' ' && ARG[i + 1] != ' '))
		{
			ARG[i] = '+';
			return ;
		}
	}
}

void		ft_process(t_data *data)
{
	ft_set_size(data);
	if (SIGN)
		ft_set_sign(data);
	if ((PREC > -1 && TYPE == 's') || PREC > (int)L_ARG)
		ARG = ft_strsub(ARG, 0, PREC + SIGN);
	if (SPACE)
		BUFFER = ft_strjoin(BUFFER, " ");
	if (LEFT)
		BUFFER = ft_strjoinf(BUFFER,
				ft_strjoin(ARG, RARG));
	else
		BUFFER = ft_strjoinf(BUFFER,
				ft_strjoin(LARG, ARG));
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

/*
** Dispatch the process depending of the type
** String VS Numbers
*/

void		ft_dispatch(t_data *data)
{
	ft_neg_case(data);
	if (FIELD > (int)L_INIT && FIELD > PREC && !LEFT)
		SPACE = 0;
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
		ft_adjust(data);
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
