/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:58:32 by inazaria          #+#    #+#             */
/*   Updated: 2024/08/16 19:16:33 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	verify_map_dimensions(int height_width[2], int fd)
{
	char	*line;
	int		current_width;

	line = get_next_line(fd);
	if (!line)
		return (ft_err("File is Empty !\n"), 0);
	height_width[0]++;
	height_width[1] = count_words(line, ' ');
	free(line);
	line = get_next_line(fd);
	while (line)
	{
		height_width[0]++;
		current_width = count_words(line, ' ');
		if (current_width != height_width[1])
			return (free(line), 0);
		free(line);
		line = get_next_line(fd);
	}
	return (1);
}

int	check_and_get_map_dimensions(char *filepath, int height_width[2])
{
	int	fd;	

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		return (ft_err("Failed to open file\n"), 0);
	if (!verify_map_dimensions(height_width, fd))
		return (ft_err("File Incorrectly Formatted !\n"), 0);
	if (close(fd) < 0)
		return (ft_err("Failed to Close File !\n"), 0);
	return (1);
}

int	allocate_points(t_point ***points, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		points[i] = (t_point **) ft_calloc(sizeof(t_point *), map->width + 1);
		if (!points[i])
			return (free_split((void **) *points), 0);
		j = 0;
		while (j < map->width)
		{
			points[i][j] = (t_point *) ft_calloc(sizeof(t_point), 1);
			if (!points[i][j])
				return (map->points = points, free_points(map), 0);
			j++;
		}
		i++;
	}
	return (1);
}

int	parse_map(t_map *map, char *filepath)
{
	int		height_width[2];
	t_point	***points;

	height_width[0] = 0;
	height_width[1] = 0;
	if (!check_and_get_map_dimensions(filepath, height_width))
		return (ft_err("Failed to check_and_get_map_dimensions()\n"), 0);
	map->height = height_width[0] - 1;
	map->width = height_width[1];
	points = (t_point ***) ft_calloc(sizeof(t_point **), map->height + 1);
	if (!points)
		return (ft_err("Failed to calloc t_points ***\n"), 0);
	if (!allocate_points(points, map))
		return (ft_err("Failed to allocate_points()\n"), 0);
	map->points = points;
	if (!parse_points(map, filepath))
		return (free_points(map),
			ft_err("Failed to parse_points()\n"), 0);
	return (1);
}
