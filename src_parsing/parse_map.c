/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:26:18 by inazaria          #+#    #+#             */
/*   Updated: 2024/05/30 00:48:01 by inazaria         ###   ########.fr       */
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

int	parse_file(t_map *map, int fd)
{
	char	*line;
	t_list	*head;

	line = get_next_line(fd);
	if (!line)
		return (ft_err("File is empty ! !\n"), 0);
	head = ft_lstnew(line);
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_lstadd_back(&head, ft_lstnew(line));
	}
	if (!parse_points_from_lines(map, head))
		return (ft_lstclear(&head, free),
			ft_err("Failed to parse_points_from_lines()\n"), 0);
	ft_lstclear(&head, free);
	return (1);
}

int	parse_map(t_data *data, t_map *map, int fd)
{
	bzero_t_map(map);
	if (!parse_file(map, fd))
		return (ft_err("Failed to parse_file()\n"), 0);
	data->map = map;
	return (1);
}

int	make_t_map(t_data *data, char *argv[])
{
	t_map	*map;
	int		fd;

	map = (t_map *) ft_calloc(sizeof(t_map), 1);
	if (!map)
		return (ft_err("Failed to calloc t_map\n"), 0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (free(map), ft_err("Failed to open file\n"), 0);
	if (!parse_map(data, map, fd))
		return (free(map), ft_err("Failed to parse_map()\n"), 0);
	data->map = map;
	return (1);
}
