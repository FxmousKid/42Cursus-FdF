/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:51:35 by inazaria          #+#    #+#             */
/*   Updated: 2024/05/27 22:41:29 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	quit_mlx(t_data *data)
{
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data);
}

void	quit_win_mlx(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	quit_mlx(data);
}

void	quit_win_mlx_img(t_data	*data)
{
	mlx_destroy_image(data->mlx_ptr, data->img->image_ptr);
	free(data->img);
	quit_win_mlx(data);
}

void	quit_img(t_data *data, t_image *img)
{
	mlx_destroy_image(data, img);
	free(img);
}

void	quit_fdf(t_data *data)
{
	free_map(data);
	quit_win_mlx_img(data);
}
