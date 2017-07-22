/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_uitoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 09:02:41 by lcharbon          #+#    #+#             */
/*   Updated: 2017/06/10 01:49:00 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ftpf_find_base(char c)
{
	if (c == 'b' || c == 'B')
		return (2);
	if (c == 'x' || c == 'X' || c == 'p')
		return (16);
	if (c == 'o' || c == 'O')
		return (8);
	return (10);
}

char				*ftpf_uitoa_base(unsigned long n, char c)
{
	char			*ret;
	int				i;
	unsigned long	nmem;
	int				base;

	base = ftpf_find_base(c);
	if (n == 0)
		return (ft_strdup("0"));
	nmem = n;
	i = 0;
	while (nmem != 0)
	{
		i++;
		nmem /= base;
	}
	ret = ft_strnew(i);
	i--;
	while (i >= 0)
	{
		ret[i--] = (n % base) + 48;
		n /= base;
	}
	ft_reverse_str(ret);
	return (ret);
}
