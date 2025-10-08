/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 14:35:29 by njooris           #+#    #+#             */
/*   Updated: 2025/10/08 11:48:29 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft.h"
#include "mlx.h"
#include "mlx_int.h"
#include <stdint.h>
#include <X11/X.h>
#include <stdbool.h>

#ifndef STRUCT_OBJS_H
#define STRUCT_OBJS_H

#define EPSILON 0.00001
#define WIDTH_CANVA 500
#define HEIGHT_CANVA 500
#define WALL_SIZE 10.00
#define IDENTITY_MTRX {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}}
typedef double t_matrix4[4][4];
typedef double (*t_matrix4_ptr)[4];
typedef double t_matrix3[3][3];
typedef double (*t_matrix3_ptr)[3];
typedef double t_matrix2[2][2];
typedef double (*t_matrix2_ptr)[2];

typedef enum e_obj_type
{
	SPHERE,
	PLANE,
	CYLINDER,
}	t_obj_type;

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

typedef struct s_obj
{
	t_obj_type	type;
	int			id;
	t_matrix4	transform;
	t_matrix4	reverse_transform;
	t_material	material;
}	t_obj;

typedef struct s_canvas
{
	uint32_t width;
	uint32_t height;
	void *mlx;
	void *window;
	void *canva;
} t_canvas;

typedef struct s_tuple
{
	double x;
	double y;
	double z;
	uint8_t w;
} t_tuple;

typedef struct s_inter
{
	double			nb_inter;
	t_obj			*obj;
	double			range;
	uint32_t		index;
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

typedef struct s_projectile
{
	t_tuple position;
	t_tuple velocity;
} t_projectile;

typedef struct s_environment
{
	t_tuple gravity;
	t_tuple wind;
} t_environment;

typedef struct s_ray
{
	t_tuple origin;
	t_tuple direction;
}	t_ray;

typedef struct s_light
{
	t_rgb	intensity;
	t_tuple	position;
}	t_light;

typedef struct s_world
{
	uint32_t	nb_obj;
	uint32_t	nb_light;
	t_obj		*obj;
	t_light		*light;
}	t_world;

t_tuple set_vector(double x, double y, double z);
t_tuple set_point(double x, double y, double z);

int double_is_equal(double x, double y);
int check_equal_tuples(t_tuple tuple1, t_tuple tuple2);
t_tuple tuple_addition(t_tuple tuple1, t_tuple tuple2);
t_tuple tuple_subtraction(t_tuple tuple1, t_tuple tuple2);
t_tuple tuple_negation(t_tuple tuple);
t_tuple tuple_multiplication(t_tuple tuple1, double scale);
t_tuple tuple_division(t_tuple tuple1, double scale);
double	tuple_magnitude(t_tuple tuple);
t_tuple tuple_normalization(t_tuple tuple);
double	dot_product(t_tuple tuple1, t_tuple tuple2);
t_tuple cross_product(t_tuple a, t_tuple b);
t_projectile tick(t_environment env, t_projectile proj);

// rgb

t_rgb	set_rgb(double r, double g, double b);
t_rgb rgb_addition(t_rgb r1, t_rgb r2);
t_rgb rgb_subtraction(t_rgb r1, t_rgb r2);
t_rgb rgb_multiplication_scalar(t_rgb r1, double scale);
t_rgb rgb_multiplication(t_rgb r1, t_rgb r2);
int	equals_rgb(t_rgb r1, t_rgb r2);

// canva

int init_canva(t_canvas *canva);
void put_px_in_canva(t_canvas canva, int x, int y, t_rgb rgb);

// matrix

uint8_t 		matrix4_is_equal(t_matrix4 m1, t_matrix4 m2);
uint8_t			matrix3_is_equal(t_matrix3 m1, t_matrix3 m2);
uint8_t 		matrix2_is_equal(t_matrix2 m1, t_matrix2 m2);
t_matrix3_ptr 	matrix4_submatrix(t_matrix4 m1, t_matrix3 m2, int row, int col);
t_matrix2_ptr 	matrix3_submatrix(t_matrix3 m1, t_matrix2 m2, int row, int col);
double 			determining_matrix2(t_matrix2 m);
double 			matrix3_minor(t_matrix3 m, int row, int col);
double 			matrix4_minor(t_matrix4 m, int row, int col);
t_matrix4_ptr 	matrix4_multiplication(t_matrix4 m1, t_matrix4 m2, t_matrix4 m3);
t_matrix4_ptr 	matrix3_multiplication(t_matrix3 m1, t_matrix3 m2, t_matrix4 m3);
t_tuple 		matrix4_multiplication_by_tuple(t_matrix4 m1, t_tuple t1);
t_matrix4_ptr 	matrix2_multiplication(t_matrix2 m1, t_matrix2 m2, t_matrix4 m3);
t_matrix4_ptr 	matrix4_transposition(t_matrix4 m1);
t_matrix3_ptr 	matrix3_transposition(t_matrix3 m1);
t_matrix2_ptr 	matrix2_transposition(t_matrix2 m1);
double 			matrix3_cofactor(t_matrix3 m, int row, int col);
double 			matrix4_cofactor(t_matrix4 m, int row, int col);
double 			determining_matrix2(t_matrix2 m);
double 			determining_matrix3(t_matrix3 m);
double 			determining_matrix4(t_matrix4 m);
int 			matrix4_is_reversible(t_matrix4 m);
t_matrix4_ptr 	matrix4_inverse(t_matrix4 m1, t_matrix4 m2);
t_matrix4_ptr	set_identity_matrix(t_matrix4 m);
t_matrix4_ptr	matrix4_cpy(t_matrix4 m, t_matrix4 m2);

// transformation

t_matrix4_ptr 	translation(double x, double y, double z, t_matrix4 m1);
t_matrix4_ptr	scaling(double x, double y, double z, t_matrix4 m);
t_matrix4_ptr	rotation_x(double radian, t_matrix4 m);
t_matrix4_ptr	rotation_y(double radian, t_matrix4 m);
t_matrix4_ptr	rotation_z(double radian, t_matrix4 m);
void			set_transform(t_obj *s, t_matrix4 m);

// ray

t_ray			set_ray(t_tuple point, t_tuple vector);
t_tuple			position(t_ray ray, double range);
t_inter			set_intersection(double t, t_obj *obj);
int				set_intersections(t_inters *inters, t_inter inter1, t_inter inter2);
t_inter			*hit(t_inters *inters);
t_ray			transform(t_ray ray, t_matrix4 m);
void			intersect(t_ray r, t_obj *o, t_inters *xs);
t_tuple			normal_at(t_obj s, t_tuple p);
t_tuple			reflect(t_tuple	v, t_tuple n);

// sphere
uint32_t 		intersect_sphere(t_obj *s, t_ray r, t_inters *inters);
t_obj			sphere(void);
void			draw_sphere(t_canvas canvas);

// light

t_material	material(void);
t_light	point_light(t_tuple	position, t_rgb inte);
t_rgb		lighting(t_material mat, t_light l, t_tuple eyev, t_tuple point, t_tuple normalv);

// world

t_world	world(void);
uint32_t	intersect_world(t_world w, t_ray r, t_inters *inters);
void	prepare_computations(t_inter *inter, const t_ray ray);
t_rgb	shade_hit(t_world world, t_inter comps);

#endif