/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_3_check_playable.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <rkost@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:04:04 by rkost             #+#    #+#             */
/*   Updated: 2023/11/10 13:17:38 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

static	t_positon	*ft_find_player_position(t_lay **map);
static	void		flood_fill_me(t_lay **map, t_positon begin, char ch);
static	int		ft_sreen_size(t_lay **map, t_positon **pos);

// return the player Position
t_positon	*ft_check_payable(t_lay **map)
{
	t_positon	*player_pos;
	t_lay		*map_copy;

	player_pos = ft_find_player_position(map);
	ft_sreen_size(map, &player_pos);
	map_copy = copy_t_lay(*map);
	flood_fill_me(&map_copy, *player_pos, 'V');
	if (map_copy->i_collect > 0 || map_copy->i_exit > 0)
	{
		ft_free_map_struct(&map_copy);
		ft_throw_map_error(map, 300);
	}
	ft_free_map_struct(&map_copy);
	return (player_pos);
}

// Check if the given map compatible with the screen_size
static	int	ft_sreen_size(t_lay **map, t_positon **pos)
{
	Display	*display;
	Screen	*screen;

	display = NULL;
	screen = DefaultScreenOfDisplay(display);
	display = XOpenDisplay(NULL);
	screen = DefaultScreenOfDisplay(display);
	(*map)->screen_width = WidthOfScreen(screen);
	(*map)->screen_hight = HeightOfScreen(screen);
	if (((*map)->i_x * 50) > ((*map)->screen_width - 150)
		|| ((*map)->i_y * 50) > ((*map)->screen_hight - 150))
	{
		free(*pos);
		XCloseDisplay(display);
		ft_throw_map_error(map, 310);
	}
	XCloseDisplay(display);
	return (0);
}

static	t_positon	*ft_find_player_position(t_lay **map)
{
	int			i_count_str;
	int			i_count_char;
	t_positon	*player_pos;

	i_count_str = 0;
	player_pos = malloc(sizeof(t_positon));
	if (!player_pos)
		return (NULL);
	while ((*map)->map[i_count_str] != NULL)
	{
		i_count_char = 0;
		while ((*map)->map[i_count_str][i_count_char] != '\0')
		{
			if ((*map)->map[i_count_str][i_count_char] == 'P')
			{
				player_pos->x = i_count_char;
				player_pos->y = i_count_str;
				return (player_pos);
			}
			i_count_char++;
		}
		i_count_str++;
	}
	return (player_pos);
}

static	void	flood_fill_me(t_lay **map, t_positon begin, char to_Fill)
{
	if ((*map)->map[begin.y][begin.x] == to_Fill || begin.y < 1
			|| begin.y >= (*map)->i_y
			|| begin.x < 1 || begin.x >= (*map)->i_x
			|| (*map)->map[begin.y][begin.x] == '1')
		return ;
	if ((*map)->map[begin.y][begin.x] == 'E')
		(*map)->i_exit = (*map)->i_exit - 1;
	else if ((*map)->map[begin.y][begin.x] == 'C')
		(*map)->i_collect = (*map)->i_collect - 1;
	(*map)->map[begin.y][begin.x] = to_Fill;
	flood_fill_me(map, (t_positon){begin.x - 1, begin.y}, to_Fill);
	flood_fill_me(map, (t_positon){begin.x + 1, begin.y}, to_Fill);
	flood_fill_me(map, (t_positon){begin.x, begin.y - 1}, to_Fill);
	flood_fill_me(map, (t_positon){begin.x, begin.y + 1}, to_Fill);
}
