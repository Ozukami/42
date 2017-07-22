/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 12:04:38 by lcharbon          #+#    #+#             */
/*   Updated: 2016/11/25 13:28:21 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_blank(char const *s)
{
	int		u;

	u = 0;
	while (s[u] == ' ' || s[u] == '\n' || s[u] == '\t')
		u++;
	return (u);
}

static int		ft_count_blank_end(char const *s, int u, int o)
{
	if (u != o)
		while (s[o - 1] == ' ' || s[o - 1] == '\n' || s[o - 1] == '\t')
			o--;
	return (o);
}

char			*ft_strtrim(char const *s)
{
	char	*ptr;
	int		u;
	int		o;
	int		n;

	if (s == NULL)
		return (NULL);
	u = ft_count_blank(s);
	o = 0;
	while (s[o] != '\0')
		o++;
	n = 0;
	o = ft_count_blank_end(s, u, o);
	o -= u;
	if (!(ptr = (char *)malloc((o + 1) * sizeof(char))))
		return (NULL);
	while (n < o)
	{
		ptr[n] = s[u];
		n++;
		u++;
	}
	ptr[o] = '\0';
	return (ptr);
}
