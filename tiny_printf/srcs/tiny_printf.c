/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 05:33:05 by apoisson          #+#    #+#             */
/*   Updated: 2017/04/17 05:40:32 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tiny_printf.h"

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
		if (TYPE == 'o' && PREC == -1)
			PREFIX = 0;
		if (TYPE != 'o' && TYPE != 'p')
			PREFIX = 0;
		if (PREC == 0)
			ARG[0] = '\0';
	}
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

void		ft_neg_case(t_data *data)
{
	if (ARG[0] == '-')
	{
		SIGN = 0;
		NEG = 1;
		SPACE = 0;
	}
}

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
			s = ft_strjoin(s, " ");
		else
			s = ft_strjoin(((TYPE == 's') ? " " : "0"), s);
		n--;
	}
	return (s);
}

t_color		*ft_new_color(t_color *color, char *name, char *code)
{
	t_color	*new;

	if (!(new = ft_memalloc(sizeof(t_color))))
		exit(0);
	new->name = name;
	new->code = code;
	new->next = color;
	return (new);
}

t_color		*ft_init_color(void)
{
	t_color	*color;

	color = ft_new_color(NULL, "white", "\033[37m");
	color = ft_new_color(color, "cyan", "\033[36m");
	color = ft_new_color(color, "purple", "\033[35m");
	color = ft_new_color(color, "blue", "\033[34m");
	color = ft_new_color(color, "yellow", "\033[33m");
	color = ft_new_color(color, "green", "\033[32m");
	color = ft_new_color(color, "red", "\033[31m");
	color = ft_new_color(color, "black", "\033[30m");
	return (color);
}

t_conv		*ft_init_conv(void)
{
	t_conv	*new;

	if (!(new = ft_memalloc(sizeof(t_conv))))
		exit(0);
	new->base = 10;
	new->space = 0;
	new->prefix = 0;
	new->zero = 0;
	new->left = 0;
	new->sign = 0;
	new->neg = 0;
	new->star = 0;
	new->field = -1;
	new->point = 0;
	new->prec = -1;
	new->delim = 0;
	return (new);
}

t_arg		*ft_init_arg(void)
{
	t_arg	*new;

	if (!(new = ft_memalloc(sizeof(t_conv))))
		exit(0);
	new->arg = NULL;
	new->final_arg = NULL;
	new->left_arg = ft_strdup("");
	new->right_arg = ft_strdup("");
	new->size_init = 0;
	new->size_arg = 0;
	new->size_farg = 0;
	new->size_larg = 0;
	new->size_rarg = 0;
	return (new);
}

t_data		*ft_init_data(char *format, va_list ap)
{
	t_data	*new;

	if (!(new = ft_memalloc(sizeof(t_data))))
		exit(0);
	new->flag = ft_strdup(" +-#0");
	new->f_p = ft_strdup("123456789.*");
	new->delim = ft_strdup("csdouxXpb");
	new->buff = ft_strdup("");
	new->format = ft_strdup(format);
	va_copy(new->ap, ap);
	new->len = 0;
	new->conv = ft_init_conv();
	new->arg = ft_init_arg();
	new->color = ft_init_color();
	new->len_adjust = 0;
	new->ptr = NULL;
	return (new);
}

void		ft_get_arg(t_data *data)
{
	char	*tmp;

	tmp = NULL;
	if (TYPE == 's')
	{
		tmp = va_arg(AP, char *);
		if (tmp)
			ARG = ft_strdup(tmp);
	}
	else if (TYPE == 'c')
		ARG = ft_straddchar(ft_strdup(""), va_arg(AP, int));
	else if (TYPE == 'p')
		ARG = ft_ulltoa_base(va_arg(AP, unsigned long long int), 16, 0);
	else if (TYPE == 'b')
		ARG = ft_lltoa_base(va_arg(AP, long long), 2, 0);
	else if (TYPE == 'd')
		ARG = ft_lltoa_base((va_arg(AP, int)), BASE, 0);
	else
		ARG = ft_lltoa_base((unsigned int)(va_arg(AP, int)),
				BASE, ((TYPE == 'X') ? 1 : 0));
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
		STAR = 1;
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
		STAR = 1;
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

void		ft_process_conv(t_data *data)
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
	ft_process_conv(data);
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

void		ft_get_conv(t_data *data, int i)
{
	LEN = 0;
	if (!FORMAT[i + LEN])
		return ;
	while (FORMAT[i + LEN] && (ft_strchr((const char *)FLAG, FORMAT[i + LEN])
			|| ft_strchr((const char *)F_P, FORMAT[i + LEN])))
	{
		if (ft_strchr((const char *)FLAG, FORMAT[i + LEN]))
			ft_get_flag(data, i);
		if (ft_strchr((const char *)F_P, FORMAT[i + LEN]))
			ft_get_f_p(data, i);
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

int			ft_color_process(t_data *data, int i)
{
	int		len;
	char	*color_flag;
	t_color	*current;

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

void		ft_sub_size_rarg(t_data *data)
{
	if (LEFT && (L_FARG > L_ARG))
	{
		L_RARG = L_FARG - L_ARG;
		L_RARG -= ((PREC >= (int)L_INIT) ? NEG : 0);
		L_RARG -= ((FIELD > (int)L_INIT && FIELD > PREC) ? SPACE : 0);
		L_RARG -= ((FIELD > (int)L_INIT && FIELD > PREC) ? (PREFIX) : 0);
		if ((int)L_RARG > -1)
			RARG = ((!ZERO) ? ft_strspace(L_RARG) : ft_strzero(L_RARG));
		else
			RARG = ft_strdup("\0");
	}
}

void		ft_sub_size_larg(t_data *data)
{
	if (L_FARG > L_ARG)
	{
		L_LARG = L_FARG - L_ARG;
		L_LARG -= ((PREC >= (int)L_INIT) ? NEG : 0);
		L_LARG -= ((FIELD > (int)L_INIT && FIELD > PREC) ? SPACE : 0);
		L_LARG -= ((FIELD > (int)L_INIT && FIELD > PREC) ? (PREFIX) : 0);
		if ((int)L_LARG > -1)
			LARG = ((!ZERO) ? ft_strspace(L_LARG) : ft_strzero(L_LARG));
		else
			LARG = ft_strdup("\0");
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
	ft_sub_size_rarg(data);
	ft_sub_size_larg(data);
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
			ARG = ft_strjoinf(ARG, ft_strdup(" "));
		else if (FIELD > (int)L_ARG)
			ARG = ft_strjoinf(ft_strdup(" "), ARG);
	}
	else if (ZERO)
		LARG = ft_strjoinf(s, LARG);
	else
		ARG = ft_strjoinf(s, ARG);
}

int			tiny_printf(const char *format, ...)
{
	t_data		*data;
	va_list		ap;
	int			r;

	va_start(ap, format);
	data = ft_init_data((char *)format, ap);
	ft_process(data);
	va_end(ap);
	ft_putstr(BUFFER);
	r = (int)ft_strlen(BUFFER) + L_ADJUST;
	return (r);
}

int			tiny_dprintf(int fd, const char *format, ...)
{
	t_data		*data;
	va_list		ap;
	int			r;

	va_start(ap, format);
	data = ft_init_data((char *)format, ap);
	ft_process(data);
	va_end(ap);
	ft_putstr_fd(BUFFER, fd);
	r = (int)ft_strlen(BUFFER) + L_ADJUST;
	return (r);
}

int			tiny_sprintf(char *s, const char *format, ...)
{
	t_data		*data;
	va_list		ap;
	int			r;

	va_start(ap, format);
	data = ft_init_data((char *)format, ap);
	ft_process(data);
	va_end(ap);
	r = (int)ft_strlen(BUFFER) + L_ADJUST;
	s = ft_strcpy(s, BUFFER);
	return (r);
}
