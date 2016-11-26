/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 15:16:40 by apoisson          #+#    #+#             */
/*   Updated: 2016/11/23 14:29:34 by qumaujea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_str_replace(char *s, char c)
{
	int		i;
	char	*rep;

	if (!(rep = ft_memalloc(ft_strlen(s) + 1)))
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == '#')
			rep[i] = c;
		else
			rep[i] = s[i];
		i++;
	}
	return (rep);
}

char	**ft_init(t_tetri *tetrilist)
{
	char	**tab;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_tetrilen(tetrilist) * 4;
	if (!(tab = malloc((sizeof(char *)) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		if (!(tab[i] = ft_fillalloc((sizeof(char)) * (len + 1))))
			return (NULL);
		i++;
	}
	tab[len] = 0;
	return (tab);
}

int		ft_place(char ***tab, t_tetri *tetrilist)
{
	int		i;
	int		k;
	int		j;

	j = 0;
	while (tab[0][j] && tetrilist->next)
	{
		i = 0;
		while (tab[0][j][i] && tetrilist->next)
		{
			k = 0;
			while ((tetrilist->tetri)[k])
			{
				if ((tetrilist->tetri)[k] == '.')
					i++;
				if ((tetrilist->tetri)[k] >= 32 && (tetrilist->tetri)[k] <= 126)
					tab[0][j][i] = (tetrilist->tetri)[k];
				if ((tetrilist->tetri)[k] == '\n')
				{
					j++;
					i = i - 4;
				}
				k++;
			}
			tetrilist = tetrilist->next;
			i++;
		}
		j++;
	}
	return (0);
}

void	ft_process(int fd)
{
	t_tetri	*tetrilist;
	char	buf[BUFSIZE + 1];
	char	l;
	int		r;
	char	**tab;

	l = 'A';
	tetrilist = NULL;
	while ((r = read(fd, buf, BUFSIZE)))
	{
		if (r < 20 || l > 'Z')
			ft_error();
		buf[r] = '\0';
		if (!ft_verif(buf))
			ft_error();
		ft_tetriadd(&tetrilist, ft_tetrinew(ft_str_replace(buf, l++)));
	}
	if (ft_strlen(tetrilist->tetri) != 20)
		ft_error();
	ft_tetrirev(&tetrilist);
	//ft_tetriprint(tetrilist);
	tab = ft_init(tetrilist);
	ft_place(&tab, tetrilist);
	int		i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}
