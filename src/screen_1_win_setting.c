#include "../include/so_long.h"

static int	handle_input(int keysym, t_mlx_data **data);
void ft_put_image_to_buffer(t_mlx_data **data);
static void ft_print_count_steps(t_mlx_data **data);

int ft_window_setting(t_lay **map, t_positon **pos)
{

    t_mlx_data	*data;
    int width;
    int hight;
  
    data = malloc(sizeof(t_mlx_data));
    if (data == NULL)
        ft_throw_map_error(map, 10);
    width = (*map)->i_x * 50;
    hight = (*map)->i_y * 50; 
    data->mlx_ptr = mlx_init();  
    data->win_ptr = mlx_new_window(data->mlx_ptr, width, hight, "so_long");
    if ((data->mlx_ptr)== NULL || (data->win_ptr)== NULL )
        ft_error_map_data(map,410,&data);
    if (!(ft_init_image(&data)))
        ft_error_map_data(map,420,&data);
    data->map = (*map);
    data->pos = (*pos);
    data->step_count = 0;
    data->win_close = 0;

    ft_put_image_to_window(&data);


    mlx_key_hook(data->win_ptr, handle_input, &data);
    mlx_hook(data->win_ptr, 17, 0, ft_close_window, &data);
    mlx_loop(data->mlx_ptr);
    ft_destroy_image(&data);
    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    mlx_destroy_display(data->mlx_ptr);
    free(data->mlx_ptr);
    free(data);
    
    return (0);
}

void ft_put_image_to_window(t_mlx_data **data)
{
    int i_x;
    int i_y;

    i_y = 0;
    while ((*data)->map->map[i_y] != NULL)
    {
        i_x = 0;
        while ((*data)->map->map[i_y][i_x] != '\0')
        {
            if ((*data)->map->map[i_y][i_x] == '1')
                mlx_put_image_to_window((*data)->mlx_ptr, (*data)->win_ptr,(*data)->img_wall,(i_x * 50), (i_y * 50) );
            if ((*data)->map->map[i_y][i_x] == '0')
                mlx_put_image_to_window((*data)->mlx_ptr, (*data)->win_ptr,(*data)->img_floor,(i_x * 50), (i_y * 50) );
            if ((*data)->map->map[i_y][i_x] == 'P')
                mlx_put_image_to_window((*data)->mlx_ptr, (*data)->win_ptr,(*data)->img_pl_front,(i_x * 50), (i_y * 50) );
            if ((*data)->map->map[i_y][i_x] == 'C')
                mlx_put_image_to_window((*data)->mlx_ptr, (*data)->win_ptr,(*data)->img_col,(i_x * 50), (i_y * 50) );
            if ((*data)->map->map[i_y][i_x] == 'E')
                mlx_put_image_to_window((*data)->mlx_ptr, (*data)->win_ptr,(*data)->img_exit,(i_x * 50), (i_y * 50) );
            i_x++;
        }
        i_y++;
    }
}

void ft_check_exit(t_mlx_data **data)
{
    int w;
    int h;

    w = 50;
    h = 50;
    if ((*data)->map->i_collect <= 0)
    {
        mlx_destroy_image((*data)->mlx_ptr, (*data)->img_exit);
        (*data)->img_exit = mlx_xpm_file_to_image((*data)->mlx_ptr, "img/exit_open.xpm", &w, &h );
    }
    if (!((*data)->img_exit))
        ft_error_map_data(&((*data)->map),420,data);
    ft_put_image_to_window(data);
}

static int	handle_input(int keysym, t_mlx_data **data)
{
    if (keysym == XK_Escape)
        ft_close_window(data);
    if (keysym == XK_Left || keysym == XK_a)
        ft_move_left(data);
    if (keysym == XK_Right || keysym == XK_d)
        ft_move_right(data);
    if (keysym == XK_Up || keysym == XK_w)
        ft_move_up(data);
    if (keysym == XK_Down || keysym == XK_s)
        ft_move_down(data);
    ft_print_count_steps(data);
    return (0);
}

static void ft_print_count_steps(t_mlx_data **data)
{
    char *str;

    str = ft_itoa((*data)->step_count);
    (*data)->step_count = (*data)->step_count + 1;
    ft_putstr(str);
    if ((*data)->win_close)
        ft_putstr(" Total");
    ft_putstr(" steps\n");
    free(str);
}



int ft_close_window(t_mlx_data **data)
{
    ssize_t ret;
    ret = write(1, "close programm\n", 16);
    if (ret == -1 )
        perror ("ERROR : write"); 
    mlx_loop_end((*data)->mlx_ptr);
    (*data)->win_close = 1;
    return (0);
}
