/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_v2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 11:22:25 by apoisson          #+#    #+#             */
/*   Updated: 2016/12/24 11:23:28 by apoisson         ###   ########.fr       */
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

char	*ft_fill(char *s, size_t size)
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

int		ft_bin_to_dec(char *bin)
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

void	ft_putchar_v2(wchar_t c)
{
	unsigned char	print;
	char			*bin;
	char			**data;
	int				bits;
	int				i;

	bin = ft_itoa_base((int)c, 2, 0);
	bits = (int)ft_strlen(bin);
	data = ft_memalloc(5);
	i = 0;
	if (bits < 8)
		return (ft_putchar(c));
	else if (bits < 12)
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
	while (data[i])
	{
		print = ft_bin_to_dec(data[i++]);
		write(1, &print, 1);
	}
}
