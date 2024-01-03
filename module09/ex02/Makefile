# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/22 15:45:27 by hait-hsa          #+#    #+#              #
#    Updated: 2024/01/02 19:16:38 by hait-hsa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98 #-fsanitize=address -g

SRC			=	main.cpp PmergeMe.cpp
HEADERS		=	PmergeMe.hpp

NAME		=	PmergeMe

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