/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequf_l.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 10:02:58 by apoisson          #+#    #+#             */
/*   Updated: 2017/06/09 10:03:00 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequf_l(char *s1, char const *s2)
{
	int		ret;

	if (!s1 || !s2)
		return (0);
	ret = ((ft_strcmp(s1, s2)) ? 0 : 1);
	ft_strdel(&s1);
	return (ret);
}