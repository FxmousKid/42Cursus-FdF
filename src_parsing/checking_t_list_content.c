/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_t_list_content.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 01:32:10 by inazaria          #+#    #+#             */
/*   Updated: 2024/05/29 01:57:11 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_line_content(char *line)
{
	int	i;

	i = 0;
	ft_printf("line = %s\n", line);
	while (line[i])
	{
		if (!ft_isdigit(line[i]) &&
			line[i] != ' ' &&
			line[i] != 'x' &&
			line[i] != 'X' &&
			line[i] != ',' &&
			line[i] != '\n' &&
			(ft_strlen(line) != 1 && line[i] != '\n'))
				return (ft_printf("line[%d] = '%c'", i, line[i]), 0);
		i++;
	}
	return (1);
}

int	check_line_len(t_list *head, char *line)
{
	int	len_nth_line;
	int	len_1st_line;

	len_1st_line = count_words(head->content, ' ');
	len_nth_line = count_words(line, ' ');
	return (len_1st_line == len_nth_line);
}

int	file_format_check(t_list *head)
{
	t_list	*head_lst;

	head_lst = head;
	while (head)
	{
		if (!check_line_len(head_lst, head->content))
			return (0);
		if (!check_line_content(head->content))
			return (0);
		head = head->next;
	}
	return (1);
}
