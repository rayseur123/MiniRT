/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 10:36:18 by njooris           #+#    #+#             */
/*   Updated: 2025/11/13 13:37:13 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_error.h"
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
				return (print_error(BAD_FORMAT_ERROR));
		}
		i++;
	}
	return (0);
}

static int	check_extension(char *str, char *ext)
{
	const size_t	len = ft_strlen(str);

	if (len <= 3)
		return (print_error(FILE_NAME_ERROR));
	return (ft_strncmp(&str[len - 3], ext, 3));
}

int	open_rt_file(char *str)
{
	if (check_extension(str, EXTENSION))
		return (-2);
	return (open(str, O_RDONLY));
}
