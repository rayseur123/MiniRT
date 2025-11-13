/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 08:33:33 by dernst            #+#    #+#             */
/*   Updated: 2025/11/13 13:04:14 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLE_H
# define TUPLE_H

# include <stdint.h>

# define EPSILON 0.0001

typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_tuple;

t_tuple	tuple_addition(t_tuple tuple1, t_tuple tuple2);
t_tuple	set_vector(double x, double y, double z);
t_tuple	set_point(double x, double y, double z);
t_tuple	tuple_subtraction(t_tuple tuple1, t_tuple tuple2);
t_tuple	tuple_negation(t_tuple tuple);
t_tuple	tuple_multiplication(t_tuple tuple1, double scale);
t_tuple	tuple_division(t_tuple tuple1, double scale);
t_tuple	cross_product(t_tuple a, t_tuple b);
t_tuple	tuple_normalization(t_tuple tuple);
double	tuple_magnitude(t_tuple tuple);
double	dot_product(t_tuple tuple1, t_tuple tuple2);
int		double_is_equal(double x, double y);
int		check_equal_tuples(t_tuple tuple1, t_tuple tuple2);

#endif
