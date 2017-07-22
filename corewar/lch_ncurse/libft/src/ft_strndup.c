/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 11:45:42 by lcharbon          #+#    #+#             */
/*   Updated: 2017/06/10 11:46:02 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, int n)
{
	int		i;
	char	*s2;

	i = 0;
	while (s1[i] != '\0')
		i++;
	if (!(s2 = (char *)malloc((i * sizeof(char)) + 1)))
		return (NULL);
	i = 0;
	while (s1[i] != '\0' && i < n)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
