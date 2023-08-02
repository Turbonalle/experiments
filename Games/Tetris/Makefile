# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbagger <jbagger@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 10:00:52 by jbagger           #+#    #+#              #
#    Updated: 2023/03/30 11:53:22 by jbagger          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tetris

FILES = main.c \
		colors.c \
		init_data.c \
		key_handler.c \
		img_handler.c

SRC_PATH = src
OBJ_PATH = obj

H_FRACTAL = incl/fractal.h
H_KEYS = incl/keys_windows.h
H_COLOR = incl/keys_mac.h

SRC = $(addprefix $(SRC_PATH)/,$(FILES))
OBJ = $(addprefix $(OBJ_PATH)/,$(FILES:.c=.o))

FLAGS = -Wall -Wextra -Werror

LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a

MLX_PATH = minilibx-linux
MLX = $(MLX_PATH)/libmlx.a

LIBS = -lm -lX11 -lXext -lbsd

.PHONY: all tmp clean fclean re

all: tmp $(NAME)

tmp:
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT_PATH)
	@$(MAKE) -C $(MLX_PATH)
	@$(CC) $(OBJ) -L$(MLX_PATH) -lmlx -L$(LIBFT_PATH) -lft $(LIBS) -o $(NAME)

clean:
	@$(MAKE) clean -C $(LIBFT_PATH)
	@$(MAKE) clean -C $(MLX_PATH)
	@/bin/rm -rf $(OBJ_PATH)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_PATH)
	@/bin/rm -f $(NAME)

re: fclean all