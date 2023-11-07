NAME	= so_long

INC=%%%%

INCLIB=$(INC)/lib

CC		= gcc
CFLAGS	= -Wall -Wextra -I$(INC) -O3 -I -g

SRC_PATH = src/
OBJ_PATH = obj/

SRC  = 	errorhandling.c \
	get_next_line.c \
	main.c \
	maps_1_read.c \
	maps_2_check_map.c \
	maps_3_check_playable.c \
	maps_100_utiles.c \
	utiles_1.c \
	utiles_2.c \
	utiles_3.c \
	window_1_setting.c 

SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
INCS	= -I ./includes/
LIB		= -Lmlx -lmlx -L../$(INCLIB) -lXext -lX11 -lm


all: $(OBJ_PATH) $(NAME)

allgdb: $(OBJ_PATH) $(NAME) -g

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

${NAME}:	${OBJS}
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

gdb: fclean allgdb

.PHONY: all clean fclean re