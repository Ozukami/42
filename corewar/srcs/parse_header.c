/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 06:30:33 by apoisson          #+#    #+#             */
/*   Updated: 2017/06/17 08:28:59 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "sys/types.h"

char	*epur_com(char *str)
{
	char	*epur;
	char	**split;

	if (str[0] == '\"' && !(str[1]))
		return (ft_strdup("\0"));
	split = ft_strsplit(str, '\"');
	epur = NULL;
	if (split[1])
	{
		epur = str_epur(split[1]);
		if (epur)
			if (epur[0] != '#')
				ft_perror("Error: lexical error");
		ft_strdel(&epur);
	}
	epur = ft_strdup(split[0]);
	ft_strdel(&(split[0]));
	free(split);
	return (ft_straddchar(epur, '\"'));
}

// 1 = com, 0 = name
void	test(t_champ *champ, char *line, int type, int i)
{
	(type) ? ft_strcpy(HEADER->comment, line) :
		ft_strcpy(HEADER->prog_name, line);
	ft_strdel(&line);
	while (get_next_line(FD, &line) > 0)
	{
		i = -1;
		while (line[++i])
		{
			if (line[i] == '\"') // && !line[i + 1])
			{
				line = (type) ? ft_strjoinf_r(HEADER->comment, epur_com(line))
					: ft_strjoinf_r(HEADER->prog_name, epur_com(line));
				(type) ? ft_strncpy(HEADER->comment, line, ft_strlen(line) - 1)
					: ft_strncpy(HEADER->prog_name, line, ft_strlen(line) - 1);
				ft_strdel(&line);
				return ;
			}
			else if (line[i] == '\"' && line[i + 1])
				ft_perror("Error: lexical error");
		}
		line = ft_straddchar(line, 0x0a);
		line = (type) ? ft_strjoinf_r(HEADER->comment, line)
			: ft_strjoinf_r(HEADER->prog_name, line);
		(type) ? ft_strcpy(HEADER->comment, line) :
			ft_strcpy(HEADER->prog_name, line);
		ft_strdel(&line);
	}
}

int		get_name(t_champ *champ, char **split, int verif, int i)
{
	char	*line;

	if (verif == 6)
		ft_perror("Error: too many .name");
	if (ft_strlen(split[1]) > PROG_NAME_LENGTH)
		ft_perror("Error: name is too large");
	if (i == 1)
	{
		if (!split[1])
			line = ft_strdup("\n");
		else
			line = ft_straddchar(split[1], 0x0a);
		test(champ, line, 0, 0);
		if (ft_strlen(HEADER->prog_name) > PROG_NAME_LENGTH)
			ft_perror("Error: name is too large");
		return (1);
	}
	if (!split[1])
	{
		(HEADER->prog_name)[0] = '\0';
		free_map(split);
		if (ft_strlen(HEADER->prog_name) > PROG_NAME_LENGTH)
			ft_perror("Error: name is too large");
		return (1);
	}
	ft_strcpy(HEADER->prog_name, split[1]);
	free_map(split);
	return (1);
}

int		get_comment(t_champ *champ, char **split, int verif, int i)
{
	char	*line;

	if (verif == 6)
		ft_perror("Error: too many .comment");
	if (ft_strlen(split[1]) > COMMENT_LENGTH)
		ft_perror("Error: comment is too large");
	if (i == 1)
	{
		if (!split[1])
			line = ft_strdup("\n");
		else
			line = ft_straddchar(split[1], 0x0a);
		test(champ, line, 1, 0);
		if (ft_strlen(HEADER->comment) > COMMENT_LENGTH)
			ft_perror("Error: comment is too large");
		return (3);
	}
	if (!split[1])
	{
		(HEADER->comment)[0] = '\0';
		free_map(split);
		if (ft_strlen(HEADER->comment) > COMMENT_LENGTH)
			ft_perror("Error: comment is too large");
		return (3);
	}
	ft_strcpy(HEADER->comment, split[1]);
	free_map(split);
	return (3);
}

// leaks ?
int		check_header(t_champ *champ, char *line)
{
	static int	verif = 0;
	char		*back_up;
	char		**split;
	int			i;
	int			j;

	back_up = ft_strdup(line);
	line = str_epur(line);
	if (!line || line[0] == COMMENT_CHAR || line[0] == ';')
		return (0);
	split = ft_strsplit(line, '\"');
	split[0] = str_epur(split[0]);
	if (line[0] == '.')
	{
		if (ft_strequ(split[0], COMMENT_CMD_STRING))
		{
			j = 0;
			i = 0;
			while (line[++j])
				if (line[j] == '\"')
					i++;
			free_map(split);
			ft_strdel(&line);
			return (get_comment(champ, ft_strsplitf(back_up, '\"'),
						verif += 3, i));
		}
		else if (ft_strequ(split[0], NAME_CMD_STRING))
		{
			j = 0;
			i = 0;
			while (line[++j])
				if (line[j] == '\"')
					i++;
			free_map(split);
			ft_strdel(&line);
			return (get_name(champ, ft_strsplitf(back_up, '\"'), verif += 1, i));
		}
		else
			ft_perror("Error: lexical error 2");
	}
	else if (verif != 4)
		ft_perror("Error: lexical error 3");
	return (0);
}
