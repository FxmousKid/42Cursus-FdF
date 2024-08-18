/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:56:06 by inazaria          #+#    #+#             */
/*   Updated: 2024/08/18 01:52:31 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_no_event(t_data *data)
{
	(void) data;
	return (0);
}

void	handle_arrow_keys(int keysym, t_data *data)
{
	if (keysym == XK_Up)
	{
		reset_drawing(data);
		data->map->y_offset_add -= 5;
		draw_on_image(data);
	}
	if (keysym == XK_Down)
	{
		reset_drawing(data);
		data->map->y_offset_add += 5;
		draw_on_image(data);
	}
	if (keysym == XK_Left)
	{
		reset_drawing(data);
		data->map->x_offset_add -= 5;
		draw_on_image(data);
	}
	if (keysym == XK_Right)
	{
		reset_drawing(data);
		data->map->x_offset_add += 5;
		draw_on_image(data);
	}
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		printf_clr(RED_TXT, "Exiting fdf...\n");
		free_fdf(data);
	}
	handle_arrow_keys(keysym, data);
	return (0);
}

int	handle_destroy_notify(t_data *data)
{
	printf_clr(RED_TXT, "Exiting fdf...\n");
	free_fdf(data);
	return (0);
}

void	hook_controls(t_data *data)
{
	void	*win;

	win = data->win_ptr;
	mlx_loop_hook(data->mlx_ptr, &handle_no_event, data);
	mlx_hook(win, KeyPress, KeyPressMask, handle_keypress, data);
	mlx_hook(win, DestroyNotify, KeyReleaseMask, &handle_destroy_notify, data);
}
