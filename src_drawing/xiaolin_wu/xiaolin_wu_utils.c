/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xiaolin_wu_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:12:32 by inazaria          #+#    #+#             */
/*   Updated: 2024/08/16 17:03:41 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_if_steep(t_data *data, t_point *p0, t_point *p1, float grdt)
{
	float	intersect_y;
	int		x;

	x = p0->wu_x;
	intersect_y = p0->wu_y;
	while (x <= p1->wu_x)
	{
		draw_pixel_w_brightness(ipart(intersect_y), x,
			rfpart(intersect_y), data);
		draw_pixel_w_brightness(ipart(intersect_y) - 1, x,
			fpart(intersect_y), data);
		intersect_y += grdt;
		x++;
	}
}

void	draw_if_n_steep(t_data *data, t_point *p0, t_point *p1, float grdt)
{
	float	intersect_y;
	int		x;

	x = p0->wu_x;
	intersect_y = p0->wu_y;
	while (x <= p1->wu_x)
	{
		draw_pixel_w_brightness(x, ipart(intersect_y),
			rfpart(intersect_y), data);
		draw_pixel_w_brightness(x, ipart(intersect_y) - 1,
			fpart(intersect_y), data);
		intersect_y += grdt;
		x++;
	}
}
