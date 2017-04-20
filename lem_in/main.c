/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumaujea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 00:18:21 by qumaujea          #+#    #+#             */
/*   Updated: 2017/04/20 06:28:14 by qumaujea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_perror(char *error)
{
	perror(error);
	exit(0);
}

/*
**	Check the line (only one number) to set the ant number
*/

int			ant_check(char *line)
{
	int		i;

	i = -1;
	while (line[++i])
		if (!ft_isdigit(line[i]))
			return (0);
	return (1);
}

int			is_room(char *line, t_room *room)
{
	int		i;
	char	**split;

	i = -1;
	split = ft_strsplit(&line, ' ');
	if (split_len(split) == 1)
		return (0);
	if (split[3] || (!ft_isdigit(split[2])
				|| !ft_isdigit(split[1]))
			|| (ft_strchr(split[0], '-')) || split[0][0] == 'L'
			|| split[0][0] == '#')
		ft_perror("ERROR");
	free_map(split);
	return (1);
}

/*
**	Get functions
*/

int			get_nb_ant(void)
{
	char	*line;
	int		nb;

	get_next_line(0, &line);
	if (!ant_check)
		return (0);
	nb = ft_atoi(line);
	ft_strdel(&line);
	return (nb);
}

char		*get_room_name(char *line)
{
	int		i;
	char	*room_name;

	room_name = NULL;
	i = -1;
	while (line[++i] && line[i] != ' ')
		room_name = ft_straddchar(line[i]);
	return (room_name);
}

int			get_room_y(char *line)
{
	char	**split;
	int		value;

	split = ft_strsplit(&line);
	value = ft_atoi(split[2]);
	free_map(split);
	return (value);
}

int			get_room_x(char *line)
{
	char	**split;
	int		value;

	split = ft_strsplit(&line);
	value = ft_atoi(split[1]);
	free_map(split);
	return (value);
}

void		get_data(void)
{
	char	*line;
	t_room	*room;

	while (get_next_line(0, &line))
	{
		if (is_room(line))
			room = create_room(get_room_name(line), get_room_x(line),
					get_room_y(line), id++);

	}
}

/*
**	INIT FUCTIONS
*/

t_room		create_room(char *name, int x, int y, int id)
{
	t_room		*room;

	new->name = name;
	new->id = id;
	new->role = 0;
	new->links = 0;
	new->nb_link = -1;
	new->x = x;
	new->y = y;
	return (room);
}

t_lemin		init_lemin(void)
{
	t_lemin		*lemin;

	if (!(lemin = ft_memalloc(sizeof(t_lemin))))
		ft_perror();
	lemin->tab = 0;
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

	if (ac != 1)
		ft_perror("Usage : ./lem-in");
	lemin = init_lemin();
	if ((NB_ANT = get_nb_ant()) <= 0)
		ft_perror("Invalid ant number");
	get_data();
	return (0);
}
