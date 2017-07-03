/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 11:19:43 by lcharbon          #+#    #+#             */
/*   Updated: 2016/11/19 11:27:45 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned long	i;
	char			*a;

	a = s;
	i = 0;
	while (i < n)
	{
		a[i] = 0;
		i++;
	}
}
