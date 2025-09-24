//
// Created by dernst on 9/24/25.
//

#include "../includes/scene.h"
#include "../includes/devan.h"

t_projectile tick(const t_environment env, const t_projectile proj)
{
	t_projectile new;

	new.position = add_tuple(proj.position,proj.velocity);
	new.velocity = add_tuple(proj.velocity, env.gravity);
	new.velocity = add_tuple(new.velocity, env.wind);
	return (new);
}

t_rgb	add_color(const t_rgb color1, const t_rgb color2) {
	t_rgb new;

	new.r = color1.r + color2.r;
	new.g = color1.g + color2.g;
	new.b = color1.b + color2.b;
	return (new);
}

t_rgb	sub_color(const t_rgb color1, const t_rgb color2) {
	t_rgb new;

	new.r = color1.r - color2.r;
	new.g = color1.g - color2.g;
	new.b = color1.b - color2.b;
	return (new);
}

t_rgb	mul_color(const t_rgb color1, const int scale) {
	t_rgb new;

	new.r = color1.r * scale;
	new.g = color1.g * scale;
	new.b = color1.b * scale;
	return (new);
}

t_rgb	hadamard_product(const t_rgb c1, const t_rgb c2) {
	t_rgb new;

	new.r = c1.r * c2.r;
	new.g = c1.g * c2.g;
	new.b = c1.b * c2.b;
	return (new);
}




