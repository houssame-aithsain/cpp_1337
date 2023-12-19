# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/09 12:47:00 by hait-hsa          #+#    #+#              #
#    Updated: 2023/12/19 19:20:13 by hait-hsa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC			=	main.cpp BitcoinExchange.cpp
HEADERS		=	BitcoinExchange.hpp

NAME		=	btc

RM			=	rm -rf

OBJS		=	$(SRC:.cpp=.o)

all			:	$(NAME)

$(NAME)		:	$(OBJS) $(HEADERS)
				$(CC) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o			:	%.cpp $(HEADERS)
				$(CC) $(CXXFLAGS) -c $< -o $@

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re
