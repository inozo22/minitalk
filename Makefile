# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 10:21:26 by nimai             #+#    #+#              #
#    Updated: 2023/03/28 15:16:02 by nimai            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= pipex

SRCDIR		:= ./src/
SRC			:=  \
				main.c \
				error_control.c \
				read_file.c


				
OBJDIR		:= ./obj/
OBJ			:= $(addprefix $(OBJDIR), $(SRC:.c=.o))
INC			:= /usr/include
INCLIB		:= $(INC)/../lib
LIBDIR		:= ./lib/
LIBFT		:= $(LIBDIR)libft
INCDIR		:= ./inc/

#SANITFLAG	:= -fsanitize=address
CC			:= gcc
CFLAGS		:= -g3 -Wall -Wextra -Werror

RM_COL		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m

all: $(OBJDIR) $(NAME)

$(OBJDIR):
	@mkdir -p $@

$(OBJDIR)%.o: $(SRCDIR)%.c
	@make -C $(LIBFT)
	@$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@ 

$(NAME): $(OBJ)
	@echo "$(BLUE)--Compiling ${RM_COL} ${YELLOW}$(NAME) ${RM_COL}..."
	@make -sC $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT)/libft.a -o $(NAME)
	@echo "$(GREEN)$(NAME) created[0m ✔️"

clean:
	@make -C $(LIBFT) clean
	@rm -rf $(OBJDIR)
	@echo "$(RED)Deleted $(YELLOW)$(NAME) $(RM_COL)objs ✔️"

fclean: clean
	@make -C $(LIBFT) fclean
	@rm -rf ./pipex.dSYM
	@rm -f $(NAME)
	@echo "$(RED)Deleted $(YELLOW)$(NAME) $(RM_COL)binary ✔️"
re:
	@make fclean all

.PHONY: all clean fclean re