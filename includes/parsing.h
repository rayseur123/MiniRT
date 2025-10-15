/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 10:49:56 by njooris           #+#    #+#             */
/*   Updated: 2025/10/15 15:52:57 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# define EXTENSION ".rt"
#include "world.h"
#include "camera.h"

int		open_rt_file(char *str);
int		parsing(char *str, t_world *world, t_camera *c);
int		make_objs(char *str, t_world *world, t_camera *c);
char	*next_obj(int fd);
int		make_sp(t_obj *o, char *str);
int		get_coord(char *str, t_tuple *point);
double	get_diameter(char *str);
int		get_rgb(char *str, t_rgb *rgb);
int		count_obj_and_light(char *str, t_world *w);
int		make_cam(t_camera *c, char *str);
int		make_light(t_light *l, char *str);

#endif