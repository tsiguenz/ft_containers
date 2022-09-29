# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 10:45:57 by tsiguenz          #+#    #+#              #
#    Updated: 2022/09/29 22:46:09 by tsiguenz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# my tests
NAME = container
NAME_REAL = $(NAME)_real

# subject tests
NAME_SUBJECT = subject
NAME_SUBJECT_REAL = $(NAME_SUBJECT)_real

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

SUBJECT_NAME = subject_main.cpp \

OBJ_NAME = $(TEST_NAME:.cpp=.o)

OBJ_SUBJECT_NAME = $(SUBJECT_NAME:.cpp=.o)

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
OBJ_REAL = $(addprefix $(REAL_PATH), $(OBJ_NAME))

OBJ_SUBJECT = $(addprefix $(OBJ_PATH), $(OBJ_SUBJECT_NAME))
OBJ_SUBJECT_REAL = $(addprefix $(REAL_PATH), $(OBJ_SUBJECT_NAME))

# My containers

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(INC) $(OBJ) -o $(NAME)

$(OBJ_PATH)%.o: $(TEST_PATH)%.cpp
	mkdir -p $(@D)
	$(CC) $(FLAGS) $(INC) -MMD -c $< -o $@

-include $(OBJ:%.o=%.d)

# Real containers

$(NAME_REAL): $(OBJ_REAL)
	$(CC) $(FLAGS) $(FLAGS_REAL) $(INC) $(OBJ_REAL) -o $(NAME_REAL)

$(REAL_PATH)%.o: $(TEST_PATH)%.cpp
	mkdir -p $(@D)
	$(CC) $(FLAGS) $(FLAGS_REAL) $(INC) -MMD -c $< -o $@

-include $(OBJ:%.o=%.d)

# My containers subject main

$(NAME_SUBJECT): $(OBJ_SUBJECT)
	$(CC) $(FLAGS) $(INC) $(OBJ_SUBJECT) -o $(NAME_SUBJECT)

$(OBJ_PATH)%.o: $(TEST_PATH)%.cpp
	mkdir -p $(@D)
	$(CC) $(FLAGS) $(INC) -MMD -c $< -o $@

-include $(OBJ:%.o=%.d)

# Real containers subject main

$(NAME_SUBJECT_REAL): $(OBJ_SUBJECT_REAL)
	$(CC) $(FLAGS) $(FLAGS_REAL) $(INC) $(OBJ_SUBJECT_REAL) -o $(NAME_SUBJECT_REAL)

$(REAL_PATH)%.o: $(TEST_PATH)%.cpp
	mkdir -p $(@D)
	$(CC) $(FLAGS) $(FLAGS_REAL) $(INC) -MMD -c $< -o $@

-include $(OBJ:%.o=%.d)

real: $(NAME_REAL)

sub: $(NAME_SUBJECT)

rsub: $(NAME_SUBJECT_REAL)

all: $(NAME) real

diff: all
	./$(NAME) > my_output
	./$(NAME_REAL) > real_output
	diff my_output real_output

subdiff: sub rsub
	./$(NAME_SUBJECT) 5 > my_output
	./$(NAME_SUBJECT_REAL) 5 > real_output
	diff my_output real_output

time: sub rsub
	@echo "My container time :"
	@time ./$(NAME_SUBJECT) 5
	@echo "Real container time :"
	@time ./$(NAME_SUBJECT_REAL) 5

clean:
	rm -rf obj
	rm -rf real

fclean: clean
	rm -rf $(NAME) $(NAME_REAL) $(NAME_SUBJECT) $(NAME_SUBJECT_REAL) my_output real_output

re: fclean all

.PHONY: all clean fclean re
