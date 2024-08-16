/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xiaolin_wu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:48:13 by inazaria          #+#    #+#             */
/*   Updated: 2024/08/16 19:06:45 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_if_steep(t_data *data, t_point *p0, t_point *p1, float grdt);
void	draw_if_n_steep(t_data *data, t_point *p0, t_point *p1, float grdt);

void	resetting_wu_coords(t_point *p0, t_point *p1)
{
	p0->wu_x = p0->x;
	p0->wu_y = p0->y;
	p0->wu_z = p0->z;
	p1->wu_x = p1->x;
	p1->wu_y = p1->y;
	p1->wu_z = p1->z;
}

void	swap_points_if_steep(int steep, t_point *p0, t_point *p1)
{
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
}

int	get_steep(t_point *p0, t_point *p1)
{
	int	steep;

	steep = abs((int) p1->wu_y - (int) p0->wu_y)
		> abs((int) p1->wu_x - (int) p0->wu_x);
	return (steep);
}

float	get_gradient(t_point *p0, t_point *p1)
{
	float	dx;
	float	dy;

	dx = p1->wu_x - p0->wu_x;
	dy = p1->wu_y - p0->wu_y;
	if (dx == 0.0)
		return (1.0);
	else
		return (dy / dx);
}

void	draw_aa_line(t_data *data, t_point *p0, t_point *p1)
{
	int		steep;
	float	gradient;

	steep = get_steep(p0, p1);
	swap_points_if_steep(steep, p0, p1);
	gradient = get_gradient(p0, p1);
	if (steep)
		draw_if_steep(data, p0, p1, gradient);
	else
		draw_if_n_steep(data, p0, p1, gradient);
	resetting_wu_coords(p0, p1);
}
