/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ncurses.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 08:09:50 by apoisson          #+#    #+#             */
/*   Updated: 2017/07/31 03:09:30 by qumaujea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <stdio.h>

unsigned char	*get_champ_name(int fd)
{
	unsigned char	*name;

	if (!(name = ft_memalloc(PROG_NAME_LENGTH + 1)))
		ft_perror(strerror(errno));
	if (read(fd, name, PROG_NAME_LENGTH) < 1)
		ft_perror(strerror(errno));
	return (name);
}

int				get_champ_size(int fd)
{
	unsigned int	prog_size;
	unsigned char	*buff;

	if (!(buff = ft_memalloc(4)))
		ft_perror(strerror(errno));
	if (lseek(fd, 0x88, SEEK_SET) == -1)
		ft_perror(strerror(errno));
	if (read(fd, buff, 4) < 1)
		ft_perror(strerror(errno));
	prog_size = buff[3];
	prog_size += buff[2] << 8;
	prog_size += buff[1] << 16;
	prog_size += buff[0] << 24;
	free(buff);
	return (prog_size);
}

unsigned char	*get_champ_comment(int fd)
{
	unsigned char	*comment;

	if (!(comment = ft_memalloc(COMMENT_LENGTH + 1)))
		ft_perror(strerror(errno));
	if (read(fd, comment, COMMENT_LENGTH) < 1)
		ft_perror(strerror(errno));
	return (comment);
}

unsigned char	*get_champ_prog(int fd, unsigned int size)
{
	unsigned char	*prog;
	unsigned int	r;

	if (lseek(fd, 0x890, SEEK_SET) == -1)
		ft_perror(strerror(errno));
	if (!(prog = ft_memalloc(CHAMP_MAX_SIZE + 1)))
		ft_perror(strerror(errno));
	if ((r = read(fd, prog, CHAMP_MAX_SIZE)) < 1)
		ft_perror(strerror(errno));
	if (r != size)
		ft_perror("Error: wrong champ size");
	return (prog);
}

t_champ			*read_champ(int fd)
{
	t_champ		*champ;

	if (!(champ = ft_memalloc(sizeof(t_champ))))
		ft_perror(strerror(errno));
	champ->name = get_champ_name(fd);
	champ->prog_size = get_champ_size(fd);
	champ->comment = get_champ_comment(fd);
	champ->prog = get_champ_prog(fd, champ->prog_size);
	return (champ);
}
