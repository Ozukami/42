/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 04:41:50 by apoisson          #+#    #+#             */
/*   Updated: 2017/04/14 03:08:24 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_1(t_env *env, t_rect *line, t_coord *diff, t_coord *adjust)
{
	int	e;
	int	i;

	mlx_pixel_put(env->mlx, env->win, L_X1, L_Y1, L_COLOR);
	e = 2 * DIFF_2 - DIFF_1;
	i = -1;
	while (++i < DIFF_1)
	{
		if (e >= 0)
		{
			L_Y1 += ADJUST_2;
			e += 2 * (DIFF_2 - DIFF_1);
		}
		else
			e += 2 * DIFF_2;
		L_X1 += ADJUST_1;
		if (L_X1 < -100 || L_Y1 < -100
				|| L_X1 > WIN_X * WIN_SIZE + 100
				|| L_Y1 > WIN_Y * WIN_SIZE + 100)
			return ;
		mlx_pixel_put(env->mlx, env->win, L_X1, L_Y1, L_COLOR);
	}
}

void	ft_draw_2(t_env *env, t_rect *line, t_coord *diff, t_coord *adjust)
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
			L_X1 += ADJUST_1;
			e += 2 * (DIFF_1 - DIFF_2);
		}
		else
			e += 2 * DIFF_1;
		L_Y1 += ADJUST_2;
		if (L_X1 < -100 || L_Y1 < -100
				|| L_X1 > WIN_X * WIN_SIZE + 100
				|| L_Y1 > WIN_Y * WIN_SIZE + 100)
			return ;
		mlx_pixel_put(env->mlx, env->win, L_X1, L_Y1, L_COLOR);
	}
}

void	ft_draw_line(t_env *env, t_rect *line)
{
	t_coord	*diff;
	t_coord	*adjust;

	diff = ft_new_coord(ft_absolute(L_X2 - L_X1), ft_absolute(L_Y2 - L_Y1));
	adjust = ft_new_coord(((L_X2 < L_X1) ? -1 : 1),
			((L_Y2 < L_Y1) ? -1 : 1));
	if (DIFF_1 > DIFF_2)
		ft_draw_1(env, line, diff, adjust);
	else
		ft_draw_2(env, line, diff, adjust);
	free(diff);
	free(adjust);
	ft_free_rect(line);
}
