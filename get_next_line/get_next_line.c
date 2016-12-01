/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 09:00:25 by apoisson          #+#    #+#             */
/*   Updated: 2016/12/01 13:51:12 by apoisson         ###   ########.fr       */
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
	free(s1);
	return (stack);
}

t_buff	*new_buff(int fd)
{
	t_buff	*new;

	if (!(new = malloc(sizeof(t_buff))))
		return (NULL);
	new->buff = malloc(BUFF_SIZE + 1);
	new->mem = -1;
	new->fd = fd;
	new->eof = 0;
	new->next = NULL;
	return (new);
}

int		get_next_line(const int fd, char **line)
{
	static t_buff	*buff;
	int				r;
	int				i;
	int				verif;

	if (!line)
		return (-1);
	if (!buff)
		buff = new_buff(fd);
	if (buff->eof)
		return (0);
	*line = ft_strdup("\0");
	verif = 0;
	/*
		ft_putchar('{');
		ft_putstr(buff->buff);
		ft_putstr("}\n");
	*/
	if (buff->mem != -1)
	{
		i = buff->mem;
		while ((buff->buff)[i])
		{
			if ((buff->buff)[i] == '\n')
			{
				*line = ft_stack(*line, ft_strsub(buff->buff, buff->mem, i - buff->mem));
				if (i < BUFF_SIZE)
					buff->mem = i + 1;
				return (1);
			}
			i++;
		}
		*line = ft_stack(*line, ft_strsub(buff->buff, buff->mem, i - buff->mem));
		buff->mem = -1;
	}
	while ((r = read(fd, buff->buff, BUFF_SIZE)) > 0)
	{
		buff->mem = -1;
		(buff->buff)[r] = '\0';
		i = 0;
		while ((buff->buff)[i])
		{
			if ((buff->buff)[i] == '\n')
			{
				*line = ft_stack(*line, ft_strsub(buff->buff, 0, i));
				if (i < BUFF_SIZE)
					buff->mem = i + 1;
				return (1);
			}
			i++;
		}
		*line = ft_stack(*line, buff->buff);
		verif = 1;
	}
	buff->eof = 1;
	if (r == -1)
		return (-1);
	if (verif)
		return (1);
	return (0);
}
