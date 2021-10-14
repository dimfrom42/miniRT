/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dim_parse_util.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 16:08:16 by dim               #+#    #+#             */
/*   Updated: 2021/10/14 15:33:57 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIM_PARSE_UTIL_H
# define DIM_PARSE_UTIL_H
# include "../vector/dim_vector.h"
# include "dim_header.h"

int			check_input(int	argc, char	**argv);
void		split_vec(t_vec *rgb, char *line);
bool		validate_vec(char *line);
int			validate_float(char *line);
int			count_split_line(char **line);
void		free_split_line(char **split_line);

#endif