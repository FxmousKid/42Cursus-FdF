# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/02 21:20:18 by inazaria          #+#    #+#              #
#    Updated: 2024/05/03 16:51:39 by inazaria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC_FILES	:= $(wildcard ./src/*.c)
OBJ_FILES	:= $(SRC_FILES:.c=.o)

NAME		:= fdf
CC		 	:= clang
INC_DIR  	:= ./includes/
LIBFT_DIR	:= ./libft/
MLX_DIR		:= ./mlx_linux/
CFLAGS	 	:= -Wall -Wextra -Werror -g3 -I$(INC_DIR)
RM			:= rm -f


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
	@$(RM) $(OBJ)
	@echo "$(GREEN)All obj files have been deleted !$(END)"

fclean : 
	@echo "$(YELLOW)Deleting libft obj files...$(END)"
	@echo "$(YELLOW)Deleting libft.a...$(END)"
	@$(MAKE) --no-print-directory -C ./libft fclean
	@echo "$(YELLOW)Deleting mlx library...$(END)"
	@$(MAKE) --no-print-directory -C ./mlx_linux clean
	@echo "$(YELLOW)Deleting fdf obj files...$(END)"
	@$(RM) $(OBJ)
	@echo "$(YELLOW)Deleting fdf library...$(END)"
	@$(RM) $(NAME)
	@echo "$(GREEN)All files have been deleted !$(END)"

re : fclean all

.PHONY : all clean fclean re libft mlx
