/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 08:10:34 by apoisson          #+#    #+#             */
/*   Updated: 2017/03/17 07:27:15 by apoisson         ###   ########.fr       */
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

# define DEBUG			1

# define OPTIONS		(ls_data->options)
# define F				(ls_data->f)
# define ARGS			(ls_data->args)
# define LST_FILES		(ls_data->args->files)

# define MODE			(ls_data->args->files->file->mode)
# define LINKS			(ls_data->args->files->file->links)
# define OWNER			(ls_data->args->files->file->owner)
# define GROUP			(ls_data->args->files->file->group)
# define SIZE			(ls_data->args->files->file->size)
# define MTIME			(ls_data->args->files->file->mtime)
# define PATHNAME		(ls_data->args->files->file->pathname)

# define F_MODE			(ls_data->f->f_mode)
# define F_LINKS		(ls_data->f->f_links)
# define F_OWNER		(ls_data->f->f_owner)
# define F_GROUP		(ls_data->f->f_group)
# define F_SIZE			(ls_data->f->f_size)
# define F_MTIME		(ls_data->f->f_mtime)
# define F_PATH			(ls_data->f->f_pathname)

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

typedef struct			s_fields
{
	int					f_mode;
	int					f_links;
	int					f_owner;
	int					f_group;
	int					f_size;
	int					f_mtime;
	int					f_pathname;
}						t_fields;

typedef struct			s_args_list
{
	char				*arg;
	t_file_list			*files;
	struct s_args_list	*next;
}						t_arg_list;

typedef struct			s_ls_data
{
	char				*options;
	t_arg_list			*args;
	t_fields			*f;
}						t_ls_data;

t_file					*ft_new_file(struct dirent *d);
void					ft_set_mode_file_type(char *mode, mode_t st_mode);
void					ft_set_mode_rights(char *mode, mode_t st_mode);

#endif
