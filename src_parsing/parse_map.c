/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:26:18 by inazaria          #+#    #+#             */
/*   Updated: 2024/05/28 01:55:27 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* A line of the map file looks like this :
 * "x1,c1 x2,c2 x3,c3 ..."      <--- x_n is a int representing the z coordinate
 *					           	     c_n is a int representing the color
 * 
 * we have to split on the " " to get :
 * {"x1,c1", "x2,c2", "x3,c3", ...}
 *
 * we again have to split, now on the "," to get
 * {{"x1", "c1"}, {"x2", "c2"}, {"x3", "c3"}, ...}
 *
 * and now we can use these **int to make the many *point
 *
 **/

int	parse_map(t_data *data, t_map *map, int fd)
{
	char	*line;

	line = get_next_line(fd);
	bzero_t_map(map);
	free(line);


	data->map = map;
	return (0);
}

int	make_t_map(t_data *data, char *argv[])
{
	t_map	*map;
	int		fd;
	int		map_status;

	map = (t_map *) ft_calloc(sizeof(t_map), 1);
	if (map == NULL)
		return (ft_err("Failed to calloc t_map\n"), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (free(map), ft_err("Failed to open file\n"), 2);
	map_status = parse_map(data, map, fd);
	if (map_status != 0)
		return (free(map), ft_err("Failed to parse_map()\n"), 3);
	data->map = map;
	return (0);
}
