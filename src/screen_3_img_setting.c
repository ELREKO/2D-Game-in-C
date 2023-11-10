/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_3_img_setting.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <rkost@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:40:09 by rkost             #+#    #+#             */
/*   Updated: 2023/11/10 15:57:48 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

static	void	ft_put_image(t_mlx_data **data, int i_y);

int	ft_init_image(t_mlx_data **list)
{
	int		width;
	int		hight;

	width = 50;
	hight = 50;
	(*list)->img_wall = mlx_xpm_file_to_image((*list)->mlx_ptr,
			"img/wall.xpm", &width, &hight);
	(*list)->img_floor = mlx_xpm_file_to_image((*list)->mlx_ptr,
			"img/floor.xpm", &width, &hight);
	(*list)->img_col = mlx_xpm_file_to_image((*list)->mlx_ptr,
			"img/collect.xpm", &width, &hight);
	(*list)->img_pl_front = mlx_xpm_file_to_image((*list)->mlx_ptr,
			"img/player.xpm", &width, &hight);
	(*list)->img_exit = mlx_xpm_file_to_image((*list)->mlx_ptr,
			"img/exit_close.xpm", &width, &hight);
	(*list)->img_enemy = mlx_xpm_file_to_image((*list)->mlx_ptr,
			"img/enemy.xpm", &width, &hight);
	if (!((*list)->img_wall) || !((*list)->img_floor) 
		|| !((*list)->img_col) || !((*list)->img_pl_front) 
		|| !((*list)->img_exit) || !((*list)->img_enemy))
		return (0);
	return (1);
}

int	ft_destroy_image(t_mlx_data **list)
{
	mlx_destroy_image((*list)->mlx_ptr, (*list)->img_wall);
	mlx_destroy_image((*list)->mlx_ptr, (*list)->img_floor);
	mlx_destroy_image((*list)->mlx_ptr, (*list)->img_col);
	mlx_destroy_image((*list)->mlx_ptr, (*list)->img_pl_front);
	mlx_destroy_image((*list)->mlx_ptr, (*list)->img_exit);
	mlx_destroy_image((*list)->mlx_ptr, (*list)->img_enemy);
	return (0);
}

void	ft_put_image_to_window(t_mlx_data **data)
{
	int	i_y;

	i_y = 0;
	while ((*data)->map->map[i_y] != NULL)
	{
		ft_put_image(data, i_y);
		i_y++;
	}
	ft_print_count_steps(data);
}

static	void	ft_put_image(t_mlx_data **data, int i_y)
{
	int	i_x;

	i_x = 0;
	while ((*data)->map->map[i_y][i_x] != '\0')
	{
		if ((*data)->map->map[i_y][i_x] == '1')
			mlx_put_image_to_window((*data)->mlx_ptr, (*data)->win_ptr,
				(*data)->img_wall, (i_x * 50), (i_y * 50));
		if ((*data)->map->map[i_y][i_x] == '0')
			mlx_put_image_to_window((*data)->mlx_ptr, (*data)->win_ptr,
				(*data)->img_floor, (i_x * 50), (i_y * 50));
		if ((*data)->map->map[i_y][i_x] == 'P')
			mlx_put_image_to_window((*data)->mlx_ptr, (*data)->win_ptr,
				(*data)->img_pl_front, (i_x * 50), (i_y * 50));
		if ((*data)->map->map[i_y][i_x] == 'C')
			mlx_put_image_to_window((*data)->mlx_ptr, (*data)->win_ptr,
				(*data)->img_col, (i_x * 50), (i_y * 50));
		if ((*data)->map->map[i_y][i_x] == 'E')
			mlx_put_image_to_window((*data)->mlx_ptr, (*data)->win_ptr,
				(*data)->img_exit, (i_x * 50), (i_y * 50));
		if ((*data)->map->map[i_y][i_x] == 'G')
			mlx_put_image_to_window((*data)->mlx_ptr, (*data)->win_ptr,
				(*data)->img_enemy, (i_x * 50), (i_y * 50));
		i_x++;
	}
}
