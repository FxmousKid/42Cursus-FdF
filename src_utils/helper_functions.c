/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 19:15:17 by inazaria          #+#    #+#             */
/*   Updated: 2024/05/29 23:45:27 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	has_ocurrence(char c, char *charset)
{
	while (*charset)
	{
		if (*charset == c)
			return (1);
		charset++;
	}
	return (0);
}

void	free_z_and_color(char **z_and_color)
{
	free(z_and_color[0]);
	free(z_and_color[1]);
	free(z_and_color);
}

int	count_occ(char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
