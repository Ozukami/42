/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetrilist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 14:58:58 by apoisson          #+#    #+#             */
/*   Updated: 2016/11/23 13:24:45 by qumaujea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri	*ft_tetrinew(char *tetri)
{
	t_tetri	*tetrinew;

	if (!(tetrinew = malloc(sizeof(t_tetri))))
		return (NULL);
	if (tetri == NULL)
		tetrinew->tetri = NULL;
	else
	{
		tetrinew->tetri = malloc(BUFSIZE + 1);
		ft_memcpy(tetrinew->tetri, tetri, BUFSIZE + 1);
	}
	tetrinew->next = NULL;
	return (tetrinew);
}

void	ft_tetriadd(t_tetri **begin, t_tetri *new)
{
	new->next = *begin;
	*begin = new;
}

void	ft_tetrirev(t_tetri **begin)
{
	t_tetri	*current;
	t_tetri	*tmp1;
	t_tetri	*tmp2;

	current = *begin;
	tmp1 = 0;
	tmp2 = 0;
	while (current)
	{
		tmp1 = current;
		current = current->next;
		tmp1->next = tmp2;
		tmp2 = tmp1;
	}
	*begin = tmp1;
}

size_t	ft_tetrilen(t_tetri *tetrilist)
{
	size_t	i;

	i = 1;
	while (tetrilist->next)
	{
		tetrilist = tetrilist->next;
		i++;
	}
	return (i);
}

void	ft_tetriprint(t_tetri *tetri)
{
	t_tetri	*current;

	current = tetri;
	while (current)
	{
		ft_putstr(current->tetri);
		current = current->next;
	}
}
