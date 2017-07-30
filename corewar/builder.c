/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champ_builder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 06:08:55 by apoisson          #+#    #+#             */
/*   Updated: 2017/07/30 04:51:00 by qumaujea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"
# include <stdio.h>
# include <fcntl.h>
# include "sys/types.h"

# define INITIAL	1
# define FINAL		2

# define NAME						(champ->name)
# define FD							(champ->fd)
# define HEADER						(champ->header)

# define PROG_SIZE					(champ->header->prog_size)
# define COMMENT					(champ->header->comment)

# define PROG_NAME_LENGTH			(128)
# define COMMENT_LENGTH				(2048)

typedef struct			s_header
{
	unsigned int		magic;
	char				prog_name[PROG_NAME_LENGTH + 1];
	unsigned int		prog_size;
	char				comment[COMMENT_LENGTH + 1];
}						t_header;

typedef struct s_champ			t_champ;

struct				s_champ
{
	char			*name;
	int				fd;
	t_header		*header;
};

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

void	write_champ(t_champ *champ, char *bin_str)
{
	int		i;
	int		j;
	int		val;

	lseek(FD, 0x890, SEEK_SET);
	i = -1;
	j = 0;
	while (++i < (int)PROG_SIZE)
	{
		if (bin_str[j] > 96)
			val = bin_str[j++] - 87;
		else if (bin_str[j] > 57)
			val = bin_str[j++] - 55;
		else
			val = bin_str[j++] - 48;
		val *= 16;
		if (bin_str[j] > 96)
			val += bin_str[j++] - 87;
		else if (bin_str[j] > 57)
			val += bin_str[j++] - 55;
		else
			val += bin_str[j++] - 48;
		j++;
		write(FD, &val, 1);
	}
}

t_champ	*init_champ(void)
{
	t_champ	*champ;

	if (!(champ = ft_memalloc(sizeof(t_champ))))
		ft_perror("Error: malloc failed");
	FD = 0;
	if (!(HEADER = ft_memalloc(sizeof(t_header))))
		ft_perror("Error: malloc failed");
	PROG_SIZE = 0;
	return (champ);
}

void	write_binary(t_champ *champ, char *bin_str)
{
	write_header(champ);
	write_champ(champ, bin_str);
	ft_putstr("\033[32mWriting output program to ");
	ft_putendl(NAME);
	ft_putstr("\033[0m");
}

void	process(char *name, char *bin_str)
{
	t_champ			*champ;
	int				i;
	unsigned int	prog_size;

	i = -1;
	prog_size = 1;
	while (bin_str[++i])
		if (bin_str[i] == ' ')
			prog_size++;
	champ = init_champ();
	ft_strcpy(champ->header->prog_name, name);
	NAME = ft_strjoin(name, ".cor");
	if (ft_strlen(name) > PROG_NAME_LENGTH)
		ft_perror("Name length is too big");
	ft_strcpy(COMMENT, "This champ was build with builder");
	PROG_SIZE = prog_size;
	if ((FD = open(NAME, O_CREAT | O_WRONLY | O_TRUNC,
					S_IRUSR | S_IWUSR)) == -1)
		ft_perror("Error: open failed");
	write_binary(champ, bin_str);
	if (close(FD) == -1)
		ft_perror("Error: close failed");
}

int		main(int ac, char **av)
{
	if (ac < 3)
		ft_perror("usage: ./asm <file name> <binary string to write>");
	process(av[1], av[2]);
	return (0);
}
