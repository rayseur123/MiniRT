/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 10:36:18 by njooris           #+#    #+#             */
/*   Updated: 2025/10/24 13:29:24 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"
#include "libft.h"

int	check_is_digit_str(char *str)
{
	int	i;
	int	count_dot;

	count_dot = 0;
	i = 0;
	if ((str[0] == '-' || str[0] == '+') && ft_strlen(str) > 1)
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			if (str[i] == '.' && count_dot == 0)
				count_dot++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}

static int	check_extension(char *str, char *ext)
{
	const size_t	len = ft_strlen(str);

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
