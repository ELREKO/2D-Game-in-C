# include "../include/so_long.h"

void ft_throw_error (char *str)
{
   ft_putstr(str);
   exit (0);
}

void ft_throw_map_error(t_lay **map, int err_num)
{
   ft_free_map_struct(map);
   if (err_num == 10)
      ft_throw_error("ERROR : Malloc map error ");
   else if (err_num == 20)
      ft_throw_error("ERROR : Malloc map error *map size\n");
   else if (err_num == 30)
      ft_throw_error("ERROR : Map isn't rectangle\n");
   else if (err_num == 100)
      ft_throw_error("ERROR : Wall is open\n");
   else if (err_num == 210)
      ft_throw_error("ERROR : Player less than 1\n");
   else if (err_num == 220)
      ft_throw_error("ERROR : Collectabel less than 1\n");
   else if (err_num == 230)
      ft_throw_error("ERROR : Exit less than 1\n");
   else if (err_num == 240)
      ft_throw_error("ERROR : Player more than 1\n");
   else if (err_num == 250)
      ft_throw_error("ERROR : Exit more than 1\n");
   else if (err_num == 300)
      ft_throw_error("ERROR : Not playable code not reach all collects or the exit\n");
   else if (err_num == 310)
      ft_throw_error("ERROR : Not playable map is to big for the screen! Please resize the width!\n");
   else if (err_num == 320)
      ft_throw_error("ERROR : Not playable map is to big for the screen! Please resize the hight!\n");
   else
      ft_throw_error("!!!THROW A MAP ERROR WITHOUT A CORRECT NUMMBER!!!");
}

void ft_free_map_struct(t_lay **map)
{
    int i_count = 0;
    if ((*map)->map != NULL)
    {
      while ((*map)->map[i_count] != NULL)
      {
         free((*map)->map[i_count]);
         (*map)->map[i_count] = NULL;
         i_count++;
      }
    }
    free((*map)->map);
    (*map)->map = NULL;
    free((*map));
    map = NULL;
}

