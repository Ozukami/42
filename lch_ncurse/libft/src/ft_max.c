/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 16:23:26 by lcharbon          #+#    #+#             */
/*   Updated: 2017/07/04 16:23:55 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_max(int n1, int n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}
