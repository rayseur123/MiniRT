/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   units.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:07:04 by dernst            #+#    #+#             */
/*   Updated: 2025/09/03 10:55:32 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNITS_H
# define UNITS_H

#define NB_TEST 10
#define NB_TEST_MATH 4
#define NB_TEST_VECTOR 8
#define PASS "\x1B[32mPASS\n\x1B[0m"
#define FAIL "\x1B[31mFAIL\n\x1B[0m"

typedef struct s_unit
{
	char			*name;
	int				(*test)(void);
	unsigned int	succes;
	struct s_unit	*next;

} t_unit;

typedef struct s_function
{
	char				*name;
	unsigned int		nb_test;
	unsigned int		nb_success;
	t_unit				*units;
	struct s_function		*next;

}	t_function;

void		display_function(char *name);
void		display_unit(t_unit unit);
void		display_stats(t_function function);
void		display_chain_f(void *head);

void		launch_unit(t_function *function, t_unit *unit);
unsigned	int select_unit(t_function **head);

#endif
