# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 10:19:10 by mcouppe           #+#    #+#              #
#    Updated: 2022/10/04 17:11:59 by mcouppe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d_disaster

SRCS_FILES = main.c getlines.c getmap.c start.c get_player_pos.c keypress.c \
			free_mlx_all.c display_wall.c \

SRCS = $(addprefix srcs/, $(SRCS_FILES))

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I. -I./mlx

MLX = mlx/libmlx.a

MLXFLAGS = -lmlx -lXext -lX11 -Lmlx

OBJS_FILES = $(SRCS_FILES:%.c=%.o)

OBJS = $(addprefix objs/, $(OBJS_FILES))

LIBFT = libft/libft.a

LIB = -Llibft -lft

RM = rm -rf

all : $(NAME)

$(NAME) : $(OBJS)
		$(MAKE) -C libft
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB) $(MLXFLAGS)

$(LIBFT):
	$(MAKE) -C libft

clean :
		$(MAKE) -C libft clean
		$(RM) $(OBJS)
		$(RM) objs/

fclean : clean
		$(MAKE) -C libft fclean
		$(RM) $(NAME)

re : fclean all

objs/%.o : srcs/%.c cub3disaster.h
		mkdir -p objs
		$(CC) $(CFLAGS) -o $@ -c $<

.PHONY : all clean fclean re
