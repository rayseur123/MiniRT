/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:04:13 by njooris           #+#    #+#             */
/*   Updated: 2024/12/10 13:28:54 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(size_t fd)
{
	static char		buff[BUFFER_SIZE];
	char			*line;
	ssize_t			size_read;
	size_t			len;

	size_read = BUFFER_SIZE;
	line = NULL;
	line = buff_manage(buff, line);
	while (!search_endl(line) && size_read == BUFFER_SIZE && size_read != 0)
	{
		size_read = read(fd, buff, BUFFER_SIZE);
		if (size_read == -1 || (size_read == 0 && !line))
			return (free(line), NULL);
		len = line_len(buff);
		if (size_read != 0)
			line = strljoin(line, buff, len);
		reset_buff(buff, len);
		if (!line)
			return (NULL);
	}
	return (line);
}
