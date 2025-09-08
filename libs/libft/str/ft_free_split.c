/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 14:47:28 by njooris           #+#    #+#             */
/*   Updated: 2025/09/02 14:52:09 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_free_split(char **split)
{
	unsigned int	i;
	char			*temp;

	i = 0;
	temp = NULL;
	if (split)
	{
		while (split[i])
		{
			temp = split[i];
			free(temp);
			i++;
		}
		free(split);
	}
	return (1);
}