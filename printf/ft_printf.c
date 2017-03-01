/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 23:54:04 by apoisson          #+#    #+#             */
/*   Updated: 2017/03/01 01:51:03 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define FORMAT	(data->format)
#define BUFFER	(data->buff)
#define FLAG	(data->flag)
#define DELIM	(data->delim)
#define MOD		(data->mod)

static void	ft_init(t_fun **tab)
{
	tab[0][0].f = &ft_va_arg_s;
	tab[0][1].f = &ft_va_arg_d;
	tab[0][2].f = &ft_va_arg_o;
	tab[0][3].f = &ft_va_arg_u;
	tab[0][4].f = &ft_va_arg_x;
	tab[0][5].f = &ft_va_arg_p;
}

void		ft_process(t_data *data, int *i)
{
	while (ft_strstr(FLAG, ))
}

int			ft_printf(const char *format, ...)
{
	t_data	*data;
	int		i;

	va_start(ap, format);
	data = ft_init_data(format, ap);
	i = -1;
	while (FORMAT[++i])
	{
		if (FORMAT[i] != '%')
			ft_straddchar(BUFFER, FORMAT[i]);
		else
			ft_process(data, &i);
	}
	va_end(ap);
	ft_putstr(BUFFER);
	return ((int)ft_strlen(data->buff));
}
