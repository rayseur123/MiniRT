/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:41:47 by njooris           #+#    #+#             */
/*   Updated: 2024/11/15 16:10:53 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	size;
	size_t	x;

	x = 0;
	if (ft_strlen(s) < start)
	{
		str = malloc(1);
		if (!str)
			return (NULL);
		return (str[0] = '\0', str);
	}
	size = ft_strlen(&s[start]);
	if (len > size)
		len = size;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s[start], len + 1);
	return (str);
}
