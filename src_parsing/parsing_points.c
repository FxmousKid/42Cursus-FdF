/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_points.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:54:24 by inazaria          #+#    #+#             */
/*   Updated: 2024/05/30 00:32:49 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	parse_points_from_lines(t_map *map, t_list *head)
{
	if (!file_format_check(head))
		return (ft_err("File is not correctly formatted !\n"), 0);
	map->height = ft_lstsize(head); // 11
	map->width = count_words(head->content, ' '); // 19
	map->points = (t_point ***) ft_calloc(sizeof(t_point **), map->height + 1);
	if (!(map->points))
		return (ft_err("Failed to calloc ***t_points\n"), 0);
	if (!alloc_array_of_points(map, head, map->points))
		return (ft_err("Failed to alloc_array_of_points()\n"), 0);

	//print_map_points(map);

	/*
	
	// Null Terminating the double arrays and the arrays
	tmp_point = map->points;
	tmp_head = head;
	i = 0;
	//ft_printf("map->height = %p\n", (*tmp_point)[map->height]);
	//tmp_point[map->height] = NULL;

	
	// Allocating space for my *t_point
	while (tmp_head != NULL)
	{
		i = 0;
		while (i <= map->width)
		{
			(*tmp_point)[i] = (t_point *) ft_calloc(sizeof(t_point), 1);
			if (!((*tmp_point)[i]))
				return (free_points(map), ft_err("Failed to calloc *t_point\n"), 0);
			i++;
		}
		tmp_head = tmp_head->next;
		(*tmp_point)++;
	}


	// Now to fill the *t_point
	tmp_head = head;
	tmp_point = map->points;
	char **line_split;
	i = 0;
	int j = 0;
	t_point	*current_point;

	while (i <= map->height)
	{
		j = 0;
		while (j <= map->width)
		{
			if (strchr(tmp_head->content, ','))
				return (0); // TO CALL ANOTHER FUNCTION TO HANDLE COLOR
			current_point = tmp_point[i][j];
			line_split = ft_split(tmp_head->content, ' ');
			current_point->x = j;
			current_point->y = map->height - i - 1;
			current_point->z = ft_atoi(line_split[0]);
			j++;
		}
		i++;
		tmp_head = tmp_head->next;
	}

	// no to display the points :
	i = 0;
	j = 0;
	while (i <= map->height)
	{
		j = 0;
		while (j <= map->width)
		{
			ft_printf("x = %d, y = %d, z = %d\n", map->points[i][j]->x, map->points[i][j]->y, map->points[i][j]->z);
			j++;
		}
		i++;
	}
	*/
	return (1);
}

