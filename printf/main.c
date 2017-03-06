/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 04:05:02 by apoisson          #+#    #+#             */
/*   Updated: 2017/03/06 23:45:18 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>

int		main(void)
{
	setlocale(LC_ALL, "");

	int		r;
	char	*s;
	char	*s2;

	r = 0;
	s = malloc(100);
	s2 = malloc(100);

	ft_printf("%s\n", "");
	printf("%s\n", "");

	/*
	r = printf("|%-05%|");
	printf("\nr = %d\n", r);
	r = ft_printf("|%-05%|");
	printf("\nr = %d\n\n", r);
	*/

	return (0);
}
