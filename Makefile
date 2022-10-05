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

SRCS =	main.c						\
		file.c						\
		utils.c						\
		texture_colors.c			\

OBJS	= ${SRCS:.c=.o}

HEADERS	= cub3d.h

CC	= clang

CFLAGS	= -Wall -Wextra -Werror -g3

LIBFT	= -L libft -lft

all: 		lib ${NAME}

${NAME}: 	${OBJS}
			@echo "${_GREEN}----------------\nCUB3D\n----------------${_END}"
			@echo "${_ORANGE}Objects CUB3D created${_END}"
			@${CC} ${CFLAGS} ${OBJS} ${LIBFT} -o ${NAME}
			@echo "${_GREEN}CUB3D compiled succesfully !${_END}"

.c.o:		
			@${CC} ${CFLAGS} -I${HEADERS} -c $< -o $@

clean:		
			@rm -f ${OBJS}
			@make -C libft clean
			@echo "${_YELLOW}Objects cub3d cleaned !${_END}"

fclean:		clean
			@rm -f ${NAME}
			@make -C libft fclean
			@echo "${_YELLOW}${NAME} cleaned !${_END}"

re:			fclean all

lib:		
			@make -C libft
			
.PHONY :	all clean fclean re lib
