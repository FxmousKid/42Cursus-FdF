/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 04:35:03 by inazaria          #+#    #+#             */
/*   Updated: 2024/06/29 00:50:57 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reverse_t_points_row(t_map *map)
{
	int		i;
	int		height;
	t_point	**tmp_row;
	t_point	***points;

	points = map->points;
	i = 0;
	height = map->height;
	while (i < height)
	{
		tmp_row = points[i];
		points[i] = points[height - 1];
		points[height - 1] = tmp_row;
		i++;
		height--;
	}	
}
