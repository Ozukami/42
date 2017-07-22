/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 11:28:28 by lcharbon          #+#    #+#             */
/*   Updated: 2016/11/25 13:13:10 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*ptr;

	i = 0;
	while (s != NULL && s[i] != '\0')
		i++;
	if (!(ptr = (char *)malloc(i * sizeof(char) + 1)))
		return (NULL);
	i = 0;
	while (s != NULL && s[i] != '\0')
	{
		ptr[i] = f(s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
