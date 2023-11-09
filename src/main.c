# include "../include/so_long.h"

static void progamm_struckt (char *filename);

int main(int argc, char **arg) 
{ 
    if (argc < 2)
        ft_throw_error("ERROR: Map is Missing!\n");
    else if (argc > 2)
        ft_throw_error("ERROR: To many Arguments! Please only one Map!\n");
    else
    {
        if (ft_strlen(arg[1]) > 6)
            progamm_struckt(arg[1]);
        else
            ft_throw_error("ERROR : Map must have *.ber!\n");
    }
    return (0); 
}



static void progamm_struckt (char *filename)
{
    t_lay *map;
    t_positon *player_pos;

    map = ft_load_map(filename);
    ft_map_controll(&map);

    player_pos = ft_check_payable(&map);
    ft_window_setting(&map, &player_pos);

    free(player_pos);
    ft_free_map_struct(&map);
 
}




