# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fleitz <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 13:19:30 by fleitz            #+#    #+#              #
#    Updated: 2022/09/29 13:19:34 by fleitz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

_END=$'\033[0m
_GREEN=$'\033[1;32m
_YELLOW=$'\033[1;33m
_ORANGE=$'\033[38;2;255;165;0m

NAME  = cub3d

SRCS =	main.c									\
		srcs/file/file.c						\
		srcs/file/utils.c						\
		srcs/file/texture_colors.c				\
		srcs/file/parse_map.c					\
		srcs/file/end.c							\
		srcs/file/protect_texture.c				\
		srcs/file/event.c						\

OBJS	= ${SRCS:.c=.o}

CC	= clang

CFLAGS	= -Wall -Wextra -Werror -g

MLXFLAGS	= -lmlx -lXext -lX11 -Lmlx

MLX		= mlx/libmlx.a mlx/libmlx_Linux.a

LIBFT	= -L libft -lft

all: 		lib minilibx ${NAME}

${NAME}: 	${OBJS}
			@echo "${_GREEN}----------------\nCUB3D\n----------------${_END}"
			@echo "${_ORANGE}Objects CUB3D created${_END}"
			@${CC} ${CFLAGS} ${OBJS} ${LIBFT} ${MLX} ${MLXFLAGS} -o ${NAME}
			@echo "${_GREEN}CUB3D compiled succesfully !${_END}"

.c.o:		
			@${CC} ${CFLAGS} -c $< -o $@

minilibx:
			@make -C mlx
			
lib:		
			@make -C libft

clean:		
			@rm -f ${OBJS}
			@make -C libft clean
			@make -C mlx clean
			@echo "${_YELLOW}Objects cub3d cleaned !${_END}"

fclean:		clean
			@rm -f ${NAME}
			@make -C libft fclean
			@echo "${_YELLOW}${NAME} cleaned !${_END}"

re:			fclean all

			
.PHONY :	all clean fclean re lib
