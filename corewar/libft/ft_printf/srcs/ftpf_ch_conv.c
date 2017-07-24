/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_ch_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 15:09:25 by lcharbon          #+#    #+#             */
/*   Updated: 2017/07/24 00:49:23 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ftpf_width(t_data *data, char **str)
{
	char			*tmp;

	if (data->data[1] > (int)ft_strlen(*str))
	{
		if (data->data[3] == 0 || data->data[4] == 1)
			tmp = ft_strnewch(data->data[1] - 1, ' ');
		else
			tmp = ft_strnewch(data->data[1] - 1, '0');
		if (data->data[4] == 0)
			*str = ft_strjoindel(tmp, *str, 3);
		else
			*str = ft_strjoindel(*str, tmp, 3);
	}
}

int					ftpf_ch_conv(t_data *data, va_list ap)
{
	char			tmp[5];
	char			*str;
	int				a;

	a = 0;
	ft_memset(tmp, '\0', 5);
	ftpf_valist_char(data, ap, tmp);
	str = ft_strdup(tmp);
	if ((int)ft_strlen(tmp) == 0)
		a++;
	if ((int)ft_strlen(tmp) == 0 && data->data[4] == 1)
		ft_putchar_fd(0, data->fd);
	if (data->data[1] > 0)
		ftpf_width(data, &str);
	ft_putstr_fd(str, data->fd);
	if ((int)ft_strlen(tmp) == 0 && data->data[4] == 0)
		ft_putchar_fd(0, data->fd);
	a += (int)ft_strlen(str);
	free(str);
	return (a);
}
