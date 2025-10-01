/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   units.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:07:04 by dernst            #+#    #+#             */
/*   Updated: 2025/09/24 14:20:16 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNITS_H
# define UNITS_H

#define PASS "\x1B[32mPASS\n\x1B[0m"
#define FAIL "\x1B[31mFAIL\n\x1B[0m"
#define SEG "\x1B[33mSEGFAULT\n\x1B[0m"

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
	struct s_function	*next;

}	t_function;


void	lib_unit(void);

//	u_printf.c
void			display_function(char *name);
void			display_unit(t_unit unit);
void			display_stats(t_function function);
void			display_chain_f(void *head);

// u_init.c
unsigned int	init_function(t_function **function, char *name);
unsigned int	init_unit(t_unit **unit, char *name, int (test)(void));

// u_manage.c
unsigned int	adding_test(t_function **function, char *name_func, char *name_test, int (test)(void));


// u_launch.c
void			launch_unit(t_function *function, t_unit *unit);
unsigned		int launch_lib_test(t_function **head);

#endif
