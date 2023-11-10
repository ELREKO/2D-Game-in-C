/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_2_win_function.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <rkost@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:13:14 by rkost             #+#    #+#             */
/*   Updated: 2023/11/10 17:32:26 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

void	draw_black_rectangle(void *mlx_ptr, void *win_ptr,
		int width, int height)
{
	int	x;
	int	y;
	int	color;

	x = 0;
	y = 0;
	color = 0x000000;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
			x++;
		}
		y++;
	}
}

void	ft_print_count_steps(t_mlx_data **data)
{
	char	*str;

	if (!((*data)->bock_key))
	{
		str = ft_itoa((*data)->step_count);
		(*data)->step_count = (*data)->step_count + 1;
		if ((*data)->win_close)
		{
			ft_putstr("Win with ");
			ft_putstr(str);
		}
		else
			ft_putstr(str);
		ft_putstr(" steps\n");
		draw_black_rectangle((*data)->mlx_ptr, (*data)->win_ptr, 30, 20);
		mlx_string_put((*data)->mlx_ptr, (*data)->win_ptr, 5, 15,
			0xfc0303, str);
		free(str);
	}
	else
		ft_putstr("You Lose!\n");
}

void	ft_destoy_screen_free_data(t_mlx_data **data)
{
	ft_destroy_image(data);
	mlx_destroy_window((*data)->mlx_ptr, (*data)->win_ptr);
	mlx_destroy_display((*data)->mlx_ptr);
	free((*data)->mlx_ptr);
	free(*data);
}

void	ft_check_exit(t_mlx_data **data)
{
	int	w;
	int	h;

	w = 50;
	h = 50;
	if ((*data)->map->i_collect <= 0)
	{
		mlx_destroy_image((*data)->mlx_ptr, (*data)->img_exit);
		(*data)->img_exit = mlx_xpm_file_to_image((*data)->mlx_ptr,
				"img/exit_open.xpm", &w, &h);
	}
	if (!((*data)->img_exit))
		ft_error_map_data(&((*data)->map), 420, data);
	ft_put_image_to_window(data);
}
