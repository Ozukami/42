/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 04:05:02 by apoisson          #+#    #+#             */
/*   Updated: 2017/03/02 02:59:57 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	printf("{%15.2d}\n\n", -158);
	printf("{%+-15.2d}\n\n", 158);
	printf("{%+-15.8d}\n\n", 158);
	printf("{%-15.8d}\n\n", 158);
	printf("{%-#15.8x}\n\n", 158);

	printf("{% d}\n", -158);
	ft_printf("{% d}\n\n", -158);

	printf("{% 5d}\n", -158);
	ft_printf("{% 5d}\n\n", -158);

	ft_printf("Bad delimiter test : {%5k}\n");

	ft_printf("Bonjour [%s], moi j'ai [%d] ans !\n",
			"Quentin", 23);
	ft_printf("Bonjour [%10s], moi j'ai [%04d] ans !\n",
			"Quentin", 23);
	return (0);
}
