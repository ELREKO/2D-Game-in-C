#include "../include/so_long.h"

static int	handle_input(int keysym, t_mlx_data **data);
static int ft_close_window(t_mlx_data **data);

static void ft_put_image_to_window(t_mlx_data **data);

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
    data->map = (*map)->map;
    data->pl_x_pos = (*pos)->x;
    data->pl_y_pos = (*pos)->y;

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



static void ft_put_image_to_window(t_mlx_data **data)
{
    int i_x;
    int i_y;

    i_y = 0;
    while ((*data)->map[i_y] != NULL)
    {
        i_x = 0;
        while ((*data)->map[i_y][i_x] != '\0')
        {
            if ((*data)->map[i_y][i_x] == '1')
                mlx_put_image_to_window((*data)->mlx_ptr, (*data)->win_ptr,(*data)->img_wall,(i_x * 50), (i_y * 50) );
            if ((*data)->map[i_y][i_x] == '0')
                mlx_put_image_to_window((*data)->mlx_ptr, (*data)->win_ptr,(*data)->img_floor,(i_x * 50), (i_y * 50) );
            if ((*data)->map[i_y][i_x] == 'P')
                mlx_put_image_to_window((*data)->mlx_ptr, (*data)->win_ptr,(*data)->img_pl_front,(i_x * 50), (i_y * 50) );
            if ((*data)->map[i_y][i_x] == 'C')
                mlx_put_image_to_window((*data)->mlx_ptr, (*data)->win_ptr,(*data)->img_col,(i_x * 50), (i_y * 50) );
            if ((*data)->map[i_y][i_x] == 'E')
                mlx_put_image_to_window((*data)->mlx_ptr, (*data)->win_ptr,(*data)->img_exit_close,(i_x * 50), (i_y * 50) );
            i_x++;
        }
        i_y++;
    }
}

void  ft_move_left(t_mlx_data **data)
{
    char ch_tmp; 

    ch_tmp = (*data)->map[(*data)->pl_y_pos][((*data)->pl_x_pos)-1];
    if (ch_tmp != '1' && ((*data)->pl_x_pos) > 0)
    {
        (*data)->pl_x_pos = ((*data)->pl_x_pos) - 1;
        (*data)->map[(*data)->pl_y_pos][(*data)->pl_x_pos] = 'P';
        (*data)->map[(*data)->pl_y_pos][(*data)->pl_x_pos + 1] = ch_tmp;
        mlx_clear_window((*data)->mlx_ptr, (*data)->win_ptr);
        ft_put_image_to_window(data);
    }
    else
        ft_putstr("No moveable! Maybe Wall!\n");
}

static int	handle_input(int keysym, t_mlx_data **data)
{
    if (keysym == XK_Escape)
        ft_close_window(data);
    if (keysym == XK_Left || keysym == XK_a)
        ft_move_left(data);
    return (0);
}



static int ft_close_window(t_mlx_data **data)
{
    ssize_t ret;
    ret = write(1, "close programm\n", 16);
    if (ret == -1 )
        perror ("ERROR : write"); 
    mlx_loop_end((*data)->mlx_ptr);
    //ft_destoy_screen_free_data(data);
    return (0);
}
