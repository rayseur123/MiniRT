/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writeunb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:42:30 by njooris           #+#    #+#             */
/*   Updated: 2024/11/29 13:03:01 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_convert_unba(char *str, int count, unsigned long int nb)

{
	unsigned long int	x;

	x = 0;
	str[count + 1] = '\0';
	while (nb > 9)
	{
		str[count] = ((nb % 10) + '0');
		nb /= 10;
		count--;
	}
	str[count] = nb + '0';
	return (str);
}

char	*ft_uitoa(unsigned long int n)
{
	int					count;
	unsigned long int	n2;
	unsigned long int	nb;
	char				*str;

	count = 0;
	n2 = n;
	nb = n2;
	while (nb > 9)
	{
		count++;
		nb /= 10;
	}
	str = malloc((count + 2) * sizeof(char));
	if (!str)
		return (NULL);
	return (ft_convert_unba(str, count, n2));
}

int	write_uiota(unsigned int nb)
{
	int					len;
	char				*str;
	unsigned long int	nb2;

	nb2 = nb;
	str = ft_uitoa(nb2);
	if (!str)
		return (-1);
	len = ft_strlen(str);
	if (write(1, str, len) == -1)
		return (-1);
	free(str);
	return (len);
}
