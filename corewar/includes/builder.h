/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builder.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 05:20:15 by apoisson          #+#    #+#             */
/*   Updated: 2017/07/30 05:30:00 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILDER_H

# define BUILDER_H

# include "libft.h"
# include <stdio.h>
# include <fcntl.h>
# include "sys/types.h"

# define INITIAL	1
# define FINAL		2

# define NAME				(champ->name)
# define FD					(champ->fd)
# define HEADER				(champ->header)

# define PROG_SIZE			(champ->header->prog_size)
# define COMMENT			(champ->header->comment)

# define PROG_NAME_LENGTH	(128)
# define COMMENT_LENGTH		(2048)

typedef struct			s_header
{
	unsigned int		magic;
	char				prog_name[PROG_NAME_LENGTH + 1];
	unsigned int		prog_size;
	char				comment[COMMENT_LENGTH + 1];
}						t_header;

typedef struct s_champ	t_champ;

struct					s_champ
{
	char				*name;
	int					fd;
	t_header			*header;
};

void					write_prog_name(t_champ *champ);
void					write_comment(t_champ *champ);
void					write_prog_size(t_champ *champ);
void					write_header(t_champ *champ);

#endif
