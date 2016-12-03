/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 09:00:25 by apoisson          #+#    #+#             */
/*   Updated: 2016/12/03 14:03:26 by apoisson         ###   ########.fr       */
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

t_buff	*new_buff(int fd, int add, t_buff **buff)
{
	t_buff	*new;

	if (!(new = malloc(sizeof(t_buff))))
		return (NULL);
	new->buff = malloc(BUFF_SIZE + 1);
	new->mem = -1;
	new->fd = fd;
	new->next = NULL;
	if (add)
	{
		new->next = *buff;
		*buff = new;
		return (new);
	}
	return (new);
}

int		read_line(int fd, t_buff *buff, char **line, int verif)
{
	int		r;
	int		i;

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
				if ((buff->buff)[i + 1])
					buff->mem = i + 1;
				return (1);
			}
			i++;
		}
		*line = ft_stack(*line, buff->buff);
		verif = 1;
	}
	if (r == -1)
		return (-1);
	return (verif);
}

int		check_mem(int fd, t_buff *buff, char **line)
{
	int		i;

	i = buff->mem;
	while ((buff->buff)[i])
	{
		if ((buff->buff)[i] == '\n')
		{
			*line = ft_stack(*line, ft_strsub(buff->buff, buff->mem,
						i - buff->mem));
			buff->mem = -1;
			if ((buff->buff)[i + 1])
				buff->mem = i + 1;
			return (1);
		}
		i++;
	}
	*line = ft_stack(*line, ft_strsub(buff->buff, buff->mem, i - buff->mem));
	buff->mem = -1;
	read_line(fd, buff, line, 0);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_buff	*buff;
	int				exists;

	if (!line)
		return (-1);
	exists = 0;
	if (!buff)
		buff = new_buff(fd, 0, NULL);
	while (buff && !exists)
	{
		if (buff->fd == fd)
			exists = 1;
		else
			buff = buff->next;
	}
	if (!exists)
		buff = new_buff(fd, 1, &buff);
	*line = ft_strdup("\0");
	if (buff->mem != -1)
		if (check_mem(fd, buff, line))
			return (1);
	return (read_line(fd, buff, line, 0));
}
