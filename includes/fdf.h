/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 21:44:13 by inazaria          #+#    #+#             */
/*   Updated: 2024/08/18 02:19:15 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/include/libft.h"
# include "../mlx_linux/mlx.h"
# include <math.h>
# include <stdarg.h>
# include <limits.h>
# include <unistd.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define BASE_16_LOWER "0123456789abcdef"

# define WIDTH  960
# define HEIGHT	540

# define SCALE 10
# define OFFSET 25
# define Z_SCALE 3
# define ANGLE 0.523598776

# define RED_TXT		"\e[0;31m"
# define GREEN_TXT		"\e[0;32m"
# define YELLOW_TXT		"\e[0;33m"
# define BLUE_TXT		"\e[0;34m"
# define PURPLE_TXT		"\e[0;35m"
# define CYAN_TXT		"\e[0;36m"
# define GREY_TXT		"\e[0;37m"
# define WHITE_TXT		"\e[0;39m"
# define BOLD_TXT		"\e[1m"
# define UNDERLINE_TXT	"\e[4m"
# define REVERSE_TXT	"\e[7m"
# define HIDDEN_TXT		"\e[8m"
# define END_TXT		"\e[0m"

# define WHITE_ARGB 0x00FFFFFF
# define RED_ARGB	0x00FF0000
# define GREEN_ARGB	0x0000FF00
# define BLUE_ARGB	0x000000FF
# define COLOR_MAX  0xFFFFFFFF

typedef struct s_point
{
	int			x;
	int			wu_x;
	int			y;
	int			wu_y;
	int			z;
	int			wu_z;
	size_t		color;
}				t_point;

typedef struct s_map
{
	t_point		***points;
	int			width;
	int			height;
	int			y_scale;
	int			x_scale;
	int			z_scale;
	int			x_offset;
	int			y_offset;
	int			scale_add;
	int			y_offset_add;
	int			x_offset_add;
}				t_map;

typedef struct s_image
{
	void	*image_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian_type;
}			t_image;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_image	*img;
	t_map	*map;
}			t_data;

/*
// OLD Parsing Functions
int		parse_map(t_map *map, int fd);
int		file_format_check(t_list *head);
int		parse_points_from_lines(t_map *map, t_list *head);
int		is_z_good(char *str);
void	assign_to_arr(int tab[2], int a, int b);
void	assign_z_and_wu_z(t_point **point, int z_value);
*/

// NEW Parsing Functions
int		get_scale(t_map *map);
int		parse_map(t_map *map, char *filepath);
int		parse_points(t_map *map, char *filepath);
void	reverse_t_points_row(t_map *map);

// Initializing Functions
void	bzero_t_data(t_data *data);
void	bzero_t_map(t_map *map);
void	bzero_t_point(t_point *point);
void	bzero_img_addr(t_image *img);
int		make_t_data(t_data *data, char *argv[]);
int		make_t_map(t_data *data, char *argv[]);
int		make_t_image(t_data *data);
int		fil_de_fer(char *argv[]);

// Drawing functions
void	my_mlx_pixel_put(t_image *img, int x, int y, int color);
void	draw_on_image(t_data *data);
void	change_background_color(t_image *img, int color);
void	draw_pixel_w_brightness(int x, int y, float brightness, t_data *data);
void	set_isometric_coords(t_point *point);
void	reset_drawing(t_data *data);
int		get_scale_value(t_map *map);

// Rotation & translation functions
void	create_matrix_rotation_x(float matrix[3][3], int angle);
void	create_matrix_rotation_y(float matrix[3][3], int angle);
void	create_matrix_rotation_z(float matrix[3][3], int angle);

// Xiaolin Wu's Line Algorithm
int		ipart(int x);
float	my_round(int x);
float	fpart(float x);
float	rfpart(float x);
void	init_wu_coord(char coord, int count, ...);
void	swap_wu_x(t_point *a, t_point *b);
void	swap_wu_y(t_point *a, t_point *b);
void	swap_wu_x_with_y(t_point *a, t_point *b);
void	swap_wu_y_with_x(t_point *a, t_point *b);
void	draw_aa_line(t_data *data, t_point *p0, t_point *p1);
void	draw_aa_line_isometric(t_data *data, t_point *p0, t_point *p1);
void	resetting_wu_coords(t_point *p0, t_point *p1);

// Utils Functions
void	ft_err(char *str);
void	print_exit_invalid_argc(void);
int		has_ocurrence(char c, char *charset);
int		count_occ(char *str, char c);
void	swap(void *a, void *b);
void	change_t_point_coords(t_point *point, int x, int y, int z);
void	print_point_info(t_point *point);
void	free_split(void **split);
void	print_point_wu_info(t_point *point);
void	print_map_with_wu_point(t_map *map);
void	print_map_points(t_map *map);
void	print_map_info_all_points(t_map *map);

// Hooking Functions
void	hook_controls(t_data *data);

// Functions to manage cascading-frees / quits
void	free_map(t_data *data);
void	free_points(t_map *map);
void	free_points_array(t_map *map);
void	free_fdf(t_data *data);
void	quit_mlx(t_data *data);
void	quit_img(t_data *data, t_image *img);
void	quit_win_mlx(t_data *data);
void	quit_win_mlx_img(t_data	*data);
void	quit_fdf(t_data *data);

#endif
