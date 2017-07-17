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

int		get_name(t_champ *champ, char *line, int verif)
{
	char	**split;
	char	*name;

	if (verif == 2)
		ft_perror("Error: too many .name");
	split = ft_strsplit(line, '\"');
	name = ft_strdup(split[1]);
	if (ft_strlen(name) <= PROG_NAME_LENGTH)
		ft_strcpy(HEADER->prog_name, name);
	else
		ft_perror("Error: Name is too large");
	free_map(split);
	ft_strdel(&name);
	return (1);
}

int		get_comment(t_champ *champ, char *line, int verif)
{
	char	**split;
	char	*comment;

	if (verif == 6)
		ft_perror("Error: too many .comment");
	split = ft_strsplit(line, '\"');
	comment = ft_strdup(split[1]);
	if (ft_strlen(comment) <= COMMENT_LENGTH)
		ft_strcpy(HEADER->comment, comment);
	else
		ft_perror("Error: comment is too large");
	free_map(split);
	ft_strdel(&comment);
	return (3);
}

void	check_error(char **split, char *line)
{
	int		i;
	int		check;

	if (!ft_strequ(str_epur(split[0]), COMMENT_CMD_STRING) &&
			!ft_strequ(str_epur(split[0]), NAME_CMD_STRING))
		ft_perror("1Error: Name or Comment not well formated");
	if (split[2])
		if (!(str_epur(split[2])) || ((str_epur(split[2]))[0] != COMMENT_CHAR
				&& (str_epur(split[2]))[0] != ';'))
			ft_perror("Error: Name or Comment not well formated");	
	i = -1;
	check = 0;
	while (line[++i] != COMMENT_CHAR && line[i] != ';' && line[i] != '\0')
		if (line[i] == '\"')
			check++;
	if (check > 2)
		ft_perror("Error: Name or Comment not well formated");	
	free_map(split);
}

int		check_header(t_champ *champ, char *line, char *line_epur)
{
	static int	verif = 0;
	char		**split;

	if (!line || !line_epur)
		return (0);
	if (line_epur[0] == COMMENT_CHAR || line_epur[0] == ';')
		return (0);
	split = ft_strsplit(line_epur, '\"');
	check_error(split, line);
	if (ft_strequf_l(ft_strsub(line_epur, 0, 8), COMMENT_CMD_STRING))
		return (get_comment(champ, line, verif += 3));
	else if (ft_strequf_l(ft_strsub(line_epur, 0, 5), NAME_CMD_STRING))
		return (get_name(champ, line, verif += 1));
	else
		ft_perror("Error: lexical error 2");
	if (verif != 4)
		ft_perror("Error: lexical error 3");
	return (0);
}
