# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/11 20:20:28 by asepulve          #+#    #+#              #
#    Updated: 2022/11/19 17:26:12 by asepulve         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 		libftprintf.a

CC 			= 		gcc

CFLAGS 		= 		-Wall -Werror -Wextra 

SRC 		= 		ft_printf.c ft_putchar.c ft_putnbrull_basel.c ft_strlen.c\
					ft_putnbr_basel.c  ft_putstr.c

OBJ			= ${SRC:%.c=%.o}

INCLUDES	=	ft_printf.h

RM		=		rm -rf

all: ${NAME}

%.o : %.c
	@${CC} ${CFLAGS} ${SRC} ${INCLUDES} -c

$(NAME): ${OBJ}
	@ar -rsc ${NAME} ${OBJ}

clean:
	@${RM} ${OBJ}

fclean:		clean
	@${RM} ${NAME}

re:	fclean ${NAME}

.PHONY: fclean clean all re