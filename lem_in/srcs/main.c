/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumaujea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 00:18:21 by qumaujea          #+#    #+#             */
/*   Updated: 2017/05/04 06:19:58 by qumaujea         ###   ########.fr       */
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

	if (!V_START || !V_END)
		ft_perror("ERROR");
	current = L_ROOM;
	nb_room = list_len(L_ROOM);
	if (!(T_ROOM = ft_memalloc(sizeof(t_room_list) * (nb_room + 1)))
			|| !(INDEX = ft_memalloc(sizeof(char *) * (nb_room + 1)))
			|| !(ID_NAME = ft_memalloc(sizeof(char *) * (nb_room + 1))))
		ft_perror("Error: Malloc Failed");
	while (--nb_room != -1)
		INDEX[nb_room] = ft_strdup("");
	while (current)
	{
		T_ROOM[current->room->id] = current->room;
		ID_NAME[current->room->id] = ft_strdup(current->room->name);
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
		free_map(split);
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
	while (T_ROOM[++i])
	{
		if (ft_strequ((T_ROOM[i])->name, split[0]))
			id_0 = i;
		if (ft_strequ((T_ROOM[i])->name, split[1]))
			id_1 = i;
	}
	if (!ft_strchr(INDEX[id_0], id_1 + '0'))
	{
		INDEX[id_0] = ft_strjoinf(INDEX[id_0], ft_strjoinf(ft_itoa(id_1),
					ft_strdup("_")));
		INDEX[id_1] = ft_strjoinf(INDEX[id_1], ft_strjoinf(ft_itoa(id_0),
					ft_strdup("_")));
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
		{
			ft_strdel(&line);
			break ;
		}
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
		else if (is_pipe(line, L_ROOM))
			break ;
		else
			ft_perror("ERROR 4");
		ft_strdel(&line);
	}
	room_list_to_tab(lemin);
	if (line[0])
		set_index(lemin, line);
}

void		display_data(t_lemin *lemin)
{
	int		i;
	int		j;
	char	**split;

	printf("%d\n", NB_ANT);
	i = -1;
	while (T_ROOM[++i])
	{
		if (T_ROLE(i) == START || T_ROLE(i) == END)
			printf("%s\n", ((T_ROLE(i) == START) ? "##start" : "##end"));
		printf("%s %d %d\n", T_NAME(i), T_X(i), T_Y(i));
	}
	i = -1;
	while (INDEX[++i])
	{
		split = ft_strsplit(INDEX[i], '_');
		j = -1;
		while (split[++j])
			if (ft_atoi(split[j]) > i)
				printf("%s-%s\n", ID_NAME[i], ID_NAME[ft_atoi(split[j])]);
		free_map(split);
	}
}

/*
**	INIT FUCTIONS
*/

int			verif_room(t_lemin *lemin, char *name, int x, int y)
{
	t_room_list	*current;

	current = L_ROOM;
	while (current)
	{
		if (ft_strequ(name, current->room->name))
			return (0);
		if (x == current->room->x && y == current->room->y)
			return (0);
		current = current->next;
	}
	return (1);
}

t_room		*create_room(t_lemin *lemin, char *line, int id, int role)
{
	t_room		*room;
	char		**split;

	if (!(room = ft_memalloc(sizeof(t_room))))
		ft_perror("Error: Malloc Failed");
	split = ft_strsplit(line, ' ');
	if (!verif_room(lemin, split[0], ft_atoi(split[1]), ft_atoi(split[2])))
		ft_perror("ERROR");
	room->name = ft_strdup(split[0]);
	room->id = id;
	room->role = role;
	room->links = NULL;
	room->nb_link = -1;
	room->x = ft_atoi(split[1]);
	room->y = ft_atoi(split[2]);
	room->empty = TRUE;
	room->visited = FALSE;
	free_map(split);
	return (room);
}

void		add_room_list(t_lemin *lemin, char *line, int id, int role)
{
	t_room_list	*room_list;

	if (role == START && !V_START)
	{
		V_START++;
		ID_START = id;
	}
	else if (role == END && !V_END)
	{
		V_END++;
		ID_END = id;
	}
	else if (role == START || role == END)
		ft_perror("ERROR");
	if (!(room_list = ft_memalloc(sizeof(t_room_list))))
		ft_perror("Error: Malloc Failed");
	room_list->room = create_room(lemin, line, id, role);
	room_list->next = L_ROOM;
	L_ROOM = room_list;
}

void		insert_way(t_way *way, t_way *next)
{
	way->next = next->next;
	next->next = way;
}

void		add_sort(t_lemin *lemin, t_way *way)
{
	t_way	*current;

	current = L_WAYS;
	while (current)
	{
		if (current->weight < way->weight)
		{
			if (!(current->next))
			{
				way->next = NULL;
				current->next = way;
				break ;
			}
			else if (current->next->weight > way->weight)
				return (insert_way(way, current));
			current = current->next;
		}
		else
			return (insert_way(way, current));
	}
}

void		add_new_way(t_lemin *lemin, char *path, int weight)
{
	t_way	*way;

	NB_WAY++;
	if (!(way = ft_memalloc(sizeof(t_way))))
		ft_perror("Error: Malloc Failed");
	way->path = ft_strdup(path);
	way->weight = weight;
	if (!L_WAYS)
	{
		way->next = L_WAYS;
		L_WAYS = way;
		return ;
	}
	else
		add_sort(lemin, way);
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
	INDEX = NULL;
	ID_NAME = NULL;
	NB_ANT = 0;
	NB_WAY = 0;
	MAX_WAY = 0;
	ID_START = 0;
	ID_END = 0;
	CURR_WEIGHT = 0;
	CURR_PATH = ft_memalloc(1);
	return (lemin);
}

/*
**	Main
*/

void		get_ways(t_lemin *lemin, t_room *current)
{
	int		i;

	if (current->visited == TRUE)
		return ;
	current->visited = TRUE;
	CURR_PATH = ft_strjoinf(CURR_PATH, ft_strjoinf(ft_itoa(current->id),
				ft_strdup("_")));
	CURR_WEIGHT++;
	if (current->role == END)
	{
		CURR_WEIGHT--;
		add_new_way(lemin, CURR_PATH, CURR_WEIGHT);
		current->visited = FALSE;
		CURR_PATH = ft_strsubf(CURR_PATH, 0, (int)ft_strlen(CURR_PATH)
				- ft_count_digit(current->id) - 1);
		return ;
	}
	i = -1;
	while (++i < current->nb_link)
		get_ways(lemin, T_ROOM[current->links[i]]);
	current->visited = FALSE;
	CURR_PATH = ft_strsubf(CURR_PATH, 0, (int)ft_strlen(CURR_PATH)
			- ft_count_digit(current->id) - 1);
	CURR_WEIGHT--;
}

int			test(char *comp, char *path)
{
	char	**split;
	int		i;

	split = ft_strsplit(ft_strsub(path, 2, ft_strlen(path) - 4), '_');
	i = -1;
	while (split[++i])
		if (ft_strstr(comp, split[i]))
			return (0);
	return (1);
}

int			backtrack_ways(t_lemin *lemin, char *comp, int n)
{
	int		i;

	if (n == MAX_WAY)
		return (1);
	i = -1;
	while (T_WAYS[++i])
	{
		if (test(comp, (T_WAYS[i])->path))
		{
			S_WAYS[n] = T_WAYS[i];
			if (backtrack_ways(lemin, ft_strjoin(comp,
							(S_WAYS[n])->path), n + 1))
				return (1);
			S_WAYS[n] = NULL;
		}
	}
	return (0);
}

void		select_ways(t_lemin *lemin)
{

	while (MAX_WAY > 0)
	{
		if (!backtrack_ways(lemin, "", 0))
			MAX_WAY--;
		else
			break ;
	}
}

void		l_to_t_ways(t_lemin *lemin)
{
	int		i;

	t_way	*current;

	current = L_WAYS;
	i = 0;
	while (current)
	{
		T_WAYS[i++] = current;
		current = current->next;
	}
}

void		process(t_lemin *lemin)
{
	int		i = -1;

	MAX_WAY = ft_min(T_NBLINK(ID_START), T_NBLINK(ID_END));
	get_ways(lemin, T_ROOM[ID_START]);
	if (!(S_WAYS = ft_memalloc(sizeof(t_way) * (MAX_WAY + 1))) ||
			!(T_WAYS = ft_memalloc(sizeof(t_way) * (NB_WAY + 1))))
		ft_perror("Error: Malloc Failed");
	l_to_t_ways(lemin);
	while (T_WAYS[++i])
		printf("{%p} [%s] (%d) |-> {%p}\n", T_WAYS[i], (T_WAYS[i])->path,
				(T_WAYS[i])->weight, (T_WAYS[i])->next);
	printf("%d\n", NB_WAY);
	select_ways(lemin);
	//ant_per_way(lemin);
	//send_ant(lemin);
}

int			main(int ac, char **av)
{
	t_lemin	*lemin;

	(void)av;
	if (ac != 1)
		ft_perror("Usage : ./lem-in");
	lemin = init_lemin();
	if (!(NB_ANT = ft_absolute(get_nb_ant())))
		ft_perror("Invalid ant number");
	get_room(lemin);
	get_pipe(lemin);
	update_tab(lemin);
	//display_data(lemin);
	process(lemin);
	//free L_ROOM
	return (0);
}
