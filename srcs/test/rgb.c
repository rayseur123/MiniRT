/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 12:30:07 by njooris           #+#    #+#             */
/*   Updated: 2025/10/09 10:26:32 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include <math.h>

int	test_set_rgb(void)
{
	t_rgb   rgb;

    rgb = set_rgb(1, 1, 1);
	if (rgb.r != 1 || rgb.g != 1 || rgb.b != 1)
		return (1);
	return (0);
}

int test_rgb_addition(void)
{
    t_rgb   rgb;

    rgb = rgb_addition(set_rgb(1, 1, 1), set_rgb(1, 1, 1));
    if (rgb.r != 2 || rgb.g != 2 || rgb.b != 2)
		return (1);
    return (0);
}

int test_rgb_subtraction(void)
{
    t_rgb   rgb;

    rgb = rgb_subtraction(set_rgb(1, 1, 1), set_rgb(1, 1, 1));
    if (rgb.r != 0 || rgb.g != 0 || rgb.b != 0)
		return (1);
    return (0);
}

int test_rgb_multiplication_scalar(void)
{
    t_rgb	rgb;

	rgb = rgb_multiplication_scalar(set_rgb(1, 1, 1), 2);
	if (rgb.r != 2 || rgb.g != 2 || rgb.b != 2)
		return (1);
	return (0);
}

int test_rgb_multiplication(void)
{
    t_rgb	rgb;

	rgb = rgb_multiplication(set_rgb(1, 1, 1), set_rgb(2, 2, 2));
	if (rgb.r != 2 || rgb.g != 2 || rgb.b != 2)
		return (1);
	return (0);
}