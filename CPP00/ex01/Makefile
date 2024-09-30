# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/21 09:00:51 by ahaarij           #+#    #+#              #
#    Updated: 2024/09/30 08:58:45 by ahaarij          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = PhoneBook.cpp Contact.cpp PhoneBook_utils.cpp
OBJ = $(SRC:.cpp=.o)
CC = c++
RM = rm -rf
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = phonebook

all: $(NAME)


$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@
	
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
