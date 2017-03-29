/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 04:41:50 by apoisson          #+#    #+#             */
/*   Updated: 2017/03/30 01:27:38 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** diff = d1, d2
** coord2 = incx, incy
*/

void	my_draw_1(t_env *env, t_rect *line, t_coord *diff, t_coord *adjust)
{
	int	e;
	int	i;

	mlx_pixel_put(env->mlx, env->win, L_X1, L_Y1, L_COLOR);
	e = 2 * DIFF_1 - DIFF_2;
	i = -1;
	while (++i < DIFF_2)
	{
		if (e >= 0)
		{
			L_Y1 += ADJUST_2;
			e += 2 * (DIFF_1 - DIFF_2);
		}
		else
			e += 2 * DIFF_1;
		L_X1 += ADJUST_1;
		mlx_pixel_put(env->mlx, env->win, L_X1, L_Y1, L_COLOR);
	}
}

void	my_draw_2(t_env *env, t_rect *line, t_coord *diff, t_coord *adjust)
{
	int	e;
	int	i;

	mlx_pixel_put(env->mlx, env->win, L_X1, L_Y1, L_COLOR);
	e = 2 * DIFF_1 - DIFF_2;
	i = -1;
	while (++i < DIFF_2)
	{
		if (e >= 0)
		{
			L_Y1 += ADJUST_2;
			e += 2 * (DIFF_1 - DIFF_2);
		}
		else
			e += 2 * DIFF_1;
		L_X1 += ADJUST_1;
		mlx_pixel_put(env->mlx, env->win, L_Y1, L_X1, L_COLOR);
	}
}

void	my_draw_line(t_env *env, t_rect *line)
{
	t_coord	*diff;
	t_coord	*adjust;

	diff = ft_new_coord(L_X2 - L_X1, L_Y2 - L_Y1);
	adjust = ft_new_coord(((L_X2 < L_X1) ? -1 : 1),
			((L_Y2 < L_Y1) ? -1 : 1));
	DIFF_1 = ft_absolute(DIFF_1);
	DIFF_2 = ft_absolute(DIFF_2);
	ft_set_coord(adjust, ((DIFF_1 > DIFF_2) ? ADJUST_1 : ADJUST_2),
			((DIFF_1 > DIFF_2) ? ADJUST_2 : ADJUST_1));
	if (DIFF_1 > DIFF_2)
	{
		ft_set_coord(diff, DIFF_2, DIFF_1);
		ft_set_coord(line->coord1, L_Y1, L_X1);
		my_draw_2(env, line, diff, adjust);
	}
	else
		my_draw_1(env, line, diff, adjust);
	free(diff);
	free(adjust);
	ft_free_rect(line);
}

void	ft_draw_line(t_env *env, int x1, int y1, int x2, int y2, int color)
{
	int dx, dy, i, e;
	int incx, incy;

	dx = ft_absolute(x2 - x1);
	dy = ft_absolute(y2 - y1);
	incx = (x2 < x1) ? -1 : 1;
	incy = (y2 < y1) ? -1 : 1;
	if (dx > dy)
	{
		mlx_pixel_put(env->mlx, env->win, x1, y1, color);
		e = 2 * dy - dx;
		for (i = 0; i < dx; i++)
		{
			if (e >= 0)
			{
				y1 += incy;
				e += 2 * (dy -dx);
			}
			else
				e += 2 * dy;
			x1 += incx;
			mlx_pixel_put(env->mlx, env->win, x1, y1, color);
		}
	}
	else
	{
		mlx_pixel_put(env->mlx, env->win, x1, y1, color);
		e = 2*dx - dy;
		for (i = 0; i < dy; i++)
		{
			if (e >= 0)
			{
				x1 += incx;
				e += 2 * (dx - dy);
			}
			else
				e += 2 * dx;
			y1 += incy;
			mlx_pixel_put(env->mlx, env->win, x1, y1, color);
		}
	}
}
