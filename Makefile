OBJ_DIR = bin/
INC_DIR = include/
SRC_DIR = src/

TESTS_SRC = $(wildcard src/tests/*.cpp)
TESTS_SRC := $(TESTS_SRC:$(SRC_DIR)%=%)

SRCS = main.cpp $(TESTS_SRC)
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.cpp=.o))
DEPENDS = $(OBJS:.o=.d)

NAME = containers

CPPFLAGS = -Wall -Werror -Wextra -std=c++98 -ggdb -fsanitize=address
INCPATH = -I$(INC_DIR)

CC = c++

all: $(NAME)

real: CPPFLAGS+= -D NAMESPACE=std
real: clean all

$(NAME) : $(OBJ_DIR) $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

-include $(DEPENDS)

$(OBJ_DIR)%.o : $(SRC_DIR)%.cpp
	$(CC) $(CPPFLAGS) $(INCPATH) -MMD -MP -c $< -o $@

$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)tests/

clean :
	rm -rf $(OBJ_DIR)

clean_test :
	rm -f realVector.output myVector.output

clean_error :
	rm -f realVector.error myVector.error

fclean : clean clean_test
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
