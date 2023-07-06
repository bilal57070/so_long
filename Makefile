# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsafi <bsafi@student.42nice.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/01 14:49:58 by bsafi             #+#    #+#              #
#    Updated: 2023/07/04 19:59:21 by bsafi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c check_error.c check_error2.c parsing.c so_long_utils.c mlx.c\

OBJS = ${SRCS:.c=.o}
NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LINKS = -lmlx -framework OpenGL -framework AppKit
RM = rm -rf
LIBFT = ./libft

all : ${NAME}

${NAME}: ${OBJS}
	@${MAKE} -C ${LIBFT}/
	@${CC} ${CFLAGS} ${LINKS} ${OBJS} ${LIBFT}/libft.a -o ${NAME}
	@echo "COMPILED so_long"

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
clean:
	@${MAKE} clean -C ${LIBFT}/
	@${RM} ${OBJS}

bonus: all

fclean: clean
	@${RM} ${NAME} ${LIBFT}/libft.a
	@echo "DELETED"
re: fclean all

.PHONY: all clean fclean re
