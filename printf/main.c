/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 04:05:02 by apoisson          #+#    #+#             */
/*   Updated: 2017/03/12 00:27:15 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>

int		main(void)
{
	setlocale(LC_ALL, "");
	char	*s = malloc(100);
	ft_printf("{%*c}", -15, 0);
		printf("\n");
	printf("{%*c}", -15, 0);
		printf("\n");
	int r = sprintf(s, "{%*c}", -15, 0);
		printf("%s|	> %d\n", s, r);
	r = ft_sprintf(s, "{%*c}", -15, 0);
		printf("%s|	> %d\n", s, r);
	return (0);
}
