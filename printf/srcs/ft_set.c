/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 05:57:37 by apoisson          #+#    #+#             */
/*   Updated: 2017/03/12 03:27:14 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_sub_size_rarg(t_data *data)
{
	if (LEFT && (L_FARG > L_ARG))
	{
		L_RARG = L_FARG - L_ARG;
		L_RARG -= ((PREC >= (int)L_INIT) ? NEG : 0);
		L_RARG -= ((FIELD > (int)L_INIT && FIELD > PREC) ? SPACE : 0);
		L_RARG -= ((FIELD > (int)L_INIT && FIELD > PREC) ? (PREFIX) : 0);
		PTR = RARG;
		if ((int)L_RARG > -1)
			RARG = ((!ZERO) ? ft_strspace(L_RARG) : ft_strzero(L_RARG));
		else
			RARG = ft_strdup("\0");
		ft_strdel(&PTR);
	}
}

void		ft_sub_size_larg(t_data *data)
{
	if (L_FARG > L_ARG)
	{
		L_LARG = L_FARG - L_ARG;
		L_LARG -= ((PREC >= (int)L_INIT) ? NEG : 0);
		L_LARG -= ((FIELD > (int)L_INIT && FIELD > PREC) ? SPACE : 0);
		L_LARG -= ((FIELD > (int)L_INIT && FIELD > PREC) ? (PREFIX) : 0);
		PTR = LARG;
		if ((int)L_LARG > -1)
			LARG = ((!ZERO) ? ft_strspace(L_LARG) : ft_strzero(L_LARG));
		else
			LARG = ft_strdup("\0");
		ft_strdel(&PTR);
		if (TYPE == 'c' && !ARG[0] && !STAR)
			POS_C0 = (int)ft_strlen(BUFFER) + (((int)L_LARG > -1) ?
					(int)L_LARG : 0);
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
	ft_sub_size_rarg(data);
	ft_sub_size_larg(data);
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
			ARG = ft_strjoinf(ARG, ft_strdup(" "));
		else if (FIELD > (int)L_ARG)
			ARG = ft_strjoinf(ft_strdup(" "), ARG);
		ft_strdel(&s);
	}
	else if (ZERO)
		LARG = ft_strjoinf(s, LARG);
	else
		ARG = ft_strjoinf(s, ARG);
}
