/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_unsign_conv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 15:09:25 by lcharbon          #+#    #+#             */
/*   Updated: 2017/06/08 05:36:34 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ftpf_prec(t_data *data, char **str)
{
	int			nb_len;
	char		*tmp;

	nb_len = ft_strlen(*str);
	if (data->data[2] == 1 && (data->conv == 'o' || data->conv == 'O'))
		nb_len++;
	tmp = ft_strnewch(data->data[0] - nb_len, '0');
	*str = ft_strjoindel(tmp, *str, 3);
}

static void		ftpf_width_noless(t_data *data, char **str)
{
	char		*tmp;

	if (data->data[1] - ft_strlen(*str) <= 0)
		return ;
	if (data->data[3] == 0 || data->data[0] > 0)
		tmp = ft_strnewch(data->data[1] - ft_strlen(*str), ' ');
	else if ((data->conv == 'x' || data->conv == 'X' || data->conv == 'p'))
	{
		if (ft_strstr(*str, "0x"))
		{
			tmp = ft_strnewch(data->data[1] - ft_strlen(*str), '0');
			*str = ft_strsubdel(*str, 2, ft_strlen(*str) - 2);
			*str = ft_strjoindel(tmp, *str, 3);
			*str = ft_strjoindel("0x", *str, 2);
			return ;
		}
		tmp = ft_strnewch(data->data[1] - ft_strlen(*str), '0');
		*str = ft_strjoindel(tmp, *str, 3);
		return ;
	}
	else
		tmp = ft_strnewch(data->data[1] - ft_strlen(*str), '0');
	*str = ft_strjoindel(tmp, *str, 3);
}

static void		ftpf_width_less(t_data *data, char **str)
{
	char		*tmp;

	tmp = ft_strnewch(data->data[1] - ft_strlen(*str), ' ');
	*str = ft_strjoindel(*str, tmp, 3);
}

static void		ftpf_flag(t_data *data, uintmax_t arg, char **str)
{
	char		*tmp;

	tmp = NULL;
	if ((data->conv == 'o' || data->conv == 'O') && arg != 0)
		tmp = ft_strdup("0");
	else if (data->conv == 'x' || data->conv == 'X' || data->conv == 'p')
		tmp = ft_strdup("0x");
	*str = ft_strjoindel(tmp, *str, 3);
}

int				ftpf_unsign_conv(t_data *data, va_list ap, char c)
{
	uintmax_t	arg;
	int			ret;
	char		*str;

	arg = ftpf_valist_unsign(data, ap, c);
	str = ftpf_uitoa_base(arg, data->conv);
	ftpf_apo_flag(&str, data);
	if (data->data[0] > ft_strlen(str))
		ftpf_prec(data, &str);
	if (arg == 0)
		ftpf_unsign_zero(data, &str, arg);
	if (data->data[2] == 1 && arg != 0)
		ftpf_flag(data, arg, &str);
	if (data->data[1] > ft_strlen(str) && data->data[4] == 1)
		ftpf_width_less(data, &str);
	if (data->data[1] > ft_strlen(str) && data->data[4] == 0)
		ftpf_width_noless(data, &str);
	if (data->conv == 'X')
		ftpf_upcase(str);
	ft_putstr_fd(str, data->fd);
	ret = ft_strlen(str);
	ft_strdel(&str);
	return (ret);
}
