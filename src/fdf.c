/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 21:46:16 by inazaria          #+#    #+#             */
/*   Updated: 2024/05/18 19:05:36 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*make_image(void *mlx_ptr)
{	
	t_image	*img;

	img = (t_image *) ft_calloc(1, sizeof(t_image));
	if (img == NULL)
		return (ft_err("failed to calloc t_img\n"), NULL);
	img->image_ptr = mlx_new_image(mlx_ptr, WIDTH, HEIGHT);
	if (img->image_ptr == NULL)
		return (ft_err("img->image_ptr is NULL\n"), NULL);
	img->addr = mlx_get_data_addr(img->image_ptr,
							      &(img->bits_per_pixel), 
							      &(img->line_length),
								  &(img->endian_type));
	if (img->addr == NULL)
		return (ft_err("img->addr is NULL\n"), NULL);
	return (img);
}

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*pixel_addr;

	pixel_addr = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*((unsigned int *) pixel_addr) = color;
}

int	fil_de_fer(void)
{
	t_image *img;
	void	*mlx_ptr;
	void	*mlx_window;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (ft_err("Failed to mlx_init()\n"), 2);
	mlx_window = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "Fil de Fer"); // Add safety
	if (mlx_window == NULL)
		return (ft_err("failed to mlx_new_window()\n"), 3);
	img = make_image(mlx_ptr);
	if (img == NULL)
		return (ft_err("Failed to make image\n"), 4);

	draw_on_image(img);
	
	if (mlx_put_image_to_window(mlx_ptr, mlx_window, img->image_ptr, 0, 0) < 0)
		return (ft_err("Failed to mlx_put_image_to_window\n"), 5);	
	mlx_loop(mlx_ptr);
	return (0);
}

int main(void)
{
	int	fdf_result;

	fdf_result = fil_de_fer();
	return (fdf_result);
}
