# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 20:25:00 by soandrad          #+#    #+#              #
#    Updated: 2023/01/11 17:51:11 by soandrad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS = checker

SOURCE_DIR = .

CC = gcc

CFLAGS = -Wall -Werror -Wextra

ARGS = 3 4 5 8 2 6 1
ARGS = 46 94 16 45 78 63 18 42 76 43 77 13 72 83 10 5 47 84 55 12 54 21 44 19 33 40 57 60 98 48 2 90 4 62 28 34 74 86 88 22 38 15 25 70 49 29 68 24 32 59 52 58 64 99 39 1 80 20 100 66 69 91 71 82 27 89 92 61 96 3 93 95 85 41 26
ARGS = 3 4 5 8 7 2 6 1 9 11 10 12

AR = ar -src

RM = rm -f

# COLORS
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

SOURCES =  $(SOURCE_DIR)/atoi.c  $(SOURCE_DIR)/bubble_sort.c  $(SOURCE_DIR)/main.c  $(SOURCE_DIR)/movements_a.c  $(SOURCE_DIR)/movements_b.c  \
		$(SOURCE_DIR)/movements_ab.c  $(SOURCE_DIR)/sorting_numbers.c  $(SOURCE_DIR)/sorting_numbers_2.c  $(SOURCE_DIR)/split.c  $(SOURCE_DIR)/tests.c  \
		$(SOURCE_DIR)/three_or_less_inputs.c  $(SOURCE_DIR)/utils_general.c 

	
SOURCES_BONUS = $(SOURCE_DIR)/atoi.c  $(SOURCE_DIR)/bubble_sort.c  $(SOURCE_DIR)/movements_a.c  $(SOURCE_DIR)/movements_b.c  \
		$(SOURCE_DIR)/movements_ab.c  $(SOURCE_DIR)/sorting_numbers.c  $(SOURCE_DIR)/sorting_numbers_2.c  $(SOURCE_DIR)/split.c  $(SOURCE_DIR)/tests.c  \
		$(SOURCE_DIR)/three_or_less_inputs.c  $(SOURCE_DIR)/utils_general.c  $(SOURCE_DIR)/checker.c $(SOURCE_DIR)/get_next_line.c $(SOURCE_DIR)/get_next_line_utils.c

OBJECTS = $(SOURCES:.c=.o)
OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)

${NAME}: $(OBJECTS)
	${CC} ${CFLAGS} ${CFLAGS_DEBUGER} ${OBJECTS} -o ${NAME}
	@echo "$(NAME): $(GREEN)Creating $(NAME)...$(RESET)"
	
all: ${NAME}
	@echo "$(NAME): $(GREEN)$(NAME) created$(RESET)"

bonus: ${BONUS} 

${BONUS}: ${OBJECTS_BONUS}
	${CC} ${CFLAGS} ${OBJECTS_BONUS} -o ${BONUS}
	@echo "$(NAME): $(GREEN)Creating $(BONUS)...$(RESET)"

test:$(NAME)
	clear
	$(SOURCE_DIR)/$(NAME) $(ARGS)
re:	fclean all

clean:
			${RM} ${OBJECTS} ${OBJECTS_BONUS}

fclean:		clean
			${RM} $(NAME) ${BONUS}
#			@$(RM) -f $(LIBFT)/libft.a
			@echo "$(NAME): $(RED)$(NAME) cleaned$(RESET)"

.PHONY: all, clean, fclean, re, bonus, test
