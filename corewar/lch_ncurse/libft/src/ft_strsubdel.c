/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 11:45:58 by lcharbon          #+#    #+#             */
/*   Updated: 2017/06/10 11:22:25 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strsubdel(char *s, unsigned int start, int len)
{
	int				i;
	int				o;
	char			*ptr;

	o = 0;
	i = start;
	if (!(ptr = (char*)malloc(len * sizeof(char) + 1)))
		return (NULL);
	while (s != NULL && o < len && i < (int)ft_strlen(s))
	{
		ptr[o] = s[i];
		o++;
		i++;
	}
	ptr[o] = '\0';
	free(s);
	return (ptr);
}
