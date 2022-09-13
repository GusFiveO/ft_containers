OBJ_DIR = bin/
INC_DIR = include/
SRC_DIR = src/

SRCS = main.cpp 
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.cpp=.o))
DEPENDS = $(OBJS:.o=.d)

NAME = containers 

CPPFLAGS = -Wall -Werror -Wextra -std=c++98
INCPATH = -I$(INC_DIR)

CC = c++

all: $(NAME)

$(NAME) : $(OBJ_DIR) $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

-include $(DEPENDS)

$(OBJ_DIR)%.o : $(SRC_DIR)%.cpp
	$(CC) $(CPPFLAGS) $(INCPATH) -MMD -MP -c $< -o $@

$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
