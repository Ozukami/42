/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumaujea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 05:36:49 by qumaujea          #+#    #+#             */
/*   Updated: 2017/03/26 00:16:33 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_multi_mod(t_data *data)
{
	if (ft_strequ(MODIF, "z") || ft_strequ(MODIF, "j"))
	{
		LEN++;
		return (1);
	}
	return (0);
}

void		ft_get_arg_d(t_data *data)
{
	if (ft_strequ(MODIF, "hh"))
		ARG = ft_lltoa_base(((char)va_arg(AP, int)), BASE, 0);
	else if (ft_strequ(MODIF, "h"))
		ARG = ft_lltoa_base(((short)va_arg(AP, int)), BASE, 0);
	else if (ft_strequ(MODIF, "l"))
		ARG = ft_lltoa_base((va_arg(AP, long)), BASE, 0);
	else if (ft_strequ(MODIF, "ll"))
		ARG = ft_lltoa_base(va_arg(AP, long), BASE, 0);
	else if (ft_strequ(MODIF, "j") || ft_strequ(MODIF, "z"))
		ARG = ft_lltoa_base((va_arg(AP, unsigned long)), BASE, 0);
	else
		ARG = ft_lltoa_base((va_arg(AP, int)), BASE, 0);
}

void		ft_get_arg_oux(t_data *data)
{
	if (ft_strequ(MODIF, ""))
		ARG = ft_lltoa_base((unsigned int)(va_arg(AP, int)),
				BASE, ((TYPE == 'X') ? 1 : 0));
	else if (ft_strequ(MODIF, "hh"))
		ARG = ft_ulltoa_base((unsigned char)va_arg(AP, int),
				BASE, ((TYPE == 'X') ? 1 : 0));
	else if (ft_strequ(MODIF, "h"))
		ARG = ft_lltoa_base((unsigned short)(va_arg(AP, int)),
				BASE, ((TYPE == 'X') ? 1 : 0));
	else
		ARG = ft_ulltoa_base((va_arg(AP, unsigned long)),
				BASE, ((TYPE == 'X') ? 1 : 0));
}

void		ft_get_arg_string(t_data *data)
{
	char	*tmp;

	tmp = NULL;
	if (ft_strequ(MODIF, "l"))
	{
		WS_ARG = va_arg(AP, wchar_t *);
		ft_conv_ws(data);
	}
	else
	{
		tmp = va_arg(AP, char *);
		if (tmp)
			ARG = ft_strdup(tmp);
	}
}

void		ft_get_arg(t_data *data)
{
	if (TYPE == 'c')
	{
		if (ft_strequ(MODIF, "l"))
		{
			WC_ARG = va_arg(AP, wchar_t);
			ERR = (WC_ARG < 0 || WC_ARG > 1114111
					|| (WC_ARG > 55295 && WC_ARG < 57344)) ? 1 : 0;
			ft_conv_wc(data, WC_ARG);
		}
		else
			ARG = ft_straddchar(ft_strdup(""), va_arg(AP, int));
	}
	else if (TYPE == 's')
		ft_get_arg_string(data);
	else if (TYPE == 'p')
		ARG = ft_ulltoa_base(va_arg(AP, unsigned long long int), 16, 0);
	else if (TYPE == 'b')
		ARG = ft_lltoa_base(va_arg(AP, long long), 2, 0);
	else if (TYPE != 'd')
		ft_get_arg_oux(data);
	else
		ft_get_arg_d(data);
}
