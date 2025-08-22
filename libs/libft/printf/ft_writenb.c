/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writenb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:41:55 by njooris           #+#    #+#             */
/*   Updated: 2024/11/29 12:44:29 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_iota(int nb)
{
	char	*str;
	int		len;

	len = 0;
	str = ft_itoa(nb);
	len = ft_strlen(str);
	if (write(1, str, len) == -1)
		len = -1;
	free(str);
	return (len);
}
