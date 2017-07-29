/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_reader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 17:23:41 by lcharbon          #+#    #+#             */
/*   Updated: 2017/07/29 06:07:26 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_lr_read(char **stock, int fd, int buff_size)
{
	int				ret;
	char			buf[buff_size + 1];
	char			*tmp;

	ft_memset(buf, '\0', buff_size + 1);
	ret = read(fd, buf, buff_size);
	tmp = ft_strjoin(*stock, buf);
	free(*stock);
	*stock = tmp;
	return (ret);
}

static int			ft_lr_process(char **line, char *stock)
{
	int				i;

	i = 0;
	if (ft_strlen(stock) < 1)
		return (0);
	while (stock[i] != '\n' && stock[i] != '\0')
		i++;
	if (stock[i] == '\n')
		*line = ft_strsub(stock, 0, i);
	else if (stock[i] == '\0')
		*line = ft_strsub(stock, 0, i);
	return (1);
}

int					ft_line_reader(int fd, char **line)
{
	int				read_ret;
	int				i;
	int				loop;
	char			*str;

	if (fd < 0 || !line)
		return (-1);
	loop = 0;
	str = ft_strdup("");
	while (loop != 1)
	{
		read_ret = ft_lr_read(&str, fd, 1);
		if (read_ret < 0)
			return (-1);
		else if (read_ret == 0)
		{
			free(str);
			return (0);
		}
		else if (ft_strchr(str, '\n'))
			loop = 1;
	}
	i = ft_lr_process(line, str);
	ft_strdel(&str);
	return (1);
}
