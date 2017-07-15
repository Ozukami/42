/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 09:02:41 by lcharbon          #+#    #+#             */
/*   Updated: 2017/06/10 10:47:11 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_uitoa_base(unsigned long n, int base)
{
	char			*ret;
	int				i;
	unsigned long	nmem;

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
