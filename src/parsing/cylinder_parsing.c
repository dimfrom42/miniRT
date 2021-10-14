/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 04:45:12 by dim               #+#    #+#             */
/*   Updated: 2021/10/14 17:53:44 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dim_parse_util.h"

bool	validate_cylinder(t_vec orient, t_vec color)
{
	bool	flag;

	flag = true;
	if (orient.x < -1 || orient.x > 1
		|| orient.y < -1 || orient.y > 1
		|| orient.z < -1 || orient.z > 1)
		flag = false;
	if (color.x < 0 || color.x > 255
		|| color.y < 0 || color.y > 255
		|| color.z < 0 || color.z > 255)
	 	flag = false;
	return (flag);
}

t_cylinder	*save_cylinder(t_vec point1, t_vec orient1,
							double diameter1, double height1, t_vec color1)
{
	t_cylinder		*cylinder;

	cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (cylinder == NULL)
		return (NULL);
	cylinder->point = point1;
	cylinder->orient = orient1;
	cylinder->color = color1;
	cylinder->diameter = (diameter1 / 2);
	cylinder->height = height1;
	return (cylinder);
}

void		cylinder_parsing(t_render *render, char **split_line)
{
	t_vec	point;
	t_vec	orient;
	double	diameter;
	double	height;
	t_vec	color;

	if (count_split_line(split_line) != 6)
		error("Information count error on Cylinder");
	if (!validate_vec(split_line[1])
		|| !validate_vec(split_line[2])
		|| !validate_float(split_line[3])
		|| !validate_float(split_line[4])
		|| !validate_vec(split_line[5]))
		error("Information error on Cylinder");
	split_vec(&point, split_line[1]);
	split_vec(&orient, split_line[2]);
	diameter = ft_atof(split_line[3]);
	height = ft_atof(split_line[4]);
	split_vec(&color, split_line[5]);
	if (!validate_cylinder(orient, color))
		error("Information range error on Cylinder");
	render->world.object->object = 
		save_cylinder(point, orient, diameter, height, color);
	if (render->world.object->object == NULL)
		error(NULL);
}
