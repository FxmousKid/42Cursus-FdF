/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 19:06:02 by inazaria          #+#    #+#             */
/*   Updated: 2024/06/04 20:59:11 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
