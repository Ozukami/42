/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 00:57:08 by apoisson          #+#    #+#             */
/*   Updated: 2017/03/11 04:14:10 by apoisson         ###   ########.fr       */
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

t_color		*ft_new_color(t_color *color, char *name, char *code)
{
	t_color	*new;

	if (!(new = ft_memalloc(sizeof(t_color))))
		exit(0);
	new->name = name;
	new->code = code;
	new->next = color;
	return (new);
}

t_color		*ft_init_color(void)
{
	t_color	*color;

	color = ft_new_color(NULL, "white", "\033[37m");
	color = ft_new_color(color, "cyan", "\033[36m");
	color = ft_new_color(color, "purple", "\033[35m");
	color = ft_new_color(color, "blue", "\033[34m");
	color = ft_new_color(color, "yellow", "\033[33m");
	color = ft_new_color(color, "green", "\033[32m");
	color = ft_new_color(color, "red", "\033[31m");
	color = ft_new_color(color, "black", "\033[30m");
	return (color);
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
	new->ptr = NULL;
	return (new);
}
