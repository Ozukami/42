/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xmajmaj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 12:37:13 by apoisson          #+#    #+#             */
/*   Updated: 2017/01/14 04:13:48 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_fp_xmaj(size_t len, char **to_print, t_conv *list)
{
	size_t	i;
	size_t	size;

	if (list->field == -1 && list->p == -1)
		size = len;
	else if (list->field == -1)
		size = (size_t)ft_max(list->p, (int)len);
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

void		ft_p_xmaj(char **to_print, t_conv *list)
{
	size_t	i;

	if (list->p > -1)
	{
		i = 0;
		while ((to_print)[0][i])
		{
			if (list->field > -1)
			{
				if (i > (size_t)(list->field - list->p - 1) && !(list->left))
					(to_print)[0][i] = '0';
				if (i < (size_t)(list->field - list->p) && list->left)
					(to_print)[0][i] = '0';
			}
			else
				(to_print)[0][i] = '0';
			i++;
		}
	}
}

int			ft_left_xmaj(char *arg, size_t len, char **to_print, t_conv *list)
{
	ft_p_xmaj(to_print, list);
	if (list->left)
	{
		if (list->prefix)
		{
			to_print[0][0] = '0';
			to_print[0][1] = 'x';
		}
		if (list->p > -1 && list->p > (int)ft_strlen(arg))
			ft_strncpy(*to_print + (size_t)(list->p) - ft_strlen(arg)
					+ list->space + (list->prefix * 2), arg, (size_t)
					(ft_min(ft_min((int)ft_strlen(arg), (int)len), list->p)));
		else
			ft_strncpy(*to_print + list->space + (list->prefix * 2), arg,
					(size_t)(ft_min((int)ft_strlen(arg), (int)len)));
		return (1);
	}
	return (0);
}

static void	ft_sub(t_conv *list, char *to_print, char *arg, size_t len)
{
	size_t	i;

	i = 0;
	while ((int)i < (int)len - (int)ft_strlen(arg) - (list->prefix * 2))
		i++;
	if (list->p > -1)
	{
		while ((int)i + list->p < (int)len
				&& ft_strlen(arg) < len)
			i++;
		if (list->prefix && list->field > list->p)
		{
			to_print[i - 2] = '0';
			to_print[i - 1] = 'x';
		}
		ft_strncpy(&(to_print)[i], arg, (size_t)
				(ft_min((int)ft_strlen(arg), (int)len)));
	}
	else
		ft_strncpy(&(to_print)[i], arg, (size_t)
				(ft_min((int)ft_strlen(arg), (int)len)));
	return ;
}

size_t		ft_va_arg_xmaj(va_list ap, t_conv *list)
{
	char	*arg;
	char	*to_print;
	size_t	len;

	arg = ft_itoa_base(va_arg(ap, int), 16, 1);
	len = ft_fp_xmaj(ft_strlen(arg), &to_print, list);
	if (!ft_left_xmaj(arg, len, &to_print, list))
	{
		ft_sub(list, to_print, arg, len);
		if (list->prefix && (list->field == -1 || list->p == -1))
		{
			ft_putstr(ft_strjoin("0x", to_print));
			return (ft_strlen(to_print) + 2);
		}
	}
	ft_putstr(to_print);
	return (ft_strlen(to_print));
}
