/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 04:41:50 by apoisson          #+#    #+#             */
/*   Updated: 2017/03/29 03:33:28 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** diff = d1, d2
** coord2 = incx, incy
*/

void	tmp_name(t_env *env, t_rect *line, t_coord *diff, t_coord *adjust)
{
	int	e;
	int	i;

	mlx_pixel_put(env->mlx, env->win, L_C1_X, L_C1_Y, color);
	e = 2 * DIFF_1 - DIFF_2;
	i = -1;
	while (++i < DIFF_2)
	{
		if (e >= 0)
		{
			L_C1_Y += ADJUST_2;
			e += 2 * (DIFF_1 -DIFF_2);
		}
		else
			e += 2 * DIFF_1;
		L_C1_X += ADJUST_1;
		mlx_pixel_put(env->mlx, env->win, L_C1_X, L_C1_Y, color);
	}
}

void	ft_draw_line(t_env *env, t_rect *line)
{
	t_coord	*diff;
	t_coord	*adjust;

	DIFF_1 = x2 - x1;
	DIFF_2 = y2 - y1;
	if (DIFF_1 < 0)
		DIFF_1 = -DIFF_1;
	if (DIFF_2 < 0)
		DIFF_2 = -DIFF_2;
	if (L_C1_X < L_C2_X && L_C1_Y < L_C2_Y)
	else if (L_C1_X < L_C2_X && L_C2_Y < L_C1_Y)
	else if (L_C2_X < L_C1_X && L_C1_Y < L_C2_Y)
	else
	tmp_name(env, line, diff, adjust);
}

void	ft_draw_line(t_env *env, int x1, int y1, int x2, int y2, int color)
{
	int dx, dy, i, e;
	int incx, incy, inc1, inc2;
	int x,y;

	dx = x2 - x1;
	dy = y2 - y1;
	if(dx < 0)
		dx = -dx;
	if(dy < 0)
		dy = -dy;
	incx = 1;
	if(x2 < x1)
		incx = -1;
	incy = 1;
	if(y2 < y1)
		incy = -1;
	x=x1;
	y=y1;
	if(dx > dy)
	{
		mlx_pixel_put(env->mlx, env->win, x, y, color);
		e = 2*dy - dx;
		inc1 = 2*( dy -dx);
		inc2 = 2*dy;
		for(i = 0; i < dx; i++)
		{
			if(e >= 0)
			{
				y += incy;
				e += inc1;
			}
			else
				e += inc2;
			x += incx;
			mlx_pixel_put(env->mlx, env->win, x, y, color);
		}
	}
	else
	{
		mlx_pixel_put(env->mlx, env->win, x, y, color);
		e = 2*dx - dy;
		inc1 = 2*( dx - dy);
		inc2 = 2*dx;
		for(i = 0; i < dy; i++)
		{
			if(e >= 0)
			{
				x += incx;
				e += inc1;
			}
			else
				e += inc2;
			y += incy;
			mlx_pixel_put(env->mlx, env->win, x, y, color);
		}
	}
}
