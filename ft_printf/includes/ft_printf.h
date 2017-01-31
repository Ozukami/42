/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 01:22:47 by apoisson          #+#    #+#             */
/*   Updated: 2017/01/24 11:46:22 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <limits.h>
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
	size_t			(*f)(va_list, t_conv *, char **str);
	char			type;
}					t_fun;

/*
** ft_get.c
*/

void				ft_get_flags(t_conv *new, char *s, int *i);
void				ft_get_field_prec(t_conv *new, char *s, int *i);
void				ft_get_mod(t_conv *new, char *s, int *i);
size_t				ft_get_len(const char *format, int i);
char				*ft_get_conv(const char *format, t_conv **list);

/*
** ft_conv.c
*/

void				ft_new_init(t_conv *new);
t_conv				*ft_new_conv(char *s);
void				ft_add_conv(t_conv *new, t_conv **list);

/*
** ft_fun_*.c
*/

size_t				ft_va_arg_c(va_list ap, t_conv *list, char **str);
size_t				ft_va_arg_s(va_list ap, t_conv *list, char **str);
size_t				ft_va_arg_d(va_list ap, t_conv *list, char **str);
size_t				ft_va_arg_o(va_list ap, t_conv *list, char **str);
size_t				ft_va_arg_u(va_list ap, t_conv *list, char **str);
size_t				ft_va_arg_x(va_list ap, t_conv *list, char **str);
size_t				ft_va_arg_xmaj(va_list ap, t_conv *list, char **str);

/*
** %d
*/

size_t				ft_fp_d(size_t len, t_conv *list, char *arg, size_t size);
void				ft_p_d(char **to_print, t_conv *list,
		size_t len, size_t size);
int					ft_left_d(char *arg, size_t len,
		char **to_print, t_conv *list);
void				ft_sub_1(t_conv *list, char *to_print,
		char *arg, size_t len);
void				ft_sub_2(t_conv *list, char **to_print, char *arg);

/*
** %x
*/

size_t				ft_fp_x(size_t len, t_conv *list);
void				ft_p_x(char **to_print, t_conv *list,
		size_t len, size_t size);
int					ft_left_x(char *arg, size_t len,
		char **to_print, t_conv *list);
void				ft_sub_x1(t_conv *list, char *to_print,
		char *arg, size_t len);
void				ft_sub_x2(t_conv *list, char *to_print,
		char *arg, size_t *i);

/*
** %o
*/

size_t				ft_fp_o(size_t len, t_conv *list);
void				ft_p_o(char **to_print, t_conv *list,
		size_t len, size_t size);
int					ft_left_o(char *arg, size_t len,
		char **to_print, t_conv *list);
void				ft_sub_o1(t_conv *list, char *to_print,
		char *arg, size_t len);
void				ft_sub_o2(t_conv *list, char *to_print,
		char *arg, size_t *i);

/*
** %u
*/

size_t				ft_fp_u(size_t len, t_conv *list);
void				ft_p_u(char **to_print, t_conv *list,
		size_t len, size_t size);
int					ft_left_u(char *arg, size_t len,
		char **to_print, t_conv *list);
void				ft_sub_u1(t_conv *list, char *to_print,
		char *arg, size_t len);
void				ft_sub_u2(t_conv *list, char *to_print,
		char *arg, size_t *i);

void				ft_putchar_v2(wchar_t c);
int					ft_printf(const char *format, ...);
char				*ft_sprintf(const char *format, ...);

#endif
