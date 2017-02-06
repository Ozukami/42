/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 09:52:38 by apoisson          #+#    #+#             */
/*   Updated: 2017/02/06 10:59:44 by apoisson         ###   ########.fr       */
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
	else if (list->p > list->field && list->p >= (int)len)
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

size_t	ft_s_mod_l(va_list ap, t_conv *list, char **str)
{
	wchar_t	*arg;
	char	*to_print;
	char 	*tmp;
	size_t	len;
	size_t	i;
	int		*tab;
	int		max;
	int		a;
	int		b;

	tmp = NULL;
	arg = va_arg(ap, wchar_t *);
	//printf("	> size(%ls) = %d\n", arg, a);
	if (arg == NULL)
	{
		*str = ft_strjoin(*str, "(null)");
		return (ft_strlen(to_print));
	}
	a = (int)ft_lslen(arg);
	len = ft_fp_s(ft_strlen((char *)arg), &to_print, list);
	//printf("[%s]\n", to_print);
	tab = ft_memalloc(ft_strlen((char *)arg) + 1);
	i = 0;
	if (arg[i])
	{
		tab[i] = ft_dothework(arg[i], &tmp, 0);
		if (list->field > a && !list->left)
			ft_strcpy(to_print + len - a, tmp);
		else if (list->p > 0 || !list->point)
			ft_strcpy(to_print, tmp);
		i++;
	}
	while (arg[i])
	{
		tab[i] = ft_dothework(arg[i], &tmp, 0);
		if (list->p > 0 || !list->point)
			to_print = ft_strjoin(to_print, tmp);
		i++;
	}
	b = ft_strlen(to_print);
	while (b < (int)len)
		to_print[b++] = ' ';
	to_print[b] = '\0';
	tab[i] = 0;
	i = 0;
	if (list->p > 0)
	{
		max = 0;
		while (max < list->p)
			max += tab[i++];
		if (max > list->p)
			max -= tab[i - 1];
		to_print[max] = '\0';
	}
	*str = ft_strjoin(*str, to_print);
	return (ft_strlen(to_print));
}

size_t	ft_va_arg_s(va_list ap, t_conv *list, char **str)
{
	char	*arg;
	char	*to_print;
	size_t	len;
	size_t	i;

	if (ft_strequ(list->mod, "l"))
		return (ft_s_mod_l(ap, list, str));
	/*
	   arg2 = va_arg(ap, wchar_t *);
	   len = ft_fp_s(ft_strlen((char *)arg2), &to_print, list);
	   i = 0;
	   if (arg2[i])
	   ft_strcpy(to_print, ft_dothework(arg2[i++], 0));
	   while (arg2[i])
	   to_print = ft_strjoin(to_print, ft_dothework(arg2[i++], 0));
	   */
	arg = va_arg(ap, char *);
	if (arg == NULL)
	{
		*str = ft_strjoin(*str, "(null)");
		return (ft_strlen(to_print));
	}
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
		else if (!list->point)
			ft_strncpy(&(to_print)[i], arg, (size_t)
					(ft_min((int)ft_strlen(arg), (int)len)));
	}
	//ft_putstr(to_print);
	*str = ft_strjoin(*str, to_print);
	return (ft_strlen(to_print));
}
