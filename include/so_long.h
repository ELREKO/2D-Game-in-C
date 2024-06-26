/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <rkost@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:34:28 by rkost             #+#    #+#             */
/*   Updated: 2023/11/10 17:57:31 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H

# include <X11/X.h>
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include <X11/keysym.h>
# include <errno.h> 
# include <aio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

/* Struct to store and handle layout properties */
typedef struct s_lay
{
	char			**map;
	unsigned int	i_x;
	unsigned int	i_y;
	unsigned int	screen_width;
	unsigned int	screen_hight;
	int				i_exit;
	int				i_pl;
	int				i_collect;
}	t_lay;

typedef struct s_position
{
	unsigned int	x;
	unsigned int	y;
}	t_positon;

typedef struct s_mlx_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_pl_front;
	void			*img_col;
	void			*img_exit;
	void			*img_wall;
	void			*img_ground;
	void			*img_floor;
	void			*img_enemy;
	void			*img_boom1;
	void			*img_boom2;
	void			*img_boom3;
	void			*img_boom4;
	void			*img_boom5;
	unsigned int	step_count;
	int				win_close;
	int				bock_key;
	t_lay			*map;
	t_positon		*pos;	
}	t_mlx_data;

unsigned int	ft_strlen(char *str);

// errorhandling.c
void			ft_throw_error(char *str);
void			ft_throw_map_error(t_lay **map, int err_num);
void			ft_error_map_data(t_lay **map, int err_num, t_mlx_data **data);
void			ft_free_map_struct(t_lay **map);

// ft_printf_1.c
int				ft_printf(char *format, ...);

// ft_printf_2_utiles.c 
int				ft_printf_char(int arg);
int				ft_printf_hex(unsigned int arg, char form);
int				ft_printf_uns_int(unsigned int arg);
int				ft_printf_int(int arg);
int				ft_printf_ptr(void *arg);

// ft_printf_3_utiles.c 
int				write_out_nbr(unsigned long long arg, char *base);
int				ft_printf_string(char *arg);

// get_next_line.c
char			*get_next_line(int fd);

// maps_1_read.c
t_lay			*ft_load_map(char *filename);

// maps_2_check_map.c
int				ft_map_controll(t_lay **map);

// maps_3_check_playabell.c
t_positon		*ft_check_payable(t_lay **map);

// maps_100_utiles.c
t_lay			*ft_creat_map_set_size(int file_discripter);
void			ft_read_map_sruct(int file_discripter, t_lay **map);
t_lay			*copy_t_lay(t_lay *src);

// screen_1_win_setting.c 
int				ft_window_setting(t_lay **map, t_positon **pos);
void			ft_put_image_to_window(t_mlx_data **data);
void			ft_check_exit(t_mlx_data **data);
int				ft_close_window(t_mlx_data **data);
void			ft_enemy_animaiton(t_mlx_data **data);
void			ft_print_count_steps(t_mlx_data **data);
void			ft_destoy_screen_free_data(t_mlx_data **data);

// screen_2_img_setting.c 
int				ft_init_image(t_mlx_data **list);
int				ft_destroy_image(t_mlx_data **list);

// screen_4_move_pl_horizontal.c
void			ft_move_left(t_mlx_data **data);
void			ft_move_right(t_mlx_data **data);

// screen_4_move_pl_vertical.C
void			ft_move_up(t_mlx_data **data);
void			ft_move_down(t_mlx_data **data);

// utiles_1.c
void			ft_putchar(char ch);
void			ft_putstr(char *str);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strdup(char *str);

// utiles_2.c
char			*ft_strjoin(char *str1, char *str2);

char			*ft_chrinstr(char *str, int chr);
char			*ft_substr(char *storage, unsigned int start, unsigned int len);

// utiles_3.c 
char			*ft_free_str(char **str);

// utiles_4_ft_itoa.c
char			*ft_itoa(int n);
#endif
