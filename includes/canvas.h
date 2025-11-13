/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 08:31:41 by dernst            #+#    #+#             */
/*   Updated: 2025/11/13 09:56:13 by dernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_H
# define CANVAS_H
# define WIDTH_CANVA 1000
# define HEIGHT_CANVA 800

# include <stdint.h>
# include "color.h"

typedef struct s_canvas
{
	int		width;
	int		height;
	void	*mlx;
	void	*window;
	void	*canva;
}	t_canvas;

int			init_canva(t_canvas *canva);
void		put_px_in_canva(t_canvas canva, int x, int y, t_rgb rgb);

#endif