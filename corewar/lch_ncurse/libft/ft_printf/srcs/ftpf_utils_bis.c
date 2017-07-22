/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_utils_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 01:36:13 by lcharbon          #+#    #+#             */
/*   Updated: 2017/06/10 01:49:49 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					ftpf_expo_pre(char **str, long double arg, int pre)
{
	if (pre > 0 && arg == 0)
		*str = ft_strjoindel(*str, ft_strnewch(pre -
		ft_strlen(*str) + 2, '0'), 3);
	else if (pre == 0 && arg >= 0)
		*str = ft_strjoindel(ft_strsub(*str, 0, 1),
		ft_strsubdel(*str, 3, ft_strlen(*str) - 3), 3);
	else if (pre == 0 && arg < 0)
		*str = ft_strjoindel(ft_strsub(*str, 0, 2),
		ft_strsubdel(*str, 4, ft_strlen(*str) - 4), 3);
}

int						ftpf_expo_cal_pre(t_data *data)
{
	int					ret;

	ret = data->data[0];
	if (data->data[0] == -1)
		data->data[0] = 6;
	else if (data->data[0] > 8)
	{
		data->data[0] = 8;
		return (ret);
	}
	return (0);
}

void					ft_reverse_str(char *str)
{
	int					i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 58 && str[i] <= 63)
			str[i] += 39;
		i++;
	}
}
