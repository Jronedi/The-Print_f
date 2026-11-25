# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mojarone <mojarone@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/25 18:07:13 by mojarone          #+#    #+#              #
#    Updated: 2026/11/25 18:52:01 by mojarone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRCS = ft_puthexupper.c \
	   ft_putstr.c \
	   ft_putadress.c \
	   ft_puthexlower.c \
	   ft_putnbr.c \
	   ft_putunbr.c \
	   ft_putchar.c \
	   ft_printf.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(AR) $(NAME) $(OBJS)

%.o: %.c ft_printf.h
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re