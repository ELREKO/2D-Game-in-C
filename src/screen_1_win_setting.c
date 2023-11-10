/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_1_win_setting.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <rkost@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:38:33 by rkost             #+#    #+#             */
/*   Updated: 2023/11/10 17:26:49 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static	void	ft_init_t_mlx_data(t_mlx_data **data, t_lay **map,
					t_positon **pos);
static	int	handle_input(int keysym, t_mlx_data **data);

int	ft_window_setting(t_lay **map, t_positon **pos)
{
	t_mlx_data	*data;
	int			width;
	int			hight;

	data = malloc(sizeof(t_mlx_data));
	if (data == NULL)
		ft_throw_map_error(map, 10);
	width = (*map)->i_x * 50;
	hight = (*map)->i_y * 50;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, width, hight, "so_long");
	if ((data->mlx_ptr) == NULL || (data->win_ptr) == NULL)
		ft_error_map_data(map, 410, &data);
	ft_init_t_mlx_data(&data, map, pos);
	ft_put_image_to_window(&data);
	mlx_key_hook(data->win_ptr, handle_input, &data);
	mlx_hook(data->win_ptr, 17, 0, ft_close_window, &data);
	mlx_loop(data->mlx_ptr);
	ft_destroy_image(&data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data);
	return (0);
}

static	void	ft_init_t_mlx_data(t_mlx_data **data, t_lay **map,
					t_positon **pos)
{
	if (!(ft_init_image(data)))
		ft_error_map_data(map, 420, data);
	(*data)->map = *map;
	(*data)->pos = *pos;
	(*data)->step_count = 0;
	(*data)->win_close = 0;
	(*data)->bock_key = 0;
}

static int	handle_input(int keysym, t_mlx_data **data)
{
	if (!((*data)->bock_key))
	{
		if (keysym == XK_Escape)
			ft_close_window(data);
		if (keysym == XK_Left || keysym == XK_a
			|| keysym == XK_Right || keysym == XK_d
			|| keysym == XK_Up || keysym == XK_w
			|| keysym == XK_Down || keysym == XK_s)
		{
			if (keysym == XK_Left || keysym == XK_a)
				ft_move_left(data);
			if (keysym == XK_Right || keysym == XK_d)
				ft_move_right(data);
			if (keysym == XK_Up || keysym == XK_w)
				ft_move_up(data);
			if (keysym == XK_Down || keysym == XK_s)
				ft_move_down(data);
		}
	}
	return (0);
}

int	ft_close_window(t_mlx_data **data)
{
	ssize_t	ret;

	ret = write(1, "close programm\n", 16);
	if (ret == (-1))
		perror ("ERROR : write");
	mlx_loop_end((*data)->mlx_ptr);
	(*data)->win_close = 1;
	ft_print_count_steps(data);
	return (0);
}
