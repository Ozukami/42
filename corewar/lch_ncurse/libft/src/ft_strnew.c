/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 11:12:26 by lcharbon          #+#    #+#             */
/*   Updated: 2016/12/31 20:39:42 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ptr;

	if (!(ptr = (char *)malloc(size + 1)))
		return (NULL);
	ft_memset(ptr, '\0', size + 1);
	return (ptr);
}
