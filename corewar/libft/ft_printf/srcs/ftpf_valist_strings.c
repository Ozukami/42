/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_valist_strings.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 15:09:25 by lcharbon          #+#    #+#             */
/*   Updated: 2017/06/08 01:49:15 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*ftpf_unicode(wint_t c)
{
	char			*ret;

	ret = (char*)ft_strnew(5);
	if (c <= 127)
		ret[0] = c;
	else if (c <= 2047)
	{
		ret[0] = (192 | (c & 1984) >> 6);
		ret[1] = (128 | (c & 63));
	}
	else if (c <= 65535)
	{
		ret[0] = (224 | (c >> 12));
		ret[1] = (128 | ((c >> 6) & 63));
		ret[2] = (128 | (c & 63));
	}
	else if (c <= 1114111)
	{
		ret[0] = (240 | (c >> 18));
		ret[1] = (128 | ((c >> 12) & 63));
		ret[2] = (128 | ((c >> 6) & 63));
		ret[3] = (128 | (c & 63));
	}
	return (ret);
}

static char			*ftpf_unicode_s(wchar_t *tmp)
{
	char			*ret;
	char			*tmp_b;
	char			*tmp_free;

	ret = ft_strnew(1);
	while (*tmp)
	{
		if ((tmp_b = ftpf_unicode((wint_t)(*tmp))) == NULL)
			return (NULL);
		tmp_free = ret;
		ret = ft_strjoin(ret, tmp_b);
		free(tmp_b);
		free(tmp_free);
		tmp++;
	}
	return (ret);
}

static char			*ftpf_valist_strings_bis(va_list ap)
{
	char			*ret;
	wchar_t			*tmp;

	tmp = (wchar_t*)va_arg(ap, wchar_t*);
	if (tmp != NULL)
	{
		if ((ret = ftpf_unicode_s(tmp)) == NULL)
			return (NULL);
	}
	else
		ret = ftpf_unicode_s(L"(null)");
	return (ret);
}

char				*ftpf_valist_strings(t_data *data, va_list ap)
{
	char			*tmp;
	char			*ret;

	ret = NULL;
	if (data->conv == 'S' || (data->conv == 's' && data->data[10] == 1))
		ret = ftpf_valist_strings_bis(ap);
	else if (data->conv == 's')
	{
		tmp = (char*)va_arg(ap, char*);
		if (tmp != NULL)
			ret = ft_strdup(tmp);
		else
			ret = ft_strdup("(null)");
	}
	return (ret);
}
