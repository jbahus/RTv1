# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/18 18:31:25 by jbahus            #+#    #+#              #
#    Updated: 2015/12/18 18:32:36 by jbahus           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1
SRC = main.c
HDR = rtv1.h
LIB = -lft -L libft
OBJ = $(SRC:%.c=obj/%.o)
GCC = gcc -Wall -Wextra -Werror

all: lib_ft obj $(NAME)

lib_ft:
	@cd libft ; $(MAKE) -f Makefile

obj:
	@mkdir -p obj/

$(NAME): $(OBJ)
	@$(GCC) $(OBJ) -o $(NAME) $(LIB)

obj/%.o: %.c $(HDR)
	@$(GCC) -c $< -o $@

clean:
	@rm -rf obj/

fclean: clean
	@rm -rf $(NAME)
	@echo "$(NAME) deleted."
	@make -C libft/ fclean

re: fclean all

norme:
	@norminette $(SRC) $(HDR)

.PHONY: all lib_ft clean fclean re norme