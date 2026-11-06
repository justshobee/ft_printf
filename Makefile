# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mochoubi <mochoubi@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/02 11:50:57 by mochoubi          #+#    #+#              #
#    Updated: 2026/11/02 17:42:14 by mochoubi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME		= libftprintf.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -rf

SRC_DIR		= src
OBJ_DIR		= obj
INCLUDES	= -I.

SRCS		= $(SRC_DIR)/ft_printf.c \
			  $(SRC_DIR)/ft_dispatch.c \
			  $(SRC_DIR)/ft_print_char.c \
			  $(SRC_DIR)/ft_print_str.c \
			  $(SRC_DIR)/ft_print_nbr.c \
			  $(SRC_DIR)/ft_print_base.c \
			  $(SRC_DIR)/ft_print_ptr.c

OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c ft_printf.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SECONDARY: $(OBJS)
