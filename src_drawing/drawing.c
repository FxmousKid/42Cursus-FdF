/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 19:03:12 by inazaria          #+#    #+#             */
/*   Updated: 2024/06/12 03:40:11 by inazaria         ###   ########.fr       */
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
	int	previous_wu_x;
	int	previous_wu_y;

	previous_wu_x = point->wu_x;
	previous_wu_y = point->wu_y;
	point->wu_x = (previous_wu_x - previous_wu_y) * cos(ANGLE);
	point->wu_y = (previous_wu_x + previous_wu_y) * sin(ANGLE) - point->z;

	(void)height;
	(void)width;

	point->wu_x += WIDTH / 2;
	//point->wu_x += (width / 2) + (WIDTH / 2);
	//point->wu_y += (height / 2);

}


void	draw_map(t_data *data)
{
	int		i;
	int		j;
	t_point	*p0;
	t_point	*p1;
	t_point	*p2;

	i = data->map->height - 1;
	while (i > 0)
	{
		j = data->map->width - 1;
		while (j > 0)
		{
			p0 = data->map->points[i][j];
			if (j - 1 > 0)
			{
				p1 = data->map->points[i][j - 1];
				draw_AA_line_isometric(data, p0, p1);
			}
			if (i - 1 > 0)
			{
				p2 = data->map->points[i - 1][j];
				draw_AA_line_isometric(data, p0, p2);
			}
			j--;
		}
		i--;
	}
}

void	draw_on_image(t_data *data)
{
	draw_map(data);
	//print_map_points(data->map);
	//draw_first_row(data, data->map->points);	
}
