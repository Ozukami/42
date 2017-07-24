/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_get_special.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 02:57:31 by lcharbon          #+#    #+#             */
/*   Updated: 2017/06/10 11:17:01 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	go_format(char const **format)
{
	while (**format && **format != '}')
		(*format)++;
	(*format)++;
}

static int	ftpf_get_special_cont(char const **format, t_data *data)
{
	if (ft_strncmp(*format, "{under}", 7) == 0)
		ft_putstr("\033[4m");
	else if (ft_strncmp(*format, "{black}", 7) == 0)
		ft_putstr("\033[30;40m");
	else if (ft_strncmp(*format, "{eoc}", 5) == 0)
		ft_putstr("\033[0m");
	else if (ft_strncmp(*format, "{nounder}", 9) == 0)
		ft_putstr("\033[24m");
	else if (ft_strncmp(*format, "{bold}", 6) == 0)
		ft_putstr("\033[1m");
	else if (ft_strncmp(*format, "{nobold}", 8) == 0)
		ft_putstr("\033[21m");
	else if (ft_strncmp(*format, "{yellow}", 8) == 0)
		ft_putstr("\033[33;40m");
	else if (ft_strncmp(*format, "{cyan}", 6) == 0)
		ft_putstr("\033[36;40m");
	else
	{
		ft_putchar_fd(**format, data->fd);
		data->n_char++;
		(*format)++;
		return (0);
	}
	return (1);
}

void		ftpf_get_special(char const **format, t_data *data, va_list ap)
{
	if (ft_strncmp(*format, "{fd}", 4) == 0 &&
	ft_strncmp(*format, "{fd=open}", 9) != 0)
		data->fd = va_arg(ap, int);
	else if (ft_strncmp(*format, "{fd=open}", 9) == 0)
	{
		data->fd = open(va_arg(ap, char *), O_WRONLY);
		data->opfd = 1;
	}
	else if (ft_strncmp(*format, "{blue}", 5) == 0)
		ft_putstr("\033[34;40m");
	else if (ft_strncmp(*format, "{red}", 5) == 0)
		ft_putstr("\033[31;40m");
	else if (ft_strncmp(*format, "{green}", 7) == 0)
		ft_putstr("\033[32;40m");
	else
	{
		if (ftpf_get_special_cont(format, data) == 0)
			return ;
	}
	go_format(format);
}
