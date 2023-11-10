#include "../include/so_long.h"

static void ft_move_horizontal(t_mlx_data **data, int steps, char ch_tmp);
static void ft_move_vertical(t_mlx_data **data, int steps, char ch_tmp);

void  ft_move_left(t_mlx_data **data)
{
    char ch_tmp; 
    int steps;

    steps = -1;
    ch_tmp = (*data)->map->map[(*data)->pos->y][((*data)->pos->x) + steps];
    if (ch_tmp == 'G')
        ft_enemy_animaiton(data);
    else if (ch_tmp == 'E' && (*data)->map->i_collect <= 0)
    {
        ft_move_horizontal(data, steps, ch_tmp);
        ft_close_window(data);
    }
    else if (ch_tmp != 'E' && ch_tmp != '1' && ((*data)->pos->x) > 0)
        ft_move_horizontal(data, steps, ch_tmp);
}

void  ft_move_right(t_mlx_data **data)
{
    char ch_tmp; 
    int steps;

    steps = 1;
    ch_tmp = (*data)->map->map[(*data)->pos->y][((*data)->pos->x) + steps];
    if (ch_tmp == 'G')
        ft_enemy_animaiton(data);
    else if (ch_tmp == 'E' && (*data)->map->i_collect <= 0)
    {
        ft_move_horizontal(data, steps, ch_tmp);
        ft_close_window(data);
    }
    else if (ch_tmp != 'E' && ch_tmp != '1'  && ((*data)->pos->x) < (*data)->map->i_x)
        ft_move_horizontal(data, steps, ch_tmp);
}

static void ft_move_horizontal(t_mlx_data **data, int steps, char ch_tmp)
{
    (*data)->pos->x = ((*data)->pos->x) + steps;
    (*data)->map->map[(*data)->pos->y][(*data)->pos->x] = 'P';
    (*data)->map->map[(*data)->pos->y][(*data)->pos->x - steps] = '0';
    mlx_put_image_to_window((*data)->mlx_ptr, (*data)->win_ptr,(*data)->img_pl_front,((*data)->pos->x * 50), ((*data)->pos->y * 50) );
    mlx_put_image_to_window((*data)->mlx_ptr, (*data)->win_ptr,(*data)->img_floor,(((*data)->pos->x - steps) * 50), ((*data)->pos->y * 50) );
    if (ch_tmp == 'C')
    {
        (*data)->map->i_collect = (*data)->map->i_collect - 1;
        ft_check_exit(data);
    }
    ft_print_count_steps(data);
}

void  ft_move_down(t_mlx_data **data)
{
    char ch_tmp; 
    int steps;

    steps = -1;
    ch_tmp = (*data)->map->map[(*data)->pos->y - steps][(*data)->pos->x];
    if (ch_tmp == 'G')
        ft_enemy_animaiton(data);
    else if (ch_tmp == 'E' && (*data)->map->i_collect <= 0)
    {
        ft_move_vertical(data, steps, ch_tmp);
        ft_close_window(data);
    }
    else if (ch_tmp != 'E' && ch_tmp != '1' && ((*data)->pos->y) > 0)
        ft_move_vertical(data, steps, ch_tmp);
}

void  ft_move_up(t_mlx_data **data)
{
    char ch_tmp; 
    int steps;

    steps = 1;
    ch_tmp = (*data)->map->map[(*data)->pos->y - steps][(*data)->pos->x];
    if (ch_tmp == 'G')
        ft_enemy_animaiton(data);
    else if (ch_tmp == 'E' && (*data)->map->i_collect <= 0)
    {
        ft_move_vertical(data, steps, ch_tmp);
        ft_close_window(data);
    }
    else if (ch_tmp != 'E' && ch_tmp != '1' && ((*data)->pos->y) < (*data)->map->i_y)
        ft_move_vertical(data, steps, ch_tmp);

}

static void ft_move_vertical(t_mlx_data **data, int steps, char ch_tmp)
{
        (*data)->pos->y = ((*data)->pos->y) - steps;
        (*data)->map->map[(*data)->pos->y][(*data)->pos->x] = 'P';
        (*data)->map->map[(*data)->pos->y + steps ][(*data)->pos->x] = '0';
        mlx_put_image_to_window((*data)->mlx_ptr, (*data)->win_ptr,(*data)->img_pl_front,((*data)->pos->x * 50), ((*data)->pos->y * 50) );
        mlx_put_image_to_window((*data)->mlx_ptr, (*data)->win_ptr,(*data)->img_floor,((*data)->pos->x * 50), (((*data)->pos->y + steps) * 50));
        if (ch_tmp == 'C')
        {
            (*data)->map->i_collect = (*data)->map->i_collect - 1;
            ft_check_exit(data);
        }
        ft_print_count_steps(data);
}