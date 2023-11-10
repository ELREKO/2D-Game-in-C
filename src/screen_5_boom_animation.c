/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_5_boom_animation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <rkost@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:37:40 by rkost             #+#    #+#             */
/*   Updated: 2023/11/10 16:37:58 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

static	void	init_image_boom(t_mlx_data **data);

void	ft_enemy_animaiton(t_mlx_data **data)
{
	(*data)->bock_key = 1;
	mlx_clear_window((*data)->mlx_ptr, (*data)->win_ptr);
	init_image_boom(data);
	mlx_destroy_image((*data)->mlx_ptr, (*data)->img_boom1);
	mlx_destroy_image((*data)->mlx_ptr, (*data)->img_boom2);
	mlx_destroy_image((*data)->mlx_ptr, (*data)->img_boom3);
	mlx_destroy_image((*data)->mlx_ptr, (*data)->img_boom4);
	mlx_destroy_image((*data)->mlx_ptr, (*data)->img_boom5);
	mlx_clear_window((*data)->mlx_ptr, (*data)->win_ptr);
	ft_close_window(data);
}

static	void	init_image_boom(t_mlx_data **data)
{
	int	w;
	int	h;

	(*data)->img_boom1 = mlx_xpm_file_to_image((*data)->mlx_ptr,
			"img/boom1.xpm", &w, &h);
	mlx_put_image_to_window((*data)->mlx_ptr, (*data)->win_ptr,
		(*data)->img_boom1, 20, 20);
	(*data)->img_boom2 = mlx_xpm_file_to_image((*data)->mlx_ptr,
			"img/boom2.xpm", &w, &h);
	mlx_put_image_to_window((*data)->mlx_ptr, (*data)->win_ptr,
		(*data)->img_boom2, 20, 20);
	(*data)->img_boom3 = mlx_xpm_file_to_image((*data)->mlx_ptr,
			"img/boom3.xpm", &w, &h);
	mlx_put_image_to_window((*data)->mlx_ptr, (*data)->win_ptr,
		(*data)->img_boom3, 20, 20);
	(*data)->img_boom4 = mlx_xpm_file_to_image((*data)->mlx_ptr,
			"img/boom4.xpm", &w, &h);
	mlx_put_image_to_window((*data)->mlx_ptr, (*data)->win_ptr,
		(*data)->img_boom4, 20, 20);
	(*data)->img_boom5 = mlx_xpm_file_to_image((*data)->mlx_ptr,
			"img/boom5.xpm", &w, &h);
	mlx_put_image_to_window((*data)->mlx_ptr, (*data)->win_ptr,
		(*data)->img_boom5, 20, 20);
}
