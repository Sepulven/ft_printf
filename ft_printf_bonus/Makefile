# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 22:03:01 by asepulve          #+#    #+#              #
#    Updated: 2023/12/01 14:09:41 by asepulve         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 		libftprintf.a

CC 			= 		gcc

CFLAGS 		= 		-Wall -Werror -Wextra 

SRC 		= 		main.c build_str.c converter.c mod_flags.c set_mod.c utils.c libft/*.c

OBJ			= ${SRC:%.c=%.o}

LIB			= libft/libft.a

RM		=		rm -rf

%.o : %.c
	@${CC} ${CFLAGS} ${SRC} -c

all: ${NAME}

$(NAME): ${OBJ}
	@ar -rsc ${NAME} *.o

bonus: ${OBJ}
	@ar -rsc ${NAME} *.o

# $(NAME):
# @make  -SC libft
# @gcc ${CFLAGS} ${SRC} ${LIB}

clean:
	@${RM} ${OBJ}

fclean:		clean
	@${RM} ${NAME}

re:	fclean ${NAME}

.PHONY: fclean clean all re