# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcouppe <mcouppe@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 13:19:30 by fleitz            #+#    #+#              #
#    Updated: 2022/10/10 17:02:36 by mcouppe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

_END=$'\033[0m
_GREEN=$'\033[1;32m
_YELLOW=$'\033[1;33m
_ORANGE=$'\033[38;2;255;165;0m

#*******************************************************************************#
#*******************************************************************************#
#*******************************************************************************#

NAME  = cub3d

INCLUDES = -I./includes -I./mlx

CC	= gcc

CFLAGS	= -Wall -Wextra -Werror -g3 $(INCLUDES)

MLX = mlx/libmlx.a

MLXFLAGS = -lmlx -lXext -lX11 -Lmlx

LIB	= -Llibft -lft

LIBFT = libft/libft.a

SRCS_FILES =	main.c parsing/file.c parsing/utils.c parsing/texture_colors.c 	\
		parsing/parse_map.c		parsing/end.c									\
		display/display_wall.c	display/get_player_pos.c	display/keypress.c	\
		display/start.c	free_mlx_all.c \

SRCS = $(addprefix srcs/ , $(SRCS_FILES))

OBJS_FILES	= ${SRCS_FILES:%.c=%.o}

OBJS = $(addprefix objs/, $(OBJS_FILES))

HEADERS	= includes/cub3d.h

RM = rm -rf

#*******************************************************************************#
#*******************************************************************************#
#*******************************************************************************#

all: 		$(NAME)

$(NAME): 	$(OBJS) $(LIBFT) $(HEADERS)
			@echo "${_GREEN}----------------\nCUB3D\n----------------${_END}"
			@echo "${_ORANGE}Objects CUB3D created${_END}"
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB) $(MLXFLAGS)
			@echo "${_GREEN}CUB3D compiled succesfully !${_END}"

$(LIBFT) :
			$(MAKE) -C libft

objs/%.o :	srcs/%.c $(HEADERS)
			@mkdir -p objs objs/display objs/parsing
			@$(CC) $(CFLAGS) -I. -o $@ -c $<

clean:		
			@${RM} ${OBJS}
			@make -C libft clean
			@echo "${_YELLOW}Objects cub3d cleaned !${_END}"

fclean:		clean
			@${RM} ${NAME}
			@make -C libft fclean
			@echo "${_YELLOW}${NAME} cleaned !${_END}"

re:			fclean all

#libft :		
#			@${MAKE} -C includes/libft
			
.PHONY :	all clean fclean re
