#include "../include/so_long.h"

//set a map 
// And set Size for x and y;
// Checking is rectangle  
t_lay *ft_creat_map_set_size(int file_discripter)
{
    t_lay *map;
    char *str_line;

    map = malloc(sizeof(t_lay));
    if (!map)
        ft_throw_map_error(&map, 10);
    str_line = get_next_line(file_discripter);
    map->i_x = ft_strlen(str_line);
    map->i_y = 0;
    while (str_line != NULL)
    {
        free(str_line);
        str_line = NULL;
        str_line = get_next_line(file_discripter);
        if ((str_line != NULL) && (map->i_x != ft_strlen(str_line)))
        {
            //printf ("y %i -- x %i -- %i -- %s\n", map->i_y, map->i_x, ft_strlen(str_line), str_line);
            ft_free_str(&str_line);
            ft_throw_map_error(&map, 30);
        }
        map->i_y = map->i_y + 1;
    }
    ft_free_str(&str_line);
    return (map);
}

// void ft_read_map_sruct(int file_discripter, t_lay **map)
// {
//     char *str_line;
//     int i_cont;
   
    
//     (*map)->map = malloc(sizeof(char *) * ((*map)->i_y + 1));
//     if (!((*map)->map))
//         ft_throw_map_error(map, 20);
//     i_cont = 0;

//     while (str_line != NULL)
//     {
//         str_line = get_next_line(file_discripter);
//     }
// }