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
#include "stdlib.h"
#include "libft.h"
#include "stdio.h"
#include <inttypes.h>
#include "tests.h"

unsigned int	init_function(t_function **function, char *name)
{
	*function = malloc(sizeof(t_function));
	if (!*function)
		return (1);
	(*function)->name = name;
	(*function)->nb_test = 0;
	(*function)->nb_success = 0;
	(*function)->next = NULL;
	(*function)->units = NULL;
	return (0);
}

unsigned int	init_unit(t_unit **unit, char *name, int (test)(void))
{
	*unit = malloc(sizeof(t_unit));
	if (!*unit)
		return (1);
	(*unit)->name = name;
	(*unit)->succes = 0;
	(*unit)->test = test;
	(*unit)->next = NULL;
	return (0);
}


unsigned int	adding_function(t_function **head, char *name)
{
	t_function *new;

	new = (t_function *)malloc(sizeof(t_function));
	if (!new)
		return (1);
	new->name = name;
	new->next = *head;
	new->nb_success = 0;
	new->nb_test = 0;
	*head = new;
	return (0);
}

unsigned int	adding_unit(t_unit **head, char *name, int (test)(void))
{
	t_unit *new;
	
	new = (t_unit *)malloc(sizeof(t_unit));
	if (!new)
		return (1);
	new->name = name;
	new->test = test;
	new->next = *head;
	new->succes = 0;
	*head = new;
	return (0);
}

//
t_function	*search_function(t_function **function, char *name)
{
	t_function *search;

	if (!*function)
		return (NULL);
	search = *function;
	while (search && ft_strncmp(search->name, name, ft_strlen(name)) != 0)
		search = search->next;
	if (search)
		return (search);
	return (NULL);
}

unsigned int	adding_test(t_function **function, char *name_func, char *name_test, int (test)(void))
{
	t_function *search;

	search = search_function(function, name_func);
	if (!search)
	{
		if (!*function)
			init_function(function, name_func);
		else
			adding_function(function, name_func);
		
		init_unit(&(*function)->units, name_test, test);
	}
	else
		adding_unit(&search->units, name_test, test);
	return (0);
}


void	launch_unit(t_function *function, t_unit *unit)
{
	if (unit->test())
	{
		unit->succes = 1;
		function->nb_success++;
	}
	else
		unit->succes = 0;
	function->nb_test++;
	display_unit(*unit);
}

unsigned int	select_unit(t_function **head)
{
	t_function	*tmp_func;
	t_unit		*tmp_unit;

	tmp_func = *head;

	while (tmp_func)
	{
		display_function(tmp_func->name);
		tmp_unit = tmp_func->units;
		while (tmp_unit)
		{
			launch_unit(tmp_func, tmp_unit);
			tmp_unit = tmp_unit->next;
		}
		display_stats(*tmp_func);
		tmp_func = tmp_func->next;
	}
	return (0);
}

// PROBLEME IF NAME FUNCTION DONT HAVE THE SAME SIZE : FUNCTION AND FUNCTION5
// FREE THE MALLOC AND FIX LEAK

int	main(void)
{
	t_function *function;

	function = NULL;
	adding_test(&function, "Function1", "AHHHH1", &unit_test1);
	adding_test(&function, "Function2", "BBBB1", &unit_test2);
	adding_test(&function, "Function2", "BBBBB2", &unit_test3);
	adding_test(&function, "Function2", "BBBB3", &unit_test2);
	adding_test(&function, "Function3", "AHHH2", &unit_test1);
	adding_test(&function, "Function1", "AHHH3", &unit_test1);
	select_unit(&function);
	return (0);
}


