/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 21:46:16 by inazaria          #+#    #+#             */
/*   Updated: 2024/05/28 01:18:05 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx_linux/mlx.h"

int	make_t_image(t_data *data)
{
	t_image	*img;

	img = (t_image *) ft_calloc(1, sizeof(t_image));
	if (img == NULL)
		return (ft_err("Failed to calloc t_img\n"), 1);
	img->image_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	if (img->image_ptr == NULL)
		return (free(img), ft_err("Failed to mlx_new_window()\n"), 2);
	img->addr = mlx_get_data_addr(img->image_ptr,
			&(img->bits_per_pixel),
			&(img->line_length),
			&(img->endian_type));
	if (img->addr == NULL)
		return (quit_img(data, img), 
				ft_err("Failed to mlx_get_data_addr()\n"), 3);
	data->img = img;
	return (0);
}

int	make_t_data(t_data *data, char *argv[])
{
	int	map_stat;
	int	img_stat;

	bzero_t_data(data);
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (free(data), ft_err("Failed to mlx_init()\n"), 1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "Fil de Fer");
	if (data->win_ptr == NULL)
		return (quit_mlx(data), ft_err("Failed to mlx_new_window()\n"), 2);
	img_stat = make_t_image(data);
	if (img_stat != 0)
		return (quit_win_mlx(data),
			ft_err("Failed to make_t_image()\n"), img_stat);
	map_stat = make_t_map(data, argv);
	if (map_stat != 0)
		return (quit_win_mlx_img(data),
			ft_err("Failed to make_t_map()\n"), map_stat);
	return (0);
}

int	fil_de_fer(char *argv[])
{
	t_data	*data;
	int		data_making_status;
	int		mlx_put_image_status;

	data = (t_data *) ft_calloc(sizeof(t_data), 1);
	if (data == NULL)
		return (ft_err("Failed to calloc t_data\n"), 1);
	data_making_status = make_t_data(data, argv);
	if (data_making_status != 0)
		return (ft_err("Failed to make_t_data()\n"), data_making_status);
	draw_on_image(data); // add safety check
	mlx_put_image_status = mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->image_ptr, 0, 0);
	if (mlx_put_image_status != 1)
		return (ft_err("Failed to mlx_put_image_to_window()\n"),
			quit_fdf(data), mlx_put_image_status);
	hook_controls(data);
	mlx_loop(data->mlx_ptr);
	quit_mlx(data);
	return (0);
}

int	main(int argc, char *argv[])
{
	int	fdf_result;

	if (argc != 2)
		return (print_exit_invalid_argc(), -1);
	fdf_result = fil_de_fer(argv);
	printf_clr(BOLD_TXT, "\nExited with code : ");
	if (fdf_result == 0)
		printf_clr(GREEN_TXT, "%d\n", fdf_result);
	else
		printf_clr(RED_TXT, "%d\n", fdf_result);
	return (fdf_result);
}
