/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 04:12:39 by apoisson          #+#    #+#             */
/*   Updated: 2017/04/17 04:12:42 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			tab_size(char **tab)
{
	int		len;

	len = 0;
	while (tab[len])
		len++;
	return (len);
}

/*
** Fais le cafe, et parfois des crepes
*/

void		moulisplit(t_env *env)
{
	char	**split;
	int		i;
	int		j;
	int		k;

	i = -1;
	while (++i < WIN_Y)
	{
		split = ft_strsplit(CONTENT[i], ' ');
		WIN_X = tab_size(split);
		k = WIN_X - 1;
		if (!(MAP[i] = ft_memalloc(sizeof(int) * WIN_X)))
			exit_error("Malloc failed");
		j = -1;
		while (split[++j])
		{
			MAP[i][k--] = atoi(split[j]);
			MAX_Z = ft_max(MAX_Z, atoi(split[j]));
			MIN_Z = ft_min(MIN_Z, atoi(split[j]));
		}
		free_map(split);
	}
	free_map(CONTENT);
}

int			get_color(t_env *env, t_coord *z)
{
	int		color;

	color = 0x00FF00FF;
	if (!DIFF_Z)
	{
		if (z->x == MIN_Z)
			color = 0x0021D04A;
		else if (z->x == MAX_Z)
			color = 0x00E92525;
		else
			color = 0x00007104 + (z->x * 250);
	}
	else
		color = 0x00007104 + (z->y * 450) + (z->x * 450);
	return (color);
}

/*
** Calcule les coordonnees dans le nouveau plan puis trace
** rect = ((x,y) (x2,y2) color)
** altitude = (z,z2)
*/

void		draw_iso(t_env *env, t_rect *line, t_coord *z)
{
	int iso_x1;
	int iso_y1;
	int iso_x2;
	int iso_y2;

	iso_x1 = L_X1 * (5 + Z) + X;
	iso_x1 -= L_Y1 * (5 + Z) + Y;
	iso_y1 = ((L_X1 * (5 + Z) + X) + (L_Y1 * (5 + Z) + Y)) / 1.5;
	iso_x2 = L_X2 * (5 + Z) + X;
	iso_x2 -= L_Y2 * (5 + Z) + Y;
	iso_y2 = ((L_X2 * (5 + Z) + X) + (L_Y2 * (5 + Z) + Y)) / 1.5;
	ft_draw_line(env, NR(NC((iso_x1 + (WIN_X * WIN_SIZE / 2)),
							(iso_y1 + (WIN_Y * WIN_SIZE / 9) - z->x)),
					NC((iso_x2 + (WIN_X * WIN_SIZE / 2)),
							(iso_y2 + (WIN_Y * WIN_SIZE / 9) - z->y)),
					get_color(env, z)));
	ft_free_rect(line);
	free(z);
}

/*
** Call the draw_iso function for every points of the map
*/

void		process(t_env *env)
{
	int		i;
	int		j;

	i = 0;
	while (i < WIN_Y)
	{
		j = 0;
		while (j < WIN_X)
		{
			if (i != WIN_Y - 1)
				draw_iso(env, NR(NC(i, j), NC(i + 1, j), 0x00007104),
						NC(MAP[i][j], MAP[i + 1][j]));
			if (j != WIN_X - 1)
				draw_iso(env, NR(NC(i, j), NC(i, j + 1), 0x00007104),
						NC(MAP[i][j], MAP[i][j + 1]));
			j++;
		}
		i++;
	}
}
