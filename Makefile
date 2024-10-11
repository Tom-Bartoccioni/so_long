# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/02 15:18:00 by tbartocc          #+#    #+#              #
#    Updated: 2024/10/11 16:11:26 by tbartocc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3 #-fsanitize=address
PRINTF = ./Printf/
LIBFT = ./Printf/Libft/
MLX_FLAGS = -L./minilibx -lmlx -lbsd -lXext -lX11 -lm

SRC_COMMON =	enemy.c \
				get_next_line_utils.c \
				get_next_line.c \
				map.c \
				mlx.c \
				movements.c \
				parsing.c \

SRC = $(SRC_COMMON)\
	so_long.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c src.h
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(MAKE) --no-print-directory -C $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJ) $(PRINTF)libftprintf.a -o $(NAME) $(MLX_FLAGS)

clean:
	@rm -f $(OBJ)
	@$(MAKE) --no-print-directory -C $(PRINTF) clean
	@$(MAKE) --no-print-directory -C $(LIBFT) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) --no-print-directory -C $(PRINTF) fclean
	@$(MAKE) --no-print-directory -C $(LIBFT) fclean

re: fclean all

mlx:
	@wget https://cdn.intra.42.fr/document/document/26928/minilibx-linux.tgz
	@tar -xzvf minilibx-linux.tgz
	@mv minilibx-linux minilibx
	@rm minilibx-linux.tgz
	@cd minilibx && make

end: fclean
	@rm -rf minilibx

.PHONY: all clean fclean re mlx end