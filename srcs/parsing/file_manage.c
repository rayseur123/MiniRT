/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 10:36:18 by njooris           #+#    #+#             */
/*   Updated: 2025/10/15 15:59:44 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"

int	check_extension(char *str, char *ext)
{
	const int	len = ft_strlen(str);

	if (len <= 3)
		return (1);
	return (ft_strncmp(&str[len - 3], ext, 3));
}

int	open_rt_file(char *str)
{
	if (check_extension(str, EXTENSION))
		return (-1);
	return (open(str, O_RDONLY));
}
