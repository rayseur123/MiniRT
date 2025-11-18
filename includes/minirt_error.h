/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_error.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 10:49:56 by njooris           #+#    #+#             */
/*   Updated: 2025/11/18 14:47:26 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_ERROR_H
# define MINIRT_ERROR_H

// system error
# define MALLOC_ERROR "Malloc failed"
# define FD_ERROR "Error with fd"
# define OPEN_ERROR "Error with open"
# define CLOSE_ERROR "Error with close"
# define READ_ERROR "Error with read"

// parsing error
# define FILE_NAME_ERROR "Bad file name"
# define DOUBLE_CAP_ERROR "Multi capitalize"
# define MISS_CAP_ERROR "Miss capitalize"
# define PARAMETER_NUMBER_ERROR "Bad number of parameter on an argument"
# define ARGUMENT_ERROR "Bad argument name"
# define BAD_FORMAT_ERROR "Alphanumeric character error"

// coord error
# define COORD_NUMBER_ERROR "Bad number of parameter on an coord"

// rgb error
# define RGB_NUMBER_ERROR "Bad number of parameter on an rgb"

// light error
# define TO_MANY_LIGHT_ERROR "To many light"

int		print_error(char *str);

#endif
