#include "../include/so_long.h"


void ft_putchar(char ch)
{
    write(1, &ch, 1);
}

void ft_putstr (char *str)
{
    int i_count;

    i_count = 0;
    while (str[i_count] != '\0')
    {
        ft_putchar(str[i_count]);
        i_count++;
    }
}