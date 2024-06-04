/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xiaolin_wu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:48:13 by inazaria          #+#    #+#             */
/*   Updated: 2024/06/04 21:14:27 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_AA_line(t_data *data, t_point *p0, t_point *p1)
{

	int steep = abs((int) p1->wu_y - (int) p0->wu_y) > 
				abs((int) p1->wu_x - (int) p0->wu_x);
	
	if (steep)
	{
		swap_wu_x_with_y(p0, p0);
		swap_wu_x_with_y(p1, p1);
	}
	
	if (p0->x > p1->x)
	{
		swap_wu_x(p0, p1);
		swap_wu_y(p0, p1);
	}

	float dx = p1->x - p0->x;
	float dy = p1->y - p0->y;
	float gradient;

	if (dx == 0.0)
		gradient = 1.0;
	else
		gradient = dy / dx;

	int xpxl1 = p0->x;
	int xpxl2 = p1->x;
	float intersect_y = p0->y;

	if (steep)
	{
		int x = xpxl1;
		while (x <= xpxl2)
		{
			draw_pixel_w_brightness(ipart(intersect_y), x, 
				rfpart(intersect_y), data);
			draw_pixel_w_brightness(ipart(intersect_y) - 1, x,
				fpart(intersect_y), data);
			intersect_y += gradient;
			x++;
		}
	}
	else
	{
		int x = xpxl1;
		while (x <= xpxl2)
		{
			draw_pixel_w_brightness(x, ipart(intersect_y), 
				rfpart(intersect_y), data);
			draw_pixel_w_brightness(x, ipart(intersect_y) - 1,
				fpart(intersect_y), data);
			intersect_y += gradient;
			x++;
		}
	}
}
