/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 14:12:43 by apoisson          #+#    #+#             */
/*   Updated: 2016/11/27 11:46:22 by qumaujea         ###   ########.fr       */
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

/*
** Liste contenant les tetriminos
*/

typedef struct		s_tetri
{
	struct s_tetri	*next;
	char			*tetri;
}					t_tetri;

/*
** Fonctions generales
*/

void				ft_usage(void);
void				ft_error(void);
void				ft_process(int fd);
char				**ft_init(t_tetri *tetrilist);

/*
** Fonctions permettant de formater les tetri
*/

char				*ft_tetri_format(char *s);
char				*ft_str_replace(char *s, char c);

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
** Fonctions permettant de manipuler la liste de tetriminos
*/

t_tetri				*ft_tetrinew(char *tetri);
void				ft_tetriadd(t_tetri **begin, t_tetri *new);
void				ft_tetrirev(t_tetri **begin);
void				ft_tetriprint(t_tetri *tetri);
size_t				ft_tetrilen(t_tetri *tetrilist);
void				ft_tetriter(t_tetri **begin, char *(*f)(char *s));

#endif
