/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:34:56 by njooris           #+#    #+#             */
/*   Updated: 2024/11/29 13:05:28 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_recursiv_int(unsigned int i)
{
	unsigned int	nb;

	nb = i;
	if (i >= 16)
	{
		nb = nb % 16;
		if (hex_recursiv_int(i / 16) == -1)
			return (-1);
	}
	if (write(1, &"0123456789abcdef"[nb], 1) == -1)
		return (-1);
	return (0);
}

int	ft_writex(unsigned int m)
{
	int				count;
	unsigned int	i;

	count = 0;
	i = m;
	if (m == 0)
		count++;
	if (hex_recursiv_int(i) == -1)
		return (-1);
	while (i != 0)
	{
		if (i < 16)
			i -= i;
		else
			i = i / 16;
		count++;
	}
	return (count);
}
