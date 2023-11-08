#include "../include/so_long.h"

static int	handle_input(int keysym, t_mlx_data *data);
static int ft_close_window(t_mlx_data *data);

#define MALLOC_ERROR    1
#define WIDTH           400
#define HEIGHT          400

int ft_window_setting(void)
{

    t_mlx_data	data;
    int w = 50;
    int h = 50;

    data.mlx_ptr = mlx_init();
    if (data.mlx_ptr == NULL)
        return (MALLOC_ERROR);
        
    data.win_ptr = mlx_new_window(data.mlx_ptr, 
                                WIDTH, 
                                HEIGHT,
                                "My first window!");
    if (data.win_ptr == NULL)
    {
        mlx_destroy_display(data.mlx_ptr);
        free(data.mlx_ptr);
        return (MALLOC_ERROR);
    }

    mlx_key_hook(data.win_ptr, 
                handle_input, 
                &data);
    
    mlx_key_hook(data.win_ptr, handle_input, &data);
    mlx_hook(data.win_ptr, 17, 0, ft_close_window, &data);

    data.img_wall = mlx_xpm_file_to_image(data.mlx_ptr, "img/exit_close.xpm", &w, &h  );
    if (!data.img_wall)
        ft_throw_error("Fuck bild konnte nicht geladen werden!");
    
    mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,data.img_wall,0,0);

    mlx_loop(data.mlx_ptr);


    mlx_destroy_image(data.mlx_ptr,data.img_wall);
    mlx_destroy_window(data.mlx_ptr, data.win_ptr);
    mlx_destroy_display(data.mlx_ptr);
    free(data.mlx_ptr);


    return (0);
}

static int	handle_input(int keysym, t_mlx_data *data)
{
    if (keysym == XK_Escape)
        ft_close_window(data);
    if (keysym == XK_Left || keysym == XK_a)
        printf(" u are a asshole\n\n");
    return (0);
}

static int ft_close_window(t_mlx_data *data)
{
    ssize_t ret;
    ret = write(1, "close programm\n", 16);
    if (ret == -1 )
        perror ("ERROR : write"); 
    mlx_loop_end(data->mlx_ptr);
    return (0);
}
