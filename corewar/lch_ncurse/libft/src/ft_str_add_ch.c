/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_add_ch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 12:53:17 by lcharbon          #+#    #+#             */
/*   Updated: 2017/02/13 18:11:35 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_str_add_ch(char *str, char c)
{
	int		i;
	char	*ret;

	i = 1;
	ret = ft_strnew(ft_strlen(str) + 1);
	ret[0] = c;
	while (str[i - 1] != '\0')
	{
		ret[i] = str[i - 1];
		i++;
	}
	ft_strdel(&str);
	return (ret);
}
