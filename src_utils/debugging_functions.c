/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 23:44:31 by inazaria          #+#    #+#             */
/*   Updated: 2024/06/11 19:47:55 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_point_wu_info(t_point *point)
{
	if (!point)
	{
		ft_printf("Point is NULL\n");
		return ;
	}
	ft_printf("Wu_point : wu_x = %d, wu_y = %d, wu_z = %d, color = %x",
		point->wu_x,
		point->wu_y,
		point->wu_z,
		point->color);
}

void	print_point_info(t_point *point)
{
	if (!point)
	{
		ft_printf("Point is NULL\n");
		return ;
	}
	ft_printf("Point : x    = %d, y    = %d, z    = %d, color = %x",
		(int) point->x,
		(int) point->y,
		(int) point->z,
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
			ft_printf("\n");
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	print_map_only_wu_point(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			print_point_wu_info(map->points[i][j]);
			ft_printf("\n");
			j++;
		}
		i++;
	}
}

void	print_map_info_all_points(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			ft_printf("   ");
			print_point_info(map->points[i][j]);
			ft_printf("\n");
			print_point_wu_info(map->points[i][j]);
			ft_printf("\n\n");
			j++;
		}
		i++;
	}
}
