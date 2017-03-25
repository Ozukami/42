/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 06:33:12 by apoisson          #+#    #+#             */
/*   Updated: 2017/03/25 02:38:02 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_replace_neg(t_data *data)
{
	int		i;

	if (PREC >= (int)L_INIT)
	{
		//PTR = ARG;
		ARG = ft_strjoin("-", ARG);
		//ft_strdel(&PTR);
	}
	i = 0;
	if (PREC >= (int)L_INIT)
	{
		while (ARG[++i])
		{
			if (ARG[i] == '-')
			{
				ARG[i] = '0';
				return ;
			}
		}
	}
}

void		ft_neg_case(t_data *data)
{
	if (ARG[0] == '-')
	{
		SIGN = 0;
		NEG = 1;
		SPACE = 0;
	}
}

char		*ft_add_space_or_zero(char *s, char c, int n)
{
	while (n-- > 0)
		s = ft_straddchar(s, c);
	return (s);
}

char		*ft_stradd_char(t_data *data, char *s, int n)
{
	while (n > 0)
	{
		if (LEFT && TYPE == 's')
		{
			//PTR = s;
			s = ft_strjoin(s, " ");
			//ft_strdel(&PTR);
		}
		else
		{
			//PTR = s;
			s = ft_strjoin(((TYPE == 's') ? " " : "0"), s);
			//ft_strdel(&PTR);
		}
		n--;
	}
	return (s);
}
