/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 11:01:15 by lcharbon          #+#    #+#             */
/*   Updated: 2016/11/24 14:32:59 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned long	*ptr;
	int				i;

	i = 0;
	if (!(ptr = (size_t*)malloc(size * sizeof(size_t))))
		return (NULL);
	while (ptr[i])
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
