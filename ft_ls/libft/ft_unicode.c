/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 05:49:32 by apoisson          #+#    #+#             */
/*   Updated: 2017/03/11 05:50:02 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_sub(t_data *data, char *byte, int n)
{
	L_BYTES += n;
	if (TYPE == 's' && PREC > -1 && L_BYTES > PREC)
		return ;
	ft_set_bytes(data, byte, n);
}

void		ft_conv_wc(t_data *data, wchar_t c)
{
	free(BIN);
	BIN = ft_itoa_base((int)c, 2, 0);
	BITS = (int)ft_strlen(BIN);
	if (BITS < 8)
		ft_sub(data, B1, 1);
	else if (BITS < 12)
		ft_sub(data, B2, 2);
	else if (BITS < 17)
		ft_sub(data, B3, 3);
	else
		ft_sub(data, B4, 4);
}

void		ft_conv_ws(t_data *data)
{
	int		i;

	free(ARG);
	if (WS_ARG == NULL)
	{
		ARG = ft_strdup("(null)");
		return ;
	}
	ARG = ft_strdup("");
	i = 0;
	while (WS_ARG[i])
	{
		ft_conv_wc(data, WS_ARG[i]);
		i++;
	}
}
