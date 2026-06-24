# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/30 15:22:40 by fgreiff           #+#    #+#              #
#    Updated: 2025/06/06 12:02:56 by fgreiff          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I. 
AR = ar rcs

SRCS = ft_printf.c ft_printid.c ft_printx.c ft_printp.c \
	ft_printu.c ft_putchar.c ft_putstr.c

all:$(NAME) 

$(NAME): $(OBJS) 
		$(AR) $(NAME) $(OBJS)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJS)
		
fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

