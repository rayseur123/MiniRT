/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:33:56 by njooris           #+#    #+#             */
/*   Updated: 2024/11/18 11:25:56 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_convert_nba(char *str, int count, long int nb, int negativ)

{
	int	x;

	x = 0;
	str[count + 1] = '\0';
	while (nb > 9)
	{
		str[count] = ((nb % 10) + '0');
		nb /= 10;
		count--;
	}
	str[count] = nb + '0';
	if (negativ < 0)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	int				count;
	int				negativ;
	long int		n2;
	long int		nb;
	char			*str;

	count = 0;
	negativ = 1;
	n2 = n;
	if (n2 < 0)
	{
		count++;
		negativ = -1;
		n2 *= negativ;
	}
	nb = n2;
	while (nb > 9)
	{
		count++;
		nb /= 10;
	}
	str = malloc((count + 2) * sizeof(char));
	if (!str)
		return (NULL);
	return (ft_convert_nba(str, count, n2, negativ));
}
