/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 02:40:25 by apoisson          #+#    #+#             */
/*   Updated: 2017/02/07 04:15:04 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_info	*ft_new_info(char p)
{
	t_info	*info;

	info = ft_memalloc(sizeof(t_info));
	info->player = p;
	info->map = NULL;
	info->x_map = 0;
	info->y_map = 0;
	info->piece = NULL;
	info->x_piece = 0;
	info->y_piece = 0;
	return (info);
}
