# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/22 12:30:11 by soandrad          #+#    #+#              #
#    Updated: 2022/10/01 19:18:04 by soandrad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRCS	=	$(shell find . -type f \( -name "*.c" ! -name "*bonus.c" \) -exec basename {} \;)

B_SRCS	=	$(shell find . -type f -name "*bonus.c" -exec basename {} \;)

OBJS	=	$(SRCS:.c=.o)

B_OBJS	=	$(B_SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

RM		=	rm -f

AR		=	ar -src

${NAME}:			${OBJS}
			${CC} -c ${CFLAGS} ${SRCS}
			${AR} ${NAME} ${OBJS}

all:		${NAME}

clean: 
			${RM} ${OBJS} ${B_OBJS}

fclean:		clean			
			${RM} $(NAME)

re:			fclean all

bonus:		${OBJS} ${B_OBJS} 
			${AR} ${NAME} ${OBJS} ${B_OBJS}

.PHONY: all, clean, fclean, re, bonus
