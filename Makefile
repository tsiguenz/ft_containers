# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 10:45:57 by tsiguenz          #+#    #+#              #
#    Updated: 2022/09/21 16:08:09 by tsiguenz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = container
NAME_REAL = $(NAME)_real

CC = c++
FLAGS = -g3 -Wall -Wextra -Werror -std=c++98
FLAGS_REAL = -D REAL

TEST_PATH = test/
OBJ_PATH = obj/
REAL_PATH = real/
INC = -Isrc -Itest
TEST_NAME = main.cpp \
			vector/vector_test.cpp \
			vector/object_managment_test.cpp \
			vector/iterator_test.cpp \
			vector/functions_test.cpp \
			vector/operators_test.cpp \
			map/pair_test.cpp \
			map/avl_test.cpp \
			map/iterators_test.cpp \
			map/functions_test.cpp \
			map/operators_test.cpp \

OBJ_NAME = $(TEST_NAME:.cpp=.o)

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
OBJ_REAL = $(addprefix $(REAL_PATH), $(OBJ_NAME))

# My containers

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(INC) $(OBJ) -o $(NAME)

$(OBJ_PATH)%.o: $(TEST_PATH)%.cpp
	mkdir -p $(@D)
	$(CC) $(FLAGS) $(INC) -MMD -c $< -o $@

-include $(OBJ:%.o=%.d)

# Real containers

$(REAL_PATH)%.o: $(TEST_PATH)%.cpp
	mkdir -p $(@D)
	$(CC) $(FLAGS) $(FLAGS_REAL) $(INC) -MMD -c $< -o $@

-include $(OBJ:%.o=%.d)

$(NAME_REAL): $(OBJ_REAL)
	$(CC) $(FLAGS) $(FLAGS_REAL) $(INC) $(OBJ_REAL) -o $(NAME_REAL)

real: $(NAME_REAL)

all: $(NAME) real

diff: all
	./$(NAME) > my_output
	./$(NAME_REAL) > real_output
	diff my_output real_output

clean:
	rm -rf obj
	rm -rf real

fclean: clean
	rm -rf $(NAME) $(NAME_REAL) my_output real_output

re: fclean all

.PHONY: all clean fclean re
