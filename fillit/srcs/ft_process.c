/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 15:16:40 by apoisson          #+#    #+#             */
/*   Updated: 2016/11/26 13:45:12 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_tetri_format(char *s)
{
	int		i;
	int		j;
	size_t	len;
	char	*rep;

	i = 0;
	while (i < 16)
	{
		if (s[i] == '.' && s[i + 1] == '.'
				&& s[i + 2] == '.' && s[i + 3] == '.')
		{
			s[i] = 'x';
			s[i + 1] = 'x';
			s[i + 2] = 'x';
			s[i + 3] = 'x';
			s[i + 4] = 'x';
		}
		i = i + 5;
	}
	i = 0;
	while (i < 4)
	{
		if ((s[i] == '.' || s[i] == 'x')
				&& (s[i + 5] == '.' || s[i + 5] == 'x')
				&& (s[i + 10] == '.' || s[i + 10] == 'x')
				&& (s[i + 15] == '.' || s[i + 15] == 'x'))
		{
			s[i] = 'x';
			s[i + 5] = 'x';
			s[i + 10] = 'x';
			s[i + 15] = 'x';
		}
		i++;
	}
	len = ft_strlen(s);
	i = 0;
	while (s[i])
	{
		if (s[i] == 'x')
			len--;
		i++;
	}
	if (!(rep = ft_memalloc(len + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == 'x')
			i++;
		rep[j] = s[i];
		i++;
		j++;
	}
	return (rep);
}

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

/*
 ** OK = 1
 ** NOK = 0
 */

int		ft_place_tracking(char ***tab, int i, t_tetri *tetri, int k)
{
	int		len;
	int		j;

	len = ft_strlen(tab[0][0]);
	j = 0;
	while ((tetri->tetri)[k] == '.')
		k++;
	if ((tetri->tetri)[k] == '\n')
	{
		while ((tetri->tetri)[j] != '\n')
			j++;
		k++;
		i = i + len - j;
	}
	if ((tetri->tetri)[k] == '\0')
		return (1);
	if (tab[0][i / len][i % len] == '.')
	{
		if (k == 0)
			printf("[ok]\n");
		if ((tetri->tetri)[k] != '\n')
			tab[0][i / len][i % len] = (tetri->tetri)[k];
		int		a = 0;
		printf("--------------\n");
		while (tab[0][a])
		{
			ft_putendl(tab[0][a]);
			a++;
		}
		printf("--------------\n");
		if (ft_place_tracking(tab, i + 1, tetri, k + 1))
			return (1);
		tab[0][i / len][i % len] = '.';
	}
	return (0);
}

int		ft_place(char ***tab, t_tetri *tetrilist)
{
	int		i;

	while (tetrilist)
	{
		i = 0;
		while (i < (int)((ft_tetrilen(tetrilist) * 4) * (ft_tetrilen(tetrilist) * 4)))
		{
			printf("{%c|%d}\n", (tetrilist->tetri)[0], i);
			if (ft_place_tracking(tab, i, tetrilist, 0))
				break ;
			i++;
		}
		if (tetrilist->next)
			tetrilist = tetrilist->next;
		else
			break ;
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
	ft_tetriter(&tetrilist, &ft_tetri_format);
	ft_tetrirev(&tetrilist);
	ft_tetriprint(tetrilist);
	tab = ft_init(tetrilist);
	ft_place(&tab, tetrilist);
	int		i = 0;
	printf("--------------\n");
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	printf("--------------\n");
}
