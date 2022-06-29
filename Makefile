# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 10:45:57 by tsiguenz          #+#    #+#              #
#    Updated: 2022/06/29 19:19:39 by tsiguenz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = container
NAME_REAL = $(NAME)_real

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
FLAGS_REAL = -D REAL

SRC_PATH = src/
OBJ_PATH = obj/
REAL_PATH = real/
INC = -Isrc -Itest -Itest/vector
SRC_NAME = main.cpp

OBJ_NAME = $(SRC_NAME:.cpp=.o)

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
OBJ_REAL = $(addprefix $(REAL_PATH), $(OBJ_NAME))
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

# My containers

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(INC) $< -o $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	mkdir -p $(@D)
	$(CC) $(FLAGS) $(INC) -MMD -c $< -o $@

-include $(OBJ:%.o=%.d)

# Real containers

$(REAL_PATH)%.o: $(SRC_PATH)%.cpp
	mkdir -p $(@D)
	$(CC) $(FLAGS) $(FLAGS_REAL) $(INC) -MMD -c $< -o $@

-include $(OBJ:%.o=%.d)

$(NAME_REAL): $(OBJ_REAL)
	$(CC) $(FLAGS) $(FLAGS_REAL) $(INC) $< -o $@

real: $(NAME_REAL)

all: $(NAME) real

clean:
	rm -rf obj
	rm -rf real

fclean: clean
	rm -rf $(NAME) $(NAME_REAL)

re: fclean all

.PHONY: all clean fclean re
