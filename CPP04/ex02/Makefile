SRC = main.cpp animal.cpp cat.cpp dog.cpp brain.cpp
OBJ = $(SRC:.cpp=.o)
CC = g++
RM = rm -rf
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic 
CPPFLAGS += -fsanitize=address -g3

NAME = Abstract

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
