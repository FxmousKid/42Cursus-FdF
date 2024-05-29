/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:28:58 by inazaria          #+#    #+#             */
/*   Updated: 2024/05/29 00:59:39 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

void	free_map(t_data *data)
{
	t_map	*map;

	map = data->map;
	free(map);
}

void	free_fdf(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img->image_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free_map(data);
	free(data->img);
}
