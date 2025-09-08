/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:35:29 by njooris           #+#    #+#             */
/*   Updated: 2025/09/02 14:40:22 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	parse_integer_part(char *str, int *i)
{
	double	result;

	result = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		result = result * 10 + (str[*i] - '0');
		(*i)++;
	}
	return (result);
}

double	parse_fractional_part(char *str, int *i)
{
	double	result;
	double	divisor;

	result = 0;
	divisor = 1;
	if (str[*i] == '.' || str[*i] == ',')
	{
		(*i)++;
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			divisor *= 10;
			result = result + (str[*i] - '0') / divisor;
			(*i)++;
		}
	}
	return (result);
}

double	ft_atod(char *str)
{
	double	result;
	int			sign;
	int			i;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	result = parse_integer_part(str, &i);
	result += parse_fractional_part(str, &i);
	return (result * sign);
}
