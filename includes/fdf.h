/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 21:44:13 by inazaria          #+#    #+#             */
/*   Updated: 2024/05/18 19:05:35 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/include/libft.h"
# include "../mlx_linux/mlx.h"
# include <math.h>

# define WIDTH 1920 / 2
# define HEIGHT 1080 / 2

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
}				t_point;

typedef struct s_image
{
	void	*image_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian_type;
}				t_image;

void	ft_err(char *str);
int		fil_de_fer(void);
void	my_mlx_pixel_put(t_image *img, int x, int y, int color);
void	draw_on_image(t_image *img);



#endif
