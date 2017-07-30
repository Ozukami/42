/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompilo.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 06:15:58 by apoisson          #+#    #+#             */
/*   Updated: 2017/07/30 08:02:12 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DECOMPILO_H
# define DECOMPILO_H

# include "libft.h"
# include "op.h"
# include <errno.h>
# include <fcntl.h>

# define FD_COR		(decomp->fd_cor)
# define FD_S		(decomp->fd_s)
# define PROGSIZE	(decomp->prog_size)
# define PROG		(decomp->prog)

typedef struct		s_decomp
{
	int				fd_cor;
	int				fd_s;
	int				prog_size;
	unsigned char	*prog;
}					t_decomp;

#endif
