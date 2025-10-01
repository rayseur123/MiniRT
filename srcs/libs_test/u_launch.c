/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_launch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:42:21 by dernst            #+#    #+#             */
/*   Updated: 2025/09/08 16:01:34 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "units.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int	check_return(int status)
{
	if (WIFSIGNALED(status))
		return (WTERMSIG(status));
	return (WEXITSTATUS(status));
}

void	manage_children(t_unit *unit)
{
	exit(unit->test());
}

void	manage_parent(t_function *function, t_unit *unit)
{
	int	status;

	wait(&status);
	status = check_return(status);
	if (status == 0)
		function->nb_success++;
	unit->succes = status;
	function->nb_test++;
	display_unit(*unit);
}

void	launch_unit(t_function *function, t_unit *unit)
{
	int pid;
	
	pid = fork();
	if (pid < 0)
		return;
	if (pid == 0)
		manage_children(unit);
	if (pid > 0)
		manage_parent(function, unit);
}

unsigned int	launch_lib_test(t_function **head)
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
