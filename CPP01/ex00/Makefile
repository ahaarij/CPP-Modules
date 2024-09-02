# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/28 07:25:11 by ahaarij           #+#    #+#              #
#    Updated: 2024/08/28 07:25:41 by ahaarij          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.cpp newZombie.cpp randomChump.cpp Zombie.cpp
OBJ = $(SRC:.cpp=.o)
CC = g++
RM = rm -rf
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

NAME = Zombie

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
