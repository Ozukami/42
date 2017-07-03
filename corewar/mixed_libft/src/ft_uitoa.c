/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 12:08:36 by lcharbon          #+#    #+#             */
/*   Updated: 2017/02/13 18:38:44 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char						*ft_uitoa(unsigned long n)
{
	char					*ret;
	int						i;
	unsigned long long		nmem;

	if (n == 0)
		return (ft_strdup("0"));
	nmem = n;
	i = 0;
	while (nmem != 0)
	{
		nmem = nmem / 10;
		i++;
	}
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
