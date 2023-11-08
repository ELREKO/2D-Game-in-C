#include "../include/so_long.h"

int ft_init_image(t_mlx_data **list)
{
    int width;
    int hight;

    width = 50;
    hight = 50; 
    (*list)->img_wall = mlx_xpm_file_to_image((*list)->mlx_ptr, "img/wall.xpm", &width, &hight );
    (*list)->img_floor = mlx_xpm_file_to_image((*list)->mlx_ptr, "img/floor.xpm", &width, &hight );
    (*list)->img_col = mlx_xpm_file_to_image((*list)->mlx_ptr, "img/collect.xpm", &width, &hight );
    (*list)->img_pl_front = mlx_xpm_file_to_image((*list)->mlx_ptr, "img/player.xpm", &width, &hight );
    (*list)->img_exit_open = mlx_xpm_file_to_image((*list)->mlx_ptr, "img/exit_open.xpm", &width, &hight );
    (*list)->img_exit_close = mlx_xpm_file_to_image((*list)->mlx_ptr, "img/exit_close.xpm", &width, &hight );
    if (!((*list)->img_wall ) ||
        !((*list)->img_floor) ||
        !((*list)->img_col) ||
        !((*list)->img_pl_front) ||
        !((*list)->img_exit_open) ||
        !((*list)->img_exit_close))
        return(0);
    return (1);
}

int ft_destroy_image(t_mlx_data **list)
{
    mlx_destroy_image((*list)->mlx_ptr, (*list)->img_wall);
    mlx_destroy_image((*list)->mlx_ptr, (*list)->img_floor);
    mlx_destroy_image((*list)->mlx_ptr, (*list)->img_col);
    mlx_destroy_image((*list)->mlx_ptr, (*list)->img_pl_front);
    mlx_destroy_image((*list)->mlx_ptr, (*list)->img_exit_open);
    mlx_destroy_image((*list)->mlx_ptr, (*list)->img_exit_close);
    return (0);
}