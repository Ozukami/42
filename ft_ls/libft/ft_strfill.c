/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 01:36:52 by apoisson          #+#    #+#             */
/*   Updated: 2017/03/17 02:12:41 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfill(size_t size, char c)
{
	char	*new;
	int		i;

	if (!(new = (char *)ft_memalloc(size + 1)))
		return (NULL);
	i = 0;
	while (i < (int)size)
		new[i++] = c;
	new[i] = '\0';
	return (new);
}
