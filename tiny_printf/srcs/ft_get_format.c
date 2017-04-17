/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 05:57:20 by apoisson          #+#    #+#             */
/*   Updated: 2017/04/17 05:15:05 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tiny_printf.h"

void		ft_get_flag(t_data *data, int i)
{
	if (FORMAT[i + LEN] == ' ')
		SPACE = 1;
	if (FORMAT[i + LEN] == '#')
		PREFIX = 2;
	if (FORMAT[i + LEN] == '-')
		LEFT = 1;
	if (FORMAT[i + LEN] == '+')
		SIGN = 1;
	if (FORMAT[i + LEN] == '0')
		ZERO = 1;
	LEN++;
}

void		ft_get_p(t_data *data, int i)
{
	if (FORMAT[i + LEN + 1] == '*')
	{
		STAR = 1;
		PREC = va_arg(AP, int);
		if (PREC < 0)
			PREC = -1;
		LEN += 2;
		return ;
	}
	PREC = ft_atoi(&(FORMAT[i + LEN + 1]));
	LEN += ft_count_digit(PREC) + 1;
}

void		ft_get_f(t_data *data, int i)
{
	if (FORMAT[i + LEN] == '*')
	{
		STAR = 1;
		FIELD = va_arg(AP, int);
		if (FIELD < 0)
		{
			LEFT = 1;
			FIELD = -FIELD;
		}
		LEN++;
	}
	else
	{
		FIELD = ft_atoi(&(FORMAT[i + LEN]));
		LEN += ft_count_digit(FIELD);
	}
}

void		ft_get_f_p(t_data *data, int i)
{
	if (FORMAT[i + LEN] == '.' && (ft_isdigit(FORMAT[i + LEN + 1]) ||
				FORMAT[i + LEN + 1] == '*'))
		ft_get_p(data, i);
	else if (FORMAT[i + LEN] == '.')
	{
		PREC = 0;
		LEN++;
	}
	else
		ft_get_f(data, i);
}
