/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchrb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 07:35:34 by lcharbon          #+#    #+#             */
/*   Updated: 2016/11/23 09:19:14 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*a;
	unsigned char	e;
	unsigned long	i;

	a = (unsigned char*)s;
	e = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (a[i] == e)
			return (&a[i]);
		i++;
	}
	return (NULL);
}
