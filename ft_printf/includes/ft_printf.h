/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 01:22:47 by apoisson          #+#    #+#             */
/*   Updated: 2016/12/15 09:36:14 by apoisson         ###   ########.fr       */
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
	size_t			(*f)(va_list, t_conv *);
	char			type;
}					t_fun;

/*
** ft_get.c
*/

void				ft_get_flags(t_conv *new, char *s, int *i);
void				ft_get_field_prec(t_conv *new, char *s, int *i);
void				ft_get_mod(t_conv *new, char *s, int *i);
char				*ft_get_conv(const char *restrict format, t_conv **list);

/*
** ft_conv.c
*/

void				ft_new_init(t_conv *new);
t_conv				*ft_new_conv(char *s);
void				ft_add_conv(t_conv *new, t_conv **list);

/*
** ft_fun_*.c
*/

size_t				ft_va_arg_p(va_list ap, t_conv *list);
size_t				ft_va_arg_c(va_list ap, t_conv *list);
size_t				ft_va_arg_cmaj(va_list ap, t_conv *list);
size_t				ft_va_arg_s(va_list ap, t_conv *list);
size_t				ft_va_arg_smaj(va_list ap, t_conv *list);
size_t				ft_va_arg_d(va_list ap, t_conv *list);
size_t				ft_va_arg_dmaj(va_list ap, t_conv *list);
size_t				ft_va_arg_o(va_list ap, t_conv *list);
size_t				ft_va_arg_omaj(va_list ap, t_conv *list);
size_t				ft_va_arg_u(va_list ap, t_conv *list);
size_t				ft_va_arg_umaj(va_list ap, t_conv *list);
size_t				ft_va_arg_x(va_list ap, t_conv *list);
size_t				ft_va_arg_xmaj(va_list ap, t_conv *list);

char				*ft_itoa_base(int value, int base, int maj);

int					ft_printf(const char *restrict format, ...);

#endif
