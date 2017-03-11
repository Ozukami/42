/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 05:59:50 by apoisson          #+#    #+#             */
/*   Updated: 2017/03/11 06:38:07 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_process_conv(t_data *data)
{
	ft_set_size(data);
	if (SIGN)
		ft_set_sign(data);
	if (PREFIX)
		ft_set_prefix(data);
	if ((PREC > -1 && TYPE == 's') || PREC > (int)L_ARG)
		ARG = ft_strsub(ARG, 0, PREC + SIGN);
	if (SPACE)
	{
		PTR = BUFFER;
		BUFFER = ft_strjoin(BUFFER, " ");
		ft_strdel(&PTR);
	}
	if (LEFT)
		FARG = ft_strjoin(ARG, RARG);
	else
		FARG = ft_strjoin(LARG, ARG);
	if (PREC == -1 && ZERO)
		ft_adjust_sign(data);
	BUFFER = ft_strjoinf(BUFFER, FARG);
}

void		ft_dispatch(t_data *data)
{
	ft_adjust_arg(data);
	L_ARG = ft_strlen(ARG);
	L_INIT = ft_strlen(ARG);
	ft_neg_case(data);
	if (FIELD > (int)L_INIT && FIELD > PREC && !LEFT && TYPE != 'd')
		SPACE = 0;
	if (TYPE == 's' || TYPE == 'c')
	{
		if (FIELD == -1 && PREC == -1)
			L_FARG = L_ARG;
		else if ((FIELD == -1) || (FIELD < PREC && PREC < (int)L_ARG))
			L_FARG = (size_t)ft_min(PREC, (int)L_ARG);
		else if ((PREC == -1) || (FIELD < (int)L_ARG && (int)L_ARG <= PREC))
			L_FARG = (size_t)ft_max(FIELD, (int)L_ARG);
		else
			L_FARG = (size_t)FIELD;
	}
	else
		L_FARG = (size_t)ft_max(ft_max(FIELD, PREC), (int)L_ARG);
	ft_process_conv(data);
}

void		ft_bad_delim(t_data *data, int i)
{
	if (!LEFT && FIELD > 0)
		BUFFER = ft_add_space_or_zero(BUFFER,
				((ZERO) ? '0' : ' '), FIELD - 1);
	BUFFER = ft_straddchar(BUFFER, FORMAT[i + LEN]);
	if (LEFT && FIELD > 0)
		BUFFER = ft_add_space_or_zero(BUFFER, ' ', FIELD - 1);
}

void		ft_get_conv(t_data *data, int i)
{
	LEN = 0;
	if (!FORMAT[i + LEN])
		return ;
	while (FORMAT[i + LEN] && (ft_strchr((const char *)FLAG, FORMAT[i + LEN])
			|| ft_strchr((const char *)F_P, FORMAT[i + LEN])
			|| ft_strchr((const char *)MOD, FORMAT[i + LEN])))
	{
		if (ft_strchr((const char *)FLAG, FORMAT[i + LEN]))
			ft_get_flag(data, i);
		if (ft_strchr((const char *)F_P, FORMAT[i + LEN]))
			ft_get_f_p(data, i);
		if (ft_strchr((const char *)MOD, FORMAT[i + LEN]))
			ft_get_mod(data, i);
	}
	if (!FORMAT[i + LEN])
		return ;
	if (!(ft_strchr((const char *)DELIM, FORMAT[i + LEN])))
		ft_bad_delim(data, i);
	else
	{
		TYPE = FORMAT[i + LEN];
		ft_adjust(data);
		ft_get_arg(data);
		ft_dispatch(data);
	}
}

int			ft_color_process(t_data *data, int i)
{
	int		len;
	char	*color_flag;
	t_color	*current;

	len = 0;
	while (FORMAT[i + len] != '}' && FORMAT[i + len] != '\0')
		len++;
	if (FORMAT[i + len] != '}')
		return (-1);
	color_flag = ft_strsub(FORMAT, i, len);
	current = COLOR;
	while (current)
	{
		if (ft_strequ(color_flag, current->name))
		{
			BUFFER = ft_strjoin(BUFFER, current->code);
			return (len + 1);
		}
		current = current->next;
	}
	return (0);
}
