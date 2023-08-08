NAME =	satisfactory-calculator
FILES =	main.c \
		recipes.c
OBJ =	$(FILES:.c=.o)
CC =	gcc
FLAGS =	-Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(FILES) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(OBJ)

re: clean all