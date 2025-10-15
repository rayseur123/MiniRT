/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 10:49:56 by njooris           #+#    #+#             */
/*   Updated: 2025/10/14 11:33:15 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# define EXTENSION ".rt"
#include "world.h"

int	open_rt_file(char *str);
int	parsing(char *str, t_world *world);

#endif