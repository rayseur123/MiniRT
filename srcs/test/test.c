/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 13:51:11 by njooris           #+#    #+#             */
/*   Updated: 2025/09/03 14:36:11 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <stdio.h>

void	test(void)
{
	printf("set_vector : ");
	if (!test_set_vector())
		printf("PASS\n");
	else
		printf("FAILD");

	printf("set_point : ");
	if (!test_set_point())
		printf("PASS\n");
	else
		printf("FAILD");
	return ;
}