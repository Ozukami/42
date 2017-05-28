/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 04:37:20 by apoisson          #+#    #+#             */
/*   Updated: 2017/05/21 04:37:21 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			get_nb_ant(void)
{
	char	*line;
	int		nb;

	get_next_line(0, &line);
	if (!line[0])
		ft_perror("Error: empty file");
	if (!is_number(line))
		return (0);
	nb = ft_atoi(line);
	ft_strdel(&line);
	return (nb);
}

int			get_role(char **line)
{
	int		i;

	i = 0;
	if (ft_strequ(*line, "##start"))
		i = START;
	else if (ft_strequ(*line, "##end"))
		i = END;
	else
		return (0);
	while (line[0][0] == '#')
	{
		ft_strdel(line);
		get_next_line(0, line);
		if (line[0][0] == '\0')
			ft_perror("Error: empty line");
		if (ft_strequ(*line, "##start"))
			i = START;
		else if (ft_strequ(*line, "##end"))
			i = END;
	}
	return (i);
}

void		set_index(t_lemin *lemin, char *line)
{
	char	**split;
	int		i;
	int		id_0;
	int		id_1;

	split = ft_strsplit(line, '-');
	ft_strdel(&line);
	i = -1;
	while (T_ROOM[++i])
	{
		if (ft_strequ((T_ROOM[i])->name, split[0]))
			id_0 = i;
		if (ft_strequ((T_ROOM[i])->name, split[1]))
			id_1 = i;
	}
	if (!ft_strchr(INDEX[id_0], id_1 + '0'))
	{
		INDEX[id_0] = ft_strjoinf(INDEX[id_0],
				ft_strjoinf_l(ft_itoa(id_1), "_"));
		INDEX[id_1] = ft_strjoinf(INDEX[id_1],
				ft_strjoinf_l(ft_itoa(id_0), "_"));
	}
	free_map(split);
}

void		get_pipe(t_lemin *lemin)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		if (line[0] == '#')
			ft_strdel(&line);
		else if (is_pipe(line, L_ROOM))
			set_index(lemin, line);
		else
			return (ft_strdel(&line));
	}
	ft_strdel(&line);
}

void		get_room(t_lemin *lemin)
{
	char	*line;
	int		id;
	int		role;

	id = 0;
	while (get_next_line(0, &line))
	{
		if (!line[0] || line[0] == ' ')
			ft_perror(ft_strjoin("Error: ", ((!line[0]) ? "empty line"
							: "space at the begining of the line")));
		role = get_role(&line);
		if (line[0] == '#')
			;
		else if (is_room(line))
			add_room_list(lemin, line, id++, role);
		else if (is_pipe(line, L_ROOM))
			break ;
		else
			ft_perror("Error: no pipe found");
		ft_strdel(&line);
	}
	room_list_to_tab(lemin);
	if (line)
		if (line[0])
			set_index(lemin, line);
}
