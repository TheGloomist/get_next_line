NAME = gnl
SRC = get_next_line.c\
	get_next_line_utils.c\
	temp.c\

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) -Wall -Wextra -Werror $(SRC)

clean:
	rm -f $(OBJ)
	
fclean: clean
	rm -f $(NAME)

re: fclean all
	
