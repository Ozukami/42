/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 12:08:36 by lcharbon          #+#    #+#             */
/*   Updated: 2017/02/13 18:05:41 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoa_neg(int i, long long n)
{
	char	*ret;

	if (n == 0)
		return (ft_strdup("0"));
	if (!(ret = ft_strnew(i + 1)))
		return (NULL);
	ret[0] = '-';
	n = n * -1;
	while (i > 0)
	{
		ret[i] = n % 10 + 48;
		n /= 10;
		i--;
	}
	return (ret);
}

char		*ft_itoa(long long n)
{
	char			*ret;
	int				i;
	long long		nmem;

	if (n < -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	nmem = n;
	i = 0;
	while (nmem != 0)
	{
		nmem = nmem / 10;
		i++;
	}
	if (n <= 0)
		return (ft_itoa_neg(i, n));
	if (!(ret = ft_strnew(i)))
		return (NULL);
	i--;
	while (i >= 0)
	{
		ret[i] = n % 10 + 48;
		n /= 10;
		i--;
	}
	return (ret);
}
