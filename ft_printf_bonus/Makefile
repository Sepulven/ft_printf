# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 22:03:01 by asepulve          #+#    #+#              #
#    Updated: 2023/11/27 23:49:02 by asepulve         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 		libftprintf.a

CC 			= 		gcc

CFLAGS 		= 		-Wall -Werror -Wextra 

SRC 		= 		main.c

OBJ			= ${SRC:%.c=%.o}

LIB			= libft/libft.a

RM		=		rm -rf

all: ${NAME}

$(NAME):
		@make  -SC libft
		@gcc ${SRC} ${LIB}

clean:
	@${RM} ${OBJ}

fclean:		clean
	@${RM} ${NAME}

re:	fclean ${NAME}

.PHONY: fclean clean all re