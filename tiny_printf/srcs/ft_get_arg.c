/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumaujea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 05:36:49 by qumaujea          #+#    #+#             */
/*   Updated: 2017/04/17 05:20:55 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tiny_printf.h"

void		ft_get_arg(t_data *data)
{
	char	*tmp;

	tmp = NULL;
	if (TYPE == 's')
	{
		tmp = va_arg(AP, char *);
		if (tmp)
			ARG = ft_strdup(tmp);
	}
	else if (TYPE == 'c')
		ARG = ft_straddchar(ft_strdup(""), va_arg(AP, int));
	else if (TYPE == 'p')
		ARG = ft_ulltoa_base(va_arg(AP, unsigned long long int), 16, 0);
	else if (TYPE == 'b')
		ARG = ft_lltoa_base(va_arg(AP, long long), 2, 0);
	else if (TYPE == 'd')
		ARG = ft_lltoa_base((va_arg(AP, int)), BASE, 0);
	else
		ARG = ft_lltoa_base((unsigned int)(va_arg(AP, int)),
				BASE, ((TYPE == 'X') ? 1 : 0));
}
