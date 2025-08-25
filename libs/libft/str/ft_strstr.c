/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 14:16:36 by njooris           #+#    #+#             */
/*   Updated: 2025/08/25 14:21:07 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *big, char *little)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	if (!big || !little)
		return (NULL);
	if (ft_strlen(little) > ft_strlen(big))
		return (NULL);
	while (big && big[i])
	{
		j = 0;
		k = i;
		while (big[i] == little[j])
			j++;
		if (little[j] == '\0')
			return (&big[k]);
		i++;
	}
	return (NULL);
}
