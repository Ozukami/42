/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 15:09:25 by lcharbon          #+#    #+#             */
/*   Updated: 2017/06/08 00:56:29 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ftpf_unsign_zero(t_data *data, char **str, uintmax_t arg)
{
	int			i;

	i = 0;
	if (data->data[0] == 0)
		ft_memset(*str, '\0', ft_strlen(*str));
	if ((data->conv == 'o' || data->conv == 'O') && data->data[2] == 1)
		*str[0] = '0';
	if (arg != 0)
		if ((data->conv == 'x' || data->conv == 'X')
		&& data->data[2] == 1)
			ft_memcpy(*str, "0x", 2);
	if (data->conv == 'p' && arg == 0 && data->data[0] == 0)
		ft_memcpy(*str, "0x", 3);
	else if (data->conv == 'p')
		ft_memcpy(*str, "0x0", 3);
}

int				ft_count_ch_int(intmax_t nb)
{
	int			i;

	i = 0;
	if (nb < 0)
		return (ft_count_ch_int(nb * -1) + 1);
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

void			ftpf_upcase(char *buf)
{
	int			i;

	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] >= 97 && buf[i] <= 122)
			buf[i] -= 32;
		i++;
	}
}
