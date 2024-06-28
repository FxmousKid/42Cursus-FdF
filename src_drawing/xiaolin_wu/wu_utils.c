/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wu_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:42:48 by inazaria          #+#    #+#             */
/*   Updated: 2024/06/28 04:25:34 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ipart(int x)
{
	return (floor(x));
}

float	my_round(int x)
{
	return (ipart(x + 0.5));
}

float	fpart(float x)
{
	if (x < 0)
		return (1 - (x - floor(x)));
	return (x - floor(x));
}

float	rfpart(float x)
{
	return (1 - fpart(x));
}

void	draw_pixel_w_brightness(int x, int y, float brightness, t_data *data)
{
	int		color;
	t_image	*img;
	size_t	intensity;

	img = data->img;
	intensity = (size_t) (255 * brightness);
	color = (intensity << 24) | intensity << 16 | intensity << 8 | intensity;
	my_mlx_pixel_put(img, x, y, color);
}
