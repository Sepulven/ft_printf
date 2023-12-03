# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 22:03:01 by asepulve          #+#    #+#              #
#    Updated: 2023/12/03 15:46:44 by asepulve         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 		libftprintf.a

CC 			= 		gcc

CFLAGS 		= 		-Wall -Werror -Wextra 

SRC 		= 		main.c build_str.c converter.c mod_flags.c mod_width.c mod_precision.c set_mod.c utils.c libft/*.c

OBJ			= ${SRC:%.c=%.o}

LIB			= libft/libft.a

RM		=		rm -rf

%.o : %.c
	@${CC} ${CFLAGS} ${SRC} -c

all: ${NAME}

$(NAME): ${OBJ}
	@ar -rsc ${NAME} *.o

exec:
	@${CC}  ./libft/*.c *.c

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