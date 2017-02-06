/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_v2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 11:22:25 by apoisson          #+#    #+#             */
/*   Updated: 2017/02/06 00:37:36 by apoisson         ###   ########.fr       */
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

void	ft_data(char *bin, char **data, int bits)
{
	if (bits < 12)
	{
		//printf("{2 octets}\n");
		bin = ft_fill(bin, 11);
		data[0] = ft_strjoin("110", ft_strsub(bin, 0, 5));
		data[1] = ft_strjoin("10", ft_strsub(bin, 5, 6));
		data[2] = 0;
	}
	else if (bits < 17)
	{
		//printf("{3 octets}\n");
		bin = ft_fill(bin, 16);
		data[0] = ft_strjoin("1110", ft_strsub(bin, 0, 4));
		data[1] = ft_strjoin("10", ft_strsub(bin, 4, 6));
		data[2] = ft_strjoin("10", ft_strsub(bin, 10, 6));
		data[3] = 0;
	}
	else
	{
		//printf("{4 octets}\n");
		bin = ft_fill(bin, 21);
		data[0] = ft_strjoin("11110", ft_strsub(bin, 0, 3));
		data[1] = ft_strjoin("10", ft_strsub(bin, 3, 6));
		data[2] = ft_strjoin("10", ft_strsub(bin, 9, 6));
		data[3] = ft_strjoin("10", ft_strsub(bin, 15, 6));
		data[4] = 0;
	}
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
	else
		ft_data(bin, data, bits);
	while (data[i])
	{
		print = ft_bin_to_dec(data[i++]);
		write(1, &print, 1);
	}
}

int		ft_dothework(wchar_t c, char **print, int j)
{
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
	data = ft_memalloc(i);
	*print = ft_memalloc(i);
	if (bits < 8)
	{
		print[0][0] = c;
		return (1);
	}
	ft_data(bin, data, bits);
	if (i >= 4)
		print[0][2] = ft_bin_to_dec(data[2]);
	while (j < i - 1)
	{
		if (j != 2)
			print[0][j] = ft_bin_to_dec(data[j]);
		j++;
	}
	print[0][j] = '\0';
	free(data);
	return (i - 1);
}
