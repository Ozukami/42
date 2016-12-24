/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 12:37:13 by apoisson          #+#    #+#             */
/*   Updated: 2016/12/24 12:37:19 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_fp_d(size_t len, char **to_print, t_conv *list)
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

void	ft_p_d(char **to_print, t_conv *list)
{
	size_t	i;

	if (list->p > -1)
	{
		i = 0;
		while ((to_print)[0][i])
		{
			if (i > (size_t)(list->field - list->p - 1) && !(list->left))
				(to_print)[0][i] = '0';
			if (i < (size_t)(list->field - list->p) && list->left)
				(to_print)[0][i] = '0';
			i++;
		}
	}
}

int		ft_left_d(char *arg, size_t len, char **to_print, t_conv *list)
{
	ft_p_d(to_print, list);
	if (list->left)
	{
		if (list->p > -1)
			ft_strncpy(*to_print + (size_t)(list->field - list->p)
					- ft_strlen(arg), arg, (size_t)
					(ft_min(ft_min((int)ft_strlen(arg), (int)len), list->p)));
		else
			ft_strncpy(*to_print, arg, (size_t)
					(ft_min((int)ft_strlen(arg), (int)len)));
		return (1);
	}
	return (0);
}

size_t	ft_va_arg_d(va_list ap, t_conv *list)
{
	char	*arg;
	char	*to_print;
	size_t	len;
	size_t	i;

	arg = ft_itoa(va_arg(ap, int));
	len = ft_fp_d(ft_strlen(arg), &to_print, list);
	if (!ft_left_d(arg, len, &to_print, list))
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
	return (ft_strlen(to_print));
}
