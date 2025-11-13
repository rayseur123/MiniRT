/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:16:02 by njooris           #+#    #+#             */
/*   Updated: 2025/11/13 13:16:34 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYHOOK_H
# define KEYHOOK_H

void	escape(int key_code, t_canvas *c);
int		actions_hook(int key_code, t_canvas *c);
int		hook_close(void *mlx);

#endif