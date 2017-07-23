/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnewch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 19:13:36 by lcharbon          #+#    #+#             */
/*   Updated: 2017/07/24 00:45:25 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnewch(size_t size, char c)
{
	char	*ptr;

	if (!(ptr = (char *)malloc(size + 1)))
		return (NULL);
	ft_memset(ptr, '\0', size + 1);
	ft_memset(ptr, c, size);
	return (ptr);
}
