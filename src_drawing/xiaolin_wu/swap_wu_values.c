/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_wu_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:37:38 by inazaria          #+#    #+#             */
/*   Updated: 2024/06/11 19:44:30 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	swap_wu_x(t_point *a, t_point *b)
{
	int	tmp;

	tmp = a->wu_x;
	a->wu_x = b->wu_x;
	b->wu_x = tmp;
}

void	swap_wu_y(t_point *a, t_point *b)
{
	int	tmp;

	tmp = a->wu_y;
	a->wu_y = b->wu_y;
	b->wu_y = tmp;
}

void	swap_wu_x_with_y(t_point *a, t_point *b)
{
	int	tmp;

	tmp = a->wu_x;
	a->wu_x = b->wu_y;
	b->wu_y = tmp;
}

void	swap_wu_y_with_x(t_point *a, t_point *b)
{
	int	tmp;

	tmp = a->wu_y;
	a->wu_y = b->wu_x;
	b->wu_x = tmp;
}
