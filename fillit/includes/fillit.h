/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 14:12:43 by apoisson          #+#    #+#             */
/*   Updated: 2016/11/23 13:42:14 by qumaujea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

# include <stdio.h> // !

# define BUFSIZE 21

void				ft_usage(void);
void				ft_error(void);
void				ft_process(int fd);
char				*ft_fillalloc(size_t size);
void				ft_bpoint(char *s, size_t n);

/*
** Fonctions permettant de verifier le fichier
*/

int					ft_verif(char *s);
int					ft_verif_1(char *s);
int					ft_verif_2(char *s, int a, int b, int c);
int					ft_verif_3(int a, int b, int c, int d);
int					ft_check_1(int a, int b);
int					ft_check_2(int a, int b, int c, int d);

/*
** Liste contenant les tetriminos
*/

typedef struct		s_tetri
{
	struct s_tetri	*next;
	char			*tetri;
}					t_tetri;

/*
** Fonctions permettant de manipuler la liste de tetriminos
*/

t_tetri				*ft_tetrinew(char *tetri);
void				ft_tetriadd(t_tetri **begin, t_tetri *new);
void				ft_tetrirev(t_tetri **begin);
void				ft_tetriprint(t_tetri *tetri);
size_t				ft_tetrilen(t_tetri *tetrilist);

#endif
