/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_points.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 00:51:05 by inazaria          #+#    #+#             */
/*   Updated: 2024/08/16 19:09:25 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_z_and_color(t_point **point, char *value)
{
	char	**z_and_color;

	z_and_color = ft_split(value, ',');
	if (!z_and_color)
		return (ft_err("Failed to split !\n"), 0);
	(*point)->z = ft_atoi(z_and_color[0]);
	(*point)->wu_z = (*point)->z;
	if (ft_strchr(value, ','))
		(*point)->color = ft_atoi_base_long(z_and_color[1], BASE_16_LOWER);
	else
		(*point)->color = WHITE_ARGB;
	free_split((void **) z_and_color);
	return (1);
}

int	parse_points_from_line(t_map *map, char **split_line, int height_idx)
{
	int		j;
	char	*value;
	t_point	*point;

	j = 0;
	while (split_line[j])
	{
		value = split_line[j];
		point = map->points[height_idx][j];
		point->x = j;
		point->wu_x = point->x;
		point->y = (height_idx);
		point->wu_y = point->y;
		if (!handle_z_and_color(&point, value))
			return (ft_err("Failed to handle_color_in_line()\n"), 0);
		j++;
	}
	return (1);
}

int	parse_points_from_list(t_map *map, t_list *head)
{
	char	**split;
	int		i;

	i = 0;
	while (head->next != NULL)
	{
		split = ft_split(head->content, ' ');
		if (!split)
			return (ft_err("Failed to split !\n"), 0);
		if (!parse_points_from_line(map, split, i))
			return (free_split((void **) split),
				ft_err("Failed to parse_points_from_line()\n"), 0);
		free_split((void **) split);
		head = head->next;
		i++;
	}
	return (1);
}

int	parse_points_info(t_map *map, int fd)
{
	char	*line;
	t_list	*head;

	line = get_next_line(fd);
	head = ft_lstnew(line);
	line = get_next_line(fd);
	while (line != NULL)
	{
		ft_lstadd_back(&head, ft_lstnew(line));
		line = get_next_line(fd);
	}
	if (!parse_points_from_list(map, head))
		return (ft_lstclear(&head, free),
			ft_err("Failed to parse_points_from_list()\n"), 0);
	ft_lstclear(&head, free);
	return (1);
}

int	parse_points(t_map *map, char *filepath)
{
	int	fd;

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		return (ft_err("Failed to open file\n"), 0);
	if (!parse_points_info(map, fd))
	{
		if (close(fd) < 0)
			ft_err("Failed to emergency close file\n");
		return (0);
	}
	if (close(fd) < 0)
		return (ft_err("Failed to close file\n"), 0);
	return (1);
}
