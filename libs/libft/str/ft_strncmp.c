/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:18:38 by njooris           #+#    #+#             */
/*   Updated: 2024/11/18 11:17:36 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	x;

	x = 0;
	if (((s1[x] - s2[x]) != 0) && n != 0)
		return (((unsigned char)s1[x]) - ((unsigned char)s2[x]));
	while ((s1[x] || s2[x]) && (x < n))
	{
		if ((s1[x] - s2[x]) != 0)
			return (((unsigned char)s1[x]) - ((unsigned char)s2[x]));
		x++;
	}
	return (0);
}
