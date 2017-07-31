/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompilo.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 06:15:58 by apoisson          #+#    #+#             */
/*   Updated: 2017/07/31 07:40:10 by apoisson         ###   ########.fr       */
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

extern t_op			g_op_tab[17];

typedef struct		s_decomp
{
	int				fd_cor;
	int				fd_s;
	int				prog_size;
	unsigned char	*prog;
}					t_decomp;

unsigned char		*get_champ_name(int fd);
int					get_champ_size(int fd);
unsigned char		*get_champ_comment(int fd);
unsigned char		*get_champ_prog(int fd, int size);
void				verif_file(int fd);
int					get_inst_length(int ocp, int op);
int					get_value(t_decomp *decomp, int nb_octet, int pc);
void				get_args(t_decomp *decomp, int ocp, int args[4], int pc);
int					get_ocp(t_decomp *decomp, int i);

#endif
