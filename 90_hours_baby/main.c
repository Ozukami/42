/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 11:28:44 by apoisson          #+#    #+#             */
/*   Updated: 2017/02/07 11:47:00 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct		s_log
{
	int				h;
	int				m;
	struct s_log	*next;
}					t_log;

t_log	*ft_new_log(int h, int m)
{
	t_log	*new;

	new = malloc(sizeof(t_log));
	new->h = h;
	new->m = m;
	new->next = NULL;
	return (new);
}

void	ft_add_log(t_log **list, t_log *new)
{
	new->next = *list;
	*list = new;
}

int		main(int ac, char **av)
{
	t_log	*list;
	int		i;
	int		h;
	int		m;

	list = NULL;
	if (ac < 3)
	{
		printf("usage : ./a.out hh.mm ... hh.mm\n");
		return (0);
	}
	i = 1;
	while (i < ac)
	{
		h = atoi(av[i]);
		m = atoi(av[i] + ((h >= 10) ? 3 : 2 ));
		ft_add_log(&list, ft_new_log(h, m));
		i++;
	}
	h = 0;
	m = 0;
	while (list)
	{
		h += list->h;
		m += list->m;
		list = list->next;
	}
	h += m / 60;
	m = m % 60;
	printf("Temps de log TOTAL : %dh et %dm\n", h, m);
	return (0);
}
