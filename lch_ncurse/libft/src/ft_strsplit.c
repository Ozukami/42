/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 12:21:35 by lcharbon          #+#    #+#             */
/*   Updated: 2016/11/25 15:29:12 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_word(char const *s, char c)
{
	int i;
	int w;

	i = 0;
	w = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
			w++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (w);
}

static int		ft_count_char(char const *s, char c)
{
	int i;
	int u;

	i = 0;
	u = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i] != c && s[i] != '\0')
	{
		u++;
		i++;
	}
	return (u);
}

static void		ft_init(int *i, int *o)
{
	*i = 0;
	*o = 0;
}

char			**ft_strsplit(char const *s, char c)
{
	int		w;
	int		i;
	int		u;
	int		o;
	char	**ret;

	if (s == NULL)
		return (NULL);
	ft_init(&i, &o);
	w = ft_count_word(s, c);
	if (!(ret = (char**)malloc((w + 1) * sizeof(char*))))
		return (NULL);
	while (i < w)
	{
		while (s[o] == c && s[o] != '\0')
			o++;
		s += o;
		o = 0;
		u = ft_count_char(s, c);
		ret[i] = ft_strsub(s, 0, u);
		s += u;
		i++;
	}
	ret[w] = NULL;
	return (ret);
}
