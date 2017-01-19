/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumaujea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 11:37:22 by qumaujea          #+#    #+#             */
/*   Updated: 2017/01/19 11:42:30 by qumaujea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

size_t		ft_fp_o(size_t len, t_conv *list)
{
	size_t	size;

	if (list->field == -1 && list->p == -1)
		size = len;
	else if (list->field == -1)
		size = (size_t)ft_max(list->p, (int)len);
	else if (list->p == -1)
		size = (size_t)ft_max(list->field, (int)len);
	else if (list->p > list->field && list->p < (int)len)
		size = len;
	else if (list->p > list->field && list->p > (int)len)
		size = (size_t)list->p;
	else if ((int)len >= list->p && (int)len > list->field)
		size = len;
	else
		size = (size_t)list->field;
	if (list->left && list->prefix && ((int)len < list->p))
		size = size + 2;
	return (size);
}

void		ft_p_o(char **to_print, t_conv *list, size_t len, size_t size)
{
	size_t	i;

	size = (list->p < (int)len) ? size : len;
	if (list->p > -1 || list->zero)
	{
		i = 0;
		while ((to_print)[0][i])
		{
			if (list->field > -1)
			{
				if (i > (size_t)(list->field - list->p - 1) && !(list->left))
					(to_print)[0][i] = '0';
				if (i < (size_t)(list->field - ft_max((int)size, list->p))
						&& list->left)
					(to_print)[0][i] = '0';
				if (list->p > (int)len || list->p == -1)
					(to_print)[0][i] = '0';
			}
			else
				(to_print)[0][i] = '0';
			i++;
		}
	}
}

int			ft_left_o(char *arg, size_t len, char **to_print, t_conv *list)
{
	ft_p_o(to_print, list, ft_strlen(arg), len);
	if (list->left)
	{
		if (list->p > -1 && list->p > (int)ft_strlen(arg))
			ft_strncpy(*to_print + (size_t)(list->p)
					- ft_strlen(arg) + (list->prefix) * 2, arg, (size_t)
					(ft_min(ft_min((int)ft_strlen(arg), (int)len), list->p)));
		else
			ft_strncpy(*to_print + (list->prefix) * 2, arg, (size_t)
					(ft_min((int)ft_strlen(arg), (int)len)));
		if (list->prefix)
		{
			to_print[0][0] = '0';
			to_print[0][1] = 'x';
		}
		return (1);
	}
	return (0);
}

void		ft_sub_o2(t_conv *list, char *to_print, char *arg, size_t *i)
{
	if (list->field > (int)ft_strlen(arg) && (int)ft_strlen(arg) > list->p)
	{
		to_print[*i - (2 + ((list->p == -1 && list->zero) ? 1 : 0))] = '0';
		to_print[*i - (1 + ((list->p == -1
						&& list->zero) ? 1 : 0))] = 'x';
	}
	else
	{
		to_print[((int)ft_strlen(arg) < list->p) ? 0 : *i] = '0';
		to_print[((int)ft_strlen(arg) < list->p) ? 1 : *i + 1] = 'x';
		*i += 2;
	}
}

void		ft_sub_o1(t_conv *list, char *to_print, char *arg, size_t len)
{
	size_t	i;

	i = 0;
	while ((int)i < (int)len - (int)ft_strlen(arg))
		i++;
	if (list->prefix && (list->field > list->p
				|| list->p > (int)ft_strlen(arg)
				|| (list->p == -1 && list->field == -1)
				|| (list->p <= (int)ft_strlen(arg)
					&& (list->field < (int)ft_strlen(arg)))))
	{
		ft_sub_o2(list, to_print, arg, &i);
	}
	if (list->p > -1)
	{
		while ((int)i + ft_max(list->p, (int)len) < (int)len
				&& ft_strlen(arg) < len)
			i++;
		ft_strncpy(&(to_print)[i], arg, (size_t)
				(ft_min((int)ft_strlen(arg), (int)len)));
	}
	else
		ft_strncpy(&(to_print)[i], arg, (size_t)
				(ft_min((int)ft_strlen(arg), (int)len)));
}
