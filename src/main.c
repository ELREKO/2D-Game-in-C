# include "../include/so_long.h"

//static void progamm_struckt (char *filename);

// int main(int argc, char **arg) 
// { 
//     if (argc < 2)
//         ft_throw_error("ERROR: Map is Missing!\n");
//     else if (argc > 2)
//         ft_throw_error("ERROR: To many Arguments! Please only one Map!\n");
//     else
//         progamm_struckt(arg[1]);
//     return (0); 
// }



// static void progamm_struckt (char *filename)
// {
//     t_lay *map;
//     t_positon *player_pos;

//     map = ft_load_map(filename);
//     ft_map_controll(&map);
//     printf(" BEFOR \n x=|%u|, y=|%u|, pl=|%i| ex=|%i| col=|%i|\n", map->i_x , map->i_y, map->i_pl,map->i_exit, map->i_collect);

//     player_pos = ft_check_payable(&map);
//     ft_window_setting(&player_pos, &map);

//     free(player_pos);
//     ft_free_map_struct(&map);
 
// }


void	*mlx;
void	*win1;
void	*im2;
int	xpm1_x;
int	xpm1_y;


int	main()
{

  if (!(mlx = mlx_init()))
    {
      printf(" !! KO !!\n");
      exit(1);
    }

  if (!(win1 = mlx_new_window(mlx,240,250,"Title1")))
    {
      printf(" !! KO !!\n");
      exit(1);
    }


  printf(" => Xpm from file ...");
  if (!(im2 = mlx_xpm_file_to_image(mlx,"open.xpm",&xpm1_x,&xpm1_y)))
    {
      printf(" !! KO !!\n");
      exit(1);
    }

  mlx_put_image_to_window(mlx,win1,im2,100,100);
  mlx_put_image_to_window(mlx,win1,im2,150,150);
 
  mlx_loop(mlx);
}



