/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 23:44:31 by inazaria          #+#    #+#             */
/*   Updated: 2024/05/30 01:04:21 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_point_info(t_point *point)
{
	if (!point)
	{
		ft_printf("Point is NULL\n");
		return ;
	}
	ft_printf("Point : x = %d, y = %d, z = %d, color = %x\n",
		point->x,
		point->y,
		point->z,
		point->color);
}

void	print_map_points(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			print_point_info(map->points[i][j]);
			j++;
		}
		i++;
	}
}
