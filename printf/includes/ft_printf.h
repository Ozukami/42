/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 01:22:47 by apoisson          #+#    #+#             */
/*   Updated: 2017/03/01 06:15:49 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <limits.h>
# include <stdbool.h>
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

/*
typedef struct		s_bool
{
	int				bool;
}					t_bool;
*/

typedef struct		s_conv
{
	char			*arg;
	char			type;
	int				base;
	bool			space;
	bool			prefix;
	bool			zero;
	bool			left;
	bool			sign;
	bool			star;
	int				field;
	bool			point;
	int				prec;
	char			*mod;
	char			delim;
}					t_conv;

typedef struct		s_fun
{
	size_t			(*f)(va_list, t_conv *, char **str);
	char			type;
}					t_fun;

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
}					t_data;

void				ft_get_flag(t_data *data, int i);
void				ft_get_f_p(t_data *data, int i);
void				ft_get_mod(t_data *data, int i);
void				ft_get_conv(t_data *data, int i);

t_data				*ft_init_data(char *format, va_list ap);

int					ft_printf(const char *format, ...);

#endif
