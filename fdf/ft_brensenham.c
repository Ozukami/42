/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumaujea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 23:04:32 by qumaujea          #+#    #+#             */
/*   Updated: 2017/02/12 13:34:09 by qumaujea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_draw_shit2_x(t_env *env, int x, int y, int x2, int y2)
{
	double	error_value;
	double	error_inc;
	double	dx;
	double	dy;
	int		tmp;

	tmp = 0;
	error_value = 0;
	if (x < x2)
		dx = (double)x2 - (double)x;
	if (x > x2)
		dx = (double)x - (double)x2;
	if (y < y2)
		dy = (double)y2 - (double)y;
	if (y > y2)
		dy = (double)y - (double)y2;
	if (dx > dy)	
		error_inc = dy / dx;
	else
		error_inc = dx / dy;
	while (x < x2)
	{
		mlx_pixel_put(env->mlx, env->win, x, y, 0x00FF0000);
		error_value = error_value + error_inc;
		if (error_value >= 0.5)
		{
			error_value -= 1.0;
			if (y > y2)
				y--;
			else
				y++;
		}
		x++;
	}
}

void		ft_draw_shit_x(t_env *env, int x, int y, int x2, int y2)
{
	double	error_value;
	double	error_inc;
	double	dx;
	double	dy;
	int		tmp;

	tmp = 0;
	error_value = 0;
	if (x < x2)
		dx = (double)x2 - (double)x;
	if (x > x2)
		dx = (double)x - (double)x2;
	if (y < y2)
		dy = (double)y2 - (double)y;
	if (y > y2)
		dy = (double)y - (double)y2;
	if (dx > dy)	
		error_inc = dy / dx;
	else
		error_inc = dx / dy;
	while (x > x2)
	{
		mlx_pixel_put(env->mlx, env->win, x, y, 0x00FF0000);
		error_value = error_value + error_inc;
		if (error_value >= 0.5)
		{
			error_value -= 1.0;
			if (y > y2)
				y--;
			else
				y++;
		}
		x--;
	}
}

void		ft_draw_shit2_y(t_env *env, int x, int y, int x2, int y2)
{
	double	error_value;
	double	error_inc;
	double	dx;
	double	dy;
	int		tmp;

	tmp = 0;
	error_value = 0;
	if (x < x2)
		dx = (double)x2 - (double)x;
	if (x > x2)
		dx = (double)x - (double)x2;
	if (y < y2)
		dy = (double)y2 - (double)y;
	if (y > y2)
		dy = (double)y - (double)y2;
	if (dx > dy)	
		error_inc = dy / dx;
	else
		error_inc = dx / dy;
	while (y < y2)
	{
		mlx_pixel_put(env->mlx, env->win, x, y, 0x00FF0000);
		error_value = error_value + error_inc;
		if (error_value >= 0.5)
		{
			error_value -= 1.0;
			if (x > x2)
				x--;
			else
				x++;
		}
		y++;
	}
}

void		ft_draw_shit_y(t_env *env, int x, int y, int x2, int y2)
{
	double	error_value;
	double	error_inc;
	double	dx;
	double	dy;
	int		tmp;

	tmp = 0;
	error_value = 0;
	if (x < x2)
		dx = (double)x2 - (double)x;
	if (x > x2)
		dx = (double)x - (double)x2;
	if (y < y2)
		dy = (double)y2 - (double)y;
	if (y > y2)
		dy = (double)y - (double)y2;
	if (dx > dy)	
		error_inc = dx / dy;
	else
		error_inc = dy / dx;
	while (y > y2)
	{
		mlx_pixel_put(env->mlx, env->win, x, y, 0x00FF0000);
		error_value = error_value + error_inc;
		if (error_value >= 0.5)
		{
			error_value -= 1.0;
			if (x > x2)
				x--;
			else
				x++;
		}
		y--;
	}
}
