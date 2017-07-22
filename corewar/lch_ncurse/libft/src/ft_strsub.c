/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 11:45:58 by lcharbon          #+#    #+#             */
/*   Updated: 2017/06/10 11:21:23 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	o;
	char			*ret;

	o = 0;
	i = start;
	if (len <= 0)
		return (NULL);
	if (!(ret = ft_strnew(len)))
		return (NULL);
	while (s != NULL && o < len && (int)i < ft_strlen(s))
	{
		ret[o] = s[i];
		o++;
		i++;
	}
	return (ret);
}
