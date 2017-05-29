/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumaujea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 03:21:32 by qumaujea          #+#    #+#             */
/*   Updated: 2017/05/29 03:30:23 by qumaujea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

typedef struct s_instruction	t_instruction;

struct				s_instruction
{
	char			*label;
	int				op;
	char			**args;
	t_instruction	*next;
};

#endif
