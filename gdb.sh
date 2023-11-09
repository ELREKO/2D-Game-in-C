cc -Wall -Wextra -Lmlx -lmlx -L../lib -lXext -lX11 -lm src/errorhandling.c \
	src/get_next_line.c \
	src/main.c \
	src/maps_1_read.c \
	src/maps_2_check_map.c \
	src/maps_3_check_playable.c \
	src/maps_100_utiles.c \
	src/utiles_1.c \
	src/utiles_2.c \
	src/utiles_3.c \
	src/utiles_4_ft_itoa.c
echo "Fertig"
