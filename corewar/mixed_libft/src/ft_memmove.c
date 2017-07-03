/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 11:48:59 by lcharbon          #+#    #+#             */
/*   Updated: 2016/11/24 15:19:14 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char*)src;
	b = (unsigned char*)dst;
	if (dst < src)
		ft_memcpy(dst, src, len);
	else
		while (len--)
			b[len] = a[len];
	return (dst);
}
