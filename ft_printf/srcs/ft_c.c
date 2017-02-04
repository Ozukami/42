/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 09:04:59 by apoisson          #+#    #+#             */
/*   Updated: 2017/02/04 05:56:25 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_va_arg_c(va_list ap, t_conv *list, char **str)
{
	size_t	i;
	char	*cpy;
	char	*tmp;
	int		j;

	tmp = NULL;
	i = 0;
	if (ft_strequ(list->mod, "l"))
		ft_dothework(va_arg(ap, wchar_t), &tmp, 0);
	else
	{
		tmp = ft_memalloc(2);
		tmp[0] = va_arg(ap, int);
	}
	cpy = (list->field > 1) ? ft_memalloc(list->field + ft_strlen(tmp) + 1) 
		: ft_memalloc(ft_strlen(tmp) + 1);
	if (ft_max(list->field, ft_strlen(tmp)) > 1)
		while ((int)i < ft_max(list->field, ft_strlen(tmp)))
			cpy[i++] = ' ';
	if (list->left)
	{
		if (!tmp[0])
			cpy[i - 1] = tmp[0];
		*str = ft_strjoinf(*str, ft_strncpy(cpy, tmp, ft_strlen(tmp)));
	}
	else
	{
		i = 0;
		j = ft_strlen(cpy) - ft_strlen(tmp);
		if (j < 0)
			j = 0;
		if (!tmp[i])
			cpy[j - 1] = tmp[i];
		while (tmp[i])
			cpy[j++] = tmp[i++];
		*str = ft_strjoinf(*str, cpy);
	}
	return (ft_max(list->field, ft_max(ft_strlen(cpy), 1)));
}
