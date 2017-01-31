/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 07:09:07 by apoisson          #+#    #+#             */
/*   Updated: 2017/01/31 12:48:35 by apoisson         ###   ########.fr       */
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
	new->point = 0;
}

void	ft_adjust(t_conv *new)
{
	if (new->type == 'C'
			|| new->type == 'S' || new->type == 'D'
			|| new->type == 'O' || new->type == 'U')
	{
		new->type += 32;
		new->mod = "l";
	}
	if (new->type == 'i')
		new->type = 'd';
	if (new->type == 'p')
	{
		new->type = 'x';
		new->prefix = 1;
		new->mod = "ll";
	}
	if (new->left)
		new->zero = 0;
	if (new->sign)
		new->space = 0;
}

t_conv	*ft_new_conv(char *s)
{
	t_conv	*new;
	int		i;

	i = 0;
	if (!(new = malloc(sizeof(t_conv))))
		return (NULL);
	ft_new_init(new);
	while (s[i])
	{
		while (s[i] == ' ')
		{
			new->space = 1;
			i++;
		}
		ft_get_flags(new, s, &i);
		ft_get_field_prec(new, s, &i);
		ft_get_mod(new, s, &i);
		new->type = s[i];
		ft_adjust(new);
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
