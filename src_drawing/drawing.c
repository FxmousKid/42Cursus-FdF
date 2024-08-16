/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 19:03:12 by inazaria          #+#    #+#             */
/*   Updated: 2024/08/16 19:40:13 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_scale_and_offset(t_map *map, t_point *point)
{
	point->wu_x *= map->x_scale + OFFSET;
	point->wu_y *= map->y_scale + OFFSET;
	point->wu_z *= map->z_scale;

}

void	draw_aa_line_isometric(t_data *data, t_point *p0, t_point *p1)
{
	set_scale_and_offset(data->map, p0);
	set_scale_and_offset(data->map, p1);
	set_isometric_coords(data->map, p0, data->map->height, data->map->width);
	set_isometric_coords(data->map, p1, data->map->height, data->map->width);
	draw_aa_line(data, p0, p1);
}


void	set_isometric_coords(t_map *map, t_point *point, int height, int width)
{
	(void) map;
	int		previous_wu_x;
	int		previous_wu_y;
	
	previous_wu_x = point->wu_x ;
	previous_wu_y = point->wu_y ;
	point->wu_x = (previous_wu_x - previous_wu_y) * cos(ANGLE);
	point->wu_y = (previous_wu_x + previous_wu_y) * sin(ANGLE) - point->wu_z;

	(void) height;
	(void) width;
	point->wu_x += (width / 2) + (WIDTH / 2);
}

void	draw_map(t_data *data)
{
	int		i;
	int		j;
	t_point	***points;

	
	
	
	
	
	// TODO : Reset coords of corners.
	
	data->map->x_scale = SCALE;
	data->map->y_scale = SCALE;
	data->map->z_scale = Z_SCALE;
	
	

	/* 
	 *
	 * */

	i = 0;
	points = data->map->points;
	while (points[i])
	{
		j = 0;
		while (points[i][j])
		{
			if (points[i][j + 1])
				draw_aa_line_isometric(data, points[i][j], points[i][j + 1]);
			if (points[i + 1] && points[i + 1][j])
				draw_aa_line_isometric(data, points[i][j], points[i + 1][j]);
			j++;
		}
		i++;
	}
}

void	draw_on_image(t_data *data)
{
	draw_map(data);
	reverse_t_points_row(data->map);
	draw_map(data);
}
