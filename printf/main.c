/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 04:05:02 by apoisson          #+#    #+#             */
/*   Updated: 2017/03/02 00:54:50 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	printf("{%S}\n\n", L"A");

	printf("{%c}\n", 'A');
	printf("{%s}\n\n", "A");
	printf("{%.7c}\n", 'A');
	printf("{%5.3s}\n\n", "Ajul");
	printf("{%.3c}\n", 'A');
	printf("{%.3s}\n\n", "A");

	ft_printf("Bad delimiter test : {%5k}\n");

	ft_printf("Bonjour [%s], moi j'ai [%d] ans !\n",
			"Quentin", 23);
	ft_printf("Bonjour [%10s], moi j'ai [%4d] ans !\n",
			"Quentin", 23);
	return (0);
}
