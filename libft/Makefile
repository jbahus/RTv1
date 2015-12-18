# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/21 15:06:26 by jbahus            #+#    #+#              #
#    Updated: 2015/12/16 16:59:47 by jbahus           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c
SRC += ft_isascii.c ft_isdigit.c ft_isprint.c ft_isspace.c
SRC += ft_itoa.c ft_memalloc.c ft_memccpy.c ft_memchr.c
SRC += ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c
SRC += ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c
SRC += ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c
SRC += ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c
SRC += ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c
SRC += ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c
SRC += ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c
SRC += ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c
SRC += ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c
SRC += ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c
SRC += ft_toupper.c ft_lstadd.c ft_lstiter.c
SRC += ft_lstmap.c ft_lstnew.c ft_lstdel.c ft_lstdelone.c ft_ultoa.c

DEL = rm -f

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@gcc $(FLAG) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\|/        "
	@echo "-o------.  "
	@echo "/|\     |\ "
	@echo " |      '-|"
	@echo " |        |"
	@echo " | libft.a|"
	@echo " '--------'"
	

clean:
	@$(DEL) $(OBJ)
	@echo "\|/        "
	@echo "-o------.  "
	@echo "/|\     |\ "
	@echo " |      '-|"
	@echo " | .o     |"
	@echo " | deleted|"
	@echo " '--------'"

fclean: clean
	@$(DEL) $(NAME)
	@echo "\|/        "
	@echo "-o------.  "
	@echo "/|\     |\ "
	@echo " |      '-|"
	@echo " | libft.a|"
	@echo " | deleted|"
	@echo " '--------'"

re: fclean all
