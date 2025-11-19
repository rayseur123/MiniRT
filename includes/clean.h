/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:20:00 by dernst            #+#    #+#             */
/*   Updated: 2025/11/19 11:12:10 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEAN_H
# define CLEAN_H

void	distroy_canvas(t_canvas c);
void	distroy_world(t_world w);
void	distroy_all(t_world w, t_canvas c);

#endif