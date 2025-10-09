/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 08:27:15 by dernst            #+#    #+#             */
/*   Updated: 2025/10/09 12:17:40 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_COLOR_H
#define MINIRT_COLOR_H

typedef struct s_rgb
{
	double r;
	double g;
	double b;
} t_rgb;

typedef struct s_material
{
	t_rgb	color;
	double	ambient;
	double	diffuse;
	double	spec;
	double	shininess;
}	t_material;

t_rgb	set_rgb(double r, double g, double b);
t_rgb	rgb_addition(t_rgb r1, t_rgb r2);
t_rgb	rgb_subtraction(t_rgb r1, t_rgb r2);
t_rgb	rgb_multiplication_scalar(t_rgb r1, double scale);
t_rgb	rgb_multiplication(t_rgb r1, t_rgb r2);
int		equals_rgb(t_rgb r1, t_rgb r2);

#endif
