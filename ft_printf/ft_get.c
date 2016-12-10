/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 07:11:20 by apoisson          #+#    #+#             */
/*   Updated: 2016/12/10 07:34:44 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_get_flags(t_conv *new, char c)
{
	if (c == '#')
		new->prefix = 1;
	if (c == '-')
		new->left = 1;
	if (c == '+')
		new->sign = 1;
	if (c == '0')
		new->zero = 1;
}

void		ft_get_field_prec(t_conv *new, char *s, int *i)
{
	int		len;

	len = 0;
	while (s[*i + len] >= '0' && s[*i + len] <= '9')
		len++;
	if (len)
		new->field = ft_atoi(ft_strsub(s, *i, len));
	if (s[*i] == '.')
	{
		*i += 1;
		while (s[*i + len] >= '0' && s[*i + len] <= '9')
			len++;
		if (len)
			new->p = ft_atoi(ft_strsub(s, *i, len));
		*i = *i + len;
	}
}

void		ft_get_mod(t_conv *new, char *s, int *i)
{
	if ((s[*i] == 'l' && s[*i + 1] == 'l')
			|| (s[*i] == 'h' && s[*i + 1] == 'h'))
	{
		new->mod = ft_strsub(s, *i, 2);
		*i += 1;
	}
	else if (s[*i] == 'l' || s[*i] == 'h'
			|| s[*i] == 'j' || s[*i] == 'z')
		new->mod = ft_strsub(s, *i, 1);
}

void	ft_get_conv(const char *restrict format, t_conv **list)
{
	int		i;
	size_t	len;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[++i] != '%')
			{
				len = 0;
				while (!(format[i + len] == 's' || format[i + len] == 'S' ||
							format[i + len] == 'p' || format[i + len] == 'i' ||
							format[i + len] == 'd' || format[i + len] == 'D' ||
							format[i + len] == 'o' || format[i + len] == 'O' ||
							format[i + len] == 'u' || format[i + len] == 'U' ||
							format[i + len] == 'x' || format[i + len] == 'X' ||
							format[i + len] == 'c' || format[i + len] == 'C'))
					len++;
				ft_add_conv(ft_new_conv(ft_strsub(format, i, len + 1)), list);
				i = i + len;
			}
		}
		i++;
	}
}
