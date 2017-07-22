/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_sign_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 15:09:25 by lcharbon          #+#    #+#             */
/*   Updated: 2017/06/10 05:23:28 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ftpf_prec(t_data *data, intmax_t arg, char **str)
{
	int				nb_len;
	char			*tmp;
	char			*tmp2;

	nb_len = ft_strlen(*str);
	if ((data->data[0] <= nb_len && arg > 0) || data->data[0] <= nb_len - 1)
		return ;
	if (arg >= 0)
		tmp = ft_strnewch(data->data[0] - nb_len, '0');
	else
	{
		tmp = ft_strnewch(data->data[0] - nb_len + 2, '0');
		tmp2 = *str;
		*str = ft_strsub(*str, 1, ft_strlen(*str) - 1);
		ft_strdel(&tmp2);
		tmp[0] = '-';
	}
	*str = ft_strjoindel(tmp, *str, 3);
}

static void			ftpf_width_noless(t_data *data, intmax_t arg, char **str)
{
	char			*tmp;
	char			*tmp2;

	if (data->data[3] == 0 || data->data[0] >= 0)
		tmp = ft_strnewch(data->data[1] - ft_strlen(*str), ' ');
	else if (arg >= 0 && *str[0] != ' ' && *str[0] != '+')
		tmp = ft_strnewch(data->data[1] - ft_strlen(*str), '0');
	else
	{
		tmp = ft_strnewch(data->data[1] - ft_strlen(*str) + 1, '0');
		tmp[0] = *str[0];
		tmp2 = *str;
		*str = ft_strsub(*str, 1, ft_strlen(*str) - 1);
		ft_strdel(&tmp2);
	}
	*str = ft_strjoindel(tmp, *str, 3);
}

static void			ftpf_width_less(t_data *data, char **str)
{
	char			*tmp;

	if (!(tmp = ft_strnewch(data->data[1] - ft_strlen(*str), ' ')))
		return ;
	*str = ft_strjoindel(*str, tmp, 3);
}

static void			ftpf_flag(t_data *data, intmax_t arg, char **str)
{
	if (arg >= 0)
	{
		if (data->data[5] == 1)
			*str = ft_strjoindel("+", *str, 2);
		else
			*str = ft_strjoindel(" ", *str, 2);
	}
}

int					ftpf_sign_conv(t_data *data, va_list ap, char c)
{
	intmax_t		arg;
	char			*str;
	int				ret;

	arg = ftpf_valist_sign(data, ap, c);
	str = ftpf_sign_itoa(arg);
	ftpf_apo_flag(&str, data);
	if (data->data[0] > 0)
		ftpf_prec(data, arg, &str);
	if (data->data[0] == 0 && arg == 0)
		ft_memset(str, '\0', 5);
	if (data->data[5] == 1 || data->data[6] == 1)
		ftpf_flag(data, arg, &str);
	if (data->data[1] > ft_strlen(str) && data->data[4] == 1)
		ftpf_width_less(data, &str);
	if (data->data[1] > ft_strlen(str) && data->data[4] == 0)
		ftpf_width_noless(data, arg, &str);
	ft_putstr_fd(str, data->fd);
	ret = ft_strlen(str);
	free(str);
	return (ret);
}
