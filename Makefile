# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/18 18:31:25 by jbahus            #+#    #+#              #
#    Updated: 2016/01/29 14:57:56 by jbahus           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1
SRC = main.c ft_pixel_put_img.c
HDR = rtv1.h
LIB = -lft -L libft -lmlx -Lminilibx_macos -framework OpenGL -framework AppKit
OBJ = $(SRC:%.c=obj/%.o)
GCC = gcc -Wall -Wextra -Werror
INC = -I /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.9.sdk/System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/

all: lib_ft lib_minilibx obj $(NAME)

lib_ft:
	@cd libft ; $(MAKE) -f Makefile

lib_minilibx:
	@echo "\033[34m-------------------------------------------------------------\033[0m"
	@make -C minilibx_macos/

obj:
	@mkdir -p obj/

$(NAME): $(OBJ)
	@$(GCC) $(OBJ) -o $(NAME) $(LIB)

obj/%.o: %.c $(HDR)
	@$(GCC) -c $< -o $@ $(INC)

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