/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 01:22:47 by apoisson          #+#    #+#             */
/*   Updated: 2016/12/11 02:53:55 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h> // !!!!!

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
	int				space;
	int				prefix;
	int				zero;
	int				left;
	int				sign;
	int				field;
	int				p;
	char			*mod;
	char			type;
	struct s_conv	*next;
}					t_conv;

typedef struct		s_fun
{
	void			(*f)(va_list);
	char			type;
}					t_fun;

/*
** ft_get.c
*/

void				ft_get_flags(t_conv *new, char c);
void				ft_get_field_prec(t_conv *new, char *s, int *i);
void				ft_get_mod(t_conv *new, char *s, int *i);
void				ft_get_conv(const char *restrict format, t_conv **list);

/*
** ft_conv.c
*/

void				ft_new_init(t_conv *new);
t_conv				*ft_new_conv(char *s);
void				ft_add_conv(t_conv *new, t_conv **list);

/*
** ft_fun_*.c
*/

void				ft_va_arg_p(va_list ap);
void				ft_va_arg_c(va_list ap);
void				ft_va_arg_cmaj(va_list ap);
void				ft_va_arg_s(va_list ap);
void				ft_va_arg_smaj(va_list ap);
void				ft_va_arg_d(va_list ap);
void				ft_va_arg_dmaj(va_list ap);
void				ft_va_arg_i(va_list ap);
void				ft_va_arg_o(va_list ap);
void				ft_va_arg_omaj(va_list ap);
void				ft_va_arg_u(va_list ap);
void				ft_va_arg_umaj(va_list ap);
void				ft_va_arg_x(va_list ap);
void				ft_va_arg_xmaj(va_list ap);

/*
** ft_a_ranger.c
*/

void				ft_putchar_wchar_t(wchar_t c);
void				ft_putstr_wchar_t(wchar_t *s);
void				ft_putnbr_long(long nb);
unsigned int		ft_int_to_unsigned(int nb);
short				ft_int_to_short(int nb);

char				*ft_itoa_base(int value, int base, int maj);

int					ft_printf(const char *restrict format, ...);

#endif
