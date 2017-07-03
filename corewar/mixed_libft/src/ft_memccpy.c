/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 11:30:10 by lcharbon          #+#    #+#             */
/*   Updated: 2016/11/24 16:31:17 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst,
		const void *src, int c, size_t n)
{
	unsigned long	i;
	unsigned char	*a;
	unsigned char	*b;
	unsigned char	e;

	a = (unsigned char*)src;
	b = (unsigned char*)dst;
	e = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		b[i] = a[i];
		if (a[i] == e)
			return (&b[i + 1]);
		i++;
	}
	return (NULL);
}
