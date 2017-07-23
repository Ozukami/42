/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 09:02:41 by lcharbon          #+#    #+#             */
/*   Updated: 2017/07/24 00:57:09 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_putaddr(void *s)
{
	char			*ret;
	int				i;
	unsigned long	n;
	unsigned long	nmem;

	n = (unsigned long)s;
	nmem = n;
	i = 0;
	while (nmem != 0)
	{
		i++;
		nmem /= 16;
	}
	i += 2;
	ret = ft_strnew(i + 2);
	i--;
	ret[0] = '0';
	ret[1] = 'x';
	while (i >= 2)
	{
		ret[i--] = (n % 16) + 48;
		n /= 16;
	}
	ft_reverse_str(ret);
	return (ret);
}
