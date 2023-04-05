# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 10:21:26 by nimai             #+#    #+#              #
#    Updated: 2023/04/05 13:17:14 by nimai            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER	:= server
CLIENT	:= client
CC		:= gcc
FLAGS	:= -Wall -Werror -Wextra
LIBS	:= -L./libft -lft
LIBFT	:= libft.a

SRCDIR	:= ./src/

all : $(LIBFT) $(SERVER) $(CLIENT)

$(LIBFT) : 
	@make -C ./libft/

$(SERVER) : $(SRCDIR)$(SERVER).o inc/minitalk.h
	@$(CC) $(SRCDIR)$(SERVER).o $(LIBS) -o $@

$(CLIENT) : $(SRCDIR)$(CLIENT).o inc/minitalk.h
	@$(CC) $(SRCDIR)$(CLIENT).o $(LIBS) -o $@

%.o : $(SRCDIR)%.c
	@$(CC) $(FLAGS) $< -c -I inc

clean :
	@make clean -C libft
	@rm -f *.o

fclean: clean
	@make fclean -C libft
	@rm -f $(SERVER) $(CLIENT)

re: fclean all