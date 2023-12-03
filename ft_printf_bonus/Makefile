# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 22:03:01 by asepulve          #+#    #+#              #
#    Updated: 2023/12/03 19:01:46 by asepulve         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 		libftprintf.a

CC 			= 		gcc

CFLAGS 		= 		-Wall -Werror -Wextra 

SRC 		= 		main.c build_str.c converter.c mod_flags.c mod_width.c\
					mod_precision.c set_mod.c utils.c ft_isdigit.c ft_strdup.c\
					ft_calloc.c ft_strjoin.c ft_strchr.c ft_strlen.c ft_atoi.c\
					ft_strlcpy.c ft_strncmp.c

OBJ			= ${SRC:%.c=%.o}

RM		=		rm -rf

%.o : %.c
	@${CC} ${CFLAGS} ${SRC} -c

all: ${NAME}

$(NAME): ${OBJ}
	@ar -rsc ${NAME} ${OBJ}

exec:
	@${CC}  ./libft/*.c *.c

bonus: ${OBJ}
	@ar -rsc ${NAME} ${OBJ}

clean:
	@${RM} ${OBJ}

fclean:		clean
	@${RM} ${NAME}

re:	fclean ${NAME}

.PHONY: fclean clean all re