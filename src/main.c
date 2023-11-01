# include "../include/so_long.h"

int main(int argc, char **arg) 
{ 
    if (argc < 2)
        ft_throw_error("ERROR: Map is Missing!\n");
    else if (argc > 2)
        ft_throw_error("ERROR: To many Arguments! Please only one Map!\n");
    else
        ft_load_map(arg[1]);
    return (0); 
}


