/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:26:40 by dim               #+#    #+#             */
/*   Updated: 2021/10/28 17:17:55 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minirt.h"

void	create_mlx(t_trace *trace)
{
	trace->mlx = mlx_init();
	trace->mlx_win = mlx_new_window(trace->mlx, \
									trace->width, trace->height, "MiniRT");
	trace->img = mlx_new_image(trace->mlx, trace->width, trace->height);
	trace->addr = mlx_get_data_addr(trace->img, &trace->bits_per_pixel, \
									&trace->line_length, &trace->endian);
}
