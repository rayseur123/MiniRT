/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:05:58 by njooris           #+#    #+#             */
/*   Updated: 2025/10/28 13:15:41 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(size_t fd);
size_t	search_endl(char *line);
size_t	line_len(char *line);
char	*strljoin(char *s1, char *s2, size_t size_s2);
char	*buff_manage(char *buff, char *line);
void	reset_buff(char *buff, size_t len);

#endif
