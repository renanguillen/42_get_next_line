NAME = get_next_line.a

SOURCES = get_next_line.c get_next_line_utils.c
OBJECTS = $(SOURCES:.c=.o)
CFLAGS = -Wall -Wextra -Werror -g

BUFFER = -D BUFFER_SIZE=1
REMOVE = rm -rf

all: $(NAME)

$(NAME): $(OBJECTS)
	cc $(BUFFER) $(CFLAGS) -o test $(OBJECTS)

$(OBJECTS): $(SOURCES)
	cc $(CFLAGS) $(BUFFER) -c $(SOURCES)

clean:
	@$(REMOVE) $(OBJECTS)

fclean: clean
	@$(REMOVE) $(NAME) test

re: fclean all

test: all
	@./test

vg:
	valgrind ./test

.PHONY: all clean fclean re test valgrind
