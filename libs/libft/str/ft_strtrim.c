/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:34:38 by njooris           #+#    #+#             */
/*   Updated: 2024/11/15 16:12:09 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	set_check(char c, char const *set)
{
	int	x;

	x = 0;
	while (set[x])
	{
		if (set[x] == c)
			return (1);
		x++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	len;

	len = ft_strlen(s1);
	while (len != 0 && set_check(s1[len - 1], set) == 1)
		len--;
	while (set_check(*s1, set) && s1)
	{
		s1++;
		len--;
	}
	return (ft_substr(s1, 0, len));
}
