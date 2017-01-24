NAME = main
SRC = main.cpp second.cpp
# $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
CC = g++
CFLAGS = -c

all: $(OBJ)
	g++ $(OBJ) -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all