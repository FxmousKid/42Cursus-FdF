/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 19:03:12 by inazaria          #+#    #+#             */
/*   Updated: 2024/06/04 21:21:44 by inazaria         ###   ########.fr       */
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

void	test_line_drawing(t_data *data)
{
	t_point		*p0;
	t_point		*p1;

	p0 = (t_point *)malloc(sizeof(t_point));
	p1 = (t_point *)malloc(sizeof(t_point));

	p0->x = 100;
	p0->y = 100;
	p0->wu_x = 100;
	p0->wu_y = 100;

	p1->x = 400;
	p1->y = 400;
	p1->wu_x = 400;
	p1->wu_y = 400;

	draw_AA_line(data, p0, p1);
	free(p0);
	free(p1);
}
