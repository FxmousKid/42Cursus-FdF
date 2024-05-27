/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 19:03:12 by inazaria          #+#    #+#             */
/*   Updated: 2024/05/27 22:39:28 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_on_image(t_data *data)
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
