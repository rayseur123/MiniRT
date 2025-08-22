/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:10:45 by njooris           #+#    #+#             */
/*   Updated: 2024/11/07 14:39:39 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	x;

	x = 0;
	if (((((unsigned char *)s1)[x] - ((unsigned char *)s2)[x]) != 0) && n != 0)
		return (((unsigned char *)s1)[x] - ((unsigned char *)s2)[x]);
	while (x < n)
	{
		if ((((unsigned char *)s1)[x] - ((unsigned char *)s2)[x]) != 0)
			return (((unsigned char *)s1)[x] - ((unsigned char *)s2)[x]);
		x++;
	}
	return (0);
}
