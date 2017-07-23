/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurse.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 00:13:56 by lcharbon          #+#    #+#             */
/*   Updated: 2017/07/22 21:44:45 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NCURSE_H
# define NCURSE_H
# include "libft.h"
# include <ncurses.h>
# include <curses.h>

typedef struct			s_ncup
{
	int					id;
	int					ll;
	int					licp;
	char				*s;
	char				*comm;
}						t_ncup;

typedef struct			s_gb
{
	int					state;
	int					cycle_sec;
	int					process;
	int					cycle_to_die;
	int					cycle_delta;
	int					nbr_live;
	int					max_checks;
	int					n_players;
	struct s_ncup		player[4];
}						t_gb;

void					ftncu_print_info(t_gb *g);
void					ftncu_init_pair(void);

#endif