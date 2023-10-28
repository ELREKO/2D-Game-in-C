# include "../include/so_long.h"

static void ft_load_map(char *filename);

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

static void ft_load_map(char *filename)
{
    int file_discripter;

    file_discripter = ft_open_maps(filename);
    printf("File Discripter %i\n", file_discripter);
    ft_close_map (file_discripter);

    return ;
}

