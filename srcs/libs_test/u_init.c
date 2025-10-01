/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 10:18:21 by dernst            #+#    #+#             */
/*   Updated: 2025/09/30 09:28:44 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:41:16 by dernst            #+#    #+#             */
/*   Updated: 2025/09/08 15:55:01 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************e************************************************************** */

#include "units.h"
#include <stdlib.h>

unsigned int	init_function(t_function **function, char *name)
{
	*function = malloc(sizeof(t_function));
	if (!*function)
		return (1);
	(*function)->name = name;
	(*function)->nb_test = 0;
	(*function)->nb_success = 0;
	(*function)->units = NULL;
	(*function)->next = NULL;
	return (0);
}

unsigned int	init_unit(t_unit **unit, char *name, int (test)(void))
{
	*unit = malloc(sizeof(t_unit));
	if (!*unit)
		return (1);
	(*unit)->name = name;
	(*unit)->test = test;
	(*unit)->succes = 0;
	(*unit)->next = NULL;
	return (0);
}


