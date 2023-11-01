# include "../include/so_long.h"

void ft_throw_error (char *str)
{
   ft_putstr(str);
   exit (0);
}

void ft_throw_map_error(t_lay **map, int err_num)
{
   free(*map);
   *map = NULL;
   if (err_num == 10)
      ft_throw_error("ERROR : Malloc map error ");
   else if (err_num == 20)
      ft_throw_error("ERROR : Malloc map error *map size\n");
   else if (err_num == 30)
      ft_throw_error("ERROR : Map isn't rectangle\n");
   else
      ft_throw_error("!!!THROW A MAP ERROR WITHOUT A CORRECT NUMMBER!!!");
}

