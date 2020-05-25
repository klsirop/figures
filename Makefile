NAME = figures
HEAD = figures.h

SRC = main.cpp
FLAGS = -Wall -Wextra -Werror

CC = g++

OBJ = $(SRC:.cpp=.o)

%.o: %.cpp $(HEAD)
	@$(CC) -c -o $@ $<

all: $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

