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
	  	printf(PASS);
	else 
		printf(FAIL);
}

void	display_stats(t_function function)
{
	printf("\n%d / %d\n\n", function.nb_success, function.nb_test);
}

void	display_chain_f(void *head)
{
	t_function *tmp_func;
	t_unit *tmp_test;

	tmp_func = head;

	while (tmp_func)
	{
		printf("%s\n", tmp_func->name);
		tmp_test = tmp_func->units;
		while (tmp_test)
		{
			printf("\t%s\n", tmp_test->name);
			tmp_test = tmp_test->next;
		}
		tmp_func = tmp_func->next;
	}
}

