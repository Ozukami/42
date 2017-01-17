/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 09:52:38 by apoisson          #+#    #+#             */
/*   Updated: 2017/01/17 08:45:01 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_fp_s(size_t len, char **to_print, t_conv *list)
{
	size_t	i;
	size_t	size;

	if (list->field == -1 && list->p == -1)
		size = len;
	else if (list->field == -1)
		size = (size_t)ft_min(list->p, (int)len);
	else if (list->p == -1)
		size = (size_t)ft_max(list->field, (int)len);
	else if (list->p > list->field && list->p < (int)len)
		size = (size_t)list->p;
	else if (list->p > list->field && list->p > (int)len)
		size = (size_t)ft_max(list->field, (int)len);
	else
		size = (size_t)list->field;
	*to_print = ft_memalloc(sizeof(char) * (size + 1));
	i = 0;
	while (i < size)
		(*to_print)[i++] = ' ';
	return (size);
}

int		ft_left_s(char *arg, size_t len, char **to_print, t_conv *list)
{
	if (list->left)
	{
		if (list->p > -1)
			ft_strncpy(*to_print, arg, (size_t)
					(ft_min(ft_min((int)ft_strlen(arg), (int)len), list->p)));
		else
			ft_strncpy(*to_print, arg, (size_t)
					(ft_min((int)ft_strlen(arg), (int)len)));
		return (1);
	}
	return (0);
}

size_t	ft_va_arg_s(va_list ap, t_conv *list, char **str)
{
	char	*arg;
	char	*to_print;
	size_t	len;
	size_t	i;

	arg = va_arg(ap, char *);
	len = ft_fp_s(ft_strlen(arg), &to_print, list);
	if (!ft_left_s(arg, len, &to_print, list))
	{
		i = 0;
		while ((int)i < (int)len - (int)ft_strlen(arg))
			i++;
		if (list->p > -1)
		{
			while ((int)i + list->p < (int)len)
				i++;
			ft_strncpy(&(to_print)[i], arg, (size_t)
					(ft_min(ft_min((int)ft_strlen(arg), (int)len), list->p)));
		}
		else
			ft_strncpy(&(to_print)[i], arg, (size_t)
					(ft_min((int)ft_strlen(arg), (int)len)));
	}
	ft_putstr(to_print);
	*str = ft_strjoin(*str, to_print);
	return (ft_strlen(to_print));
}
