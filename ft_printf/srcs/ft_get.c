/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 07:11:20 by apoisson          #+#    #+#             */
/*   Updated: 2016/12/18 06:26:33 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_get_flags(t_conv *new, char *s, int *i)
{
	if (s[*i] == '#')
		new->prefix = 1;
	else if (s[*i] == '-')
		new->left = 1;
	else if (s[*i] == '+')
		new->sign = 1;
	else if (s[*i] == '0')
		new->zero = 1;
	else
		return ;
	*i = *i + 1;
	ft_get_flags(new, s, i);
}

void	ft_get_field_prec(t_conv *new, char *s, int *i)
{
	int		len;

	len = 0;
	while (s[*i + len] >= '0' && s[*i + len] <= '9')
		len++;
	if (len)
		new->field = ft_atoi(ft_strsub(s, *i, len));
	*i += len;
	if (s[*i] == '.')
	{
		len = 0;
		*i += 1;
		while (s[*i + len] >= '0' && s[*i + len] <= '9')
			len++;
		if (len)
			new->p = ft_atoi(ft_strsub(s, *i, len));
		*i = *i + len;
	}
}

void	ft_get_mod(t_conv *new, char *s, int *i)
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

size_t	ft_get_len(const char *restrict format, int i)
{
	size_t	len;

	len = 0;
	while (!(format[i + len] == 's' || format[i + len] == 'S' ||
				format[i + len] == 'p' || format[i + len] == 'i' ||
				format[i + len] == 'd' || format[i + len] == 'D' ||
				format[i + len] == 'o' || format[i + len] == 'O' ||
				format[i + len] == 'u' || format[i + len] == 'U' ||
				format[i + len] == 'x' || format[i + len] == 'X' ||
				format[i + len] == 'c' || format[i + len] == 'C'))
		len++;
	return (len);
}

char	*ft_get_conv(const char *restrict format, t_conv **list)
{
	int		i;
	size_t	len;
	char	*to_print;

	to_print = ft_memalloc(1);
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			to_print = ft_straddchar(to_print, format[i]);
			if (format[++i] != '%')
			{
				len = ft_get_len(format, i);
				ft_add_conv(ft_new_conv(ft_strsub(format, i, len + 1)), list);
				i = i + len;
			}
			to_print = ft_straddchar(to_print, format[i]);
		}
		else
			to_print = ft_straddchar(to_print, format[i]);
	}
	return (to_print);
}
