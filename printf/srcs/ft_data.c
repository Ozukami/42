/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 00:57:08 by apoisson          #+#    #+#             */
/*   Updated: 2017/03/11 23:11:40 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_conv		*ft_init_conv(void)
{
	t_conv	*new;

	if (!(new = malloc(sizeof(t_conv))))
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
	new->mod = ft_strdup("");
	new->delim = 0;
	return (new);
}

t_arg		*ft_init_arg(void)
{
	t_arg	*new;

	if (!(new = malloc(sizeof(t_conv))))
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

t_uni		*ft_init_uni(void)
{
	t_uni	*new;

	if (!(new = malloc(sizeof(t_uni))))
		exit(0);
	new->wc_arg = 0;
	new->ws_arg = NULL;
	new->bin = NULL;
	new->bits = 0;
	new->bytes = 0;
	new->byte1 = ft_strdup("0xxxxxxx");
	new->byte2 = ft_strdup("110xxxxx10xxxxxx");
	new->byte3 = ft_strdup("1110xxxx10xxxxxx10xxxxxx");
	new->byte4 = ft_strdup("11110xxx10xxxxxx10xxxxxx10xxxxxx");
	new->len_bytes = 0;
	return (new);
}

t_data		*ft_init_data(char *format, va_list ap)
{
	t_data	*new;

	if (!(new = malloc(sizeof(t_data))))
		exit(0);
	new->flag = ft_strdup(" +-#0");
	new->f_p = ft_strdup("123456789.*");
	new->mod = ft_strdup("hljz");
	new->delim = ft_strdup("cCsSdDioOuUxXpb");
	new->buff = ft_strdup("");
	new->format = ft_strdup(format);
	va_copy(new->ap, ap);
	new->len = 0;
	new->conv = ft_init_conv();
	new->arg = ft_init_arg();
	new->uni = ft_init_uni();
	new->color = ft_init_color();
	new->error = 0;
	new->len_adjust = 0;
	new->pos_c0 = -1;
	new->ptr = NULL;
	return (new);
}
