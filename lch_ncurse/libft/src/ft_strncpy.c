/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 07:52:36 by lcharbon          #+#    #+#             */
/*   Updated: 2016/11/23 08:06:19 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char			*a;
	char			*b;
	unsigned long	i;

	a = (char*)src;
	b = (char*)dst;
	i = 0;
	while (a[i] != '\0' && i < len)
	{
		b[i] = a[i];
		i++;
	}
	while (i < len)
	{
		b[i] = '\0';
		i++;
	}
	return (b);
}
