/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 21:46:16 by inazaria          #+#    #+#             */
/*   Updated: 2024/08/10 15:32:47 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	make_t_map(t_data *data, char **argv)
{
	t_map	*map;

	map = (t_map *) ft_calloc(sizeof(t_map), 1);
	if (!map)
		return (ft_err("Failed to calloc t_map\n"), 0);
	if (!parse_map(map, argv[1]))
		return (free(map), ft_err("Failed to parse_map()\n"), 0);
	data->map = map;
	return (1);
}

int	make_t_image(t_data *data)
{
	t_image	*img;

	img = (t_image *) ft_calloc(1, sizeof(t_image));
	if (!img)
		return (ft_err("Failed to calloc t_img\n"), 0);
	img->image_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	if (!(img->image_ptr))
		return (free(img), ft_err("Failed to mlx_new_window()\n"), 0);
	img->addr = mlx_get_data_addr(img->image_ptr,
			&(img->bits_per_pixel),
			&(img->line_length),
			&(img->endian_type));
	if (!(img->addr))
		return (quit_img(data, img),
			ft_err("Failed to mlx_get_data_addr()\n"), 0);
	data->img = img;
	return (1);
}

int	make_t_data(t_data *data, char *argv[])
{
	bzero_t_data(data);
	data->mlx_ptr = mlx_init();
	if (!(data->mlx_ptr))
		return (free(data), ft_err("Failed to mlx_init()\n"), 0);
	if (!make_t_map(data, argv))
		return (quit_mlx(data), ft_err("Failed to make_t_map()\n"), 0);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "Fil de Fer");
	if (!(data->win_ptr))
		return (quit_mlx(data), free_map(data),
			ft_err("Failed to mlx_new_window()\n"), 0);
	if (!make_t_image(data))
		return (quit_win_mlx(data),
			ft_err("Failed to make_t_image()\n"), 0);
	return (1);
}

int	fil_de_fer(char *argv[])
{
	t_data	*data;
	int		mlx_put_image_status;

	data = (t_data *) ft_calloc(sizeof(t_data), 1);
	if (!data)
		return (ft_err("Failed to calloc t_data\n"), 0);
	if (!make_t_data(data, argv))
		return (ft_err("Failed to make_t_data()\n"), 0);
	draw_on_image(data);
	mlx_put_image_status = mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->image_ptr, 0, 0);
	if (!mlx_put_image_status)
		return (ft_err("Failed to mlx_put_image_to_window()\n"),
			quit_fdf(data), 0);
	hook_controls(data);
	mlx_loop(data->mlx_ptr);
	quit_mlx(data);
	return (1);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		print_exit_invalid_argc();
		return (1);
	}
	if (fil_de_fer(argv))
	{
		printf_clr(GREEN_TXT, "Successfully exited fdf !\n");
		printf_clr(BOLD_TXT, "\nExited with code : ");
		printf_clr(GREEN_TXT, "0\n");
		return (0);
	}
	printf_clr(BOLD_TXT, "\nExited with code : ");
	printf_clr(RED_TXT, "1\n");
	return (1);
}
