#include "../include/so_long.h"

static int ft_check_wall_first_last_row(char *str);
static int ft_check_wall_middel(char *str);

int ft_map_controll_wall(t_lay **map)
{
    unsigned int i_count; 

    i_count = 0;
    while ((*map)->map[i_count] != NULL)
    {
        //printf("checking row %i\n", i_count);
        if (i_count == 0 || i_count == (((*map)->i_y) - 1))
        {
            if (!(ft_check_wall_first_last_row((*map)->map[i_count])))
                ft_throw_map_error_open_wall(map, 100);
        }
        else
        {
            if (!(ft_check_wall_middel((*map)->map[i_count])))
                ft_throw_map_error_open_wall(map, 100);
        }
        i_count++; 
    }
    return (1);
}

static int ft_check_wall_first_last_row(char *str)
{
    int i_count;

    i_count = 0;
    while (str[i_count] != '\0')
    {
        if (str[i_count] != '1')
            return (0);
        i_count++;
    }
    return (1);
}

static int ft_check_wall_middel(char *str)
{
    unsigned int i_size;
    i_size = ft_strlen(str); 
    if (str[0] != '1' || str[i_size - 1] != '1')
    {
        //printf ("|%c| -- |%c| i_size %i \n" ,str[0] , str[i_size], i_size );
        return (0);
    }
    return (1);
}


    // if (((*map)->i_x >= 3 && (*map)->i_y < 5) || 
    //     ((*map)->i_x < 3 && (*map)->i_y >= 5) ||
    //     ((*map)->i_x < 3 && (*map)->i_y < 5)  ||
    //     ((*map)->i_x >=5  && (*map)->i_y < 3) ||
    //     ((*map)->i_x < 5 && (*map)->i_y >= 3) || 
    //     ((*map)->i_x < 5 && (*map)->i_y < 3))
    // // if (((*map)->i_x < 3 && (*map)->i_y < 5) || 
    // //      ((*map)->i_x < 5 && (*map)->i_y < 3))
    // {
    //     printf("x %u y %u\n", (*map)->i_x , (*map)->i_y);
    //     ft_throw_map_error(map, 100);
    // }
    // return (1);