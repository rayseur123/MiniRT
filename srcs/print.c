/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 10:02:51 by dernst            #+#    #+#             */
/*   Updated: 2025/09/03 10:03:10 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "units.h"
#include <stdio.h>

void	display_function(char *name)
{
	printf("---------------------------------------------------------\n");
	printf("%s:\n\n", name);
}

void	display_unit(t_unit unit)
{
	printf("%s = ", unit.name);
	if (unit.succes == 1)
	  	printf("{SUCCESS}\n");
	else 
		printf("{FAILURE}\n");
}

void	display_stats(t_function function)
{
	printf("\n%d / %d\n\n", function.nb_success, function.nb_test);
}
