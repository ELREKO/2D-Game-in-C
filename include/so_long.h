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

// errorhandling.c
void ft_throw_error (char *str);

// get_next_line.c
char	*ft_free(char **str);
char	*ft_clean_storage(char *storage);
char	*ft_new_line(char *storage);
char	*ft_readbuf(int fd, char *storage);
char	*get_next_line(int fd);

// get_next_line_utiles.c
char	*ft_strjoin(char *str1, char *str2);
size_t	ft_strlen(char *str);
char	*ft_chrinstr(char *str, int chr);
char	*ft_substr(char *storage, unsigned int start, size_t len);

// maps_read.c
int ft_open_maps(char *filename);
void ft_close_map (int file_discripter);

// utiles.c
void ft_putchar(char ch);
void ft_putstr (char *str);


#endif