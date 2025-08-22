/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:13:11 by njooris           #+#    #+#             */
/*   Updated: 2024/11/18 10:45:49 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*buff;

	if (nmemb != 0)
		if ((2147483647 / nmemb) < size)
			return (NULL);
	buff = malloc(nmemb * size);
	if (!buff)
		return (NULL);
	ft_bzero(buff, size * nmemb);
	return (buff);
}
