/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 12:37:13 by apoisson          #+#    #+#             */
/*   Updated: 2017/01/20 11:39:01 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_fp_d(size_t len, t_conv *list, char *arg, size_t size)
{
	if (list->field == -1 && list->p == -1)
		size = len;
	else if (list->field == -1 && arg[0] != '-')
		size = (size_t)ft_max(list->p, (int)len) + (size_t)list->space;
	else if (list->field == -1)
		size = (size_t)ft_max(list->p, (int)len);
	else if (list->p == -1 && arg[0] != '-')
		size = (size_t)ft_max(list->field, (int)len + list->space);
	else if (list->p == -1)
		size = (size_t)ft_max(list->field, (int)len);
	else if (list->p > list->field && list->p < (int)len && arg[0] != '-')
		size = len + (size_t)list->space;
	else if (list->p > list->field && list->p < (int)len)
		size = len;
	else if (list->p > list->field && list->p > (int)len && arg[0] != '-')
		size = (size_t)list->p + (size_t)list->space;
	else if (list->p > list->field && list->p > (int)len)
		size = (size_t)list->p;
	else
		size = (size_t)list->field;
	if ((arg[0] == '-' || (arg[0] == '+' && list->sign)) && list->p > (int)len
			&& list->p > list->field)
		size++;
	return (size);
}

void		ft_p_d(char **to_print, t_conv *list, size_t len, size_t size)
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
				if (list->left && (int)i < list->p)
					(to_print)[0][i] = '0';
				if ((i > (size_t)(list->field - list->p - 1) && !(list->left))
						|| (i < (size_t)(list->field -
								ft_max((int)size, list->p)) && list->left)
						|| ((list->p > (int)len && list->field < list->p)
							|| list->p == -1))
					(to_print)[0][i] = '0';
			}
			else
				(to_print)[0][i] = '0';
			i++;
		}
	}
}

int			ft_left_d(char *arg, size_t len, char **to_print, t_conv *list)
{
	ft_p_d(to_print, list, ft_strlen(arg), len);
	if (list->space && arg[0] != '-')
		to_print[0][0] = ' ';
	if (list->left)
	{
		if (list->p > -1 && list->p > (int)ft_strlen(arg) && arg[0] == '-')
			ft_strncpy(*to_print + (size_t)(list->p)
					- ft_strlen(arg) + 1, arg, (size_t)
					(ft_min(ft_min((int)ft_strlen(arg), (int)len), list->p)));
		else if (list->p > -1 && list->p > (int)ft_strlen(arg))
			ft_strncpy(*to_print + (size_t)(list->p)
					- ft_strlen(arg) + list->space + list->sign, arg, (size_t)
					(ft_min(ft_min((int)ft_strlen(arg), (int)len), list->p)));
		else if (arg[0] == '-')
			ft_strncpy(*to_print, arg, (size_t)
					(ft_min((int)ft_strlen(arg), (int)len)));
		else
			ft_strncpy(*to_print + list->space, arg, (size_t)
					(ft_min((int)ft_strlen(arg), (int)len)));
		return (1);
	}
	return (0);
}

void		ft_sub_1(t_conv *list, char *to_print, char *arg, size_t len)
{
	size_t	i;

	i = 0;
	while ((int)i < (int)len - (int)ft_strlen(arg))
		i++;
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

void		ft_sub_2(t_conv *list, char **to_print, char *arg)
{
	int		i;

	i = 1;
	if ((list->p > (int)ft_strlen(arg) || (list->p == -1 && list->zero))
			&& (arg[0] == '-' || arg[0] == '+'))
	{
		if (list->p < list->field && list->p > (int)ft_strlen(arg))
		{
			to_print[0][list->field - list->p - 1 - list->left] = arg[0];
			i = list->field - list->p;
		}
		else
			to_print[0][0] = arg[0];
		while (to_print[0][i++])
		{
			if (to_print[0][i] == arg[0])
				to_print[0][i] = '0';
		}
	}
}
