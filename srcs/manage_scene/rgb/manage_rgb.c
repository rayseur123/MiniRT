/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 09:14:09 by njooris           #+#    #+#             */
/*   Updated: 2025/11/14 15:08:54 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "color.h"
#include "world.h"
#include "libft.h"
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int	random_vector(t_tuple *vector)
{
	static uint32_t	seed;
	int				fd;
	double			x;
	double			y;
	double			z;

	if (!seed)
	{
		fd = open("/dev/urandom", O_RDONLY);
		if (fd == -1)
			return (1);
		if (read(fd, &seed, 4) == -1)
			return (1);
		close(fd);
	}
	x = random_xor(&seed);
	y = random_xor(&seed);
	z = random_xor(&seed);
	*vector = set_vector(x, y, z);
	*vector = tuple_normalization(*vector);
	return (0);
}

t_rgb	indirect_light_maker(t_comp *h, t_world w,
		uint32_t nb_bounce, t_linter *linter)
{
	int		i;
	t_ray	new_ray;
	t_rgb	indirect_color;

	i = 0;
	new_ray.origin = tuple_addition(h->point,
			tuple_multiplication(h->normalv, 0.001));
	indirect_color = set_rgb(0, 0, 0);
	while (i < NB_RAY)
	{
		random_vector(&new_ray.direction);
		if (dot_product(new_ray.direction, h->normalv) < 0)
			new_ray.direction = tuple_negation(new_ray.direction);
		indirect_color = rgb_addition(indirect_color,
				color_at(w, new_ray, nb_bounce - 1, *linter));
		indirect_color = rgb_multiplication(indirect_color,
				h->material.color);
		i++;
	}
	indirect_color = rgb_multiplication_scalar(indirect_color, 1.0 / NB_RAY);
	return (indirect_color);
}

t_rgb	color_at(t_world w, t_ray r, uint32_t nb_bounce, t_linter linter)
{
	t_inter			*h;
	t_rgb			direct_color;
	t_rgb			indirect_light;
	t_comp			comp;

	if (nb_bounce == 0)
		return (set_rgb(0, 0, 0));
	intersect_world(w, r, &linter);
	h = hit(&linter);
	if (!h)
		return (set_rgb (0, 0, 0));
	comp = prepare_computations(h, r);
	direct_color = shade_hit(w, comp, linter);
	indirect_light = indirect_light_maker(&comp, w, nb_bounce, &linter);
	return (rgb_addition(direct_color, indirect_light));
}

int	equals_rgb(t_rgb r1, t_rgb r2)
{
	if (double_is_equal(r1.r, r2.r) && double_is_equal(r1.g, r2.g)
		&& double_is_equal(r1.b, r2.b))
		return (1);
	return (0);
}
