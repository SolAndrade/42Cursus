# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soandrad <soandrad@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/22 12:30:11 by soandrad          #+#    #+#              #
#    Updated: 2022/09/22 12:30:13 by soandrad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS	=	*.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

RM		=	rm -f

all: ${NAME}

${NAME}: ${OBJS}
			${CC} -c ${CFLAGS} ${SRCS}
			ar crs ${NAME} ${OBJS}

clean: 
				${RM} ${OBJS}

fclean:		clean			
						${RM} $(NAME)

re:			fclean all

.PHONY: all, clean, fclean, re
