/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumaujea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 23:04:32 by qumaujea          #+#    #+#             */
/*   Updated: 2017/02/23 02:02:31 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_rework_location(int *x, int *y, int *x_end, int *y_end);

void	bres(t_env *env, int x1, int y1, int x2, int y2, int color)
{
	int dx, dy, i, e;
	int incx, incy, inc1, inc2;
	int x,y;

	dx = x2 - x1;
	dy = y2 - y1;

	if(dx < 0) dx = -dx;
	if(dy < 0) dy = -dy;
	incx = 1;
	if(x2 < x1) incx = -1;
	incy = 1;
	if(y2 < y1) incy = -1;
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
			else e += inc2;
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
			else e += inc2;
			y += incy;
			mlx_pixel_put(env->mlx, env->win, x, y, color);
		}
	}
}


void		ft_draw_shit_x(t_env *env, int x, int y, int x2, int y2, int color)
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
		mlx_pixel_put(env->mlx, env->win, x, y, color);
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

void		ft_draw_shit2_y(t_env *env, int x, int y, int x2, int y2, int color)
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
		mlx_pixel_put(env->mlx, env->win, x, y, color);
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

void		ft_draw_shit_y(t_env *env, int x, int y, int x2, int y2, int color)
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
	while (y > y2)
	{
		mlx_pixel_put(env->mlx, env->win, x, y, color);
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
