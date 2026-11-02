# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mochoubi <mochoubi@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/02 11:50:57 by mochoubi          #+#    #+#              #
#    Updated: 2026/11/02 12:27:20 by mochoubi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME		= libftprintf.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -rf

SRC_DIR		= src
OBJ_DIR		= obj
LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a
INCLUDES	= -I. -I$(LIBFT_DIR)

SRCS		= $(SRC_DIR)/ft_printf.c \
			  $(SRC_DIR)/ft_dispatch.c \
			  $(SRC_DIR)/ft_print_char.c \
			  $(SRC_DIR)/ft_print_str.c \
			  $(SRC_DIR)/ft_print_nbr.c \
			  $(SRC_DIR)/ft_print_base.c \
			  $(SRC_DIR)/ft_print_ptr.c

OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)

$(LIBFT): FORCE
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c ft_printf.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

FORCE:

.PHONY: all clean fclean re FORCE

