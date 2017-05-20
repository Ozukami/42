/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 05:44:09 by apoisson          #+#    #+#             */
/*   Updated: 2017/05/20 03:19:47 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tiny_printf.h"

int		main(void)
{
	tiny_printf("{red}Tests tiny_printf{white}\n");
	tiny_printf("%10.5s\n", "Bonjour salut coucou");
	while (1);
	return (0);
}
