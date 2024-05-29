/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_t_list_content.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 01:32:10 by inazaria          #+#    #+#             */
/*   Updated: 2024/05/30 00:18:22 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_line_content(char *line)
{
	int	nl_flag;
	
	nl_flag = has_ocurrence('\n', line);
	while (line && *line)
	{
		if (!ft_isdigit(*line) && !has_ocurrence(*line, "xX, abcedf\n"))
				return (0);
		if (ft_strlen(line) == 1 && line[0] == '\n' && nl_flag == 0)
				return (0);
		line++;
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
