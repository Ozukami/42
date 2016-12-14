/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 07:09:07 by apoisson          #+#    #+#             */
/*   Updated: 2016/12/14 15:38:25 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_new_init(t_conv *new)
{
	new->space = 0;
	new->prefix = 0;
	new->zero = 0;
	new->left = 0;
	new->sign = 0;
	new->field = -1;
	new->p = -1;
	new->mod = NULL;
	new->next = NULL;
}

t_conv	*ft_new_conv(char *s)
{
	t_conv	*new;
	int		i;
	size_t	len;

	i = 0;
	if (!(new = malloc(sizeof(t_conv))))
		return (NULL);
	ft_new_init(new);
	while (s[i])
	{
		len = 0;
		while (s[i] == ' ')
		{
			new->space = 1;
			i++;
		}
		ft_get_flags(new, s, &i);
		ft_get_field_prec(new, s, &i);
		ft_get_mod(new, s, &i);
		new->type = s[i];
		i++;
	}
	return (new);
}

void	ft_add_conv(t_conv *new, t_conv **list)
{
	t_conv	*begin;

	begin = *list;
	if (!(*list))
	{
		*list = new;
		return ;
	}
	while ((*list)->next)
		*list = (*list)->next;
	(*list)->next = new;
	*list = begin;
}
