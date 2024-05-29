/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_printing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:34:42 by inazaria          #+#    #+#             */
/*   Updated: 2024/05/30 01:00:16 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_err(char *str)
{
	if (str == NULL)
		return ;
	ft_putstr_fd(RED_TXT, 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(END_TXT, 2);
}

void	print_exit_invalid_argc(void)
{
	ft_printf("Invalid use of fdf.\n");
	ft_printf("Usage:");
	printf_clr(YELLOW_TXT, " ./fdf <path/to/map.fdf>\n");
	printf_clr(BOLD_TXT, "\nExited with code : ");
	printf_clr(RED_TXT, "1\n");
}
