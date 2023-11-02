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
    map->i_pl = 0;
    map->i_exit = 0;
    map->i_collect = 0;
    map->map = NULL;
    while (str_line != NULL)
    {
        free(str_line);
        str_line = NULL;
        str_line = get_next_line(file_discripter);
        if ((str_line != NULL) && (map->i_x != ft_strlen(str_line)))
        {
            ft_free_str(&str_line);
            ft_throw_map_error(&map, 30);
        }
        map->i_y = map->i_y + 1;
    }

    ft_free_str(&str_line);
    return (map);
}



void ft_read_map_sruct(int file_discripter, t_lay **map)
{
    char *str_line;
    unsigned int i_count;
   
    // Creating **Map ! 
    (*map)->map = malloc(sizeof(char *) * ((*map)->i_y + 1));
    if (!((*map)->map))
        ft_throw_map_error(map, 20);
    (*map)->map[(*map)->i_y] = NULL;
    i_count = 0;
    while (i_count < (*map)->i_y)
    {
        (*map)->map[i_count] = malloc(sizeof(char) * ((*map)->i_x + 1));
        i_count++;
    }
    str_line = get_next_line(file_discripter);
    i_count = 0;
    while (str_line != NULL)
    {
        if (str_line != NULL)
        {
            (*map)->map[i_count] = ft_strcpy((*map)->map[i_count], str_line);
            if (!((*map)->map[i_count]))
                ft_throw_map_error(map, 20);
        }
        //printf("\n\nI COUNT is %i -- map[iYactu] = |%s| imap[count] %s \n\n", i_count,(*map)->map[i_count] ,(*map)->map[(*map)->i_y]);
        free(str_line);
        str_line = get_next_line(file_discripter);
        i_count++;
    }
    free(str_line);
    str_line = NULL;
}

void ft_print_out_map(t_lay *map)
{
    int i_count = 0;
    printf("Mapp Printing given Map\n\n");
    while (map->map[i_count] != NULL)
        printf("%s\n", map->map[i_count++]);
}