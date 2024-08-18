/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 19:03:12 by inazaria          #+#    #+#             */
/*   Updated: 2024/08/18 02:17:35 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_scale_and_offset(t_map *map, t_point *point)
{
	point->wu_x = point->wu_x * map->x_scale + map->x_offset_add;
	point->wu_y = point->wu_y * map->y_scale + map->y_offset_add;
	point->wu_z = point->wu_z * map->z_scale;
}

void	draw_aa_line_isometric(t_data *data, t_point *p0, t_point *p1)
{
	set_scale_and_offset(data->map, p0);
	set_scale_and_offset(data->map, p1);
	set_isometric_coords(p0);
	set_isometric_coords(p1);
	p0->wu_x = p0->wu_x + data->map->x_offset;
	p0->wu_y = p0->wu_y + data->map->y_offset;
	p1->wu_x = p1->wu_x + data->map->x_offset;
	p1->wu_y = p1->wu_y + data->map->y_offset;
	draw_aa_line(data, p0, p1);
}

void	set_isometric_coords(t_point *point)
{
	int		previous_wu_x;
	int		previous_wu_y;

	previous_wu_x = point->wu_x ;
	previous_wu_y = point->wu_y ;
	point->wu_x = (previous_wu_x - previous_wu_y) * cos(ANGLE);
	point->wu_y = (previous_wu_x + previous_wu_y) * sin(ANGLE) - point->wu_z;
}

void	draw_map(t_data *data)
{
	int		i;
	int		j;
	t_point	***points;

	points = data->map->points;
	i = 0;
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
	t_map		*map;
	int			scale;

	map = data->map;
	scale = get_scale_value(map);
	data->map->x_scale = scale - 8;
	data->map->y_scale = scale - 8;
	data->map->z_scale = Z_SCALE;
	data->map->x_offset = WIDTH / 2;
	data->map->y_offset = 0;
	draw_map(data);
	reverse_t_points_row(data->map);
	draw_map(data);
}
