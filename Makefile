# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: diomende <diomende@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/09 17:57:15 by diomende          #+#    #+#              #
#    Updated: 2025/07/22 15:28:32 by diomende         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC_DIR = src
MINILIBX_DIR = Minilibx
MINILIBX = $(MINILIBX_DIR)/libmlx.a
LIBFT_DIR = $(SRC_DIR)/Libft
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF_DIR = $(SRC_DIR)/ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

SRCS = $(SRC_DIR)/so_long.c \
       $(SRC_DIR)/map_reader.c \
       $(SRC_DIR)/map_checker_utils.c \
       $(SRC_DIR)/Initializer_utils.c \
       $(SRC_DIR)/Inputs.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = -L$(MINILIBX_DIR) -lmlx -lXext -lX11

all: $(MINILIBX) $(LIBFT) $(PRINTF) $(NAME)

$(MINILIBX):
	$(MAKE) -C $(MINILIBX_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
	
$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(OBJS) $(MINILIBX) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -L$(PRINTF_DIR) -lft -lftprintf $(MLX_FLAGS) -o $(NAME)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	$(MAKE) -C $(MINILIBX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
	$(MAKE) -C $(MINILIBX_DIR) clean

re: fclean all