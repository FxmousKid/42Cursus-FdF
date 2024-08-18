/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 19:06:02 by inazaria          #+#    #+#             */
/*   Updated: 2024/08/18 02:18:08 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_t_point_coords(t_point *point, int x, int y, int z)
{
	point->x = x;
	point->y = y;
	point->z = z;
	point->wu_x = x;
	point->wu_y = y;
	point->wu_z = z;
	point->color = 0xFFFFFF;
}

void	change_background_color(t_image *img, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			my_mlx_pixel_put(img, x, y, color);
			x++;
		}
		y++;
	}
}

int	get_center_x(void)
{
	int	center_x;

	center_x = (WIDTH / 2);
	return (center_x);
}

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*pixel_addr;

	pixel_addr = img->addr + \
		(y * img->line_length + x * (img->bits_per_pixel / 8));
	*((unsigned int *) pixel_addr) = color;
}

int	get_scale_value(t_map *map)
{
	t_point	corners[4];
	int		dx;
	int		dy;

	corners[0] = *(map->points[0][0]);
	corners[1] = *(map->points[0][map->width - 1]);
	corners[2] = *(map->points[map->height - 1][0]);
	corners[3] = *(map->points[map->height - 1][map->width - 1]);
	set_isometric_coords(&corners[0]);
	set_isometric_coords(&corners[1]);
	set_isometric_coords(&corners[2]);
	set_isometric_coords(&corners[3]);
	dx = WIDTH / (corners[1].wu_x - corners[2].wu_x);
	dy = HEIGHT / (corners[0].wu_y - corners[3].wu_y);
	if (dx > dy)
		return (dx);
	return (dy);
}
