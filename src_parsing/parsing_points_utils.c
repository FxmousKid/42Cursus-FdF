/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_points_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 01:16:25 by inazaria          #+#    #+#             */
/*   Updated: 2024/05/30 01:37:45 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_z_good(char *str)
{
	while (*str && *str != ',')
	{
		if (!ft_isdigit(*str) && *str != '\n' && *str != '-')
			return (0);
		str++;
	}
	return (1);
}
