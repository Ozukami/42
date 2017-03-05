/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 01:22:47 by apoisson          #+#    #+#             */
/*   Updated: 2017/03/05 23:37:25 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h> // !!!!!

# define ERROR		-1
# define SUCCES		1

# define AP			(data->ap)

# define FORMAT		(data->format)
# define BUFFER		(data->buff)
# define ERR		(data->error)
# define LEN		(data->len)

# define FLAG		(data->flag)
# define F_P		(data->f_p)
# define MOD		(data->mod)
# define DELIM		(data->delim)

# define ARG 		((data->arg)->arg)
# define FARG 		((data->arg)->final_arg)
# define LARG 		((data->arg)->left_arg)
# define RARG		((data->arg)->right_arg)

# define L_INIT		((data->arg)->size_init)
# define L_ARG		((data->arg)->size_arg)
# define L_FARG		((data->arg)->size_farg)
# define L_LARG		((data->arg)->size_larg)
# define L_RARG 	((data->arg)->size_rarg)

# define TYPE		((data->conv)->type)
# define BASE		((data->conv)->base)
# define SPACE		((data->conv)->space)
# define PREFIX		((data->conv)->prefix)
# define ZERO		((data->conv)->zero)
# define LEFT		((data->conv)->left)
# define SIGN		((data->conv)->sign)
# define NEG		((data->conv)->neg)
# define STAR		((data->conv)->star)
# define FIELD		((data->conv)->field)
# define POINT		((data->conv)->point)
# define PREC		((data->conv)->prec)
# define MODIF		((data->conv)->mod)
# define DELI		((data->conv)->delim)

# define WC_ARG		((data->uni)->wc_arg)
# define WS_ARG		((data->uni)->ws_arg)
# define BIN		((data->uni)->bin)
# define BITS		((data->uni)->bits)
# define BYTES		((data->uni)->bytes)
# define B1			((data->uni)->byte1)
# define B2			((data->uni)->byte2)
# define B3			((data->uni)->byte3)
# define B4			((data->uni)->byte4)
# define L_BYTES	((data->uni)->len_bytes)

# define L_ADJUST	(data->len_adjust)

# define LL			(long long)

/*
** space = blank after %
** prefix = #
** zero = padding with 0
** left = left justify (-)
** sign = display sign (+)
** field = minimum field width
** p = precision
** mod = modifiers flags
** type = coversion type
*/

typedef struct		s_conv
{
	char			type;
	int				base;
	bool			space;
	int				prefix;
	bool			zero;
	bool			left;
	bool			sign;
	bool			neg;
	bool			star;
	int				field;
	bool			point;
	int				prec;
	char			*mod;
	char			delim;
}					t_conv;

typedef struct		s_arg
{
	char			*arg;
	char			*final_arg;
	char			*left_arg;
	char			*right_arg;
	size_t			size_init;
	size_t			size_arg;
	size_t			size_farg;
	size_t			size_larg;
	size_t			size_rarg;
}					t_arg;

typedef struct		s_uni
{
	wchar_t			wc_arg;
	wchar_t			*ws_arg;
	char			*bin;
	int				bits;
	int				bytes;
	char			*byte1;
	char			*byte2;
	char			*byte3;
	char			*byte4;
	int				len_bytes;
}					t_uni;

/*
** len = size from % to delimiter
*/

typedef struct		s_data
{
	char			*flag;
	char			*f_p;
	char			*mod;
	char			*delim;
	char			*buff;
	char			*format;
	va_list			ap;
	size_t			len;
	t_conv			*conv;
	t_arg			*arg;
	t_uni			*uni;
	bool			error;
	int				len_adjust;
}					t_data;

void				ft_get_flag(t_data *data, int i);
void				ft_get_f_p(t_data *data, int i);
void				ft_get_mod(t_data *data, int i);
void				ft_get_conv(t_data *data, int i);

t_data				*ft_init_data(char *format, va_list ap);

int					ft_printf(const char *format, ...);
int					ft_sprintf(char *s, const char *format, ...);

#endif
