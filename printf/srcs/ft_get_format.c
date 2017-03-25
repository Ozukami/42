/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 05:57:20 by apoisson          #+#    #+#             */
/*   Updated: 2017/03/25 02:36:02 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void		ft_get_mod(t_data *data, int i)
{
	if (ft_multi_mod(data))
		return ;
	//ft_strdel(&MODIF);
	if (FORMAT[i + LEN] == 'l' && FORMAT[i + LEN + 1] == 'l')
	{
		MODIF = ft_strdup("ll");
		LEN++;
	}
	else if (FORMAT[i + LEN] == 'h' && FORMAT[i + LEN + 1] == 'h')
	{
		MODIF = ft_strdup("hh");
		LEN++;
	}
	else if (FORMAT[i + LEN] == 'l')
		MODIF = ft_strdup("l");
	else if (FORMAT[i + LEN] == 'h')
		MODIF = ft_strdup("h");
	else if (FORMAT[i + LEN] == 'j')
		MODIF = ft_strdup("j");
	else if (FORMAT[i + LEN] == 'z')
		MODIF = ft_strdup("z");
	else
		MODIF = ft_strdup("");
	LEN++;
}
