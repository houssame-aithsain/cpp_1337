CC = c++

CXXFLAGS = -fsanitize=address -g -Wall -Wextra -Werror -std=c++98

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
