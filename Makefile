# **************************************************************************** #
#                                                                              #
#                                                        :::      ::::::::     #
#    Makefile                                          :+:      :+:    :+:     #
#                                                    +:+ +:+         +:+       #
#    By: kseltenr <kseltenr@student.42.fr>         #+#  +:+       +#+          #
#                                                +#+#+#+#+#+   +#+             #
#    Created: 2026/10/11 18:41:13 by kseltenr         #+#    #+#               #
#    Updated: 2026/11/09 16:14:20 by kseltenr        ###   ########.fr         #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
CPPFLAGS	= -MMD -MP -I inc -I $(LIBFT_DIR)/inc
DEBUG		?= 0
RM			= rm -f

# nproc fails on mac but it should be fine cause we use linux
JOBS		?= $(shell nproc)
MAKEFLAGS	+= -j $(JOBS) -l $(JOBS)

ifeq ($(DEBUG),1)
CFLAGS		+= -g3
CPPFLAGS	+= -DDEBUG=1
endif

SRC_DIR		= src
OBJ_DIR		= obj
LIBFT_DIR	= libft

LIBFT		= $(LIBFT_DIR)/libft.a
SRCS		= $(SRC_DIR)/main.c \
			  $(SRC_DIR)/disorder.c \
			  $(SRC_DIR)/init/parsing.c \
			  $(SRC_DIR)/init/stack.c \
			  $(SRC_DIR)/operations/ops.c \
			  $(SRC_DIR)/operations/op_helpers.c \
			  $(SRC_DIR)/operations/primitives.c
OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEPS		= $(OBJS:.o=.d)

COMPILE_DB	= compile_commands.json

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re:
	$(MAKE) fclean
	$(MAKE) all

-include $(DEPS)

.PHONY: all clean fclean re
.DEFAULT_GOAL := all

