/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:42:01 by njooris           #+#    #+#             */
/*   Updated: 2025/01/14 15:36:13 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

int	ft_printf(const char *str, ...);
int	ft_writec(char c);
int	ft_writes(char	*str);
int	ft_writep(void	*m);
int	write_iota(int nb);
int	write_uiota(unsigned int nb);
int	ft_writex(unsigned int m);
int	ft_upwritex(unsigned int m);

#endif
