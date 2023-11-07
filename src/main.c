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
    t_positon *player_pos;

    map = ft_load_map(filename);
    ft_map_controll(&map);
    printf(" BEFOR \n x=|%u|, y=|%u|, pl=|%i| ex=|%i| col=|%i|\n", map->i_x , map->i_y, map->i_pl,map->i_exit, map->i_collect);

    player_pos = ft_check_payable(&map);
    ft_window_setting();

    free(player_pos);
    ft_free_map_struct(&map);
 
}




