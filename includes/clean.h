/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:20:00 by dernst            #+#    #+#             */
/*   Updated: 2025/11/17 16:23:26 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_CLEAN_H
#define MINIRT_CLEAN_H

void	distroy_canvas(t_canvas c);
void	distroy_world(t_world w);
void	distroy_all(t_world w, t_canvas c);


#endif //MINIRT_CLEAN_H