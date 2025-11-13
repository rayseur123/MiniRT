/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 08:28:59 by dernst            #+#    #+#             */
/*   Updated: 2025/11/13 13:13:57 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "color.h"
# include "tuple.h"
# include <stdbool.h>
# include <math.h>

typedef struct s_light
{
	t_rgb	intensity;
	t_tuple	position;
}	t_light;

typedef struct s_lighting
{
	t_material	mat;
	t_light		light;
	t_tuple		eyev;
}	t_lighting;

t_material	material(void);
t_light		point_light(t_tuple	position, t_rgb inte);
t_rgb		lighting(t_lighting l, t_tuple point, t_tuple normalv,
				bool is_shadowed);
t_rgb		cal_ambient(t_rgb *ef_color, t_light l, t_material mat);
t_rgb		cal_spec(t_material mat, double reflect_dot_eye, t_light l);
t_rgb		cal_diffuse(const t_rgb ef_color, const double light,
				t_material mat);

double		random_xor(uint32_t *seed);

#endif
