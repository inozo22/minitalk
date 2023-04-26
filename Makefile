# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 10:21:26 by nimai             #+#    #+#              #
#    Updated: 2023/04/26 13:17:14 by nimai            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SER		:= server
NAME_CLI		:= client
NAME_SER_B		:= server_bonus
NAME_CLI_B		:= client_bonus
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

LIBS			:= ft
LIBS_TARGET		:= lib/libft/libft.a 

INCS			:= \
					inc \
					lib/libft/inc \

INCS_B			:= \
					inc_bonus \
					lib/libft/inc \

SRC_DIR			:= src
B_SRC_DIR		:= src_bonus
SRCS_SER		:= server.c
SRCS_SER		:= $(SRCS_SER:%=$(SRC_DIR)/%)
SRCS_CLI		:= client.c
SRCS_CLI		:= $(SRCS_CLI:%=$(SRC_DIR)/%)
B_SRCS_SER		:= server_bonus.c
B_SRCS_SER		:= $(B_SRCS_SER:%=$(B_SRC_DIR)/%)
B_SRCS_CLI		:= client_bonus.c
B_SRCS_CLI		:= $(B_SRCS_CLI:%=$(B_SRC_DIR)/%)

BUILD_DIR		:= .build
OBJS_SER		:= $(SRCS_SER:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
B_OBJS_SER		:= $(B_SRCS_SER:$(B_SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
OBJS_CLI		:= $(SRCS_CLI:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
B_OBJS_CLI		:= $(B_SRCS_CLI:$(B_SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS_SER		:= $(OBJS_SER:.o=.d)
B_DEPS_SER		:= $(B_OBJS_SER:.o=.d)
DEPS_CLI		:= $(OBJS_CLI:.o=.d)
B_DEPS_CLI		:= $(B_OBJS_CLI:.o=.d)

CC				:= cc
CFLAGS			:= -Wall -Wextra -Werror
CPPFLAGS		:= $(addprefix -I,$(INCS)) -MMD -MP
CPPFLAGS_B		:= $(addprefix -I,$(INCS_B)) -MMD -MP
LDFLAGS			:= $(addprefix -L,$(dir $(LIBS_TARGET)))
LDLIBS			:= $(addprefix -l,$(LIBS))
#ライブラリを使ってビルドするには、3つのフラグが必要:
#Iはコンパイラにlibヘッダファイルの場所を指示
#Lはリンカ-にライブラリの場所を指示
#lはこのライブラリの名前（従来のlibプレフィックスを除いたもの）
#------------------------------------------------#
#   UTENSILS                                     #
#------------------------------------------------#
# RM        force remove
# MAKEFLAGS make flags
# DIR_DUP   duplicate directory tree

RM				:= rm -f
rf				:= rm -rf
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

all: $(NAME_CLI) $(NAME_SER) bonus
bonus: $(NAME_CLI_B) $(NAME_SER_B)

$(NAME_CLI): $(OBJS_CLI) $(LIBS_TARGET)
	$(CC) $(LDFLAGS) $(OBJS_CLI) $(LDLIBS) -o $(NAME_CLI)
	$(info CREATED $(NAME_CLI))

$(NAME_SER): $(OBJS_SER) $(LIBS_TARGET)
	$(CC) $(LDFLAGS) $(OBJS_SER) $(LDLIBS) -o $(NAME_SER)
	$(info CREATED $(NAME_SER))

$(NAME_CLI_B): $(B_OBJS_CLI) $(LIBS_TARGET)
	$(CC) $(LDFLAGS) $(B_OBJS_CLI) $(LDLIBS) -o $(NAME_CLI_B)
	$(info CREATED $(NAME_CLI_B))

$(NAME_SER_B): $(B_OBJS_SER) $(LIBS_TARGET)
	$(CC) $(LDFLAGS) $(B_OBJS_SER) $(LDLIBS) -o $(NAME_SER_B)
	$(info CREATED $(NAME_SER_B))

$(LIBS_TARGET):
	$(MAKE) -C $(@D)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)

$(BUILD_DIR)/%.o: $(B_SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS_B) -c -o $@ $<
	$(info CREATED $@)

-include $(DEPS_CLI) $(DEPS_SER) $(B_DEPS_CLI) $(B_DEPS_SER)

clean:
	for f in $(dir $(LIBS_TARGET)); do $(MAKE) -C $$f clean; done
	$(RM) $(OBJS_CLI) $(DEPS_CLI) $(OBJS_SER) $(DEPS_SER)
	$(RM) $(B_OBJS_CLI) $(B_DEPS_CLI)  $(B_OBJS_SER) $(B_DEPS_SER)

fclean: clean
	for f in $(dir $(LIBS_TARGET)); do $(MAKE) -C $$f fclean; done
	$(RM) $(NAME_CLI) $(NAME_SER)
	$(RM) $(NAME_CLI_B) $(NAME_SER_B)
#	$(RF) *.dSYM

re:
	$(MAKE) fclean
	$(MAKE) all

info-%:
	$(MAKE) --dry-run --always-make $* | grep -v "info"

#------------------------------------------------#
#   SPEC                                         #
#------------------------------------------------#

.PHONY: all clean fclean re bonus
.SILENT: