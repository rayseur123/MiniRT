/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:20:10 by njooris           #+#    #+#             */
/*   Updated: 2025/01/02 13:22:05 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	search_endl(char *line)
{
	size_t	i;

	if (!line)
		return (0);
	i = 0;
	while (line[i])
	{
		if (line[i] == '\n' && i != 0)
			return (i);
		else if (line[i] == '\n' && i == 0)
			return (1);
		i++;
	}
	return (0);
}

size_t	line_len(char *line)
{
	size_t	i;

	i = 0;
	while (line && line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\n')
		i++;
	return (i);
}

char	*strljoin(char *s1, char *s2, size_t size_s2)
{
	size_t		i;
	size_t		j;
	char		*line;

	i = 0;
	while (s1 && s1[i])
		i++;
	line = malloc(i + size_s2 + 1);
	if (!line)
		return (free(s1), NULL);
	i = 0;
	while (s1 && s1[i])
	{
		line[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && j < size_s2)
		line[i++] = s2[j++];
	line[i] = 0;
	free(s1);
	return (line);
}

char	*buff_manage(char *buff, char *line)
{
	size_t	buff_len;
	size_t	i;

	buff_len = line_len(buff);
	if (buff[0])
		line = strljoin(line, buff, buff_len);
	buff_len = line_len(buff);
	i = 0;
	while (buff && buff[i] && i < BUFFER_SIZE && buff[buff_len])
	{
		buff[i] = buff[buff_len];
		buff_len++;
		i++;
	}
	while (i < BUFFER_SIZE)
	{
		buff[i] = '\0';
		i++;
	}
	return (line);
}

void	reset_buff(char *buff, size_t len)
{
	size_t	i;

	i = 0;
	while (buff && buff[i] && i < BUFFER_SIZE && (BUFFER_SIZE - len) != 0)
	{
		buff[i] = buff[len];
		len++;
		i++;
	}
	while (i < BUFFER_SIZE)
	{
		buff[i] = '\0';
		i++;
	}
}
