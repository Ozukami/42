/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 08:46:35 by lcharbon          #+#    #+#             */
/*   Updated: 2017/05/12 18:29:23 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	char	*a;
	char	*b;
	int		i;
	int		u;
	int		o;

	a = (char*)big;
	b = (char*)little;
	i = 0;
	u = 0;
	o = 0;
	while (b[u] != '\0')
		u++;
	if (u == 0)
		return (a);
	while (a[i] != '\0')
	{
		if (a[i] == b[o])
			if (ft_strncmp(&a[i], &b[o], u) == 0)
				return (&a[i - o]);
		i++;
	}
	return (NULL);
}
