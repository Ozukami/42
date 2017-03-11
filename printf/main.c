/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 04:05:02 by apoisson          #+#    #+#             */
/*   Updated: 2017/03/11 07:10:11 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>

int		main(void)
{
	setlocale(LC_ALL, "");
	ft_printf("\033[5mIl faut {cyan}Bonjour{white} test\n");
	printf("%zd\n", LLONG_MIN);
	ft_printf("%zd\n", LLONG_MIN);
	ft_printf("%%   %", "test");
	printf("\n%%   %\n", "test");
	return (0);
}
