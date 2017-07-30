/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 05:20:11 by apoisson          #+#    #+#             */
/*   Updated: 2017/07/30 09:23:27 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builder.h"

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

void	process(t_champ *champ, char *name, char *bin_str)
{
	int				i;
	unsigned int	prog_size;

	i = -1;
	prog_size = 1;
	while (bin_str[++i])
		if (bin_str[i] == ' ')
			prog_size++;
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
	t_champ			*champ;

	if (ac < 3)
		ft_perror("usage: ./asm <file name> <binary string to write>");
	champ = init_champ();
	process(champ, av[1], av[2]);
	free(HEADER);
	ft_strdel(&NAME);
	free(champ);
	return (0);
}
