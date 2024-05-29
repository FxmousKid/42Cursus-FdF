/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:28:58 by inazaria          #+#    #+#             */
/*   Updated: 2024/05/30 00:33:09 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

void	free_points_array(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height && map->points[i] != NULL)
	{
		free(map->points[i]);
		i++;
	}
	free(map->points);
}

void	free_points(t_map *map)
{
	t_point		***points;
	int			i;
	int			j;

	i = 0;
	points = map->points;
	while (i < map->height && points[i] != NULL)
	{
		j = 0;
		while (j < map->width && points[i][j] != NULL)
		{
			free(points[i][j]);
			j++;
		}
		free(points[i]);
		i++;
	}
	free(points);
}

void	free_map(t_data *data)
{
	t_map	*map;

	map = data->map;
	free_points(map);
	free(map);
}

void	free_fdf(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img->image_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free_map(data);
	free(data->img);
}
