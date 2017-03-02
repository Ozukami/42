/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumaujea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 01:26:49 by qumaujea          #+#    #+#             */
/*   Updated: 2017/03/02 01:28:59 by qumaujea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strzero(size_t size)
{
	char	*str;

	if (!(str = malloc(size + 1)))
		return (NULL);
	ft_fill_zero(str, size + 1);	
	return (str);
}
