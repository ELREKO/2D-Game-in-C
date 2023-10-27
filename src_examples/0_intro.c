#include "../minilibx-linux/mlx.h"
//#include "../minilibx-linux/mlx_int.h"
#include <stdlib.h>

// Creating and Destroying a Xvar
int ft_init_Xvar (void)
{
    void *mlx_ptr;

    mlx_ptr = mlx_init();
    if (mlx_ptr == NULL)
        return (1);

    mlx_destroy_display(mlx_ptr);
    free(mlx_ptr);
    return (0);
}

int main (void)
{
    if (ft_init_Xvar())
        return (1); 
    return (0);
}

// Compliling 
// gcc src/0_intro.c -Lminilibx-linux -lmlx_Linux -lX11 -lXext
