#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h> 
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

/* Struct to store and handle layout properties */
typedef struct s_lay
{
	char **map;
	unsigned int i_x;
	unsigned int i_y;
	int	i_exit;
	int	i_pl;
	int	i_gh;
	int	i_collect;
}	t_lay;

typedef struct s_position
{
	int	x;
	int	y;
}	t_positon;

// errorhandling.c
void ft_throw_error (char *str);
void ft_throw_map_error(t_lay **map, int err_num);

// get_next_line.c
char	*get_next_line(int fd);

// maps_1_read.c
void ft_load_map(char *filename);

// maps_2_checking.c
int ft_map_checking (int file_discripter);

// maps_100_utiles.c
t_lay *ft_creat_map_set_size(int file_discripter);
void ft_read_map_sruct(int file_discripter, t_lay **map);

// utiles_1.c
void ft_putchar(char ch);
void ft_putstr (char *str);

// utiles_2.c
char	*ft_strjoin(char *str1, char *str2);
unsigned int	ft_strlen(char *str);
char	*ft_chrinstr(char *str, int chr);
char	*ft_substr(char *storage, unsigned int start, unsigned int len);

// utiles_3.c 
char	*ft_free_str(char **str);


#endif