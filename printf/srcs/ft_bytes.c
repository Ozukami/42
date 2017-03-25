/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bytes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 05:48:09 by apoisson          #+#    #+#             */
/*   Updated: 2017/03/26 00:16:02 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_reset_bytes(t_data *data)
{
	ft_strdel(&B1);
	B1 = ft_strdup("0xxxxxxx");
	ft_strdel(&B2);
	B2 = ft_strdup("110xxxxx10xxxxxx");
	ft_strdel(&B3);
	B3 = ft_strdup("1110xxxx10xxxxxx10xxxxxx");
	ft_strdel(&B4);
	B4 = ft_strdup("11110xxx10xxxxxx10xxxxxx10xxxxxx");
}

int			ft_bin_to_dec(char *bin)
{
	int		hex;
	int		i;
	int		power;

	hex = 0;
	i = 0;
	power = 7;
	while (bin[i])
		hex += (bin[i++] - '0') * ft_recursive_power(2, power--);
	return (hex);
}

void		ft_split_bytes(t_data *data, char *byte)
{
	int		i;
	char	multi_octet[BYTES + 1];

	if (TYPE == 'c')
		ARG = ft_strdup("");
	i = 0;
	while (i < BYTES)
	{
		multi_octet[i] = ft_bin_to_dec(ft_strsub(byte, 8 * i, 8));
		i++;
	}
	multi_octet[BYTES] = '\0';
	ARG = ft_strjoin(ARG, multi_octet);
}

void		ft_set_bytes(t_data *data, char *byte, int bytes)
{
	int		i;
	int		j;

	ft_reset_bytes(data);
	BYTES = bytes;
	i = BITS - 1;
	j = ft_strlen(byte) - 1;
	while (j >= 0)
	{
		if (byte[j] == 'x')
		{
			if (i >= 0)
				byte[j] = BIN[i--];
			else
				byte[j] = '0';
		}
		j--;
	}
	ft_split_bytes(data, byte);
}
