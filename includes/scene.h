/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 14:35:29 by njooris           #+#    #+#             */
/*   Updated: 2025/09/10 13:27:17 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft.h"
#include "mlx.h"
#include "mlx_int.h"
#include <stdint.h>
#include <X11/X.h>

#ifndef STRUCT_OBJS_H
# define STRUCT_OBJS_H

# define EPSILON 0.00001
# define WIDTH_CANVA 900;
# define HEIGHT_CANVA 550;
# define IDENTITY_MTRX {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
typedef double t_matrix4[4][4];
typedef double (*t_matrix4_ptr)[4];
typedef double t_matrix3[3][3];
typedef double (*t_matrix3_ptr)[3];
typedef double t_matrix2[2][2];
typedef double (*t_matrix2_ptr)[2];

typedef struct s_rgb
{
	int8_t r;
	int8_t g;
	int8_t b;
}	t_rgb;

typedef struct s_canvas
{
	uint32_t	width;
	uint32_t	height;
	void		*mlx;
	void		*window;
	void		*canva;
}	t_canvas;

typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	uint8_t	w;
}	t_tuple;

typedef struct s_projectile
{
	t_tuple	position;
	t_tuple velocity;
}	t_projectile;

typedef struct s_environment
{
	t_tuple	gravity;
	t_tuple	wind;
}	t_environment;

t_tuple	set_vector(double x, double y, double z);
t_tuple	set_point(double x, double y, double z);

int				double_is_equal(double x, double y);
int				check_equal_tuples(t_tuple tuple1, t_tuple tuple2);
t_tuple			tuple_addition(t_tuple tuple1, t_tuple tuple2);
t_tuple			tuple_subtraction(t_tuple tuple1, t_tuple tuple2);
t_tuple			tuple_negation(t_tuple tuple);
t_tuple			tuple_multiplication(t_tuple tuple1, double scale);
t_tuple			tuple_division(t_tuple tuple1, double scale);
double			tuple_magnitude(t_tuple tuple);
t_tuple			tuple_normalization(t_tuple tuple);
int				dot_product(t_tuple tuple1, t_tuple tuple2);
t_tuple			cross_product(t_tuple a, t_tuple b);
t_projectile	tick(t_environment env, t_projectile proj);

// rgb

t_rgb	set_rgb(int8_t r, int8_t g, int8_t b);
t_rgb	rgb_addition(t_rgb r1, t_rgb r2);
t_rgb	rgb_subtraction(t_rgb r1, t_rgb r2);
t_rgb	rgb_multiplication_scalar(t_rgb r1, int scale);
t_rgb	rgb_multiplication(t_rgb r1, t_rgb r2);
int		rgb_to_int(t_rgb rgb);

// canva

int		init_canva(t_canvas *canva);
void	put_px_in_canva(t_canvas canva, int x, int y, t_rgb rgb);

// matrix

uint8_t			matrix4_is_equal(t_matrix4 m1, t_matrix4 m2);
uint8_t			matrix3_is_equal(t_matrix3 m1, t_matrix3 m2);
uint8_t			matrix2_is_equal(t_matrix2 m1, t_matrix2 m2);
t_matrix3_ptr	matrix4_submatrix(t_matrix4 m1, t_matrix3 m2, int row, int col);
t_matrix2_ptr	matrix3_submatrix(t_matrix3 m1, t_matrix2 m2, int row, int col);
int				determining_matrix2(t_matrix2 m);
double			matrix3_minor(t_matrix3 m, int i, int j);
t_matrix4_ptr	matrix4_multiplication(t_matrix4 m1, t_matrix4 m2, t_matrix4 m3);
t_matrix4_ptr	matrix3_multiplication(t_matrix3 m1, t_matrix3 m2, t_matrix4 m3);
t_tuple			matrix4_multiplication_by_tuple(t_matrix4 m1, t_tuple t1);
t_matrix4_ptr	matrix2_multiplication(t_matrix2 m1, t_matrix2 m2, t_matrix4 m3);
t_matrix4_ptr	matrix4_transposition(t_matrix4 m1);
t_matrix3_ptr	matrix3_transposition(t_matrix3 m1);
t_matrix2_ptr	matrix2_transposition(t_matrix2 m1);

#endif