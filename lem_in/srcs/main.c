/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumaujea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 00:18:21 by qumaujea          #+#    #+#             */
/*   Updated: 2017/04/21 23:49:33 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** A TRANSFERER DANS LA LIBFT
*/

int		tab_size(char **tab)
{
	int		len;

	len = 0;
	while (tab[len])
		len++;
	return (len);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_strdel(&(map[i]));
		i++;
	}
	free(map);
}

/*******************************************************/

void	ft_perror(char *error)
{
	perror(error);
	exit(0);
}

int			list_len(t_room_list *list)
{
	int		len;

	len = 0;
	while (list)
	{
		len++;
		list = list->next;
	}
	return (len);
}

/*
**	Check the line (only one number) to set the ant number
*/

int			is_number(char *line)
{
	int		i;

	if (!line)
		return (0);
	i = -1;
	while (line[++i])
		if (!ft_isdigit(line[i]))
			return (0);
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
		ft_perror("ERROR 1");
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
		ft_perror("ERROR 2");
	if (!is_in_list(split[0], room_list) || !is_in_list(split[1], room_list))
	{
		free_map(split);
		return (0);
	}
	free_map(split);
	return (1);
}

void		room_list_to_tab(t_lemin *lemin)
{
	int			nb_room;
	t_room_list	*current;

	current = LIST;
	nb_room = list_len(LIST);
	if (!(TAB = ft_memalloc(sizeof(t_room_list) * (nb_room + 1)))
			|| !(INDEX = ft_memalloc(sizeof(char *) * (nb_room + 1))))
		ft_perror("Error: Malloc Failed");
	while (--nb_room != -1)
		INDEX[nb_room] = ft_strdup("");
	while (current)
	{
		TAB[current->room->id] = current->room;
		current = current->next;
	}
}

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
	}
}

/*
**	Get functions
*/

int			get_nb_ant(void)
{
	char	*line;
	int		nb;

	get_next_line(0, &line);
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
			ft_perror("ERROR 3");
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
	while (TAB[++i])
	{
		if (ft_strequ((TAB[i])->name, split[0]))
			id_0 = i;
		if (ft_strequ((TAB[i])->name, split[1]))
			id_1 = i;
	}
	INDEX[id_0] = ft_strjoin(INDEX[id_0], ft_strjoin(ft_itoa(id_1), "_"));
	INDEX[id_1] = ft_strjoin(INDEX[id_1], ft_strjoin(ft_itoa(id_0), "_"));
	free_map(split);
}

void		get_pipe(t_lemin *lemin)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		if (is_pipe(line, LIST))
			set_index(lemin, line);
		else
			break ;
	}
}

void		get_room(t_lemin *lemin)
{
	char	*line;
	int		id;
	int		role;

	id = 0;
	while (get_next_line(0, &line))
	{
		if (!line)
			break ;
		role = get_role(&line);
		if (line[0] == '#')
			;
		else if (is_room(line))
			add_room_list(lemin, line, id++, role);
		else if (is_pipe(line, LIST))
			break ;
		else
			ft_perror("ERROR 4");
		ft_strdel(&line);
	}
	room_list_to_tab(lemin);
	if (line[0])
		set_index(lemin, line);
}

/*
**	INIT FUCTIONS
*/

t_room		*create_room(char *line, int id, int role)
{
	t_room		*room;
	char		**split;

	if (!(room = ft_memalloc(sizeof(t_room))))
		ft_perror("Error: Malloc Failed");
	split = ft_strsplit(line, ' ');
	room->name = ft_strdup(split[0]);
	room->id = id;
	room->role = role;
	room->links = NULL;
	room->nb_link = -1;
	room->x = ft_atoi(split[1]);
	room->y = ft_atoi(split[2]);
	printf("	> ROOM = %s (%d) %d [%d][%d]\n", room->name, room->id,
			room->role, room->x, room->y);
	return (room);
}

void		add_room_list(t_lemin *lemin, char *line, int id, int role)
{
	t_room_list	*room_list;

	if (role == START && !V_START)
		V_START++;
	else if (role == END && !V_END)
		V_END++;
	else if (role == START || role == END)
		ft_perror("ERROR");
	if (!(room_list = ft_memalloc(sizeof(t_room_list))))
		ft_perror("Error: Malloc Failed");
	room_list->room = create_room(line, id, role);
	room_list->next = LIST;
	LIST = room_list;
}

t_lemin		*init_lemin(void)
{
	t_lemin		*lemin;

	if (!(lemin = ft_memalloc(sizeof(t_lemin))))
		ft_perror("Error: Malloc Failed");
	lemin->list = NULL;
	lemin->tab = NULL;
	lemin->index = NULL;
	lemin->nb_ant = 0;
	return (lemin);
}

/*
**	Main
*/

int			main(int ac, char **av)
{
	t_lemin	*lemin;

	(void)av;
	if (ac != 1)
		ft_perror("Usage : ./lem-in");
	lemin = init_lemin();
	if (!(NB_ANT = ft_absolute(get_nb_ant())))
		ft_perror("Invalid ant number");
	printf("	> NB_ANT = %d\n", NB_ANT);
	get_room(lemin);
	get_pipe(lemin);
	update_tab(lemin);
	printf("Processing...\n");
	//process(lemin);
	//free LIST
	
	int		i = -1;
	printf("\nINDEX :\n");
	while (INDEX[++i])
		printf("[%d] %s\n", i, INDEX[i]);
	printf("\nLIST\n");
	while (LIST)
	{
		printf("%s\n", LIST->room->name);
		LIST = LIST->next;
	}
	printf("\nTAB\n");
	i = -1;
	while (TAB[++i])
		printf("[%d] %s\n", i, (TAB[i])->name);
	return (0);
}
