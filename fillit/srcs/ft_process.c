/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 15:16:40 by apoisson          #+#    #+#             */
/*   Updated: 2016/11/27 15:32:57 by apoisson         ###   ########.fr       */
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
	if (k > 0)
		if (i % len == 0 && (tetri->tetri)[k - 1] != '\n'  && (tetri->tetri)[k] != '\n')
			return (0);
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
	{
		printf("-- CURRENT %d --\n", len);
		int	z = 0;
		while (tab[0][z])
		{
			printf("%s\n", tab[0][z]);
			z++;
		}
		printf("-- END CURRENT --\n");
		return (1);
	}
	if (i >= len * len)
		return (0);
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

void	ft_delete_tetri(char ***tab, t_tetri *tetri)
{
	int		i;
	int		j;

	i = 0;
	while (tab[0][i])
	{
		j = 0;
		while (tab[0][i][j])
		{
			if (tab[0][i][j] == tetri->l)
				tab[0][i][j] = '.';
			j++;
		}
		i++;
	}
}

int		ft_place(char ***tab, t_tetri *tetrilist, size_t opti_size)
{
	while (tetrilist)
	{
		while (tetrilist->i < (int)(opti_size * opti_size))
		{
			if (ft_place_tracking(tab, tetrilist->i, tetrilist, 0))
			{
				tetrilist->i = tetrilist->i;
				break ;
			}
			tetrilist->i += 1;
		}
		if (tetrilist->i == (int)(opti_size * opti_size))
		{
			tetrilist->i = 0;
			if (tetrilist->prev)
			{
				ft_delete_tetri(tab, tetrilist);
				tetrilist = tetrilist->prev;
				printf("ok\n");
			}
			else
				return (0);
		}
		else if (tetrilist->next)
			tetrilist = tetrilist->next;
		else
			break ;
	}
	return (1);
}

void	ft_process_2(t_tetri *tetrilist)
{
	char	**tab;
	int		i;
	size_t	opti_size;

	i = 0;
	while (!(opti_size = ft_sqrt(ft_tetrilen(tetrilist) * 4 + i)))
		i++;
	tab = ft_init(opti_size);
	while (!ft_place(&tab, tetrilist, opti_size))
	{
		ft_tafritatoukompri(&tab);
		opti_size++;
		tab = ft_init(opti_size);
	}
	printf("{final size = %zu}\n", opti_size);
	printf("-- FINAL --\n");
	int	z = 0;
	while (tab[z])
	{
		printf("%s\n", tab[z]);
		z++;
	}
	printf("-- END --\n");
	ft_tafritatoukompri(&tab);
}

void	ft_process(int fd)
{
	t_tetri	*tetrilist;
	char	buf[BUFSIZE + 1];
	char	l;
	int		r;

	l = 'A';
	tetrilist = NULL;
	while ((r = read(fd, buf, BUFSIZE)))
	{
		if (r < 20 || l > 'Z')
			ft_error();
		buf[r] = '\0';
		if (!ft_verif(buf))
			ft_error();
		ft_tetriadd(&tetrilist, ft_tetrinew(ft_str_replace(buf, l), l));
		l++;
	}
	if (ft_strlen(tetrilist->tetri) != 20)
		ft_error();
	ft_tetriter(&tetrilist, &ft_tetri_format);
	ft_tetrirev(&tetrilist);
	ft_tetriprint(tetrilist);
	ft_process_2(tetrilist);
}
