NAME = my_program

SRC = 4_pixel.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

LFLAGS = -Lminilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(CFLAGS) -o $@ $^ $(LFLAGS)

%.o: %.c
	gcc $(CFLAGS) -Iminilibx_opengl_20191021 -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
