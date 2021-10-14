/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:00:23 by dim               #+#    #+#             */
/*   Updated: 2021/10/14 14:27:13 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing/dim_header.h"

void	error(char *msg)
{
	if (msg != NULL)
		printf("%s\n", msg);
	else
		printf("%s\n", strerror(errno));
}