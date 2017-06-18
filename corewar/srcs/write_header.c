/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 06:08:55 by apoisson          #+#    #+#             */
/*   Updated: 2017/06/18 01:02:22 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "sys/types.h"

void	write_prog_name(t_champ *champ)
{
	char	*name;
	int		i;

	if (!(name = ft_memalloc(ft_strlen(HEADER->prog_name))))
		ft_perror("Error: malloc failed");
	i = -1;
	while ((HEADER->prog_name)[++i])
		name[i] = (HEADER->prog_name)[i];
	write(FD, name, ft_strlen(HEADER->prog_name));
	ft_strdel(&name);
}

void	write_comment(t_champ *champ)
{
	char	*comment;
	int		i;

	if (!(comment = ft_memalloc(ft_strlen(HEADER->comment))))
		ft_perror("Error: malloc failed");
	i = -1;
	while ((HEADER->comment)[++i])
		comment[i] = (HEADER->comment)[i];
	lseek(FD, 0x8c, SEEK_SET);
	write(FD, comment, ft_strlen(HEADER->comment));
	ft_strdel(&comment);
}

void	write_prog_size(t_champ *champ)
{
	char	*prog_size;

	if (!(prog_size = ft_memalloc(4)))
		ft_perror("Error: malloc failed");
	prog_size[3] = PROG_SIZE & 0xff;
	prog_size[2] = (PROG_SIZE >> 8) & 0xff;
	prog_size[1] = (PROG_SIZE >> 16) & 0xff;
	prog_size[0] = (PROG_SIZE >> 24) & 0xff;
	lseek(FD, 0x88, SEEK_SET);
	write(FD, prog_size, 4);
	ft_strdel(&prog_size);
}

void	write_header(t_champ *champ)
{
	int		*magic;
	char	c;

	if (!(magic = ft_memalloc(sizeof(int))))
		ft_perror("Error: malloc failed");
	magic[0] = 0xf383ea00;
	write(FD, magic, 4);
	write_prog_name(champ);
	write_comment(champ);
	write_prog_size(champ);
	lseek(FD, 0x88F, SEEK_SET);
	c = 0x0;
	write(FD, &c, 1);
	free(magic);
}
