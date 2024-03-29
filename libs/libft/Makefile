# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: femaury <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/18 20:03:09 by femaury           #+#    #+#              #
#    Updated: 2018/06/03 15:05:06 by femaury          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC_PATH = .
SRC_NAME = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		   ft_isdigit.c ft_isprint.c ft_memalloc.c ft_memccpy.c ft_memchr.c \
		   ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c \
		   ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c \
		   ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c \
		   ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c \
		   ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c \
		   ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c \
		   ft_strncmp.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c \
		   ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c \
		   ft_toupper.c ft_itoa.c ft_strncpy.c ft_lstadd.c ft_lstdel.c \
		   ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_lstsize.c \
		   ft_lstrev.c ft_lstfind_content.c ft_lstfind_size.c ft_itoa_base.c \
		   ft_putlst.c ft_strtablen.c ft_strtablen_at.c ft_sqrt.c \
		   ft_strndup.c ft_strnjoin.c ft_strnclr.c ft_uimaxtoa_base.c \
		   ft_isupper.c ft_islower.c ft_setupcase.c ft_setlowcase.c \
		   ft_imaxtoa_base.c ft_wcharlen.c ft_wstrlen.c ft_strhasc.c ft_gnl.c \
		   ft_strisonly.c ft_pow.c ft_tabdel.c get_next_line.c ft_strisonlyc.c
OBJ_PATH = objs
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
CC = gcc
CFLAGS = -Wall -Wextra -Werror

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $@ $^
	@ranlib $@
	@echo "\n[\033[32mOK\033[0m] $(NAME) is ready!\n"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -Iincludes -o $@ -c $^
	@echo "\033[36mlibs/libft\033[0m: [\033[32mOK\033[0m] $@ successfully compiled."

clean:
	@$(RM) $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "\n[\033[32mOK\033[0m] $(NAME) objects cleaned.\n"

fclean: clean
	@$(RM) $(NAME)
	@echo "\n[\033[32mOK\033[0m] $(NAME) \033[31mhas been removed.\033[0m\n"

re: fclean all
