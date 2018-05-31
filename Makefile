# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: femaury <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/18 20:03:09 by femaury           #+#    #+#              #
#    Updated: 2018/05/30 18:17:31 by femaury          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = femaury.filler
SRC_PATH = srcs
SRC_NAME = filler.c filler_set_piece.c filler_put_piece.c
OBJ_PATH = objs
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
CC = gcc
CFLAGS = -Wall -Wextra -Werror

.PHONY: all, clean, fclean, re, libft, printf

all: libft printf

$(NAME): $(OBJ) libs/libft/libft.a libs/ft_printf/libftprintf.a
	@$(CC) $(CFLAGS) -Iincludes -o $(NAME) $(OBJ) libs/libft/libft.a libs/ft_printf/libftprintf.a
	@echo "\n[\033[32mOK\033[0m] $(NAME) compiled successfully."

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -Iincludes -o $@ -c $<
	@echo "[\033[32mOK\033[0m] $@ compiled successfully."

libft:
	@$(MAKE) -C libs/libft/

printf:
	@$(MAKE) -C libs/ft_printf/
	@$(MAKE) $(NAME)

clean:
	@$(RM) $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@$(MAKE) -C libs/libft/ clean
	@$(MAKE) -C libs/ft_printf/ clean

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C libs/libft/ fclean
	@$(MAKE) -C libs/ft_printf/ clean

re: fclean all
