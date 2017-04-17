/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 04:52:55 by apoisson          #+#    #+#             */
/*   Updated: 2017/04/17 05:41:41 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TINY_PRINTF_H
# define TINY_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>

# define ERROR		-1
# define SUCCES		1

# define AP			(data->ap)

# define FORMAT		(data->format)
# define BUFFER		(data->buff)
# define LEN		(data->len)
# define PTR		(data->ptr)
# define COLOR		(data->color)

# define FLAG		(data->flag)
# define F_P		(data->f_p)
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
	char			delim;
}					t_conv;

typedef struct		s_arg
{
	char			*arg;			// Free
	char			*final_arg;		// Free
	char			*left_arg;		// Free
	char			*right_arg;		// Free
	size_t			size_init;
	size_t			size_arg;
	size_t			size_farg;
	size_t			size_larg;
	size_t			size_rarg;
}					t_arg;

typedef struct		s_color
{
	char			*name;			// Free
	char			*code;			// Free
	struct s_color	*next;			// Free
}					t_color;

typedef struct		s_data
{
	char			*flag;			// Free
	char			*f_p;			// Free
	char			*delim;			// Free
	char			*buff;			// Free
	char			*format;		// Free
	va_list			ap;
	int				len;
	t_conv			*conv;			// Free
	t_arg			*arg;			// Free
	t_color			*color;			// Free
	int				len_adjust;
	int				pos_c0;
	char			*ptr;			// Free
}					t_data;

t_data				*ft_init_data(char *format, va_list ap);

int					tiny_printf(const char *format, ...);
int					tiny_dprintf(int fd, const char *format, ...);
int					tiny_sprintf(char *s, const char *format, ...);

t_color				*ft_new_color(t_color *color, char *name, char *code);
t_color				*ft_init_color(void);

void				ft_get_arg(t_data *data);

char				*ft_add_space_or_zero(char *s, char c, int n);
char				*ft_stradd_char(t_data *data, char *s, int n);

void				ft_get_flag(t_data *data, int i);
void				ft_get_p(t_data *data, int i);
void				ft_get_f(t_data *data, int i);
void				ft_get_f_p(t_data *data, int i);

void				ft_adjust_2(t_data *data);
void				ft_adjust(t_data *data);
void				ft_adjust_arg(t_data *data);

void				ft_neg_case(t_data *data);
void				ft_replace_neg(t_data *data);
void				ft_adjust_sign(t_data *data);
void				ft_sub_size(t_data *data);
void				ft_set_size(t_data *data);
void				ft_set_sign(t_data *data);
void				ft_set_prefix(t_data *data);

void				ft_process_conv(t_data *data);
void				ft_dispatch(t_data *data);
void				ft_bad_delim(t_data *data, int i);
void				ft_get_conv(t_data *data, int i);
void				ft_reset_conv(t_data *data);
int					ft_color_process(t_data *data, int i);

#endif
