# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/18 19:03:51 by nimai             #+#    #+#              #
#    Updated: 2023/04/13 16:41:41 by nimai            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCDIR = ./
SRC = \
ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c get_next_line.c

SRC_BONUS = \
ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c 

OBJDIR = ./obj/
OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))
OBJ_BONUS = $(addprefix $(OBJDIR), $(SRC_BONUS:.c=.o))

PRINTF	:= ./printf

CC = gcc
CFLAGS = -Wall -Wextra -Werror

CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m

all: $(OBJDIR) $(NAME) bonus

$(OBJDIR):
	@mkdir -p $@

$(OBJDIR)%.o : $(SRCDIR)%.c
#	@make -C $(PRINTF)
	@$(CC) -c $(CFLAGS) -o $@ $<

$(NAME): $(OBJ)
	@echo "$(BLUE)--Compiling ${CLR_RMV} $(NAME) ${CLR_RMV}..."
	@ar -rc $(NAME) $^

bonus: $(OBJ_BONUS) $(NAME)
	@ar -rc $(NAME) $^

printf: $(OBJ_PRINTF) $(NAME)
	@ar -rc $(NAME) $^

clean:
	@rm -rf $(OBJDIR)

fclean: clean
#	@make fclean -C $(PRINTF)
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, bonus
