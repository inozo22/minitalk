# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 10:21:26 by nimai             #+#    #+#              #
#    Updated: 2023/04/13 16:39:56 by nimai            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER			:= server
CLIENT			:= client
SERVER_BONUS	:= server_bonus
CLIENT_BONUS	:= client_bonus
CC				:= gcc
FLAGS			:= -Wall -Werror -Wextra
LIBS			:= -L./libft -lft
LIBFT			:= libft.a

SRCDIR			:= ./src/
SRC_BONUSDIR	:= ./src_bonus/

all : $(LIBFT) $(SERVER) $(CLIENT) #bonus

#bonus : $(SERVER_BONUS) $(CLIENT_BONUS)

$(LIBFT) : 
	@make -C ./libft/

$(SERVER) : $(SRCDIR)$(SERVER).o inc/minitalk.h
	@$(CC) $(SRCDIR)$(SERVER).o $(LIBS) -o $@

$(CLIENT) : $(SRCDIR)$(CLIENT).o inc/minitalk.h
	@$(CC) $(SRCDIR)$(CLIENT).o $(LIBS) -o $@

#$(SERVER_BONUS) : $(SRC_BONUSDIR)$(SERVER_BONUS).o inc/minitalk.h
#	@$(CC) $(SRC_BONUSDIR)$(SERVER_BONUS).o $(LIBS) -o $@

#$(CLIENT_BONUS) : $(SRC_BONUSDIR)$(CLIENT_BONUS).o inc/minitalk.h
#	@$(CC) $(SRC_BONUSDIR)$(CLIENT_BONUS).o $(LIBS) -o $@

%.o : $(SRCDIR)%.c
	@$(CC) $(FLAGS) $< -c -I inc

#%.o : $(SRC_BONUSDIR)%.c
#	@$(CC) $(FLAGS) $< -c -I inc

clean :
	@make clean -C libft
	@rm -f $(SRCDIR)*.o
#	@rm -f $(SRC_BONUSDIR)*.o

fclean: clean
	@make fclean -C libft
	@rm -f $(SERVER) $(CLIENT)
#	@rm -f $(SERVER_BONUS) $(CLIENT_BONUS)

re: fclean all