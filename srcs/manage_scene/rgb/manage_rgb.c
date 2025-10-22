/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 09:14:09 by njooris           #+#    #+#             */
/*   Updated: 2025/10/22 09:34:35 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "color.h"
#include "world.h"
#include "mlx.h"
#include "mlx_int.h"
#include "libft.h"
#include <X11/X.h>
#include <stdlib.h>
#include <time.h>

#include <unistd.h>

double double_random(void) // changer le random
{
    static uint64_t seed = 0;
    
    // Initialisation paresseuse au premier appel
    if (seed == 0)
        seed = (uint64_t)&seed ^ (uint64_t)__TIME__[7];
    
    // xorshift64
    seed ^= seed << 13;
    seed ^= seed >> 7;
    seed ^= seed << 17;
    
    return (seed >> 11) * 0x1.0p-53;
}

t_rgb indirect_light_maker(t_inter *h, t_world w, uint32_t nb_bounce)
{
    int     i;
    t_ray   new_ray;
    t_rgb   indirect_color;
    double  lambert;

    i = 0;
    new_ray.origin = tuple_addition(h->point, tuple_multiplication(h->normalv, 0.01));
    indirect_color = set_rgb(0, 0, 0);
    while (i < NB_RAY)
    {
        new_ray.direction = tuple_normalization(set_vector(double_random(), double_random(), double_random()));
        lambert = dot_product(new_ray.direction, h->normalv);
        if (lambert < 0)
		{
			new_ray.direction = tuple_negation(new_ray.direction);
			lambert = -lambert;
		}
		indirect_color = rgb_addition(indirect_color, color_at(w, new_ray, nb_bounce - 1));
        i++;
    }
    indirect_color = rgb_multiplication_scalar(indirect_color, 1.0 / NB_RAY);
    return (indirect_color);
}

t_rgb	color_at(t_world w, t_ray r, uint32_t nb_bounce)
{
	static t_inters	inters;
	t_inter			*h;
	t_rgb			direct_color;
	t_rgb			indirect_light;

	if (!inters.inters)
		inters.inters = malloc((2 * w.nb_obj) * sizeof(t_inter));
	if (nb_bounce == 0)
		return (set_rgb(0, 0, 0));
	intersect_world(w, r, &inters);
	h = hit(&inters);
	if (!h)
		return (set_rgb	(0, 0, 0));
	prepare_computations(h, r);
	direct_color = shade_hit(w, *h);
	indirect_light = set_rgb(0, 0, 0);
	//indirect_light = indirect_light_maker(h, w, nb_bounce);
	return (rgb_addition(direct_color, indirect_light));
}

int	equals_rgb(t_rgb r1, t_rgb r2)
{
	if (double_is_equal(r1.r, r2.r) && double_is_equal(r1.g, r2.g)
		&& double_is_equal(r1.b, r2.b))
		return (1);
	return (0);
}
