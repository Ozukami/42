/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 23:54:04 by apoisson          #+#    #+#             */
/*   Updated: 2017/03/11 02:34:24 by qumaujea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	ft_strdel(&bin);
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
	PTR = ARG;
	ARG = ft_strjoin(ARG, multi_octet);
	ft_strdel(&PTR);
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
	free(BIN);
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

void		ft_conv_ws(t_data *data)
{
	int		i;

	free(ARG);
	if (WS_ARG == NULL)
	{
		ARG = ft_strdup("(null)");
		return ;
	}
	ARG = ft_strdup("");
	i = 0;
	while (WS_ARG[i])
	{
		ft_conv_wc(data, WS_ARG[i]);
		i++;
	}
}

void		ft_get_arg_d(t_data *data)
{
	free(ARG);
	if (ft_strequ(MODIF, "hh"))
		ARG = ft_lltoa_base(((char)va_arg(AP, int)), BASE, 0);
	else if (ft_strequ(MODIF, "h"))
		ARG = ft_lltoa_base(((short)va_arg(AP, int)), BASE, 0);
	else if (ft_strequ(MODIF, "l"))
		ARG = ft_lltoa_base((va_arg(AP, long)), BASE, 0);
	else if (ft_strequ(MODIF, "ll"))
		ARG = ft_lltoa_base(va_arg(AP, long), BASE, 0);
	else if (ft_strequ(MODIF, "j") || ft_strequ(MODIF, "z"))
		ARG = ft_lltoa_base((va_arg(AP, unsigned long)), BASE, 0);
	else
		ARG = ft_lltoa_base((va_arg(AP, int)), BASE, 0);
}

void		ft_get_arg_oux(t_data *data)
{
	free(ARG);
	if (ft_strequ(MODIF, ""))
		ARG = ft_lltoa_base((unsigned int)(va_arg(AP, int)),
				BASE, ((TYPE == 'X') ? 1 : 0));
	else if (ft_strequ(MODIF, "hh"))
		ARG = ft_ulltoa_base((unsigned char)va_arg(AP, int),
				BASE, ((TYPE == 'X') ? 1 : 0));
	else if (ft_strequ(MODIF, "h"))
		ARG = ft_lltoa_base((unsigned short)(va_arg(AP, int)),
				BASE, ((TYPE == 'X') ? 1 : 0));
	else
		ARG = ft_ulltoa_base((va_arg(AP, unsigned long)),
				BASE, ((TYPE == 'X') ? 1 : 0));
}

void		ft_get_string_arg(t_data *data)
{
	char	*tmp;

	tmp = NULL;
	if (ft_strequ(MODIF, "l"))
	{
		WS_ARG = va_arg(AP, wchar_t *);
		ft_conv_ws(data);
	}
	else
	{
		tmp = va_arg(AP, char *);
		free(ARG);
		if (tmp)
			ARG = ft_strdup(tmp);
	}
}

void		ft_get_arg(t_data *data)
{
	if (TYPE == 'c')
	{
		free(ARG);
		if (ft_strequ(MODIF, "l"))
		{
			WC_ARG = va_arg(AP, wchar_t);
			ERR = (WC_ARG < 0 || WC_ARG > 2097152) ? 1 : 0;
			ft_conv_wc(data, WC_ARG);
		}
		else
			ARG = ft_straddchar(ft_strdup(""), va_arg(AP, int));
	}
	else if (TYPE == 's')
		ft_get_string_arg(data);
	else if (TYPE == 'p')
		ARG = ft_ulltoa_base(va_arg(AP, unsigned long long int), 16, 0);
	else if (TYPE == 'b')
		ARG = ft_lltoa_base(va_arg(AP, long long), 2, 0);
	else if (TYPE != 'd')
		ft_get_arg_oux(data);
	else
		ft_get_arg_d(data);
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
	LEN++;
}

void		ft_get_p(t_data *data, int i)
{
	if (FORMAT[i + LEN + 1] == '*')
	{
		PREC = va_arg(AP, int);
		if (PREC < 0)
			PREC = -1;
		LEN += 2;
		return ;
	}
	PREC = ft_atoi(&(FORMAT[i + LEN + 1]));
	LEN += ft_count_digit(PREC) + 1;
}

void		ft_get_f(t_data *data, int i)
{
	if (FORMAT[i + LEN] == '*')
	{
		FIELD = va_arg(AP, int);
		if (FIELD < 0)
		{
			LEFT = 1;
			FIELD = -FIELD;
		}
		LEN++;
	}
	else
	{
		FIELD = ft_atoi(&(FORMAT[i + LEN]));
		LEN += ft_count_digit(FIELD);
	}
}

void		ft_get_f_p(t_data *data, int i)
{
	if (FORMAT[i + LEN] == '.' && (ft_isdigit(FORMAT[i + LEN + 1]) ||
				FORMAT[i + LEN + 1] == '*'))
		ft_get_p(data, i);
	else if (FORMAT[i + LEN] == '.')
	{
		PREC = 0;
		LEN++;
	}
	else
		ft_get_f(data, i);
}

int			ft_multi_mod(t_data *data)
{
	if (ft_strequ(MODIF, "z") || ft_strequ(MODIF, "j"))
	{
		LEN++;
		return (1);
	}
	return (0);
}

void		ft_get_mod(t_data *data, int i)
{
	if (ft_multi_mod(data))
		return ;
	free(MODIF);
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
	else
		MODIF = ft_strdup("");
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
		free(MODIF);
		MODIF = ft_strdup("l");
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
			s = ft_strjoin(s, " "); // !
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
		ARG = ft_strjoin("-", ARG); // !
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

void		ft_sub_size(t_data *data)
{
	if (LEFT && (L_FARG > L_ARG))
	{
		L_RARG = L_FARG - L_ARG;
		L_RARG -= ((PREC >= (int)L_INIT) ? NEG : 0);
		L_RARG -= ((FIELD > (int)L_INIT && FIELD > PREC) ? SPACE : 0);
		L_RARG -= ((FIELD > (int)L_INIT && FIELD > PREC) ? (PREFIX) : 0);
		PTR = RARG;
		RARG = ((!ZERO) ? ft_strspace(L_RARG) : ft_strzero(L_RARG));
		ft_strdel(&PTR);
	}
	else if (L_FARG > L_ARG)
	{
		L_LARG = L_FARG - L_ARG;
		L_LARG -= ((PREC >= (int)L_INIT) ? NEG : 0);
		L_LARG -= ((FIELD > (int)L_INIT && FIELD > PREC) ? SPACE : 0);
		L_LARG -= ((FIELD > (int)L_INIT && FIELD > PREC) ? (PREFIX) : 0);
		PTR = LARG;
		LARG = ((!ZERO) ? ft_strspace(L_LARG) : ft_strzero(L_LARG));
		ft_strdel(&PTR);
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
	ft_sub_size(data);
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
			ARG = ft_strjoinf(ARG, " ");
		else if (FIELD > (int)L_ARG)
			ARG = ft_strjoinf(" ", ARG);
	}
	else if (ZERO)
		LARG = ft_strjoinf(s, LARG);
	else
		ARG = ft_strjoinf(s, ARG);
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
	{
		PTR = BUFFER;
		BUFFER = ft_strjoin(BUFFER, " ");
		ft_strdel(&PTR);
	}
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
	if (FIELD > (int)L_INIT && FIELD > PREC && !LEFT && TYPE != 'd')
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
		BUFFER = ft_add_space_or_zero(BUFFER, ' ', FIELD - 1);
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
	if (!FORMAT[i + LEN])
		return ;
	if (!(ft_strchr((const char *)DELIM, FORMAT[i + LEN])))
		ft_bad_delim(data, i);
	else
	{
		TYPE = FORMAT[i + LEN];
		ft_adjust(data);
		ft_get_arg(data);
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
	ft_strdel(&MODIF);
	MODIF = ft_strdup("");
}

void		ft_free_the_shit(t_data *data)
{
	ft_strdel(&FLAG);
	ft_strdel(&F_P);
	ft_strdel(&MOD);
	ft_strdel(&DELIM);
	ft_strdel(&BUFFER);
	ft_strdel(&FORMAT);
	ft_strdel(&MODIF);
	ft_strdel(&B1);
	ft_strdel(&B2);
	ft_strdel(&B3);
	ft_strdel(&B4);
	ft_strdel(&ARG);
	ft_strdel(&LARG);
	ft_strdel(&RARG);
	ft_strdel(&BIN);
	free(data->conv);
	free(data->arg);
	free(data->uni);
	free(data);
}

/*
** FREE TEST (not tested yet)
*/

/*
void		ft_free_conv(t_conv *conv)
{
	free(conv->mod);
	conv->mod = NULL;
}

void		ft_free_arg(t_arg *arg)
{
	free(arg->arg);
	arg->arg = NULL;
	free(arg->final_arg);
	arg->final_arg = NULL;
	free(arg->left_arg);
	arg->left_arg = NULL;
	free(arg->right_arg);
	arg->right_arg = NULL;
}

void		ft_free_uni(t_uni *uni)
{
	free(uni->ws_arg);
	uni->ws_arg = NULL;
	free(uni->bin);
	uni->bin = NULL;
	free(uni->byte1);
	uni->byte1 = NULL;
	free(uni->byte2);
	uni->byte2 = NULL;
	free(uni->byte3);
	uni->byte3 = NULL;
	free(uni->byte4);
	uni->byte4 = NULL;
}

void		ft_free_data(t_data *data)
{
	ft_free_conv((data->conv));
	ft_free_arg((data->arg));
	ft_free_uni((data->uni));
	free(FLAG);
	FLAG = NULL;
	free(F_P);
	F_P = NULL;
	free(MOD);
	MOD = NULL;
	free(DELIM);
	DELIM = NULL;
	free(BUFFER);
	BUFFER = NULL;
	free(FORMAT);
	FORMAT = NULL;
}
*/

// A RENAME

int				ft_color_process(t_data *data, int i)
{
	int		len;
	char	*color;

	len = 0;
	while (FORMAT[i + len] != '}' || FORMAT[i + len] != '\0')
		len++;
	if (FORMAT[i + len] != '}')
		return (-1);
	ft_strsub(FORMAT, i, i + len);
}

static void		ft_process_2(t_data *data)
{
	int		i;

	i = -1;
	while (FORMAT[++i])
	{
		if (FORMAT[i] != '%')
			BUFFER = ft_straddchar(BUFFER, FORMAT[i]);
		if (FORMAT[i] == '{')
			if (!ft_color_process(data, i))
				ft_straddchar(BUFFER, FORMAT[i]);
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
	ft_free_the_shit(data);
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
	ft_free_the_shit(data);
	return (r);
}
