/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_wu_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:37:38 by inazaria          #+#    #+#             */
/*   Updated: 2024/05/31 19:49:04 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	swap_wu_x(t_point *a, t_point *b)
{
	int	tmp;

	tmp = a->x;
	a->x = b->x;
	b->x = tmp;
}

void	swap_wu_y(t_point *a, t_point *b)
{
	int	tmp;

	tmp = a->y;
	a->y = b->y;
	b->y = tmp;
}

void	swap_wu_x_with_y(t_point *a, t_point *b)
{
	int	tmp;

	tmp = a->x;
	a->x = b->y;
	b->y = tmp;
}

void	swap_wu_y_with_x(t_point *a, t_point *b)
{
	int	tmp;

	tmp = a->y;
	a->y = b->x;
	b->x = tmp;
}
