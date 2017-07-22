/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 13:09:24 by lcharbon          #+#    #+#             */
/*   Updated: 2016/11/24 16:32:04 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	unsigned long	i;
	unsigned long	u;

	i = 0;
	u = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[u] != '\0' && u < n)
	{
		s1[i] = s2[u];
		i++;
		u++;
	}
	s1[i] = '\0';
	return (s1);
}
