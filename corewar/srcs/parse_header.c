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

#include "asm.h"
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

int		get_name2(t_champ *champ, char *line, int verif)
{
	int			i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == '\"')
		{
		}
	}
	if (verif == 6)
		ft_perror("Error: too many .comment");
	if (ft_strlen(line) > COMMENT_LENGTH)
		ft_perror("Error: comment is too large");
	return (3);
}

int		get_comment2(t_champ *champ, char *line, int verif)
{
	int			i;

	i = -1;
	if (verif == 6)
		ft_perror("Error: too many .comment");
	if (ft_strlen(line) > COMMENT_LENGTH)
		ft_perror("Error: comment is too large");
	return (3);
}

void	check_error(char **split)
{
	if (!ft_strequ(str_epurf(split[0]), COMMENT_CMD_STRING) ||
			!ft_strequ(str_epurf(split[0], NAME_CMD_STRING)))
		ft_perror("Error: Name or Comment not well formated");
	
}

int		check_header(t_champ *champ, char *line, char *line_epur)
{
	static int	verif = 0;
	char		**split;

	if (!line || !line_epurf)
		return (0);
	if (line_epur[0] == COMMENT_CHAR || line_epur[0] == ';')
		return (0);
	split = ft_strsplit(line_epur, '\"');
	check_error(split);
	else if (verif != 4)
		ft_perror("Error: lexical error 3");
	return (0);
}

int		check_headeri2(t_champ *champ, char *line, char *line_epur)
{
	static int	verif = 0;

	if (!line || !line_epur)
		return (0);
	if (line_epur[0] == COMMENT_CHAR || line_epurf[0] == ';')
		return (0);
	if (line_epur[0] == '.')
	{
		if (ft_strequf_l(ft_strsub(line_epur, 0, 8), COMMENT_CMD_STRING))
		//	return (get_comment(champ, ft_strsplitf(line, '\"'), verif += 3));
			return (get_comment2(champ, line, verif += 3));
		else if (ft_strequf_l(ft_strsub(line_epur, 0, 5), NAME_CMD_STRING))
		//	return (get_name(champ, ft_strsplitf(line, '\"'), verif += 1));
			return (get_name2(champ, line, verif += 1));
		else
			ft_perror("Error: lexical error 2");
	}
	else if (verif != 4)
		ft_perror("Error: lexical error 3");
	return (0);
}
