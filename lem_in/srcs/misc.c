/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 04:49:30 by apoisson          #+#    #+#             */
/*   Updated: 2017/05/21 04:49:33 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		update_tab(t_lemin *lemin)
{
	char	**split;
	int		i;
	int		j;

	i = -1;
	while (INDEX[++i])
	{
		split = ft_strsplit(INDEX[i], '_');
		T_NBLINK(i) = tab_size(split);
		if (!(T_LINKS(i) = ft_memalloc(sizeof(int) * (T_NBLINK(i) + 1))))
			ft_perror("Error: Malloc Failed");
		j = -1;
		while (split[++j])
			(T_LINKS(i))[j] = ft_atoi(split[j]);
		free_map(split);
	}
}

void		display_data(t_lemin *lemin)
{
	int		i;
	int		j;
	char	**split;

	ft_my_printf("%d\n", NB_ANT);
	i = -1;
	while (T_ROOM[++i])
	{
		if (T_ROLE(i) == START || T_ROLE(i) == END)
			ft_my_printf("%s\n", ((T_ROLE(i) == START) ? "##start" : "##end"));
		ft_my_printf("%s %d %d\n", T_NAME(i), T_X(i), T_Y(i));
	}
	i = -1;
	while (INDEX[++i])
	{
		split = ft_strsplit(INDEX[i], '_');
		j = -1;
		while (split[++j])
			if (ft_atoi(split[j]) > i)
				ft_my_printf("%s-%s\n", ID_NAME[i], ID_NAME[ft_atoi(split[j])]);
		free_map(split);
	}
	ft_putendl("");
}

t_lemin		*init_lemin(void)
{
	t_lemin		*lemin;

	if (!(lemin = ft_memalloc(sizeof(t_lemin))))
		ft_perror("Error: Malloc Failed");
	L_ROOM = NULL;
	T_ROOM = NULL;
	L_WAYS = NULL;
	T_WAYS = NULL;
	S_WAYS = NULL;
	L_ANT = NULL;
	INDEX = NULL;
	ID_NAME = NULL;
	NB_ANT = 0;
	ANT_END = 0;
	NB_WAY = 0;
	MAX_WAY = 0;
	ID_START = 0;
	ID_END = 0;
	CURR_WEIGHT = 0;
	CURR_PATH = ft_memalloc(1);
	NB_ROOM = 0;
	return (lemin);
}

int			to_tronc(char *path, int opt)
{
	int		i;
	int		rep;
	int		verif;

	i = -1;
	verif = 1;
	rep = 1;
	while (path[++i])
	{
		if (path[i] != '_' && verif)
			rep++;
		if (path[i] == '_')
			verif = 0;
	}
	if (opt)
		return (rep);
	i--;
	while (path[--i] != '_' && i > -1)
		rep++;
	return (++rep);
}
