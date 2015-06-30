# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/07/16 09:42:25 by fvivaudo          #+#    #+#              #
#    Updated: 2015/03/13 11:00:00 by fvivaudo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra

SRC = 	srcs/fdf.c			\
		srcs/draw.c			\
		srcs/env.c			\
		srcs/event.c

OBJ  = $(subst srcs/,,$(SRC:.c=.o))

NAME = fdf

MLX =  -framework OpenGL -framework AppKit -lmlx -lm

all : $(NAME)

$(NAME) :
	@make -C libft
	@gcc $(FLAGS) $(SRC) $(MLX) -I includes/ -I libft/includes -L libft/ -lft -o $(NAME)

clean:
	@rm -Rf $(OBJ)

fclean: clean
	@rm -Rf $(NAME)

re: fclean all
	
