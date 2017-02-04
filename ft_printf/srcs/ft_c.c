/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 09:04:59 by apoisson          #+#    #+#             */
/*   Updated: 2017/02/04 02:04:28 by qumaujea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 ** Decoupage caractere multi-octet
 ** 0xxxxxxx								 	 7 bits
 ** 110xxxxx 10xxxxxx						11 bits
 ** 1110xxxx 10xxxxxx 10xxxxxx				16 bits
 ** 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx		21 bits
 */

static char	*ft_fill(char *s, size_t size)
{
	char	*s2;
	size_t	i;
	int		j;

	j = (int)ft_strlen(s);
	if (j == (int)size)
		return (s);
	if (!(s2 = ft_memalloc(size)))
		return (NULL);
	i = 0;
	while (i < size)
		s2[i++] = '0';
	while (j >= 0)
		s2[i--] = s[j--];
	return (s2);
}

static int	ft_bin_to_dec(char *bin)
{
	int		hex;
	int		i;
	int		power;

	hex = 0;
	i = 0;
	power = 7;
	while (bin[i])
		hex += (bin[i++] - '0') * ft_recursive_power(2, power--);
	return (hex);
}

static void	ft_data(char *bin, char **data, int bits)
{
	if (bits < 12)
	{
		bin = ft_fill(bin, 11);
		data[0] = ft_strjoin("110", ft_strsub(bin, 0, 5));
		data[1] = ft_strjoin("10", ft_strsub(bin, 5, 6));
		data[2] = 0;
	}
	else if (bits < 17)
	{
		bin = ft_fill(bin, 16);
		data[0] = ft_strjoin("1110", ft_strsub(bin, 0, 4));
		data[1] = ft_strjoin("10", ft_strsub(bin, 4, 6));
		data[2] = ft_strjoin("10", ft_strsub(bin, 10, 6));
		data[3] = 0;
	}
	else
	{
		bin = ft_fill(bin, 21);
		data[0] = ft_strjoin("11110", ft_strsub(bin, 0, 3));
		data[1] = ft_strjoin("10", ft_strsub(bin, 3, 6));
		data[2] = ft_strjoin("10", ft_strsub(bin, 9, 6));
		data[3] = ft_strjoin("10", ft_strsub(bin, 15, 6));
		data[4] = 0;
	}
}

char	*ft_dothework(wchar_t c, int j)
{
	char			*print;
	char			*bin;
	char			**data;
	int				bits;
	int				i;

	bin = ft_itoa_base((int)c, 2, 0);
	bits = (int)ft_strlen(bin);
	if (bits < 8)
		i = 2;
	else if (bits < 12)
		i = 3;
	else if (bits < 17)
		i = 4;
	else
		i = 5;
	data = ft_memalloc(5);
	print = ft_memalloc(i);
	if (bits < 8)
	{
		print[0] = c;
		return (print);
	}
	ft_data(bin, data, bits);
	while (j < i - 1)
	{
		print[j] = ft_bin_to_dec(data[j]);
		j++;
	}
	return (print);
}

size_t		ft_va_arg_c(va_list ap, t_conv *list, char **str)
{
	size_t	i;
	char	*cpy;
	char	*tmp;
	int		j;

	i = 0;
	tmp = ft_dothework(va_arg(ap, wchar_t), 0);
	cpy = (list->field > 1) ? ft_memalloc(list->field + ft_strlen(tmp) + 1) 
		: ft_memalloc(ft_strlen(tmp) + 1);
	if (ft_max(list->field, ft_strlen(tmp)) > 1)
		while ((int)i < ft_max(list->field, ft_strlen(tmp) + 1))
			cpy[i++] = ' ';
	if (list->left)
		*str = ft_strjoinf(*str, ft_strncpy(cpy, tmp, ft_strlen(tmp)));
	else
	{
		i = 0;
		j = ft_strlen(cpy) - ft_strlen(tmp);
		if (j < 0)
			j = 0;
		while (tmp[i])
			cpy[j++] = tmp[i++];
		*str = ft_strjoinf(*str, cpy);
	}
	return (ft_strlen(cpy));
}
