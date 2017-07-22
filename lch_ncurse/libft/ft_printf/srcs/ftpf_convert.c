/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_convert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 15:09:25 by lcharbon          #+#    #+#             */
/*   Updated: 2017/06/10 05:26:56 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ftpf_width(t_data *data, char **str)
{
	char		*tmp;

	if (data->data[1] > ft_strlen(*str))
	{
		if (data->data[4] == 1 || data->data[3] == 0)
			tmp = ft_strnewch(data->data[1] - ft_strlen(*str), ' ');
		else
			tmp = ft_strnewch(data->data[1] - ft_strlen(*str), '0');
		if (ft_strlen(tmp) == 0)
			return ;
		if (data->data[4] == 0)
			*str = ft_strjoindel(tmp, *str, 3);
		else
			*str = ft_strjoindel(*str, tmp, 3);
	}
}

static int		ftpf_noconv(t_data *data, char c)
{
	char		*str;
	int			ret;

	str = ft_strnew(1);
	str[0] = c;
	if (data->data[1] > 0)
		ftpf_width(data, &str);
	ft_putstr_fd(str, data->fd);
	ret = ft_strlen(str);
	free(str);
	return (ret);
}

static int		ftpf_more_conv(t_data *data, va_list ap, char c)
{
	if (c == 'f' || c == 'F')
		return (ftpf_float_conv(data, ap));
	if (c == 'g' || c == 'G')
		return (ftpf_gep_conv(data, ap));
	else if (c == 'a' || c == 'A')
		return (ftpf_hexafloat_conv(data, ap));
	else if (c == 'e' || c == 'E')
		return (ftpf_expo_conv(data, ap));
	else if (c == 'k')
		return (ftpf_iso_conv(data, ap));
	else if (c == 'n')
		return (ftpf_n_conv(data, ap));
	else
		return (ftpf_noconv(data, c));
	return (0);
}

int				ftpf_convert(t_data *data, va_list ap)
{
	char		c;

	c = data->conv;
	if (c == 'd' || c == 'D' || c == 'i')
		return (ftpf_sign_conv(data, ap, c));
	else if (c == 'u' || c == 'U' || c == 'x' || c == 'x' ||
		c == 'X' || c == 'o' || c == 'O' || c == 'b' || c == 'B')
		return (ftpf_unsign_conv(data, ap, c));
	else if (c == 'p')
		return (ftpf_unsign_p_conv(data, ap));
	else if (c == 'c' || c == 'C')
		return (ftpf_ch_conv(data, ap));
	else if (c == 's' || c == 'S')
		return (ftpf_strings_conv(data, ap));
	else
		return (ftpf_more_conv(data, ap, c));
	return (0);
}
