/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   amb_light_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 04:41:04 by dim               #+#    #+#             */
/*   Updated: 2021/11/01 19:51:23 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

bool	validate_amb_light(double light_ratio, t_vec *rgb)
{
	bool	flag;

	flag = true;
	if (light_ratio < 0.0 || light_ratio > 1.0)
		flag = false;
	if (rgb->x < 0 || rgb->x > 255
		|| rgb->y < 0 || rgb->y > 255
		|| rgb->z < 0 || rgb->z > 255)
		flag = false;
	return (flag);
}

t_vec	*save_amb_light(double light_ratio, t_vec *rgb)
{
	t_vec	*alloc_rgb;

	alloc_rgb = (t_vec *)malloc(sizeof(t_vec));
	if (alloc_rgb == NULL)
		return (NULL);
	*alloc_rgb = product_scalar(*rgb, light_ratio / 255);
	return (alloc_rgb);
}

void	amb_light_parsing(t_render *render, char **split_line)
{
	double	light_ratio;
	t_vec	rgb;

	if (count_split_line(split_line) != 3)
		error("Information count error on Ambient lightning");
	if (!validate_float(split_line[1]) \
		|| !validate_vec(split_line[2]))
		error("Information error on Ambient lightning");
	light_ratio = ft_atof(split_line[1]);
	split_vec(&rgb, split_line[2]);
	if (!validate_amb_light(light_ratio, &rgb))
		error("Information range error on Ambient lightning");
	if (render->world.ambient_light != NULL)
		error("Duplicated element on Ambient lightning");
	render->world.ambient_light = save_amb_light(light_ratio, &rgb);
	if (render->world.ambient_light == NULL)
		error(NULL);
}
