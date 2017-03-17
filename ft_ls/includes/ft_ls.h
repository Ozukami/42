/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 08:10:34 by apoisson          #+#    #+#             */
/*   Updated: 2017/03/17 02:55:33 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "ft_printf.h"
# include <dirent.h>
# include <stdio.h>
# include <errno.h>
# include <sys/xattr.h>
# include <sys/stat.h>
# include <grp.h>
# include <pwd.h>
# include <time.h>

# define MODE			(lst->file->mode)
# define LINKS			(lst->file->links)
# define OWNER			(lst->file->owner)
# define GROUP			(lst->file->group)
# define SIZE			(lst->file->size)
# define MTIME			(lst->file->mtime)
# define PATHNAME		(lst->file->pathname)

typedef struct			s_file
{
	char				*mode;
	int					links;
	char				*owner;
	char				*group;
	int					size;
	char				*mtime;
	char				*pathname;
}						t_file;

typedef struct			s_file_list
{
	t_file				*file;
	struct s_file_list	*next;
}						t_file_list;

t_file					*ft_new_file(struct dirent *d);
void					ft_set_mode_file_type(char *mode, mode_t st_mode);
void					ft_set_mode_rights(char *mode, mode_t st_mode);

#endif
