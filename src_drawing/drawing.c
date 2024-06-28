/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 19:03:12 by inazaria          #+#    #+#             */
/*   Updated: 2024/06/29 00:31:39 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_red_cross(t_data *data)
{
	t_image	*img;
	int		pixel_x;
	int		pixel_y;

	img = data->img;
	pixel_x = (WIDTH / 2) - 100;
	bzero_img_addr(img);
	while (pixel_x < (WIDTH / 2) + 100)
		my_mlx_pixel_put(img, pixel_x++, HEIGHT / 2, RED_ARGB);
	pixel_y = (HEIGHT / 2) - 200;
	while (pixel_y < (HEIGHT / 2) + 200)
		my_mlx_pixel_put(img, WIDTH / 2, pixel_y++, RED_ARGB);
}

void	set_isometric_coords(t_point *point, int height, int width)
{
	int		previous_wu_x;
	int		previous_wu_y;
	double	angle;

	angle = 0.523599;


	previous_wu_x = point->wu_x;
	previous_wu_y = point->wu_y;
	point->wu_x = (previous_wu_x - previous_wu_y) * cos(angle);
	point->wu_y = (previous_wu_x + previous_wu_y) * sin(angle) - point->wu_z;

	(void) height;
	(void) width;
	point->wu_x += (width / 2) + (WIDTH / 2);
	//point->wu_y += (height / 2);

}


void	draw_map(t_data *data)
{
	int		i;
	int		j;
	t_point	***points;
	t_point	*p0;
	t_point	*p1;
	t_point	*p2;

	i = 0;
	points = data->map->points;
	while (points[i])
	{
		j = 0;
		while (points[i][j])
		{
			p0 = points[i][j];
			if (points[i][j + 1])
			{
				p1 = data->map->points[i][j + 1];
				draw_AA_line_isometric(data, p0, p1);
			}
			if (points[i + 1] && points[i + 1][j])
			{
				p2 = data->map->points[i + 1][j];
				draw_AA_line_isometric(data, p0, p2);
			}
			j++;
		}
		i++;
	}
}

void	draw_on_image(t_data *data)
{
	//print_map_points(data->map);
	draw_map(data);
	reverse_t_points_row(data->map);
	draw_map(data);
	//draw_first_row(data, data->map->points);	
}
