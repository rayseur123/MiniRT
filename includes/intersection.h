/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 08:28:17 by dernst            #+#    #+#             */
/*   Updated: 2025/10/24 15:18:53 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_INTERSECTION_H
#define MINIRT_INTERSECTION_H

#include <stdbool.h>
#include "intersection.h"
#include "tuple.h"
#include "matrix.h"
#include "color.h"

typedef struct s_ray	t_ray;

typedef enum e_obj_type
{
	SPHERE,
	PLANE,
	CYLINDER,
}	t_obj_type;

typedef struct s_obj
{
	t_obj_type	type;
	int			id;
	t_matrix4	transform;
	t_matrix4	inverse_transform;
	t_material	material;
	t_ray		*saved_ray;
}	t_obj;

typedef struct s_inter
{
	double			nb_inter;
	t_obj			*obj;
	double			range;
	t_tuple			point;
	t_tuple			eyev;
	t_tuple			normalv;
	bool			inside;
}	t_inter;


typedef struct s_inters
{
	uint32_t	count;
	t_inter		*inters;
} t_inters;

typedef struct s_ray
{
	t_tuple origin;
	t_tuple direction;
}	t_ray;

t_ray			set_ray(t_tuple point, t_tuple vector);
t_tuple			position(t_ray ray, double range);
t_inter			set_intersection(double t, t_obj *obj);
int				set_intersections(t_inters *inters, t_inter inter1, t_inter inter2);
t_inter			*hit(t_inters *inters);
t_ray			transform(t_ray ray, t_matrix4 m);
void			intersect(t_ray r, t_obj *o, t_inters *xs);
t_tuple			normal_at(t_obj s, t_tuple p);
t_tuple			reflect(t_tuple	v, t_tuple n);

#endif