# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 11:48:58 by nimai             #+#    #+#              #
#    Updated: 2023/04/14 17:46:27 by nimai            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

RM = rm -f

LIBFT_PATH = libft

LIBS = $(LIBFT_PATH)/libft.a

SRC = ft_printf.c ft_printf_utils.c 

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -c $(SRC)
	@make -C $(LIBFT_PATH)
	@mv $(LIBS) $(NAME)
	@ar rcs $(NAME) $(OBJS)

clean:
	@$(RM) $(OBJS)
	@make clean --directory $(LIBFT_PATH)

fclean: clean
	make fclean --directory $(LIBFT_PATH)
	@$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
