/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 15:02:56 by apoisson          #+#    #+#             */
/*   Updated: 2016/11/19 17:27:58 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_usage(void)
{
	ft_putendl("usage: ./fillit file");
	exit(0);
}

void	ft_error(void)
{
	ft_putendl("error");
	exit(0);
}
