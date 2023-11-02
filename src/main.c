# include "../include/so_long.h"

static void progamm_struckt (char *filename);

int main(int argc, char **arg) 
{ 
    if (argc < 2)
        ft_throw_error("ERROR: Map is Missing!\n");
    else if (argc > 2)
        ft_throw_error("ERROR: To many Arguments! Please only one Map!\n");
    else
        progamm_struckt(arg[1]);
    return (0); 
}

static void progamm_struckt (char *filename)
{
    t_lay *map;

    map = ft_load_map(filename);
    ft_map_controll_wall(&map);

    

    printf("x %u y %u\n", map->i_x , map->i_y);
    ft_print_out_map(map);

    ft_free_map_struct(&map);
}

