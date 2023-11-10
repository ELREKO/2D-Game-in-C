/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_100_utiles.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <rkost@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:42:30 by rkost             #+#    #+#             */
/*   Updated: 2023/11/10 12:37:28 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

static	void	init_lay(t_lay **map, char *str);
static	void	init_map(t_lay **map);

//set a map 
// And set Size for x and y;
// Checking is rectangle
t_lay	*ft_creat_map_set_size(int file_discripter)
{
	t_lay	*map;
	char	*str_line;

	map = malloc(sizeof(t_lay));
	if (!map)
		ft_throw_map_error(&map, 10);
	str_line = get_next_line(file_discripter);
	init_lay(&map, str_line);
	while (str_line != NULL)
	{
		free(str_line);
		str_line = NULL;
		str_line = get_next_line(file_discripter);
		if ((str_line != NULL) && (map->i_x != ft_strlen(str_line)))
		{
			ft_free_str(&str_line);
			ft_throw_map_error(&map, 30);
		}
		map->i_y = map->i_y + 1;
	}
	ft_free_str(&str_line);
	return (map);
}

static	void	init_lay(t_lay **map, char *str)
{
	(*map)->i_x = ft_strlen(str);
	(*map)->i_y = 0;
	(*map)->i_pl = 0;
	(*map)->i_exit = 0;
	(*map)->i_collect = 0;
	(*map)->screen_width = 0;
	(*map)->screen_hight = 0;
	(*map)->map = NULL;
}

void	ft_read_map_sruct(int file_discripter, t_lay **map)
{
	char			*str_line;
	unsigned int	i_count;

	init_map(map);
	str_line = get_next_line(file_discripter);
	i_count = 0;
	while (str_line != NULL)
	{
		if (str_line != NULL)
		{
			(*map)->map[i_count] = ft_strcpy((*map)->map[i_count], str_line);
			if (!((*map)->map[i_count]))
				ft_throw_map_error(map, 20);
		}
		free(str_line);
		str_line = get_next_line(file_discripter);
		i_count++;
	}
	free(str_line);
	str_line = NULL;
}

static	void	init_map(t_lay **map)
{
	unsigned int	i_count;

	(*map)->map = malloc(sizeof(char *) * ((*map)->i_y + 1));
	if (!((*map)->map))
		ft_throw_map_error(map, 20);
	(*map)->map[(*map)->i_y] = NULL;
	i_count = 0;
	while (i_count < (*map)->i_y)
	{
		(*map)->map[i_count] = malloc(sizeof(char) * ((*map)->i_x + 1));
		i_count++;
	}
}
