NAME 	= megaphone
CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++20
SRCS	= megaphone.cpp
OBJS 	= $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
