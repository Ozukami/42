/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_iso_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 04:48:49 by lcharbon          #+#    #+#             */
/*   Updated: 2017/06/10 06:14:40 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ftpf_iso_get_format(char **str)
{
	int			i;
	int			a;
	char		*tmp;
	char		*tmp2;

	i = 0;
	a = 0;
	tmp = ft_strnew(ft_strlen(*str));
	tmp2 = *str;
	while (tmp2[i] != '\0')
	{
		if (tmp2[i] == '-' || tmp2[i] == ':' || ft_isdigit(tmp2[i]) == 1)
			tmp[a++] = tmp2[i];
		else if (tmp2[i] == 'T')
			tmp[a++] = ' ';
		i++;
	}
	free(*str);
	*str = ft_strdup(tmp);
	free(tmp);
	return (1);
}

int				ftpf_iso_conv(t_data *data, va_list ap)
{
	int			ret;
	char		*str;

	str = ft_strdup(va_arg(ap, char*));
	if (ftpf_iso_get_format(&str) != 1)
	{
		free(str);
		return (0);
	}
	ft_putstr_fd(str, data->fd);
	ret = ft_strlen(str);
	free(str);
	return (ret);
}
