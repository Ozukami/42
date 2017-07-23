/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoindel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 11:51:05 by lcharbon          #+#    #+#             */
/*   Updated: 2017/07/24 00:45:55 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoindel(char *s1, char *s2, int i)
{
	char			*ptr;

	if (!s1 || s1 == NULL)
		return ((char*)s2);
	if (!s2 || s2 == NULL)
		return ((char*)s1);
	if (!(ptr = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	ft_strcpy(ptr, s1);
	ft_strcat(ptr, s2);
	if (i == 1)
		ft_strdel(&s1);
	if (i == 2)
		ft_strdel(&s2);
	if (i == 3)
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
	return (ptr);
}
