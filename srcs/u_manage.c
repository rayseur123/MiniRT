/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_manage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:44:45 by dernst            #+#    #+#             */
/*   Updated: 2025/09/08 16:34:35 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <units.h>
#include <stdlib.h>
#include "libft.h"

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
	while (search && ft_strncmp(search->name, name, ft_strlen(name) + ft_strlen(search->name)) != 0)
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
