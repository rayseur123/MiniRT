/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upwritex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:36:40 by njooris           #+#    #+#             */
/*   Updated: 2024/11/29 12:59:47 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	uphex_recursiv_int(unsigned int i)
{
	unsigned int	nb;

	nb = i;
	if (i >= 16)
	{
		nb = nb % 16;
		if (uphex_recursiv_int(i / 16) == -1)
			return (-1);
	}
	if (write(1, &"0123456789ABCDEF"[nb], 1) == -1)
		return (-1);
	return (0);
}

int	ft_upwritex(unsigned int m)
{
	int				count;
	unsigned int	i;

	count = 0;
	i = m;
	if (m == 0)
		count++;
	if (uphex_recursiv_int(i) == -1)
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
