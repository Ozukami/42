/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumaujea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 05:23:41 by qumaujea          #+#    #+#             */
/*   Updated: 2017/03/12 03:28:40 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_free_color(t_color *color)
{
	if (color->next)
		ft_free_color(color->next);
	free(color);
}

void		ft_free_conv(t_conv *conv)
{
	free(conv->mod);
	conv->mod = NULL;
	free(conv);
}

void		ft_free_arg(t_arg *arg)
{
	free(arg->arg);
	arg->arg = NULL;
	free(arg->left_arg);
	arg->left_arg = NULL;
	free(arg->right_arg);
	arg->right_arg = NULL;
	free(arg);
}

void		ft_free_uni(t_uni *uni)
{
	free(uni->bin);
	uni->bin = NULL;
	free(uni->byte1);
	uni->byte1 = NULL;
	free(uni->byte2);
	uni->byte2 = NULL;
	free(uni->byte3);
	uni->byte3 = NULL;
	free(uni->byte4);
	uni->byte4 = NULL;
	free(uni);
}

int			ft_free_data(t_data *data)
{
	ft_free_conv((data->conv));
	ft_free_arg((data->arg));
	ft_free_uni((data->uni));
	ft_free_color(data->color);
	free(FLAG);
	FLAG = NULL;
	free(F_P);
	F_P = NULL;
	free(MOD);
	MOD = NULL;
	free(DELIM);
	DELIM = NULL;
	free(BUFFER);
	BUFFER = NULL;
	free(FORMAT);
	FORMAT = NULL;
	free(data);
	return (ERROR);
}
