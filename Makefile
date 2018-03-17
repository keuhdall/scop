#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2017/11/19 05:25:46 by lmarques          #+#    #+#             *#
#*   Updated: 2018/03/08 07:48:30 by lmarques         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME=scop

SRC_PATH=./srcs
INC_PATH=./includes
OBJ_PATH=./objs
LIBFT_PATH=./libft

#GLEW_INC_PATH=/usr/local/Cellar/glew/2.1.0/include/
#GLEW_LIB_PATH=/usr/local/Cellar/glew/2.1.0/lib/
#GLFW_INC_PATH=/usr/local/Cellar/glfw/3.2.1/include/
#GLFW_LIB_PATH=/usr/local/Cellar/glfw/3.2.1/lib/

GLEW_INC_PATH=/Users/lmarques/.brew/Cellar/glew/2.1.0/include/
GLEW_LIB_PATH=/Users/lmarques/.brew/Cellar/glew/2.1.0/lib/
GLFW_INC_PATH=/Users/lmarques/.brew/Cellar/glfw/3.2.1/include/
GLFW_LIB_PATH=/Users/lmarques/.brew/Cellar/glfw/3.2.1/lib/

SRC_NAME = scop.c \
			init.c \
			matrix.c \
			reader.c \
			parse.c \
			tools.c \

OBJ_NAME = $(SRC_NAME:.c=.o)

CC = gcc -g
CFLAGS = -Werror -Wextra -Wall

SRC=$(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ=$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_PATH)
	$(CC) $^ -o $@ -L$(GLFW_LIB_PATH) -lglfw -L$(GLEW_LIB_PATH) -lglew -L$(LIBFT_PATH) -lft -framework OpenGL -framework GLUT

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) -o $@ -c $< $(CFLAGS) -I$(INC_PATH) -I$(LIBFT_PATH) -I$(GLFW_INC_PATH) -I$(GLEW_INC_PATH)

clean:
	rm -fv $(OBJ)
		@rmdir $(OBJ_PATH) 2> /dev/null || true
		make -C $(LIBFT_PATH) clean

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -fv $(NAME)

re:fclean all

.PHONY: all, clean, fclean, re
