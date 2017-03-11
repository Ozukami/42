/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adjust.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 05:50:32 by apoisson          #+#    #+#             */
/*   Updated: 2017/03/11 05:51:42 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_adjust_2(t_data *data)
{
	if (TYPE != 'd')
	{
		SPACE = 0;
		SIGN = 0;
	}
	if (TYPE == 'd' || TYPE == 's' || TYPE == 'c')
		PREFIX = 0;
	if (TYPE == 'o' && PREFIX)
		PREFIX = 1;
	if (TYPE == 'c')
		PREC = -1;
	if (TYPE == 'p')
		PREFIX = 2;
	if (PREC > -1 && TYPE != 's')
		ZERO = 0;
}

void		ft_adjust(t_data *data)
{
	if (TYPE >= 'C' && TYPE <= 'U')
	{
		TYPE += 32;
		free(MODIF);
		MODIF = ft_strdup("l");
	}
	if (TYPE == 'i')
		TYPE = 'd';
	if (TYPE == 'x' || TYPE == 'X' || TYPE == 'p')
		BASE = 16;
	else if (TYPE == 'o')
		BASE = 8;
	else
		BASE = 10;
	if (LEFT)
		ZERO = 0;
	if (SIGN)
		SPACE = 0;
	if (TYPE == 's')
	{
		SIGN = 0;
		PREFIX = 0;
	}
	ft_adjust_2(data);
}

void		ft_adjust_sign(t_data *data)
{
	int		i;

	if (NEG)
		FARG[0] = '-';
	else if (SIGN)
		FARG[0] = '+';
	i = 0;
	while (FARG[++i])
	{
		if (FARG[i] == '-' || FARG[i] == '+')
		{
			FARG[i] = '0';
			return ;
		}
	}
}

void		ft_adjust_arg(t_data *data)
{
	if (ARG == NULL)
	{
		ARG = ft_strdup("(null)");
		return ;
	}
	if (!(ARG[0]) && TYPE != 's')
	{
		FIELD--;
		L_ADJUST++;
	}
	if (ARG[0] == '0')
	{
		if (TYPE != 'o' && TYPE != 'p')
			PREFIX = 0;
		if (PREC == 0)
			ARG[0] = '\0';
	}
}
