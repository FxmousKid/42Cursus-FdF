/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:56:06 by inazaria          #+#    #+#             */
/*   Updated: 2024/05/30 00:27:07 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <X11/X.h>

int	handle_no_event(t_data *data)
{
	(void) data;
	return (0);
}

int	handle_escape_press(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		printf_clr(RED_TXT, "Exiting fdf...\n");
		free_fdf(data);
	}
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
	mlx_hook(win, KeyPress, KeyPressMask, &handle_escape_press, data);
	mlx_hook(win, DestroyNotify, KeyReleaseMask, &handle_destroy_notify, data);
}
