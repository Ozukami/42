/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 09:02:41 by lcharbon          #+#    #+#             */
/*   Updated: 2017/06/10 10:47:18 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoa_base_neg(long n, int i, int base)
{
	char	*ret;

	if (n == 0)
		return (ft_strdup("0"));
	ret = ft_strnew(i + 1);
	ret[0] = '-';
	n *= -1;
	while (i >= 1)
	{
		ret[i--] = (n % base) + 48;
		n /= base;
	}
	ft_reverse_str(ret);
	return (ret);
}

char		*ft_itoa_base(long n, int base)
{
	char	*ret;
	int		i;
	long	nmem;

	nmem = n;
	i = 0;
	while (nmem != 0)
	{
		i++;
		nmem /= base;
	}
	if (n <= 0)
		return (ft_itoa_base_neg(n, i, base));
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
