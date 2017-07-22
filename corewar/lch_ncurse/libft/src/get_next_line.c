/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 09:05:52 by lcharbon          #+#    #+#             */
/*   Updated: 2017/05/21 20:35:35 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		gnl_process(char *str, char **line, char **stock, int a)
{
	int			i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n' && a == 1)
	{
		*line = ft_strnew(i);
		ft_memcpy(*line, str, i);
		*stock = ft_strsub(str, i + 1, ft_strlen(str) - i);
		ft_strdel(&str);
		return (1);
	}
	else if (str[i] == '\0' && a == 0)
	{
		*line = ft_strnew(i);
		ft_memcpy(*line, str, i);
		ft_strdel(&str);
		ft_strdel(stock);
		return (1);
	}
	return (0);
}

static char		*gnl_read(char *tmp, char *str, char *buf, int read_ret)
{
	tmp = str;
	buf[read_ret] = '\0';
	str = ft_strjoin(str, buf);
	ft_strdel(&tmp);
	return (str);
}

int				gnl_ret(int read_ret, char *str)
{
	if (read_ret == -1)
		return (-1);
	if (ft_strlen(str) < 1)
		return (0);
	return (1);
}

static int		gnl_bufdel(char *buf)
{
	ft_strdel(&buf);
	return (1);
}

int				get_next_line(int fd, char **line, int buff_size)
{
	static char	*stock[MAX_FD];
	t_gnl		list;

	if (fd < 0 || buff_size < 1 || !line || fd > MAX_FD)
		return (-1);
	list.buf = ft_strnew(buff_size);
	list.str = ft_strnew(buff_size);
	list.tmp = list.str;
	if (stock[fd])
	{
		list.str = ft_strjoin(list.str, stock[fd]);
		ft_strdel(&list.tmp);
	}
	while ((list.read_ret = read(fd, list.buf, buff_size)) > 0)
	{
		list.str = gnl_read(list.tmp, list.str, list.buf, list.read_ret);
		if (gnl_process(list.str, line, &stock[fd], 1) == 1)
			return (gnl_bufdel(list.buf));
	}
	if (gnl_ret(list.read_ret, list.str) != 1)
		return (gnl_ret(list.read_ret, list.str));
	if (gnl_process(list.str, line, &stock[fd], 1) == 1)
		return (1);
	return (gnl_process(list.str, line, &stock[fd], 0));
}
