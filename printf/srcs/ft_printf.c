/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 23:54:04 by apoisson          #+#    #+#             */
/*   Updated: 2017/03/06 00:00:27 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_debug(t_data *data)
{
	printf("\n|%s|%s|%s|\n", LARG, ARG, RARG);
}

void		ft_reset_bytes(t_data *data)
{
	free(B1);
	B1 = ft_strdup("0xxxxxxx");
	free(B2);
	B2 = ft_strdup("110xxxxx10xxxxxx");
	free(B3);
	B3 = ft_strdup("1110xxxx10xxxxxx10xxxxxx");
	free(B4);
	B4 = ft_strdup("11110xxx10xxxxxx10xxxxxx10xxxxxx");
}

int			ft_bin_to_dec(char *bin)
{
	int		hex;
	int		i;
	int		power;

	hex = 0;
	i = 0;
	power = 7;
	while (bin[i])
		hex += (bin[i++] - '0') * ft_recursive_power(2, power--);
	return (hex);
}

void		ft_split_bytes(t_data *data, char *byte)
{
	int		i;
	char	multi_octet[BYTES + 1];

	if (TYPE == 'c')
		ARG = ft_strdup("");
	i = 0;
	while (i < BYTES)
	{
		multi_octet[i] = ft_bin_to_dec(ft_strsub(byte, 8 * i, 8));
		i++;
	}
	multi_octet[BYTES] = '\0';
	ARG = ft_strjoin(ARG, multi_octet);
}

void		ft_set_bytes(t_data *data, char *byte, int bytes)
{
	int		i;
	int		j;

	ft_reset_bytes(data);
	BYTES = bytes;
	i = BITS - 1;
	j = ft_strlen(byte) - 1;
	while (j >= 0)
	{
		if (byte[j] == 'x')
		{
			if (i >= 0)
				byte[j] = BIN[i--];
			else
				byte[j] = '0';
		}
		j--;
	}
	ft_split_bytes(data, byte);
}

static void	ft_sub(t_data *data, char *byte, int n)
{
	L_BYTES += n;
	if (TYPE == 's' && PREC > -1 && L_BYTES > PREC)
		return ;
	ft_set_bytes(data, byte, n);
}

void		ft_conv_wc(t_data *data, wchar_t c)
{
	BIN = ft_itoa_base((int)c, 2, 0);
	BITS = (int)ft_strlen(BIN);
	if (BITS < 8)
		ft_sub(data, B1, 1);
	else if (BITS < 12)
		ft_sub(data, B2, 2);
	else if (BITS < 17)
		ft_sub(data, B3, 3);
	else
		ft_sub(data, B4, 4);
}

void		ft_get_arg_2(t_data *data)
{
	if (ft_strequ(MODIF, ""))
		ARG = ft_lltoa_base(LL(va_arg(AP, int)),
				BASE, ((TYPE == 'X') ? 1 : 0));
	else if (ft_strequ(MODIF, "hh") && (TYPE == 'x' || TYPE == 'X'))
		ARG = ft_lltoa_base(LL((unsigned char)va_arg(AP, int)),
				BASE, ((TYPE == 'X') ? 1 : 0));
	else if (ft_strequ(MODIF, "hh"))
		ARG = ft_lltoa_base(LL((char)va_arg(AP, int)),
				BASE, ((TYPE == 'X') ? 1 : 0));
	else if (ft_strequ(MODIF, "h") && TYPE == 'd')
		ARG = ft_lltoa_base(LL((short)va_arg(AP, int)),
				BASE, ((TYPE == 'X') ? 1 : 0));
	else if (ft_strequ(MODIF, "h") && TYPE != 'd')
		ARG = ft_lltoa_base(LL((unsigned short)va_arg(AP, int)),
				BASE, ((TYPE == 'X') ? 1 : 0));
	else if ((ft_strequ(MODIF, "l") || ft_strequ(MODIF, "ll")) &&
				(TYPE == 'x' || TYPE == 'X'))
	{
		long	stock;

		stock = va_arg(AP, long);
		if ((unsigned long)stock < ULONG_MAX)
			ARG = ft_lltoa_base(stock,
					BASE, ((TYPE == 'X') ? 1 : 0));
		else
			ARG = ft_ulltoa_base((unsigned long)stock, BASE,
						((TYPE == 'X') ? 1 : 0));
	}
	else if (ft_strequ(MODIF, "l"))
		ARG = ft_lltoa_base(LL(va_arg(AP, long)),
				BASE, ((TYPE == 'X') ? 1 : 0));
	else if (ft_strequ(MODIF, "ll"))
		ARG = ft_lltoa_base(va_arg(AP, long long),
				BASE, ((TYPE == 'X') ? 1 : 0));
	else if ((ft_strequ(MODIF, "j") || ft_strequ(MODIF, "z")) && TYPE == 'd')
		ARG = ft_lltoa_base(LL(va_arg(AP, unsigned long)),
				BASE, ((TYPE == 'X') ? 1 : 0));
	else if ((ft_strequ(MODIF, "j") || ft_strequ(MODIF, "z")))
		ARG = ft_ulltoa_base(LL(va_arg(AP, unsigned long)),
				BASE, ((TYPE == 'X') ? 1 : 0));
	else
		ARG = ft_ulltoa_base(LL((char)va_arg(AP, int)),
				BASE, ((TYPE == 'X') ? 1 : 0));
}

void		ft_conv_ws(t_data *data, wchar_t *arg)
{
	int		i;

	ARG = ft_strdup("");
	i = 0;
	while (arg[i])
	{
		ft_conv_wc(data, arg[i]);
		i++;
	}
}

void		ft_get_arg_1(t_data *data)
{
	if (TYPE == 's' && ft_strequ(MODIF, "l"))
	{
		WS_ARG = va_arg(AP, wchar_t *);
		if (WS_ARG == NULL)
		{
			ARG = ft_strdup("(null)");
			return ;
		}
		ft_conv_ws(data, WS_ARG);
	}
	else if (TYPE == 's')
		ARG = va_arg(AP, char *);
	else if (TYPE == 'c' && ft_strequ(MODIF, "l"))
	{
		WC_ARG = va_arg(AP, wchar_t);
		ERR = (WC_ARG < 0 || WC_ARG > 2097152) ? 1 : 0;
		ft_conv_wc(data, WC_ARG);
	}
	else if (TYPE == 'c')
		ARG = ft_straddchar(ft_strdup(""), va_arg(AP, int));
	else if (TYPE == 'p')
		ARG = ft_ulltoa_base(va_arg(AP, unsigned long long int), 16, 0);
	else if (TYPE == 'u' || TYPE == 'o')
	{
		if (ft_strequ(MODIF, ""))
			ARG = ft_lltoa_base((unsigned int)(va_arg(AP, int)), BASE, 0);
		else if (ft_strequ(MODIF, "hh"))
		{
			if (TYPE == 'o')
			{
				char stock;

				stock = va_arg(AP, int);
				if ((unsigned char)stock < UCHAR_MAX)
					ARG = ft_lltoa_base(stock, BASE, 0);
				else
					ARG = ft_ulltoa_base((unsigned char)stock, BASE, 0);
			}
			else
				ARG = ft_lltoa_base((unsigned char)va_arg(AP, int), BASE, 0);
		}
		else if (ft_strequ(MODIF, "h"))
			ARG = ft_lltoa_base((unsigned short)(va_arg(AP, int)), BASE, 0);
		else
			ARG = ft_ulltoa_base((unsigned long)(va_arg(AP, long)), BASE, 0);
	}
	else
		ft_get_arg_2(data);
}

/*
** Adds n spaces to the string s
*/

char		*ft_add_space_or_zero(char *s, char c, int n)
{
	while (n-- > 0)
		s = ft_straddchar(s, c);
	return (s);
}

void		ft_get_flag(t_data *data, int i)
{
	if (FORMAT[i + LEN] == ' ')
		SPACE = 1;
	if (FORMAT[i + LEN] == '#')
		PREFIX = 2;
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
	if (FORMAT[i + LEN] == '.' && ft_isdigit(FORMAT[i + LEN + 1]))
	{
		PREC = ft_atoi(&(FORMAT[i + LEN + 1]));
		LEN += ft_count_digit(PREC) + 1;
	}
	else if (FORMAT[i + LEN] == '.')
	{
		PREC = 0;
		LEN++;
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

void		ft_adjust_2(t_data *data)
{
	if (TYPE != 'd')
	{
		SPACE = 0;
		SIGN = 0;
	}
	if (TYPE == 'd' || TYPE == 's' || TYPE == 'c')
		PREFIX = 0;
	if (TYPE == 'o' && PREFIX)
		PREFIX = 1;
	if (TYPE == 'c')
		PREC = -1;
	if (TYPE == 'p')
		PREFIX = 2;
	if (PREC > -1 && TYPE != 's')
		ZERO = 0;
}

void		ft_adjust(t_data *data)
{
	if (TYPE >= 'C' && TYPE <= 'U')
	{
		TYPE += 32;
		MODIF = "l";
	}
	if (TYPE == 'i')
		TYPE = 'd';
	if (TYPE == 'x' || TYPE == 'X' || TYPE == 'p')
		BASE = 16;
	else if (TYPE == 'o')
		BASE = 8;
	else
		BASE = 10;
	if (LEFT)
		ZERO = 0;
	if (SIGN)
		SPACE = 0;
	if (TYPE == 's')
	{
		SIGN = 0;
		PREFIX = 0;
	}
	ft_adjust_2(data);
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

	if (PREC >= (int)L_INIT)
		ARG = ft_strjoin("-", ARG);
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

void		ft_adjust_sign(t_data *data)
{
	int		i;

	if (NEG)
		FARG[0] = '-';
	else if (SIGN)
		FARG[0] = '+';
	i = 0;
	while (FARG[++i])
	{
		if (FARG[i] == '-' || FARG[i] == '+')
		{
			FARG[i] = '0';
			return ;
		}
	}
}

void		ft_set_size(t_data *data)
{
	if (TYPE == 's' && PREC >= (int)L_INIT)
		PREC = -1;
	L_ARG = (((PREC > -1 && TYPE == 's') || PREC >= (int)L_ARG) ?
			(PREC + SIGN) : L_ARG + SIGN);
	if (L_ARG > ft_strlen(ARG))
		ARG = ft_stradd_char(data, ARG, L_ARG - ft_strlen(ARG));
	if (LEFT && (L_FARG > L_ARG))
	{
		L_RARG = L_FARG - L_ARG;
		L_RARG -= ((PREC >= (int)L_INIT) ? NEG : 0);
		L_RARG -= ((FIELD > (int)L_INIT && FIELD > PREC) ? SPACE : 0);
		L_RARG -= ((FIELD > (int)L_INIT && FIELD > PREC) ? (PREFIX) : 0);
		RARG = ((!ZERO) ? ft_strspace(L_RARG) : ft_strzero(L_RARG));
	}
	else if (L_FARG > L_ARG)
	{
		L_LARG = L_FARG - L_ARG;
		L_LARG -= ((PREC >= (int)L_INIT) ? NEG : 0);
		L_LARG -= ((FIELD > (int)L_INIT && FIELD > PREC) ? SPACE : 0);
		L_LARG -= ((FIELD > (int)L_INIT && FIELD > PREC) ? (PREFIX) : 0);
		LARG = ((!ZERO) ? ft_strspace(L_LARG) : ft_strzero(L_LARG));
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

void		ft_set_prefix(t_data *data)
{
	char	*s;

	s = ft_strdup("0");
	if (TYPE == 'x' || TYPE == 'p')
		s = ft_straddchar(s, 'x');
	else if (TYPE == 'X')
		s = ft_straddchar(s, 'X');
	if (TYPE == 'o' && PREFIX && PREC > (int)L_INIT)
	{
		if (FIELD > (int)L_ARG && LEFT)
			ARG = ft_strjoin(ARG, " ");
		else if (FIELD > (int)L_ARG)
			ARG = ft_strjoin(" ", ARG);
	}
	else if (ZERO)
		LARG = ft_strjoin(s, LARG);
	else
		ARG = ft_strjoin(s, ARG);
}

void		ft_process(t_data *data)
{
	ft_set_size(data);
	if (SIGN)
		ft_set_sign(data);
	if (PREFIX)
		ft_set_prefix(data);
	if ((PREC > -1 && TYPE == 's') || PREC > (int)L_ARG)
		ARG = ft_strsub(ARG, 0, PREC + SIGN);
	if (SPACE)
		BUFFER = ft_strjoin(BUFFER, " ");
	if (LEFT)
		FARG = ft_strjoin(ARG, RARG);
	else
		FARG = ft_strjoin(LARG, ARG);
	if (PREC == -1 && ZERO)
		ft_adjust_sign(data);
	BUFFER = ft_strjoinf(BUFFER, FARG);
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

void		ft_adjust_arg(t_data *data)
{
	if (ARG == NULL)
	{
		ARG = ft_strdup("(null)");
		return ;
	}
	if (!(ARG[0]) && TYPE != 's')
	{
		FIELD--;
		L_ADJUST++;
	}
	if (ARG[0] == '0')
	{
		if (TYPE != 'o' && TYPE != 'p')
			PREFIX = 0;
		if (PREC == 0)
			ARG[0] = '\0';
	}
}

/*
** Dispatch the process depending of the type
** String VS Numbers
*/

void		ft_dispatch(t_data *data)
{
	ft_adjust_arg(data);
	L_ARG = ft_strlen(ARG);
	L_INIT = ft_strlen(ARG);
	ft_neg_case(data);
	if (FIELD > (int)L_INIT && FIELD > PREC && !LEFT)
		SPACE = 0;
	if (TYPE == 's' || TYPE == 'c')
	{
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

void		ft_bad_delim(t_data *data, int i)
{
	if (!LEFT && FIELD > 0)
		BUFFER = ft_add_space_or_zero(BUFFER,
				((ZERO) ? '0' : ' '), FIELD - 1);
	BUFFER = ft_straddchar(BUFFER, FORMAT[i + LEN]);
	if (LEFT && FIELD > 0)
		BUFFER = ft_add_space_or_zero(BUFFER,
				((ZERO) ? '0' : ' '), FIELD - 1);
}

/*
** Get the flags, the field, the precision, the modifiers
** Verify if the delimiter is OK, treat directly if not
** If delim OK : get the arg and call the process
*/

void		ft_get_conv(t_data *data, int i)
{
	LEN = 0;
	if (!FORMAT[i + LEN])
		return ;
	while (FORMAT[i + LEN] && (ft_strchr((const char *)FLAG, FORMAT[i + LEN])
			|| ft_strchr((const char *)F_P, FORMAT[i + LEN])
			|| ft_strchr((const char *)MOD, FORMAT[i + LEN])))
	{
		if (ft_strchr((const char *)FLAG, FORMAT[i + LEN]))
			ft_get_flag(data, i);
		if (ft_strchr((const char *)F_P, FORMAT[i + LEN]))
			ft_get_f_p(data, i);
		if (ft_strchr((const char *)MOD, FORMAT[i + LEN]))
			ft_get_mod(data, i);
	}
	if (!(ft_strchr((const char *)DELIM, FORMAT[i + LEN])))
		ft_bad_delim(data, i);
	else
	{
		TYPE = FORMAT[i + LEN];
		ft_adjust(data);
		ft_get_arg_1(data);
		ft_dispatch(data);
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
	MODIF = ft_strdup("");
}

void		ft_free_the_shit(t_data *data)
{
	free(FLAG);
	free(F_P);
	free(MOD);
	free(DELIM);
	free(BUFFER);
	free(FORMAT);
	free(B1);
	free(B2);
	free(B3);
	free(B4);
	/*
	if (ARG)
	{
		printf("ARG |%s|\n", ARG);
		free(ARG);
	}
	if (LARG)
	{
		printf("LARG |%s|\n", LARG);
		free(LARG);
	}
	if (RARG)
	{
		printf("RARG |%s|\n", RARG);
		free(RARG);
	}
	if (WS_ARG)
	{
		printf("WS_ARG |%ls|\n", WS_ARG);
		free(WS_ARG);
	}
	if (BIN)
	{
		printf("BIN |%s|\n", BIN);
		free(BIN);
	}
	*/
/*
	free(WS_ARG);
	free(BIN);
	*/
}

/*
** Ne pas oublier de free les struct si mem leaks au filechecker !!!
*/

int			ft_printf(const char *format, ...)
{
	t_data		*data;
	va_list		ap;
	int			i;
	int			r;

	va_start(ap, format);
	data = ft_init_data((char *)format, ap);
	i = -1;
	while (FORMAT[++i])
	{
		if (FORMAT[i] != '%')
			BUFFER = ft_straddchar(BUFFER, FORMAT[i]);
		else
		{
			ft_reset_conv(data);
			ft_get_conv(data, ++i);
			i += LEN;
		}
	}
	va_end(ap);
	if (ERR)
		return (ERROR);
	ft_putstr(BUFFER);
	r = (int)ft_strlen(BUFFER) + L_ADJUST;
	ft_free_the_shit(data);
	return (r);
}

int			ft_sprintf(char *s, const char *format, ...)
{
	t_data		*data;
	va_list		ap;
	int			i;
	int			r;

	va_start(ap, format);
	data = ft_init_data((char *)format, ap);
	i = -1;
	while (FORMAT[++i])
	{
		if (FORMAT[i] != '%')
			BUFFER = ft_straddchar(BUFFER, FORMAT[i]);
		else
		{
			ft_reset_conv(data);
			ft_get_conv(data, ++i);
			i += LEN;
		}
	}
	va_end(ap);
	if (ERR)
		return (ERROR);
	r = (int)ft_strlen(BUFFER) + L_ADJUST;
	s = ft_strcpy(s, BUFFER);
	ft_free_the_shit(data);
	return (r);
}
