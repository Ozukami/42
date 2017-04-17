/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 00:57:08 by apoisson          #+#    #+#             */
/*   Updated: 2017/04/17 05:14:41 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tiny_printf.h"

t_conv		*ft_init_conv(void)
{
	t_conv	*new;

	if (!(new = ft_memalloc(sizeof(t_conv))))
		exit(0);
	new->base = 10;
	new->space = 0;
	new->prefix = 0;
	new->zero = 0;
	new->left = 0;
	new->sign = 0;
	new->neg = 0;
	new->star = 0;
	new->field = -1;
	new->point = 0;
	new->prec = -1;
	new->delim = 0;
	return (new);
}

t_arg		*ft_init_arg(void)
{
	t_arg	*new;

	if (!(new = ft_memalloc(sizeof(t_conv))))
		exit(0);
	new->arg = NULL;
	new->final_arg = NULL;
	new->left_arg = ft_strdup("");
	new->right_arg = ft_strdup("");
	new->size_init = 0;
	new->size_arg = 0;
	new->size_farg = 0;
	new->size_larg = 0;
	new->size_rarg = 0;
	return (new);
}

t_data		*ft_init_data(char *format, va_list ap)
{
	t_data	*new;

	if (!(new = ft_memalloc(sizeof(t_data))))
		exit(0);
	new->flag = ft_strdup(" +-#0");
	new->f_p = ft_strdup("123456789.*");
	new->delim = ft_strdup("csdouxXpb");
	new->buff = ft_strdup("");
	new->format = ft_strdup(format);
	va_copy(new->ap, ap);
	new->len = 0;
	new->conv = ft_init_conv();
	new->arg = ft_init_arg();
	new->color = ft_init_color();
	new->len_adjust = 0;
	new->ptr = NULL;
	return (new);
}
