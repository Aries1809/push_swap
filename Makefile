# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kseltenr <kseltenr@student.42vienna.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/09 19:10:29 by kseltenr          #+#    #+#              #
#    Updated: 2026/11/10 05:08:38 by kseltenr        ###   ########.fr         #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CHECKER		= checker

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
SHARED_SRCS	= $(SRC_DIR)/init/parsing.c \
			  $(SRC_DIR)/init/stack.c \
			  $(SRC_DIR)/operations/ops.c \
			  $(SRC_DIR)/operations/op_helpers.c \
			  $(SRC_DIR)/operations/primitives.c \
			  $(SRC_DIR)/algorithms/simple.c \
			  $(SRC_DIR)/bench/disorder.c \
			  $(SRC_DIR)/bench/bench.c
MAIN_SRCS	= $(SRC_DIR)/main.c
BONUS_SRCS	= $(SRC_DIR)/main_bonus.c
SHARED_OBJS	= $(SHARED_SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
MAIN_OBJS	= $(MAIN_SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
BONUS_OBJS	= $(BONUS_SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEPS		= $(SHARED_OBJS:.o=.d) $(MAIN_OBJS:.o=.d) $(BONUS_OBJS:.o=.d)

COMPILE_DB	= compile_commands.json

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(SHARED_OBJS) $(MAIN_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

bonus: $(CHECKER)

$(CHECKER): $(SHARED_OBJS) $(BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(CHECKER)
	$(MAKE) -C $(LIBFT_DIR) fclean

re:
	$(MAKE) fclean
	$(MAKE) all

-include $(DEPS)

.PHONY: all clean fclean re bonus
.DEFAULT_GOAL := all

