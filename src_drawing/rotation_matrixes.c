/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrixes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:53:01 by inazaria          #+#    #+#             */
/*   Updated: 2024/05/31 16:56:30 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_matrix_rotation_y(float matrix[3][3], int angle)
{
	matrix[0][0] = cos(angle);
	matrix[0][1] = 0;
	matrix[0][2] = sin(angle);
	matrix[1][0] = 0;
	matrix[1][1] = 1;
	matrix[1][2] = 0;
	matrix[2][0] = -sin(angle);
	matrix[2][1] = 0;
	matrix[2][2] = cos(angle);
}

void	create_matrix_rotation_x(float matrix[3][3], int angle)
{
	matrix[0][0] = 1;
	matrix[0][1] = 0;
	matrix[0][2] = 0;
	matrix[1][0] = 0;
	matrix[1][1] = cos(angle);
	matrix[1][2] = -sin(angle);
	matrix[2][0] = 0;
	matrix[2][1] = sin(angle);
	matrix[2][2] = cos(angle);
}

void	create_matrix_rotation_z(float matrix[3][3], int angle)
{
	matrix[0][0] = cos(angle);
	matrix[0][1] = -sin(angle);
	matrix[0][2] = 0;
	matrix[1][0] = sin(angle);
	matrix[1][1] = cos(angle);
	matrix[1][2] = 0;
	matrix[2][0] = 0;
	matrix[2][1] = 0;
	matrix[2][2] = 1;
}
