/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:40:11 by njooris           #+#    #+#             */
/*   Updated: 2024/11/29 13:07:19 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	choose_write(char c, va_list args)
{
	int	len;

	if (args == NULL)
		return (0);
	if (c == 'c')
		len = ft_writec((char)va_arg(args, int));
	if (c == 's')
		len = ft_writes(va_arg(args, char *));
	if (c == 'p')
		len = ft_writep(va_arg(args, void *));
	if (c == 'd' || c == 'i')
		len = write_iota(va_arg(args, int));
	if (c == 'u')
		len = write_uiota(va_arg(args, unsigned int));
	if (c == 'x')
		len = ft_writex(va_arg(args, unsigned int));
	if (c == 'X')
		len = ft_upwritex(va_arg(args, unsigned int));
	if (c == '%')
		len = ft_writec('%');
	if (len == -1)
		return (-1);
	return (len);
}

int	write_char(const char *str, va_list args)
{
	int	i;
	int	len;
	int	check;

	i = -1;
	len = 0;
	check = 0;
	while (str[++i])
	{
		if (str[i] != '%')
			write(1, &str[i], 1);
		if (str[i] == '%' && str[i + 1])
		{
			len--;
			check = choose_write(str[i + 1], args);
			if (check == -1)
				return (-1);
			len += check;
			i++;
		}
		if (str[i] == '%' && !str[i + 1] && str[i -1] != '%')
			len--;
		len++;
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;

	if (!str)
		return (-1);
	len = 0;
	va_start(args, str);
	len = write_char(str, args);
	if (len == -1)
		return (-1);
	va_end(args);
	return (len);
}
