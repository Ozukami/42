/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 14:56:56 by lcharbon          #+#    #+#             */
/*   Updated: 2017/02/13 18:11:09 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_str_insert(char *s1, char *s2, int n)
{
	char	*str1;
	char	*str2;
	char	*str3;
	char	*ret;

	str1 = ft_strsub(s1, 0, n);
	str2 = ft_strsub(s1, n, ft_strlen(s1) - n);
	str3 = ft_strjoin(str1, s2);
	ret = ft_strjoin(str3, str2);
	ft_strdel(&str1);
	ft_strdel(&str2);
	ft_strdel(&str3);
	ft_strdel(&s1);
	return (ret);
}
