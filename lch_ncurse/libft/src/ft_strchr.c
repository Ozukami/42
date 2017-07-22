/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 08:31:03 by lcharbon          #+#    #+#             */
/*   Updated: 2016/11/25 14:35:57 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			*a;
	unsigned char	e;
	size_t			i;

	a = (char*)s;
	e = c;
	i = 0;
	while (a[i] != '\0')
	{
		if (a[i] == e)
			return (&a[i]);
		i++;
	}
	if (a[i] == e)
		return (&a[i]);
	return (NULL);
}
