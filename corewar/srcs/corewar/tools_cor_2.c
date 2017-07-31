/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_cor_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumaujea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 04:31:18 by qumaujea          #+#    #+#             */
/*   Updated: 2017/07/31 05:14:24 by qumaujea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			verif_file(int fd)
{
	unsigned char	magic_number[4];

	if (read(fd, magic_number, 4) < 1)
		ft_perror(strerror(errno));
	if (magic_number[0] != 0x00 || magic_number[1] != 0xea
			|| magic_number[2] != 0x83 || magic_number[3] != 0xf3)
		ft_perror("Error: bad magic number");
}
