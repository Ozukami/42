/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 08:09:08 by apoisson          #+#    #+#             */
/*   Updated: 2017/03/16 05:54:54 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				display_dirent_info(struct dirent *d)
{
	ft_printf("| %s\n", d->d_name);
	ft_printf("|	> d_ino = %ju\n", (uintmax_t)(d->d_ino));
	ft_printf("|	> d_namlen = %d\n", d->d_namlen);
	ft_printf("|	> d_reclen = %d\n", d->d_reclen);
	ft_printf("|	> d_type = %d\n", d->d_type);
}

int					main(int ac, char **av)
{
	DIR				*dir;
	struct dirent	*d;

	if (!ac)
		return (-1);
	ft_printf("| {cyan}Starting ft_ls {white}|\n");
	if (ac == 1)
	{
		dir = opendir(".");
		while ((d = readdir(dir)))
			if ((d->d_name)[0] != '.')
				display_dirent_info(d);
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
