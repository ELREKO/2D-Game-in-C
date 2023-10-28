#include "../include/so_long.h"

static int ft_check_filename_ber(char *str);

int ft_open_maps(char *filename)
{
    int file_discripter;
    
    if (!(ft_check_filename_ber(filename)))
        ft_throw_error("ERROR: Map ending must be *.ber\n");
    file_discripter = open(filename, O_RDONLY);
    if (file_discripter < 0)
    {
        perror("ERROR: Map could not open! ");
        exit(1);
    }
    return (file_discripter);
}

void ft_close_map (int file_discripter)
{
    int i_res;

    i_res = close(file_discripter);
    if (i_res < 0)
    {
        perror("ERROR: Map could not Close! ");
        exit(1);
    }
    return ; 
}

static int ft_check_filename_ber(char *str)
{
    unsigned int i_size; 

    i_size = 0;
    while (str[i_size] != '\0')
        i_size++;
    if (str[i_size - 1] != 'r' &&
        str[i_size - 2] != 'e' &&
        str[i_size - 3] != 'b' &&
        str[i_size - 4] != '.')
    {
        return (0);
    }
    return (1);
}