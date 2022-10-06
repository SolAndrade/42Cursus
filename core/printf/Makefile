# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 18:04:58 by soandrad          #+#    #+#              #
#    Updated: 2022/10/06 20:17:05 by soandrad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRCS	=	ft_printf.c utils.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

RM		=	rm -f

AR		=	ar -src

${NAME}:			${OBJS}
			${CC} -c ${CFLAGS} ${SRCS}
			${AR} ${NAME} ${OBJS}

all:		${NAME}

clean: 
			${RM} ${OBJS}

fclean:		clean			
			${RM} $(NAME)

re:			fclean all

.PHONY: all, clean, fclean, re
