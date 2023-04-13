# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 10:21:26 by nimai             #+#    #+#              #
#    Updated: 2023/04/13 17:48:13 by nimai            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#NAME			:= pancakes
NAME_SERVER		:= server
NAME_CLIENT		:= client
#------------------------------------------------#
#   INGREDIENTS                                  #
#------------------------------------------------#
# LIBS        libraries to be used
# LIBS_TARGET libraries to be built
## INCS        header file locations
## SRC_DIR     source directory
# SRCS        source files
## BUILD_DIR   build directory
# OBJS        object files
# DEPS        dependency files
## CC          compiler
# CFLAGS      compiler flags
# CPPFLAGS    preprocessor flags
# LDFLAGS     linker flags
# LDLIBS      libraries name

LIBS			:= libft
LIBS_TARGET		:= libft/libft.a
INCS			:= inc/

SRC_DIR			:= src/
SRCS_SER		:= server.c
SRCS_CLI		:= client.c
#SRCS			:= $(SRCS:%=$(SRC_DIR)/%)

BUILD_DIR		:= .build
OBJS_SER		:= $(SRCS_SER:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
OBJS_CLI		:= $(SRCS_CLI:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS_SER		:= $(OBJS_SER:.o=.d)
DEPS_CLI		:= $(OBJS_CLI:.o=.d)

CC				:= clang
CFLAGS			:= -Wall -Wextra -Werror
CPPFLAGS		:= $(addprefix -I,$(INCS)) -MMD -MP
LDFLAGS			:= $(addprefix -L,$(dir $(LIBS_TARGET)))
LDLIBS			:= $(addprefix -l,$(LIBS))

#------------------------------------------------#
#   UTENSILS                                     #
#------------------------------------------------#
# RM        force remove
# MAKEFLAGS make flags
# DIR_DUP   duplicate directory tree

RM				:= rm -f
MAKEFLAGS		+= --silent --no-print-directory
DIR_DUP			= mkdir -p $(@D)

#------------------------------------------------#
#   RECIPES                                      #
#------------------------------------------------#
# all       default goal
# $(NAME)   link .o -> archive
# $(LIBS)   build libraries
# %.o       compilation .c -> .o
# clean     remove .o
# fclean    remove .o + binary
# re        remake default goal
# run       run the program
# info      print the default goal recipe

all: $(NAME)

$(NAME): $(OBJS) $(LIBS_TARGET)
	$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)
	$(info CREATED $(NAME))

$(LIBS_TARGET):
	$(MAKE) -C $(@D)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)

-include $(DEPS)

clean:
	for f in $(dir $(LIBS_TARGET)); do $(MAKE) -C $$f clean; done
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	for f in $(dir $(LIBS_TARGET)); do $(MAKE) -C $$f fclean; done
	$(RM) $(NAME)

re:
    $(MAKE) fclean
    $(MAKE) all