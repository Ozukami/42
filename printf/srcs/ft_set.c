/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 05:57:37 by apoisson          #+#    #+#             */
/*   Updated: 2017/03/11 05:58:25 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_multi_mod(t_data *data)
{
	if (ft_strequ(MODIF, "z") || ft_strequ(MODIF, "j"))
	{
		LEN++;
		return (1);
	}
	return (0);
}

void		ft_sub_size(t_data *data)
{
	if (LEFT && (L_FARG > L_ARG))
	{
		L_RARG = L_FARG - L_ARG;
		L_RARG -= ((PREC >= (int)L_INIT) ? NEG : 0);
		L_RARG -= ((FIELD > (int)L_INIT && FIELD > PREC) ? SPACE : 0);
		L_RARG -= ((FIELD > (int)L_INIT && FIELD > PREC) ? (PREFIX) : 0);
		PTR = RARG;
		RARG = ((!ZERO) ? ft_strspace(L_RARG) : ft_strzero(L_RARG));
		ft_strdel(&PTR);
	}
	else if (L_FARG > L_ARG)
	{
		L_LARG = L_FARG - L_ARG;
		L_LARG -= ((PREC >= (int)L_INIT) ? NEG : 0);
		L_LARG -= ((FIELD > (int)L_INIT && FIELD > PREC) ? SPACE : 0);
		L_LARG -= ((FIELD > (int)L_INIT && FIELD > PREC) ? (PREFIX) : 0);
		PTR = LARG;
		LARG = ((!ZERO) ? ft_strspace(L_LARG) : ft_strzero(L_LARG));
		ft_strdel(&PTR);
	}
}

void		ft_set_size(t_data *data)
{
	if (TYPE == 's' && PREC >= (int)L_INIT)
		PREC = -1;
	L_ARG = (((PREC > -1 && TYPE == 's') || PREC >= (int)L_ARG) ?
			(PREC + SIGN) : L_ARG + SIGN);
	if (L_ARG > ft_strlen(ARG))
		ARG = ft_stradd_char(data, ARG, L_ARG - ft_strlen(ARG));
	ft_sub_size(data);
	if (NEG && PREC > 0)
		ft_replace_neg(data);
}

void		ft_set_sign(t_data *data)
{
	int		i;

	i = -1;
	while (ARG[++i])
	{
		if (ARG[i] == '0' || (ARG[i] == ' ' && ARG[i + 1] != ' '))
		{
			ARG[i] = '+';
			return ;
		}
	}
}

void		ft_set_prefix(t_data *data)
{
	char	*s;

	s = ft_strdup("0");
	if (TYPE == 'x' || TYPE == 'p')
		s = ft_straddchar(s, 'x');
	else if (TYPE == 'X')
		s = ft_straddchar(s, 'X');
	if (TYPE == 'o' && PREFIX && PREC > (int)L_INIT)
	{
		if (FIELD > (int)L_ARG && LEFT)
			ARG = ft_strjoinf(ARG, " ");
		else if (FIELD > (int)L_ARG)
			ARG = ft_strjoinf(" ", ARG);
	}
	else if (ZERO)
		LARG = ft_strjoinf(s, LARG);
	else
		ARG = ft_strjoinf(s, ARG);
}
