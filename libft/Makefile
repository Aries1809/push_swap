# **************************************************************************** #
#                                                                              #
#                                                        :::      ::::::::     #
#    Makefile                                          :+:      :+:    :+:     #
#                                                    +:+ +:+         +:+       #
#    By: kseltenr <kseltenr@student.42.fr>         #+#  +:+       +#+          #
#                                                +#+#+#+#+#+   +#+             #
#    Created: 2026/10/07 13:47:16 by kseltenr         #+#    #+#               #
#    Updated: 2026/10/21 05:56:23 by kseltenr        ###   ########.fr         #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I inc
BUFFER_SIZE	= 42

LIBC_SRC	= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
       ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd_back.c \
       ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
       ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_memchr.c \
       ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
       ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
       ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
       ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
       ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c 
PRINTF_SRC	= ft_printf_bonus.c ft_convert_bonus.c \
		ft_emit_bonus.c ft_parse_bonus.c
FPRINTF_SRC	= ft_fprintf.c ft_fconvert.c ft_femit.c
DPRINTF_SRC	= ft_dprintf.c ft_dconvert.c ft_demit.c
GNL_SRC		= get_next_line_bonus.c get_next_line_utils_bonus.c

SRCS		= $(addprefix src/libc/, $(LIBC_SRC)) \
			  $(addprefix src/printf/, $(PRINTF_SRC)) \
			  $(addprefix src/fprintf/, $(FPRINTF_SRC)) \
			  $(addprefix src/dprintf/, $(DPRINTF_SRC)) \
			  $(addprefix src/gnl/, $(GNL_SRC))
OBJS		= $(SRCS:src/%.c=obj/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

obj/.buffer_size: FORCE
	@mkdir -p obj
	@echo $(BUFFER_SIZE) | cmp -s - $@ || echo $(BUFFER_SIZE) > $@

obj/gnl/%.o: src/gnl/%.c inc/get_next_line_bonus.h obj/.buffer_size
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -c $< -o $@

obj/printf/%.o: src/printf/%.c inc/ft_printf_bonus.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

obj/fprintf/%.o: src/fprintf/%.c inc/ft_fprintf.h inc/ft_printf_bonus.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

obj/dprintf/%.o: src/dprintf/%.c inc/ft_dprintf.h inc/ft_printf_bonus.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

obj/%.o: src/%.c inc/libft.h inc/ft_printf_bonus.h inc/ft_fprintf.h \
			inc/ft_dprintf.h inc/get_next_line_bonus.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf obj

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re FORCE
