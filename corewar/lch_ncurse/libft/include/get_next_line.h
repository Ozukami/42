/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 07:54:59 by lcharbon          #+#    #+#             */
/*   Updated: 2017/05/21 17:25:11 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# define MAX_FD 10240

typedef struct	s_gnl
{
	char	*buf;
	char	*str;
	char	*tmp;
	int		read_ret;
}				t_gnl;

int				get_next_line(const int fd, char **line, int buff_size);

#endif
