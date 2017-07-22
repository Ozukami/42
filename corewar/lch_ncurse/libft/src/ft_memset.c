/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 10:16:34 by lcharbon          #+#    #+#             */
/*   Updated: 2017/03/18 18:48:20 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned long	i;
	unsigned char	a;
	char			*tmp;

	if (!b)
		return (NULL);
	tmp = b;
	i = 0;
	a = c;
	while (i < len)
	{
		tmp[i] = a;
		i++;
	}
	return (b);
}
