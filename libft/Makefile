# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/20 13:29:21 by fgreiff           #+#    #+#              #
#    Updated: 2025/08/28 16:33:02 by fgreiff          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	  ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	  ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	  ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
	  ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
	  ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c $(GNL_SRCS)
BONUS_SRCS = ft_lstmap.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
			ft_lstiter.c ft_lstlast.c ft_lstnew.c ft_lstsize.c 
NAME = libft.a
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I. -I$(GNL_DIR) -I$(PRINTF_DIR)
AR = ar rcs
GNL_DIR = get_next_line
GNL_SRCS = $(GNL_DIR)/get_next_line_bonus.c
PRINTF_DIR = printf

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(PRINTF_DIR)
	cp $(PRINTF_DIR)/libftprintf.a $(NAME)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

get_next_line:
	make -s -C get_next_line

bonus: $(NAME) $(BONUS_OBJS)
	$(AR) $(NAME) $(BONUS_OBJS)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

.PHONY: all clean fclean re
