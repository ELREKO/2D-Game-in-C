#include "../include/so_long.h"

static int	handle_input(int keysym, t_mlx_data *data);
static int ft_close_window(t_mlx_data *data);

#define MALLOC_ERROR    1
#define WIDTH           400
#define HEIGHT          400

int ft_window_setting(t_positon **pos, t_lay **map)
{

    t_mlx_data	data;

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

   // Leave the control to the EVENT LOOP

    /*
     * HOOKS
     *  "Hooking into events" (react to events)
     * When i press a key, handle_input() is triggered
     * 💡 Every event is linked to its own prototype handler 💡
    */
    mlx_key_hook(data.win_ptr, 
                handle_input, 
                &data);
    
    mlx_key_hook(data.win_ptr, handle_input, &data);
    mlx_hook(data.win_ptr, 17, 0, ft_close_window, &data);

    mlx_loop(data.mlx_ptr);

    mlx_destroy_window(data.mlx_ptr, data.win_ptr);
    mlx_destroy_display(data.mlx_ptr);
    free(data.mlx_ptr);


    return (0);
}

static int	handle_input(int keysym, t_mlx_data *data)
{
    //Check the #defines
    //find / -name keysym.h 2>/dev/null
    //find / -name keysymdef.h 2>/dev/null
    if (keysym == XK_Escape)
        ft_close_window(data);
    if (keysym == XK_Left || keysym == XK_a)
        printf(" u are a asshole\n\n");
    return (0);
}

static int ft_close_window(t_mlx_data *data)
{
    write(1, "close programm\n", 15);
    mlx_loop_end(data->mlx_ptr);
    // mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    // mlx_destroy_display(data->mlx_ptr);
    return (0);
   // exit(0); // Optional: Du kannst auch eine andere Exit-Nummer verwenden
}
