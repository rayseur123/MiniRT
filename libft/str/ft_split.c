/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:51:12 by njooris           #+#    #+#             */
/*   Updated: 2024/11/18 11:03:11 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	count_str(char const *str, char c)
{
	int	x;
	int	count;

	x = 0;
	count = 0;
	while (str[x] != '\0')
	{
		while (str[x] == c && str[x])
			x++;
		if (str[x] != c && str[x] != '\0')
			count++;
		while (str[x] != c && str[x])
			x++;
	}
	return (count);
}

int	count_fd(char const *str, char c, int *size)
{
	int	count;

	count = 0;
	while (str[count] != c && str[count])
		count++;
	*size = count;
	return (count);
}

char	**free_str(char **str, int start)
{
	while (start >= 0)
	{
		free(str[start]);
		start--;
	}
	free(str);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		x;
	char	**split;
	int		size;
	int		z;

	z = 0;
	x = 0;
	split = ft_calloc((count_str(s, c) + 1), sizeof (char *));
	if (!split)
		return (NULL);
	while (s[x])
	{
		while (s[x] == c && s[x])
			x++;
		if (s[x] != c && s[x] && count_fd(&s[x], c, &size))
		{
			split[z] = malloc(size + 1);
			if (!split[z])
				return (free_str(split, z - 1));
			ft_strlcpy(split[z], &s[x], size + 1);
			x += size;
			z++;
		}
	}
	return (split);
}
