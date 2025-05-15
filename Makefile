# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/14 17:39:25 by tfilipe-          #+#    #+#              #
#    Updated: 2025/05/15 14:24:30 by tfilipe-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = pipex
CFLAGS = -Wall -Wextra -Werror


LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INC = $(LIBFT_DIR) 

SRCS = pipex.c utils.c command.c get_cmd_path.c
OBJS = $(SRCS:.c=.o)

RM = rm -f

all: $(NAME)


%.o: %.c
	@$(CC) $(CFLAGS) -I$(LIBFT_INC) -c $< -o $@

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)
	@echo "pipex successfully compiled with libft"

clean:
	@make -C $(LIBFT_DIR) clean
	@$(RM) $(OBJS)
	@echo "clean Objects removed"

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "fclean Executable removed"

re: fclean all

.PHONY: all clean fclean re
