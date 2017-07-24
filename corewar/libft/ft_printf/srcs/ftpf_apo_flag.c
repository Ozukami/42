/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_apo_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 04:46:04 by lcharbon          #+#    #+#             */
/*   Updated: 2017/06/08 05:32:45 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_stradd(char **str, int pos)
{
	char		*tmp;
	char		*tmp2;
	char		*ret;

	tmp = ft_strsub(*str, 0, pos);
	tmp2 = ft_strsub(*str, pos, ft_strlen(*str) - pos);
	ret = ft_strjoindel(tmp, " ", 1);
	ret = ft_strjoindel(ret, tmp2, 3);
	free(*str);
	*str = ret;
}

void			ftpf_apo_flag(char **str, t_data *data)
{
	int			i;
	int			a;
	int			len;

	a = 0;
	i = 3;
	if (data->data[14] == 0)
		return ;
	len = ft_strlen(*str);
	if (len <= 3)
		return ;
	while (len > 0)
	{
		if (a == 3)
		{
			ft_stradd(str, len);
			a = 0;
		}
		len--;
		a++;
	}
}
