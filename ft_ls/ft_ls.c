/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 08:09:08 by apoisson          #+#    #+#             */
/*   Updated: 2017/03/25 01:17:03 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				ft_usage(char c)
{
	if (c)
		ft_printf("ft_ls: illegal option -- %c\n", c);
	ft_printf("usage: ./ft_ls [-Ralrt] [file ...]\n");
	exit(0);
}

void				ft_throw_ft_memalloc_error(void)
{
	perror("ft_memalloc failed.");
	exit(0);
}

void				ft_throw_error(char *s, int i)
{
	errno = i;
	perror(ft_strjoin("ft_ls: ", s));
	exit(0);
}

t_fields			*ft_new_fields(void)
{
	t_fields		*new;

	if (!(new = ft_memalloc(sizeof(t_fields))))
		ft_throw_ft_memalloc_error();
	new->f_mode = 0;
	new->f_links = 0;
	new->f_owner = 0;
	new->f_group = 0;
	new->f_size = 0;
	new->f_mtime = 0;
	new->f_pathname = 0;
	return (new);
}

void				ft_set_mode_file_type(char *mode, mode_t st_mode)
{
	if (S_ISDIR(st_mode))
		mode[0] = 'd';
	else if (S_ISFIFO(st_mode))
		mode[0] = 'p';
	else if (S_ISCHR(st_mode))
		mode[0] = 'c';
	else if (S_ISBLK(st_mode))
		mode[0] = 'b';
	else if (S_ISSOCK(st_mode))
		mode[0] = 's';
	else if (S_ISLNK(st_mode))
		mode[0] = 'l';
}

void				ft_set_mode_rights(char *mode, mode_t st_mode)
{
	if (st_mode & S_IRUSR)
		mode[1] = 'r';
	if (st_mode & S_IWUSR)
		mode[2] = 'w';
	if (st_mode & S_IXUSR)
		mode[3] = 'x';
	if (st_mode & S_IRGRP)
		mode[4] = 'r';
	if (st_mode & S_IWGRP)
		mode[5] = 'w';
	if (st_mode & S_IXGRP)
		mode[6] = 'x';
	if (st_mode & S_IRUSR)
		mode[7] = 'r';
	if (st_mode & S_IWOTH)
		mode[8] = 'w';
	if (st_mode & S_IXOTH)
		mode[9] = 'x';
}

char				*ft_get_mode(mode_t st_mode)
{
	char			*mode;

	if (!(mode = ft_strfill(10, '-')))
		ft_throw_ft_memalloc_error();
	ft_set_mode_file_type(mode, st_mode);
	ft_set_mode_rights(mode, st_mode);
	return (mode);
}

char				*ft_format_time(time_t sec)
{
	char			*full_time;

	if (sec < time(NULL) - (6 * 30 * 24 * 60 * 60) || sec > time(NULL))
		full_time = ft_strjoin(ft_strsub(ctime(&sec), 4, 7),
				ft_strsub(ctime(&sec), 20, 4));
	else
		full_time = ft_strsub(ctime(&sec), 4, 12);
	return (full_time);
}

t_file				*ft_new_file(struct dirent *d)
{
	t_file			*new;
	struct stat		*stat;

	stat = NULL;
	if (!(new = ft_memalloc(sizeof(t_file)))
			|| !(stat = ft_memalloc(sizeof(struct stat))))
		ft_throw_ft_memalloc_error();
	lstat(d->d_name, stat);
	new->mode = ft_get_mode(stat->st_mode);
	new->links = stat->st_nlink;
	new->owner = ft_strdup((getpwuid(stat->st_uid))->pw_name);
	new->group = ft_strdup((getgrgid(stat->st_gid))->gr_name);
	new->size = stat->st_size;
	new->mtime = ft_format_time(stat->st_mtimespec.tv_sec);
	new->pathname = ft_strdup(d->d_name);
ft_printf("%s  %d %s  %s  %d  %s  %s\n",
		new->mode, new->links, new->owner, new->group,
		new->size, new->mtime, new->pathname);
	return (new);
}

t_file_list			*ft_new_file_list(t_file *f)
{
	t_file_list		*new;

	if (!(new = ft_memalloc(sizeof(t_file_list))))
		ft_throw_ft_memalloc_error();
	new->file = f;
	return (new);
}

void				ft_add_file(t_file_list **lst, t_file *f)
{
	t_file_list		*add;

	add = ft_new_file_list(f);
	add->next = *lst;
	*lst = add;
}


t_arg_list			*ft_new_arg_list(char *arg)
{
	t_arg_list		*new;

	if (!(new = ft_memalloc(sizeof(t_arg_list))))
		ft_throw_ft_memalloc_error();
	new->arg = arg;
	new->files = NULL;
	new->next = NULL;
	return (new);
}

void				ft_add_arg(t_arg_list **lst, char *arg)
{
	t_arg_list		*add;

	add = ft_new_arg_list(arg);
	add->next = *lst;
	*lst = add;
}

t_ls_data			*ft_init_ls_data(void)
{
	t_ls_data			*new;

	if (!(new = ft_memalloc(sizeof(t_ls_data))))
		ft_throw_ft_memalloc_error();
	new->options = ft_strdup("");
	new->args = NULL;
	new->f = ft_new_fields();
	return (new);
}

/*
void				display_dirent_info(struct dirent *d)
{
	ft_printf("| %s\n", d->d_name);
	ft_printf("|	> d_ino = %ju\n", (uintmax_t)(d->d_ino));
	ft_printf("|	> d_namlen = %d\n", d->d_namlen);
	ft_printf("|	> d_reclen = %d\n", d->d_reclen);
	ft_printf("|	> d_type = %d\n", d->d_type);
}

void				display_stat_info(struct stat *info)
{
	ft_printf("|		- %d\n", info->st_ino);
	ft_printf("|		- %d\n", info->st_mode);
	ft_printf("|		- %d\n", info->st_nlink);
	ft_printf("|		- %d\n", info->st_uid);
	ft_printf("|		- %d\n", info->st_gid);
	ft_printf("|		- %d\n", info->st_mtimespec);
	ft_printf("|		- %d\n", info->st_size);
	ft_printf("|		- %d\n", info->st_blocks);
}
*/

void				ft_update_fields(t_ls_data *ls_data)
{
	F_MODE = ft_max((int)ft_strlen(MODE), F_MODE);
	F_LINKS = ft_max((int)ft_count_digit(LINKS), F_LINKS);
	F_OWNER = ft_max((int)ft_strlen(OWNER), F_OWNER);
	F_GROUP = ft_max((int)ft_strlen(GROUP), F_GROUP);
	F_SIZE = ft_max((int)ft_count_digit(SIZE), F_SIZE);
	F_MTIME = ft_max((int)ft_strlen(MTIME), F_MTIME);
	F_PATH = ft_max((int)ft_strlen(PATHNAME), F_PATH);
}

void				ft_reset_fields(t_ls_data *ls_data)
{
	F_MODE = 0;
	F_LINKS = 0;
	F_OWNER = 0;
	F_GROUP = 0;
	F_SIZE = 0;
	F_MTIME = 0;
	F_PATH = 0;
}

void				ft_set_option(t_ls_data *ls_data, char *option)
{
	int				i;

	i = 1;
	while (option[i])
	{
		if (ft_strchr("Ralrt", option[i]))
		{
			if (!ft_strchr(OPTIONS, option[i]))
				OPTIONS = ft_straddchar(OPTIONS, option[i]);
		}
		else
			ft_usage(option[i]);
		i++;
	}
}

int					ft_no_args()
{
	DIR				*dir;
	struct dirent	*d;

	dir = opendir(".");
	while ((d = readdir(dir)))
		if ((d->d_name)[0] != '.')
			ft_printf("%s\n", d->d_name);
	closedir(dir);
	return (1);
}

void				ft_process(t_ls_data *ls_data)
{
	t_arg_list		*current;
	DIR				*dir;
	struct dirent	*d;
	struct stat		*buf;
	int				blocks;

	current = ARGS;
	while (current)
	{
		blocks = 0;
		buf = ft_memalloc(sizeof(struct stat));
		if (!(dir = opendir(current->arg)))
			ft_throw_error(current->arg, ENOENT);
		ft_reset_fields(ls_data);
		while ((d = readdir(dir)))
		{
			if ((d->d_name)[0] != '.' || ft_strchr(OPTIONS, 'a'))
			{
				ft_printf("test\n");
				ft_add_file(&(current->files), ft_new_file(d));
				ft_update_fields(ls_data);
				lstat(d->d_name, buf);
				blocks += buf->st_blocks;
			}
		}
		if (ft_strchr(OPTIONS, 'l'))
			ft_printf("total %d\n", blocks);
		while (LST_FILES)
		{
			if (ft_strchr(OPTIONS, 'l'))
				ft_printf("%s  %*d %*s  %*s  %*d  %*s  %s\n",
						MODE, F_LINKS, LINKS, F_OWNER, OWNER, F_GROUP,
						GROUP, F_SIZE, SIZE, F_MTIME, MTIME, PATHNAME);
			else
				ft_printf("%s\n", PATHNAME);
			LST_FILES = LST_FILES->next;
		}
		closedir(dir);
		current = current->next;
	}
}

void				ft_test(char *dir_name)
{
	DIR				*dir;
	struct dirent	*d;
	struct stat		*buf;
	int				blocks;

	if (!dir_name)
		dir_name = ft_strdup("dir_test");
	dir_name = ft_strjoin(dir_name, "/");
	blocks = 0;
	buf = ft_memalloc(sizeof(struct stat));
	ft_printf("Opening dir... %s\n", dir_name);
	if (!(dir = opendir(dir_name)))
		ft_throw_error(dir_name, ENOENT);
	while ((d = readdir(dir)))
	{
		if ((d->d_name)[0] != '.')
		{
			lstat(ft_strjoin(dir_name, d->d_name), buf);
			blocks += buf->st_blocks;
ft_printf("%s  %d %s  %s  %d  %s  %s\n",
	ft_get_mode(buf->st_mode),
	buf->st_nlink,
	ft_strdup((getpwuid(buf->st_uid))->pw_name),
	ft_strdup((getgrgid(buf->st_gid))->gr_name),
	(int)buf->st_size,
	ft_format_time(buf->st_mtimespec.tv_sec),
	ft_strdup(d->d_name));
		}
	}
	ft_printf("total %d\n", blocks);
	free(buf);
	exit(0);
}

int					main(int ac, char **av)
{
	int				i;
	t_ls_data		*ls_data;
	char			*test;

	test = malloc(10);
	free(test);
	if (!ac || !av)
		return (-1);
	i = 1;
	ls_data = ft_init_ls_data();
	//ft_test(av[1]);
	if (ac == 1)
		return (ft_no_args());
	while (av[i] && av[i][0] == '-')
		ft_set_option(ls_data, av[i++]);
	if (i == ac)
		ft_add_arg(&ARGS, ".");
	while (i < ac)
		ft_add_arg(&ARGS, av[i++]);
	ft_process(ls_data);
	return (0);
}
