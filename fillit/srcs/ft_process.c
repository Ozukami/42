/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 15:16:40 by apoisson          #+#    #+#             */
/*   Updated: 2016/11/27 11:58:17 by qumaujea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** OK = 1
** NOK = 0
*/

int		ft_place_tracking(char ***tab, int i, t_tetri *tetri, int k)
{
	int		len;
	int		j;

	len = ft_strlen(tab[0][0]);
	while ((tetri->tetri)[k] == '.')
	{
		k++;
		i++;
	}
	if ((tetri->tetri)[k] == '\n')
	{
		j = 0;
		while ((tetri->tetri)[j] != '\n')
			j++;
		k++;
		i = i + len - j;
	}
	if ((tetri->tetri)[k] == '\0')
		return (1);
	if (tab[0][i / len][i % len] == '.')
	{
		if ((tetri->tetri)[k] != '\n')
			tab[0][i / len][i % len] = (tetri->tetri)[k];
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
		while (i < (int)((ft_tetrilen(tetrilist) * 4)
					* (ft_tetrilen(tetrilist) * 4)))
		{
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
