/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:34:42 by inazaria          #+#    #+#             */
/*   Updated: 2024/05/27 22:41:03 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_err(char *str)
{
	if (str == NULL)
		return ;
	ft_putstr_fd(str, 2);
}

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*pixel_addr;

	pixel_addr = img->addr + \
		(y * img->line_length + x * (img->bits_per_pixel / 8));
	*((unsigned int *) pixel_addr) = color;
}

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
