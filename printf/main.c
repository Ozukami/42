/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 04:05:02 by apoisson          #+#    #+#             */
/*   Updated: 2017/03/12 00:56:07 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <fcntl.h>
#include <locale.h>

int		main(int ac, char **av)
{
	int		fd;

	setlocale(LC_ALL, "");
	if (ac < 2)
		return (0);
	fd = open(av[1], O_RDWR);
	ft_dprintf(fd, "Salut %s de %d!\n", "les amis", 42);
	close(fd);
	return (0);
}
