/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppt_pgt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 04:29:18 by apoisson          #+#    #+#             */
/*   Updated: 2017/05/21 04:29:34 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			get_pgt(t_lemin *lemin)
{
	int		i;
	int		pgt;

	i = 0;
	pgt = SW_A(i) + SW_W(i);
	while (++i < MAX_WAY)
		pgt = ft_max(pgt, SW_A(i) + SW_W(i));
	return (pgt);
}

int			get_ppt(t_lemin *lemin)
{
	int		i;
	int		ppt;

	i = 0;
	ppt = SW_A(i) + SW_W(i);
	while (++i < MAX_WAY)
		ppt = ft_min(ppt, SW_A(i) + SW_W(i));
	return (ppt);
}

t_way		*get_pgt_way(t_lemin *lemin)
{
	int		i;
	t_way	*pgt_way;

	i = 0;
	pgt_way = SW(i);
	while (++i < MAX_WAY)
		if (SW_A(i) + SW_W(i) > pgt_way->ant_to_send + pgt_way->weight)
			pgt_way = SW(i);
	return (pgt_way);
}

t_way		*get_ppt_way(t_lemin *lemin)
{
	int		i;
	t_way	*ppt_way;

	i = 0;
	ppt_way = SW(i);
	while (++i < MAX_WAY)
		if (SW_A(i) + SW_W(i) < ppt_way->ant_to_send + ppt_way->weight)
			ppt_way = SW(i);
	return (ppt_way);
}
