/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_initialize_wu_values.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:04:08 by inazaria          #+#    #+#             */
/*   Updated: 2024/05/31 19:30:29 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	re_init_wu_x(int count, va_list args)
{
	t_point	*point;

	while (count-- > 0)
	{
		point = va_arg(args, t_point *);
		point->wu_x = point->x;
	}
}

void	re_init_wu_y(int count, va_list args)
{
	t_point	*point;

	while (count-- > 0)
	{
		point = va_arg(args, t_point *);
		point->wu_y = point->y;
	}
}

void	re_init_wu_z(int count, va_list args)
{
	t_point	*point;

	while (count-- > 0)
	{
		point = va_arg(args, t_point *);
		point->wu_z = point->z;
	}
}

void	init_wu_coord(char coord, int count, ...)
{
	va_list	args;

	va_start(args, count);
	if (coord == 'x')
		re_init_wu_x(count, args);
	else if (coord == 'y')
		re_init_wu_y(count, args);
	else if (coord == 'z')
		re_init_wu_z(count, args);
	va_end(args);	
}
