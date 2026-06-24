# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/21 12:06:22 by fgreiff           #+#    #+#              #
#    Updated: 2025/09/30 17:30:03 by fgreiff          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
MLX_FLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm
INCLUDES = -I. -I$(LIBFT_DIR)
AR = ar rcs

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

SRCS = so_long.c map_parsing.c map_parsing_2.c parsing_utils.c utils.c create_map.c \
	game.c exit_utils.c 

all: $(NAME)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

libft:
	make -s -C libft
	
clean:
	rm -f $(OBJS)
	make clean -C libft 

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re