# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcouppe <mcouppe@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 13:19:30 by fleitz            #+#    #+#              #
#    Updated: 2022/10/24 10:51:32 by mcouppe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

_END=$'\033[0m
_GREEN=$'\033[1;32m
_YELLOW=$'\033[1;33m
_ORANGE=$'\033[38;2;255;165;0m

NAME		= cub3d

SRCS_FILES	=	main.c									\
				parse/file.c							\
				parse/texture_colors.c					\
				parse/parse_map.c						\
				parse/end.c								\
				parse/utils.c							\
				execution/create_imgs.c					\
				execution/event.c						\
				execution/show.c						\
				execution/display_wall.c				\
				execution/get_dist.c					\
				execution/get_player_pos.c				\
				execution/vectors.c						\
				bonus/mini_map.c						\

SRCS		= ${addprefix srcs/, ${SRCS_FILES}}

CC			= clang

CFLAGS		= -Wall -Wextra -Werror -g3 -I.

MLXFLAGS	= -lmlx -lXext -lX11 -Lmlx

MLX			= mlx/libmlx.a mlx/libmlx_Linux.a

LIBFT		= -Llibft -lft

OBJS_FILES	= ${SRCS_FILES:%.c=%.o}

OBJS		= ${addprefix objs/, ${OBJS_FILES}}

DEP			= ${OBJS:%.o=%.d}

all: 		lib minilibx ${NAME}

${NAME}: 	${OBJS}
			@echo "${_GREEN}----------------\nCUB3D\n----------------${_END}"
			@echo "${_ORANGE}Objects CUB3D created${_END}"
			@${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT} ${MLX} ${MLXFLAGS} -lm #-o ${NAME} ${OBJS}
			@echo "${_GREEN}CUB3D compiled succesfully !${_END}"

minilibx:
			@make -C mlx
			@echo "${_GREEN}MLX compiled succesfully !${_END}"
			
lib:		
			@make -C libft

clean:		
			@rm -rf ${OBJS}
			@make -C libft clean
			@make -C mlx clean
			@echo "${_YELLOW}Objects cub3d cleaned !${_END}"

fclean:		clean
			@rm -f ${NAME}
			@make -C libft fclean
			@echo "${_YELLOW}${NAME} cleaned !${_END}"

re:			fclean all

objs/%.o :	srcs/%.c cub3d.h
			@mkdir -p objs
			@mkdir -p objs/parse objs/execution
			@${CC} ${CFLAGS} -MMD -o $@ -c $<

			
.PHONY :	all clean fclean re lib
