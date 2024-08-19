# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/02 21:20:18 by inazaria          #+#    #+#              #
#    Updated: 2024/08/19 11:23:29 by inazaria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PASRING_DIR		= ./src_parsing/
C_FILES_PARSING		= parse_map.c
C_FILES_PARSING		+= parsing_utils.c
C_FILES_PARSING		+= parse_points.c
SRC_FILES_PARSING	= $(addprefix $(SRC_PASRING_DIR), $(C_FILES_PARSING))

    

SRC_DRAWING_DIR		= ./src_drawing/
C_FILES_DRAWING		= drawing.c
C_FILES_DRAWING		+= drawing_utils.c
C_FILES_DRAWING		+= reset_drawing.c
C_FILES_DRAWING		+= rotation_matrixes.c
C_FILES_DRAWING		+= isometric_projection.c
SRC_FILES_DRAWING	= $(addprefix $(SRC_DRAWING_DIR), $(C_FILES_DRAWING))

SRC_XIAOLIN_WU_DIR		= ./src_drawing/xiaolin_wu/
C_FILES_XIAOLIN_WU		= xiaolin_wu.c
C_FILES_XIAOLIN_WU		+= xiaolin_wu_utils.c
C_FILES_XIAOLIN_WU		+= wu_utils.c
C_FILES_XIAOLIN_WU		+= swap_wu_values.c
C_FILES_XIAOLIN_WU		+= re_initialize_wu_values.c
SRC_FILES_XIAOLIN_WU	= $(addprefix $(SRC_XIAOLIN_WU_DIR), $(C_FILES_XIAOLIN_WU))

SRC_EXIT_FDF_DIR	= ./src_exit_fdf/
C_FILES_EXIT_FDF	= free_fdf.c
C_FILES_EXIT_FDF	+= quit_fdf.c
C_FILES_EXIT_FDF	+= error_printing.c
SRC_FILES_EXIT_FDF	= $(addprefix $(SRC_EXIT_FDF_DIR), $(C_FILES_EXIT_FDF))

SRC_UTILS_DIR		= ./src_utils/
C_FILES_UTILS		= initializing_utils.c
C_FILES_UTILS		+= helper_functions.c
C_FILES_UTILS		+= debugging_functions.c
SRC_FILES_UTILS		= $(addprefix $(SRC_UTILS_DIR), $(C_FILES_UTILS))

SRC_HOOKS_DIR		= ./src_hooks/
C_FILES_HOOKS		= hooks.c
SRC_FILES_HOOKS		= $(addprefix $(SRC_HOOKS_DIR), $(C_FILES_HOOKS))

SRC_FILES   = fdf.c
SRC_FILES  += $(SRC_FILES_PARSING)
SRC_FILES  += $(SRC_FILES_DRAWING)
SRC_FILES  += $(SRC_FILES_EXIT_FDF)
SRC_FILES  += $(SRC_FILES_UTILS)
SRC_FILES  += $(SRC_FILES_HOOKS)
SRC_FILES  += $(SRC_FILES_XIAOLIN_WU)

OBJ_FILES	:= $(SRC_FILES:.c=.o)

NAME		:= fdf
CC		 	:= clang
INC_DIR  	:= ./includes/
LIBFT_DIR	:= ./libft/
MLX_DIR		:= ./mlx_linux/
CFLAGS	 	:= -Wall -Wextra -Werror -g3 -I$(INC_DIR)
RM			:= rm -f
CAT 		:= cat

BLUE		:= $(shell echo -e "\033[34m") 
YELLOW		:= $(shell echo -e "\033[33m")
GREEN		:= $(shell echo -e "\033[32m")
END			:= $(shell echo -e "\033[0m")

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)


$(NAME) : $(OBJ_FILES) mlx libft
	@$(CC) $(CFLAGS) $(OBJ_FILES) -Lmlx_linux -lmlx -lXext -lX11 -lm -lz libft/libft.a -o $(NAME)
	@echo "$(GREEN)$(NAME) has been created$(END)"

mlx : 
	@echo "$(YELLOW)Creating mlx library$(END)"
	@$(MAKE) --no-print-directory -C $(MLX_DIR)
	@echo "$(GREEN)Mlx library has been created$(END)"

libft :
	@echo "$(YELLOW)Creating libft library$(END)"
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) all
	@echo "$(GREEN)Libft library has been created$(END)"

clean :
	@echo "$(YELLOW)Deleting libft obj files...$(END)"
	@$(MAKE) --no-print-directory -C ./libft clean
	@echo "$(YELLOW)Deleting mlx obj files...$(END)"
	@$(MAKE) --no-print-directory -C ./mlx_linux clean
	@echo "$(YELLOW)Deleting fdf obj files...$(END)"
	@$(RM) $(OBJ_FILES)
	@echo "$(GREEN)All obj files have been deleted !$(END)"

fclean : 
	@echo "$(YELLOW)Deleting libft obj files...$(END)"
	@echo "$(YELLOW)Deleting libft.a...$(END)"
	@$(MAKE) --no-print-directory -C ./libft fclean
	@echo "$(YELLOW)Deleting mlx library...$(END)"
	@$(MAKE) --no-print-directory -C ./mlx_linux clean
	@echo "$(YELLOW)Deleting fdf obj files...$(END)"
	@$(RM) $(OBJ_FILES)
	@echo "$(YELLOW)Deleting fdf library...$(END)"
	@$(RM) $(NAME)
	@echo "$(GREEN)All files have been deleted !$(END)"

re : fclean all

.PHONY : all clean fclean re libft mlx
