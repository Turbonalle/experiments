NAME =		tictactoe
FILES =		main.c \
			bot.c \
			check_win.c \
			input_handler.c \
			print.c
HEADER =	incl/tictactoe.h
SRC_PATH =	src
OBJ_PATH =	obj

SRC = $(addprefix $(SRC_PATH)/,$(FILES))
OBJ = $(addprefix $(OBJ_PATH)/,$(FILES:.c=.o))

.PHONY: all clean fclean re

all: $(NAME)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	@cc -c $< -o $@

$(NAME): $(OBJ)
	@cc $(OBJ) -o $(NAME) -I $(HEADER)
	@clear

clean:
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm $(NAME)

re: fclean all