/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_points_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 01:16:25 by inazaria          #+#    #+#             */
/*   Updated: 2024/05/30 16:55:39 by inazaria         ###   ########.fr       */
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
	(*point)->z = z_value;
	(*point)->wu_z = z_value;
}
