/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializing_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 00:38:23 by inazaria          #+#    #+#             */
/*   Updated: 2024/06/03 20:47:14 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bzero_img_addr(t_image *img)
{
	ft_bzero(img->addr, WIDTH * HEIGHT * (img->bits_per_pixel / 8));
}

void	bzero_t_data(t_data *data)
{
	data->img = NULL;
	data->map = NULL;
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
}

void	bzero_t_map(t_map *map)
{
	map->height = 0;
	map->width = 0;
	map->points = NULL;
}

void	bzero_t_point(t_point *point)
{
	point->x = 0;
	point->y = 0;
	point->z = 0;
	point->color = 0;
}
