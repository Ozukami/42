/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 00:57:08 by apoisson          #+#    #+#             */
/*   Updated: 2017/03/01 01:12:05 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data		*ft_init_data(char *format, va_list ap)
{
	t_data	*new;

	if (!(new = malloc(sizeof(t_data))))
		exit(0);
	new->flag = ft_strdup(" 0123456789.+-#*");
	new->delim = ft_strdup("cCsSdDioOuUxXp");
	new->mod = ft_strdup("hljz");
	new->buff = ft_strdup("");
	new->format = ft_strdup(format);
	va_copy(new->ap, ap);
	new->list = NULL;
	return (new);
}
