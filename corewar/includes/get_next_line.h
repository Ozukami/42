/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 09:02:16 by apoisson          #+#    #+#             */
/*   Updated: 2017/07/29 23:28:37 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <sys/types.h>
# include <sys/uio.h>

# define BUFF_SIZE 1000

int					get_next_line(const int fd, char **line);

typedef struct		s_buff
{
	char			*buff;
	int				mem;
	int				fd;
	struct s_buff	*next;
	struct s_buff	*prev;
}					t_buff;

#endif
