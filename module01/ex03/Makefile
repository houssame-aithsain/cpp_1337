# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 20:17:02 by hait-hsa          #+#    #+#              #
#    Updated: 2023/10/23 20:17:04 by hait-hsa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = HumanA.cpp HumanB.cpp main.cpp Weapon.cpp

NAME = humans

RM = rm -rf

OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
