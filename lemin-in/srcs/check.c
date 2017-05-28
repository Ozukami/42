/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 04:03:55 by apoisson          #+#    #+#             */
/*   Updated: 2017/05/21 04:08:30 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
**	Check if the line contains only one number
*/

int			is_number(char *line)
{
	int		i;
	long	verif;

	if (!line)
		return (0);
	verif = ft_atol(line);
	if (verif >= INT_MAX || verif < 0)
		ft_perror(ft_strjoin("Error: invalid number ", line));
	i = -1;
	while (line[++i])
		if (!ft_isdigit(line[i]))
			return (0);
	if (i > 10)
		ft_perror(ft_strjoin("Error: invalid number", line));
	return (1);
}

int			is_room(char *line)
{
	char	**split;

	split = ft_strsplit(line, ' ');
	if (tab_size(split) == 1)
	{
		free_map(split);
		return (0);
	}
	if (tab_size(split) > 3 || (!is_number(split[2]) || !is_number(split[1]))
			|| (ft_strchr(split[0], '-')) || split[0][0] == 'L'
			|| split[0][0] == '#')
	{
		free_map(split);
		ft_perror(ft_strjoin("Error: ", line));
	}
	free_map(split);
	return (1);
}

int			is_in_list(char *name, t_room_list *list)
{
	while (list)
	{
		if (ft_strequ(name, list->room->name))
			return (1);
		list = list->next;
	}
	return (0);
}

int			is_pipe(char *line, t_room_list *room_list)
{
	char		**split;

	split = ft_strsplit(line, '-');
	if (tab_size(split) != 2)
	{
		free_map(split);
		return (0);
	}
	if (!room_list)
		ft_perror(ft_strjoin("Error: ", line));
	if (!is_in_list(split[0], room_list) || !is_in_list(split[1], room_list))
	{
		free_map(split);
		return (0);
	}
	free_map(split);
	return (1);
}

/*
** Check if the path of the current way is compatible with pathes
** already selected
*/

int			is_overcross(char *comp, char *path)
{
	char	**split;
	char	*to_split;
	char	*to_comp;
	int		i;

	to_split = ft_strsub(path, to_tronc(path, 1),
			ft_strlen(path) - to_tronc(path, 0));
	split = ft_strsplit(to_split, '_');
	i = -1;
	while (split[++i])
	{
		to_comp = ft_strjoinf_r("_", ft_strjoin(split[i], "_"));
		if (ft_strstr(comp, to_comp))
		{
			free_map(split);
			ft_strdel(&to_comp);
			ft_strdel(&to_split);
			return (0);
		}
		ft_strdel(&to_comp);
	}
	free_map(split);
	ft_strdel(&to_split);
	return (1);
}
