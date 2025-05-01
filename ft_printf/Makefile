# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/14 17:39:25 by tfilipe-          #+#    #+#              #
#    Updated: 2025/04/14 17:39:31 by tfilipe-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror

SRCS =  ft_printf_putchar.c ft_printf_putstr.c ft_printf.c ft_putnbr_base.c \
		ft_putnbr_unsigned.c ft_putnbr.c ft_putptr.c


OBJS = $(SRCS:%.c=%.o)

RM = rm -f
AR = ar
ARFLAGS = rcs

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):  $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	@echo "Libftprintf successfully compiled"


clean:
	$(RM) $(OBJS)
	@echo "clean Objects removed"

fclean: clean
	$(RM) $(NAME)
	@echo "fclean Archive removed"

re: fclean all


.PHONY: all clean fclean re
