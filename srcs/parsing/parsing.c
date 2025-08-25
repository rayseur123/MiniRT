/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 14:10:57 by njooris           #+#    #+#             */
/*   Updated: 2025/08/25 15:09:40 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_extension(char *str, char *extension)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (!str || !extension)
		return (1);
	while (str[i])
		i++;
	while (extension[j])
		j++;
	while (i > 0 && j > 0 && extension[j] == str[i])
	{
		j--;
		i--;
	}
	if (j == 0)
		return (0);
	return (1);
}

int	check_name_rt_file(char *str)
{
	int	i;
	
	i = 0;
	if (!str || ft_strlen(str) <= 3)
		return (1);
	return (check_extension(str, ".rt"));
}

