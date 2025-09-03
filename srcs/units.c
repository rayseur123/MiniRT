/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   units.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:05:08 by dernst            #+#    #+#             */
/*   Updated: 2025/09/03 10:46:43 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "units.h"
#include "tests.h"
#include "stdlib.h"

unsigned int	prepare_units(t_function **function)
{
	t_unit *unit1;

	*function = malloc(4 * sizeof(*function));
	(*function)[0].name = "Function1";
	(*function)[0].nb_success = 0;
	(*function)[1].name = NULL;

	unit1 = malloc(4 * sizeof(t_unit));

	unit1[0].name = "Test1";
	unit1[0].test = &unit_test1;
	unit1[1].name = "Test2";
	unit1[1].test = &unit_test2;
	unit1[2].name = "Test3";
	unit1[2].test = &unit_test3;
	unit1[3].name = NULL;

	function[0]->units = unit1;
	return (0);
}


unsigned int	adding_test(t_function **function, )
{
	
}

void	launch_unit(t_function *function, t_unit *unit)
{
	if (unit->test())
	{
		unit->succes = 1;
		function->nb_success++;
	}
	else
	{
		function->units->succes = 0;
	}
	function->nb_test++;
	display_unit(*unit);
}

unsigned int	select_unit(t_function **functions)
{

	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while ((*functions)[i].name != NULL)
	{
		display_function((*functions)[i].name);
		while ((*functions)[i].units[j].name != NULL)
		{
			launch_unit((functions)[i], &functions[i]->units[j]);
			j++;
		}
		display_stats((*functions)[i]);
		j = 0;
		i++;
	}
	return (0);
}

int	main(void)
{
	t_function *function;

	if (prepare_units(&function))
		return (1);
	select_unit(&function);
	return (0);
}


