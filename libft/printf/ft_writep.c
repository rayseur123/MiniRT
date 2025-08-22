/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:32:22 by njooris           #+#    #+#             */
/*   Updated: 2024/11/29 12:59:19 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_recursiv(unsigned long int i)
{
	unsigned int	nb;

	nb = i;
	if (i > 15)
	{
		nb = nb % 16;
		if (hex_recursiv(i / 16) == -1)
			return (-1);
	}
	else if (i <= 15)
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
		if (write(1, &"0123456789abcdef"[nb], 1) == -1)
			return (-1);
		return (0);
	}
	if (write(1, &"0123456789abcdef"[nb], 1) == -1)
		return (-1);
	return (0);
}

int	ft_writep(void	*m)
{
	unsigned long int	i;
	int					count;

	count = 0;
	i = (unsigned long int)m;
	if (!m)
	{
		if (write(1, "(nil)", 5) == -1)
			return (-1);
		return (5);
	}
	if (hex_recursiv(i) == -1)
		return (-1);
	while (i != 0)
	{
		if (i < 16)
			i -= i;
		else
			i = i / 16;
		count++;
	}
	return (count + 2);
}
