_END=$'\033[0m
_GREEN=$'\033[1;32m
_YELLOW=$'\033[1;33m
_ORANGE=$'\033[38;2;255;165;0m

NAME		= test

SRCS		= mlx_test.c			\

OBJS		= ${SRCS:.c=.o}

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

LIB			= ../libft/libft.a

MLX			= ./minilibx-linux/libmlx.a minilibx-linux/libmlx_Linux.a

all:		${NAME}

${NAME}:	${OBJS}
			@echo "${_ORANGE}Objects test created${_END}"
			@make -C ../libft
			@make -C minilibx-linux
			@${CC} ${CFLAGS} -L /usr/lib ${OBJS} ${LIB} ${MLX} -lXext -lX11 -lm -lz -o ${NAME}
			@echo "${_GREEN}TEST compiled succesfully !${_END}"

clean:
			@make clean -C ../libft
			@make clean -C minilibx-linux
			@rm -f ${OBJS}
			@echo "${_YELLOW}Objects cleaned !${_END}"

fclean:		clean
			@rm -f ${NAME} ${LIB}
			@echo "${_YELLOW}${NAME} cleaned !${_END}"

re:			fclean all

.PHONY:		clean fclean re all
