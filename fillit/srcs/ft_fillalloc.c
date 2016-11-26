/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillalloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumaujea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 13:05:46 by qumaujea          #+#    #+#             */
/*   Updated: 2016/11/23 13:57:02 by qumaujea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_fillalloc(size_t size)
{
	char	*rep;

	rep = malloc(size);
	if (rep)
	{
		ft_bpoint(rep, size);
		return (rep);
	}
	return (NULL);
}
