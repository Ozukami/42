/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lslen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 00:49:31 by apoisson          #+#    #+#             */
/*   Updated: 2017/03/06 22:33:59 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

size_t	ft_lslen(wchar_t *s)
{
	int		i;
	size_t	len;
	size_t	bits;

	i = 0;
	len = 0;
	//printf("|%ls|\n", s);
	while (s[i])
	{
		bits = ft_strlen(ft_itoa_base((int)s[i], 2, 0));
		//printf(" > {%s} (%zu)\n", ft_itoa_base((int)s[i], 2, 0), bits);
		if (bits < 8)
			len++;
		else if (bits < 12)
			len += 2;
		else if (bits < 17)
			len += 3;
		else
			len += 4;
		i++;
	}
	return (len);
}
