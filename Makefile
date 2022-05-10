NAME = get_next_line.a

SOURCES = get_next_line.c get_next_line_utils.c
OBJECTS = $(SOURCES:.c=.o)
FLAGS = -Wall -Wextra -Werror

ARCHIVE = ar rcs
BUFFER = -D BUFFER_SIZE=42
REMOVE = rm -rf

all: $(NAME)

$(OBJECTS): $(SOURCES)
	cc $(FLAGS) $(BUFFER) -c $(SOURCES)

$(NAME): $(OBJECTS)
	$(ARCHIVE) $(NAME) $(OBJECTS)

clean:
	$(REMOVE) $(OBJECTS)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

.PHONY: all clean fclean re