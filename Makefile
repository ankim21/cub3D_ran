# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ankim <ankim@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/28 18:41:05 by rabi-aka          #+#    #+#              #
#    Updated: 2026/03/03 13:20:48 by ankim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D
SRC_DIR		= sources
OBJS_DIR	= build
LIBFT_DIR	= libft
MLX_DIR		= minilibx-linux-master
MLX_FLAGS	= -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm
LIB_MLX		= make -C $(MLX_DIR)
LIBS		= -lft
SRC_EXT		= c
SRCS		=	$(SRC_DIR)/get_next_line.c\
				$(SRC_DIR)/free_game.c\
				$(SRC_DIR)/init_dda.c\
				$(SRC_DIR)/launch_mlx.c\
				$(SRC_DIR)/main.c\
				$(SRC_DIR)/raycasting.c\
				$(SRC_DIR)/rotations.c\
				$(SRC_DIR)/utils.c\
				$(SRC_DIR)/utils_spaces.c\
				$(SRC_DIR)/validity_args.c\
				$(SRC_DIR)/validity_file.c\
				$(SRC_DIR)/validity_file_infos.c\
				$(SRC_DIR)/validity_file_infos_colors.c\
				$(SRC_DIR)/validity_file_infos_textures.c\
				$(SRC_DIR)/validity_file_map.c\
				$(SRC_DIR)/validity_map_infos.c\
				$(SRC_DIR)/render.c\
				$(SRC_DIR)/move.c\

#$(patsubst pattern,replacement,input)
OBJS		= $(patsubst $(SRC_DIR)/%.$(SRC_EXT),$(OBJS_DIR)/%.o,$(SRCS))
RM			= -rm -rf
ECHO		= echo
YELLOW		= "\033[01;33m"
GREEN		= "\033[01;32m"
DEFAULT		= "\033[00;39m"
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g3
INC			= -Iinclude -I$(MLX_DIR)
LIBFT		=	$(LIBFT_DIR)/libft.a
LIBFT_FLAGS	=	-L $(LIBFT_DIR)

all : $(NAME)

$(LIBFT):
	@make -s -C $(LIBFT_DIR)

$(NAME) : $(LIBFT) $(OBJS)
	@$(ECHO) $(GREEN) "Module files compiled." $(DEFAULT)
	@make -s -C $(MLX_DIR)
	$(CC) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)
	@$(ECHO) $(GREEN) "Compilation successful." $(DEFAULT)

$(OBJS_DIR)/%.o : $(SRC_DIR)/%.$(SRC_EXT)
	@$(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean :
	$(RM) $(OBJS)
	@$(ECHO) $(YELLOW) "Module files removed." $(DEFAULT)
	@make -s -C $(LIBFT_DIR) clean
	@$(ECHO) $(YELLOW) "Libft files removed." $(DEFAULT)

fclean : clean
	$(RM) $(NAME)
	@$(ECHO) $(YELLOW) "Exec files removed." $(DEFAULT)
	@make -s -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(MLX_DIR) clean
	@$(ECHO) $(YELLOW) "Mlx cleaned." $(DEFAULT)

re : fclean all

.PHONY : all fclean clean re