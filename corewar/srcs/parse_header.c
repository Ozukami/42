/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 06:30:33 by apoisson          #+#    #+#             */
/*   Updated: 2017/06/16 06:30:47 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "sys/types.h"

int		get_name(t_champ *champ, char **split, int verif)
{
	if (!split[1])
	{
		(HEADER->prog_name)[0] = '\0';
		free_map(split);
		return (1);
	}
	if (split[2])
		ft_perror("Error: lexical error 1");
	if (verif == 2)
		ft_perror("Error: too many .name");
	if (ft_strlen(split[1]) > PROG_NAME_LENGTH)
		ft_perror("Error: name is too large");
	ft_strcpy(HEADER->prog_name, split[1]);
	free_map(split);
	return (1);
}

int		get_comment(t_champ *champ, char **split, int verif)
{
	if (!split[1])
	{
		(HEADER->comment)[0] = '\0';
		free_map(split);
		return (3);
	}
	if (split[2])
		ft_perror("Error: lexical error ici");
	if (verif == 6)
		ft_perror("Error: too many .comment");
	if (ft_strlen(split[1]) > COMMENT_LENGTH)
		ft_perror("Error: comment is too large");
	ft_strcpy(HEADER->comment, split[1]);
	free_map(split);
	return (3);
}

int		check_header(t_champ *champ, char *line)
{
	static int	verif = 0;

	if (!line)
		return (0);
	if (line[0] == COMMENT_CHAR || line[0] == ';')
		return (0);
	if (line[0] == '.')
	{
		if (ft_strequf_l(ft_strsub(line, 0, 8), COMMENT_CMD_STRING))
			return (get_comment(champ, ft_strsplitf(line, '\"'), verif += 3));
		else if (ft_strequf_l(ft_strsub(line, 0, 5), NAME_CMD_STRING))
			return (get_name(champ, ft_strsplitf(line, '\"'), verif += 1));
		else
			ft_perror("Error: lexical error 2");
	}
	else if (verif != 4)
		ft_perror("Error: lexical error 3");
	return (0);
}
