# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 20:25:00 by soandrad          #+#    #+#              #
#    Updated: 2023/01/12 20:06:25 by soandrad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS = checker

SOURCE_DIR = .

CC = gcc

CFLAGS = -Wall -Werror -Wextra

ARGS = 3 4 5 8 7 2 6 1 9 11 10 12

AR = ar -src

RM = rm -f

# COLORS
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

SOURCES =  $(SOURCE_DIR)/atoi.c  $(SOURCE_DIR)/bubble_sort.c  $(SOURCE_DIR)/main.c  $(SOURCE_DIR)/movements_a.c  $(SOURCE_DIR)/movements_b.c  \
		$(SOURCE_DIR)/movements_ab.c  $(SOURCE_DIR)/sorting_numbers.c  $(SOURCE_DIR)/sorting_numbers_2.c  $(SOURCE_DIR)/split.c  $(SOURCE_DIR)/tests.c  \
		$(SOURCE_DIR)/three_or_less_inputs.c  $(SOURCE_DIR)/utils_general.c $(SOURCE_DIR)/input_checks.c $(SOURCE_DIR)/utils_general_2.c

	
SOURCES_BONUS = $(SOURCE_DIR)/atoi.c  $(SOURCE_DIR)/bubble_sort.c  $(SOURCE_DIR)/movements_a_bonus.c  $(SOURCE_DIR)/movements_b_bonus.c  \
		$(SOURCE_DIR)/movements_ab_bonus.c  $(SOURCE_DIR)/sorting_numbers.c  $(SOURCE_DIR)/sorting_numbers_2.c  $(SOURCE_DIR)/split.c  $(SOURCE_DIR)/tests.c  \
		$(SOURCE_DIR)/three_or_less_inputs.c  $(SOURCE_DIR)/utils_general.c  $(SOURCE_DIR)/checker.c $(SOURCE_DIR)/get_next_line.c  \
		$(SOURCE_DIR)/get_next_line_utils.c $(SOURCE_DIR)/utils_checker.c $(SOURCE_DIR)/input_checks.c $(SOURCE_DIR)/utils_general_2.c

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
