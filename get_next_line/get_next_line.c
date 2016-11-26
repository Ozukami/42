/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 09:00:25 by apoisson          #+#    #+#             */
/*   Updated: 2016/11/23 09:48:44 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_stack(char *s1, const char *s2)
{
	char		*stack;
	int			i;
	int			j;

	stack = ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	j = 0;
	while (s1[i])
	{
		stack[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		stack[i + j] = s2[j];
		j++;
	}
	return (stack);
}

int		sub_ft(char *buff, char **line, int *mem)
{
	int			i;

	i = -1;
	while (buff[++i])
	{
		if (buff[i] == '\n')
		{
			*line = ft_stack(*line, ft_strsub(buff, 0, i));
			if (buff[i + 1])
				*mem = i;
			return (1);
		}
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static int	mem = -1;
	int			verif;
	int			r;
	static char	buff[BUFF_SIZE + 1];

	*line = ft_strdup("\0");
	verif = 0;
	if (mem != -1)
	{
		*line = ft_strdup(ft_strsub(buff, mem + 1, BUFF_SIZE - mem));
		mem = -1;
		verif = 1;
	}
	while ((r = read(fd, buff, BUFF_SIZE)))
	{
		if (r == -1)
			return (r);
		buff[r] = '\0';
		if (sub_ft(buff, line, &mem))
			return (1);
		*line = ft_stack(*line, ft_strdup(buff));
	}
	if (verif)
		return (1);
	return (0);
}
