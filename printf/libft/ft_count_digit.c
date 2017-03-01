/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 10:48:38 by exam              #+#    #+#             */
/*   Updated: 2017/03/01 03:11:49 by qumaujea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		get_size(long value)
{
	if (value > -10 && value <= -1)
		return (2);
	if (value >= 0 && value < 10)
		return (1);
	if (value < -10)
		return (2 + get_size(-value / 10));
	return (1 + get_size(value / 10));
}
