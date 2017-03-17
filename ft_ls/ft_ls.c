/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 08:09:08 by apoisson          #+#    #+#             */
/*   Updated: 2017/03/17 01:23:53 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file				*ft_new_file(struct dirent *d)
{
	t_file			*new;
	struct stat		*stat;

	if (!(new = malloc(sizeof(t_file)))
			|| !(stat = malloc(sizeof(struct stat))))
		return (NULL);
	lstat(d->d_name, stat);
	new->mode = ft_strdup("N/A");
	new->links = stat->st_nlink;
	new->owner = ft_strdup((getpwuid(stat->st_uid))->pw_name);
	new->group = ft_strdup((getgrgid(stat->st_gid))->gr_name);
	new->size = stat->st_size;
	new->mtime = ft_strdup("N/A");
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

int					main(int ac, char **av)
{
	DIR				*dir;
	struct dirent	*d;
	struct stat		*buf;
	t_file_list		*lst;
	int				blocks;

	lst = NULL;
	blocks = 0;
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
				lstat(d->d_name, buf);
				blocks += buf->st_blocks;
			}
		}
		ft_printf("total %d\n", blocks);
		while (lst)
		{
			ft_printf("%s	%d	%s	%s	%d	%s	%s\n", MODE, LINKS,
					OWNER, GROUP, SIZE, MTIME, PATHNAME);
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
