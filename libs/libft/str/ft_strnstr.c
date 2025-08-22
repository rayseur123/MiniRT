/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:42:37 by njooris           #+#    #+#             */
/*   Updated: 2024/11/18 11:18:11 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	x;
	size_t	y;
	size_t	z;

	x = 0;
	y = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (big[x] && (len > x))
	{
		z = x;
		if (big[x] == little[y])
		{
			while (big[z] == little[y] && (len > z))
			{
				if (little[y + 1] == '\0')
					return ((char *)big + x);
				z++;
				y++;
			}
			y = 0;
		}
		x++;
	}
	return (NULL);
}
