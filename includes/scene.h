/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 14:35:29 by njooris           #+#    #+#             */
/*   Updated: 2025/08/25 15:11:38 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#ifndef STRUCT_OBJS_H
# define STRUCT_OBJS_H

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
}	t_point;

typedef struct s_vec
{
	double	x;
	double	y;
	double	z;
}	t_vec;

typedef	struct s_color_rgb
{
	uint8_t	r;
	uint8_t g;
	uint8_t b;
}	t_color_rgb;

typedef	struct s_sphere
{
	t_point coordinate;
	t_color_rgb	rgb;
	double	diameter;
}	t_sphere;

typedef	struct s_cylinder
{
	t_point coordinate;
	t_color_rgb	rgb;
	double		diameter;
	double		height;
	t_vec		vec;
	
}	t_cylinder;

typedef	struct s_plane
{
	t_point coordinate;
	t_color_rgb	rgb;
	double		diameter;
	double		height;
	t_vec		vec;
}	t_plane;

typedef struct s_light
{
	t_point coordinate;
	float	ratio;
	t_color_rgb	rgb;
}	t_light;

typedef struct s_camera
{
	t_point			coordinate;
	t_vec			vec;
	uint8_t			fov;
}	t_camera;

typedef	struct s_scene
{
	t_camera	camera;
	t_light		*lst_light;
	t_plane		*lst_plane;
	t_cylinder	*lst_cylinder;
	t_sphere	*lst_sphere;
	
}	t_scene;


#endif