/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 08:09:08 by apoisson          #+#    #+#             */
/*   Updated: 2017/03/17 05:42:31 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_fields			*ft_new_fields(void)
{
	t_fields		*new;

	if (!(new = malloc(sizeof(t_fields))))
		exit(0);
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
	{
		perror("Malloc failed. Not enough memory.");
		exit(0);
	}
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

	if (!(new = malloc(sizeof(t_file)))
			|| !(stat = malloc(sizeof(struct stat))))
		return (NULL);
	lstat(d->d_name, stat);
	new->mode = ft_get_mode(stat->st_mode);
	new->links = stat->st_nlink;
	new->owner = ft_strdup((getpwuid(stat->st_uid))->pw_name);
	new->group = ft_strdup((getgrgid(stat->st_gid))->gr_name);
	new->size = stat->st_size;
	new->mtime = ft_format_time(stat->st_mtimespec.tv_sec);
	new->pathname = ft_strdup(d->d_name);
	return (new);
}

t_file_list			*ft_new_file_list(t_file *f)
{
	t_file_list		*new;

	if (!(new = malloc(sizeof(t_file_list))))
		return (NULL);
	new->file = f;
	return (new);
}

void				ft_add(t_file_list **lst, t_file *f)
{
	t_file_list		*add;

	add = ft_new_file_list(f);
	add->next = *lst;
	*lst = add;
}

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

void				ft_update_fields(t_fields *f, t_file_list *lst)
{
	F_MODE = ft_max((int)ft_strlen(MODE), F_MODE);
	F_LINKS = ft_max((int)ft_count_digit(LINKS), F_LINKS);
	F_OWNER = ft_max((int)ft_strlen(OWNER), F_OWNER);
	F_GROUP = ft_max((int)ft_strlen(GROUP), F_GROUP);
	F_SIZE = ft_max((int)ft_count_digit(SIZE), F_SIZE);
	F_MTIME = ft_max((int)ft_strlen(MTIME), F_MTIME);
	F_PATH = ft_max((int)ft_strlen(PATHNAME), F_PATH);
}

int					main(int ac, char **av)
{
	DIR				*dir;
	struct dirent	*d;
	struct stat		*buf;
	t_file_list		*lst;
	int				blocks;
	t_fields		*f;

	lst = NULL;
	blocks = 0;
	f = ft_new_fields();
	buf = malloc(sizeof(struct stat));
	if (!ac)
		return (-1);
	ft_printf("| {cyan}Starting ft_ls {white}|\n");
	if (ac == 1)
	{
		dir = opendir(".");
		while ((d = readdir(dir)))
		{
			if ((d->d_name)[0] != '.')
			{
				ft_add(&lst, ft_new_file(d));
				ft_update_fields(f, lst);
				lstat(d->d_name, buf);
				blocks += buf->st_blocks;
			}
		}
		ft_printf("total %d\n", blocks);
		while (lst)
		{
			ft_printf("%s  %*d %*s  %*s  %*d  %*s  %s\n", MODE, F_LINKS,
					LINKS, F_OWNER, OWNER, F_GROUP, GROUP, F_SIZE, SIZE,
					F_MTIME, MTIME, PATHNAME);
			lst = lst->next;
		}
	}
	if (ac == 2)
	{
		dir = opendir(av[1]);
		while ((d = readdir(dir)))
			ft_printf("|	{green}File found{white}: %s\n", d->d_name);
	}
	ft_printf("| {cyan}End of ft_ls {white}|\n");
	closedir(dir);
	return (0);
}
