/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_points.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:54:24 by inazaria          #+#    #+#             */
/*   Updated: 2024/05/30 16:55:32 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_color_and_z_value(t_point **point, char *vals)
{
	char		**z_and_color;
	long long	z_value;
	long long	color;

	if (count_occ(vals, ',') > 1 || !is_z_good(vals))
		return (ft_err("File is badly formatted !\n"), 0);
	(*point)->color = 0x00FFFFFF;
	z_and_color = ft_split(vals, ',');
	if (z_and_color == NULL)
		return (free_split(z_and_color), ft_err("Failed to split z\n"), 0);
	z_value = ft_atoi_long(z_and_color[0]);
	if (z_value > INT_MAX || z_value < INT_MIN)
		return (free_split(z_and_color), ft_err("Z value overflow int!\n"), 0);
	assign_z_and_wu_z(point, z_value);
	(*point)->color = 0x00FFFFFF;
	if (ft_strchr(vals, ','))
	{
		color = ft_atoi_base_long(z_and_color[1] + 2, "0123456789abcdef");
		if (color < 0 || color > COLOR_MAX)
			return (free_split(z_and_color), ft_err("Color not formated\n"), 0);
		(*point)->color = color;
	}
	return (free_split(z_and_color), 1);
}

int	alloc_point_in_array(t_point **point, char *vals, int x_y[2], int height)
{
	*point = (t_point *) ft_calloc(sizeof(t_point), 1);
	if (point == NULL)
		return (ft_err("Failed to calloc *t_point\n"), 0);
	(*point)->x = x_y[0];
	(*point)->wu_x = x_y[0];
	(*point)->y = height - x_y[1] - 1;
	(*point)->wu_y = height - x_y[1] - 1;

	if (!handle_color_and_z_value(point, vals))
		return (ft_err("Failed to handle_color_in_point()\n"), 0);
	return (1);
}

int	create_points_in_array(t_map *map, t_list *head, t_point ***points)
{
	int		i_j[2];
	int		x_y[2];
	char	**line_split;

	i_j[0] = 0;
	while (i_j[0] < map->height && head)
	{
		i_j[1] = 0;
		line_split = ft_split(head->content, ' ');
		if (line_split == NULL)
			return (ft_err("Failed to split line\n"), 0);
		while (i_j[1] < map->width)
		{
			assign_to_arr(x_y, i_j[1], i_j[0]);
			if (!alloc_point_in_array(&(points[i_j[0]][i_j[1]]),
				line_split[i_j[1]], x_y, map->height))
				return (ft_err("Failed to alloc_point_in_array()\n"),
					free_split(line_split), 0);
			(i_j[1])++;
		}
		(i_j[0])++;
		free_split(line_split);
		head = head->next;
	}
	return (1);
}

int	alloc_array_of_points(t_map *map, t_list *head, t_point ***points)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		points[i] = (t_point **) ft_calloc(sizeof(t_point *), map->width + 1);
		if (points[i] == NULL)
			return (ft_err("Failed to calloc **t_points\n"),
				free_points_array(map), 0);
		i++;
	}
	if (!create_points_in_array(map, head, points))
		return (ft_err("Failed to create_points_in_array()\n"),
			free_points(map), 0);
	return (1);
}

int	parse_points_from_lines(t_map *map, t_list *head)
{
	if (!file_format_check(head))
		return (ft_err("File is not correctly formatted !\n"), 0);
	map->height = ft_lstsize(head);
	map->width = count_words(head->content, ' ');
	map->points = (t_point ***) ft_calloc(sizeof(t_point **), map->height + 1);
	if (!(map->points))
		return (ft_err("Failed to calloc ***t_points\n"), 0);
	if (!alloc_array_of_points(map, head, map->points))
		return (ft_err("Failed to alloc_array_of_points()\n"), 0);
	return (1);
}
