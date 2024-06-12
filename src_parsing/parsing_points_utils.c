/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_points_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 01:16:25 by inazaria          #+#    #+#             */
/*   Updated: 2024/06/12 01:47:12 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_z_good(char *str)
{
	while (str && *str && *str != ',')
	{
		if (!ft_isdigit(*str) && *str != '\n' && *str != '-')
			return (0);
		str++;
	}
	return (1);
}

void	assign_z_and_wu_z(t_point **point, long long z_value)
{
	(*point)->z = ((int) z_value) * Z_SCALE;
	(*point)->wu_z = (*point)->z;
}

/*
*  The problem i am encountering is that the file is being parsed
*  from top to bottom, which if simply parsed, will result in the
*  y coordinate of the first point of the first line to be 0, where
*  it's supposed to be number of  rows in the file - 1.
*
*  To fix this, i am parsing the points by substracting the index 
*  of the row to the total number of rows - 1, so that the y coord
*  is correct.
*
*  However i still want to reverse the rows, so 1st row becomes last,
*  2nd row becomes 2nd last and so on. So i'll reverse the t_points **.
*
*  This way the 1st point i draw is the 1st point in the file from the 
*  bottom left corner.
*
*  the way i'll reverse is simple :
*
*	------>		Row 1: [A, B, C, ...];
*	|  |-->		Row 2 : [A', B', C', ...];
*	|  |		.
*	|  |		.
*	|  |		.
*	|  |-->		Row n-1 : [X, Y, Z, ...];
*	------>		Row n : [X', Y', Z', ...];
*
* */

void	reverse_t_points_row(t_map *map)
{
	int		i;
	int		height;
	t_point	**tmp_row;
	t_point	***points;

	points = map->points;
	i = 0;
	height = map->height;
	while (i < height)
	{
		tmp_row = points[i];
		points[i] = points[height - 1];
		points[height - 1] = tmp_row;
		i++;
		height--;
	}	
}
