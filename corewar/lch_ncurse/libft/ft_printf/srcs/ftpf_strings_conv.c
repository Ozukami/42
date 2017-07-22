/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_strings_conv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 15:09:25 by lcharbon          #+#    #+#             */
/*   Updated: 2017/06/08 02:34:58 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int				ftpf_byte_len(char *str)
{
	unsigned char		n;

	n = (unsigned char)*str;
	if ((n & 128) == 0)
		return (1);
	if ((n & 224) == 192)
		return (2);
	if ((n & 240) == 224)
		return (3);
	if ((n & 248) == 240)
		return (4);
	return (0);
}

static void				ftpf_prec(t_data *data, char *str)
{
	int					i;
	int					tmp;

	tmp = 0;
	if (data->conv == 'S')
	{
		i = 0;
		while (tmp + i <= data->data[0])
		{
			tmp += i;
			i = ftpf_byte_len(str + tmp);
		}
		str[tmp] = '\0';
	}
	else
		str[data->data[0]] = '\0';
}

static void				ftpf_width(t_data *data, char **str)
{
	char				*tmp;
	int					i;

	i = 0;
	if (data->data[1] > ft_strlen(*str))
	{
		tmp = *str;
		if (data->data[3] == 0 || data->data[4] == 1)
			while (i < data->data[1])
				i++;
		else
			while (i < data->data[1])
				i++;
		*str = ft_strnew(i);
		if (data->data[3] == 0 || data->data[4] == 1)
			ft_memset(*str, ' ', i);
		else
			ft_memset(*str, '0', i);
		if (data->data[4] == 0)
			ft_strncpy(*str + data->data[1] -
			ft_strlen(tmp), tmp, ft_strlen(tmp));
		else
			ft_strncpy(*str, tmp, ft_strlen(tmp));
		free(tmp);
	}
}

int						ftpf_strings_conv(t_data *data, va_list ap)
{
	char				*tmp;
	int					ret;

	tmp = ftpf_valist_strings(data, ap);
	if ((data->data[0] >= 0 && data->data[0] < ft_strlen(tmp)))
		ftpf_prec(data, tmp);
	if (data->data[1] > 0)
		ftpf_width(data, &tmp);
	ft_putstr_fd(tmp, data->fd);
	ret = ft_strlen(tmp);
	free(tmp);
	return (ret);
}
