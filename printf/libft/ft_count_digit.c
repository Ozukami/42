/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 03:15:15 by apoisson          #+#    #+#             */
/*   Updated: 2017/03/01 03:15:36 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_count_digit(long value)
{
	if (value > -10 && value <= -1)
		return (2);
	if (value >= 0 && value < 10)
		return (1);
	if (value < -10)
		return (2 + get_size(-value / 10));
	return (1 + get_size(value / 10));
}
