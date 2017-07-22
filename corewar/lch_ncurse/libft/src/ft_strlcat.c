/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 11:16:16 by lcharbon          #+#    #+#             */
/*   Updated: 2016/11/24 16:32:30 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned long	i;
	unsigned long	o;
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char*)src;
	b = (unsigned char*)dst;
	i = 0;
	while (b[i] != '\0' && i < size)
		i++;
	o = i;
	while (a[i - o] != '\0' && i < size - 1)
	{
		b[i] = a[i - o];
		i++;
	}
	if (o < size)
		b[i] = '\0';
	return (o + ft_strlen(src));
}
