/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 10:42:45 by dernst            #+#    #+#             */
/*   Updated: 2025/09/03 10:46:55 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	function_to_test(unsigned int nb, unsigned int nb2)
{
	return (nb + nb2);
}

int	unit_test2(void)
{
	if (function_to_test(6, 6) == 12)
		return (0);
	return (1);
}

int unit_test3(void)
{
	 int *ptr = NULL;
    *ptr = 42;  // Segmentation fault ici !
    
    printf("Cette ligne ne sera jamais exécutée\n");
    return 0;
}

int	unit_test1(void)
{
	if (function_to_test(2, 5) == 4)
		return (0);
	return (1);
}
