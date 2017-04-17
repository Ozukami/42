/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 00:57:08 by apoisson          #+#    #+#             */
/*   Updated: 2017/04/17 04:53:40 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tiny_printf.h"

t_color		*ft_new_color(t_color *color, char *name, char *code)
{
	t_color	*new;

	if (!(new = ft_memalloc(sizeof(t_color))))
		exit(0);
	new->name = name;
	new->code = code;
	new->next = color;
	return (new);
}

t_color		*ft_init_color(void)
{
	t_color	*color;

	color = ft_new_color(NULL, "white", "\033[37m");
	color = ft_new_color(color, "cyan", "\033[36m");
	color = ft_new_color(color, "purple", "\033[35m");
	color = ft_new_color(color, "blue", "\033[34m");
	color = ft_new_color(color, "yellow", "\033[33m");
	color = ft_new_color(color, "green", "\033[32m");
	color = ft_new_color(color, "red", "\033[31m");
	color = ft_new_color(color, "black", "\033[30m");
	return (color);
}
