#include "../include/so_long.h"

// static void ft_check_wall_first_last_row(char **str_test, t_lay **map);

// int ft_map_checking (int file_discripter)
// {

//     return (file_discripter);
// }

// Checking if the sting is all with num 1; --> storage the size of collum 
// Errorhandling if it doesn't work map to small or the row open;


// static void ft_check_wall_first_last_row(char **str_test, t_lay **map)
// {  
//     int i_count;
    
//     i_count = 0;
//     while ((*str_test)[i_count] != '\0')
//     {
//         if ((*str_test)[i_count] != '1')
//         {
//             i_count = -1;
//             break;
//         }
//         i_count++;
//     }
//     if (i_count < 3)
//     {
//         free(*map);
//         *map = NULL;
//         ft_free_str(str_test);
//         if (i_count == -1)
//             ft_throw_error("ERROR : Map not close in the first or last row!\n");
//         else
//             ft_throw_error("ERROR : Less than 3 cloums in the Map!\n");
//         return ;
//     }
//     (*map)->i_col = i_count;
// }