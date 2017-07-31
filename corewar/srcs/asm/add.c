/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 06:42:54 by apoisson          #+#    #+#             */
/*   Updated: 2017/06/16 06:42:58 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "sys/types.h"

void	add_label(t_champ *champ, char *str, int id)
{
	t_label_list	*label;

	if (!(label = ft_memalloc(sizeof(t_label_list))))
		ft_perror("Error: malloc failed");
	label->label = ft_strdup(str);
	label->next = L_LABEL;
	label->id = id;
	L_LABEL = label;
}

void	add_labcheck(t_champ *champ, char *str)
{
	t_label_list	*label;
	int				i;

	if (!(label = ft_memalloc(sizeof(t_label_list))))
		ft_perror("Error: malloc failed");
	i = (str[0] == DIRECT_CHAR) ? 2 : 1;
	label->label = ft_strsub(str, i, ft_strlen(str) - i);
	label->next = L_LABCHECK;
	L_LABCHECK = label;
}
