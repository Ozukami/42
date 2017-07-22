/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstrb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:00:48 by lcharbon          #+#    #+#             */
/*   Updated: 2016/11/25 15:16:46 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	u;
	char	*str1;
	char	*str2;

	i = 0;
	u = 0;
	str1 = (char*)big;
	str2 = (char*)little;
	if (*little == '\0')
		return ((char*)big);
	while (str2[u] != '\0')
		u++;
	while (str1[i] != '\0' && (i + u) <= len)
	{
		if (ft_strncmp(str1 + i, str2, u) == 0)
			return (str1 + i);
		i++;
	}
	return (NULL);
}
