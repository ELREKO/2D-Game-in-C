/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_2_check_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <rkost@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:52:52 by rkost             #+#    #+#             */
/*   Updated: 2023/11/10 16:49:46 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

static	int	ft_check_wall_first_last_row(char *str);
static	int	ft_check_wall_middel(char *str);
static	int	ft_count_equiment(t_lay **map, char *str);
static	void	ft_check_sum_of_equiment(t_lay **map);

int	ft_map_controll(t_lay **map)
{
	unsigned int	i_count; 

	i_count = 0;
	while ((*map)->map[i_count] != NULL)
	{
		if (i_count == 0 || i_count == (((*map)->i_y) - 1))
		{
			if (!(ft_check_wall_first_last_row((*map)->map[i_count])))
				ft_throw_map_error(map, 100);
		}
		else
		{
			if (!(ft_count_equiment(map, ((*map)->map[i_count]))))
				ft_throw_map_error(map, 90);
			if (!(ft_check_wall_middel((*map)->map[i_count])))
				ft_throw_map_error(map, 100);
		}
		i_count++;
	}
	ft_check_sum_of_equiment(map);
	return (1);
}

static	int	ft_check_wall_first_last_row(char *str)
{
	int	i_count;

	i_count = 0;
	while (str[i_count] != '\0')
	{
		if (str[i_count] != '1')
			return (0);
		i_count++;
	}
	return (1);
}

static	int	ft_check_wall_middel(char *str)
{
	unsigned int	i_size;

	i_size = ft_strlen(str);
	if (str[0] != '1' || str[i_size - 1] != '1')
		return (0);
	return (1);
}

// Count Player // Count Collectables //Count exit 
static	int	ft_count_equiment(t_lay **map, char *str)
{
	int	i_count; 

	i_count = 0;
	while (str[i_count] != '\0')
	{
		if (str[i_count] == '1'
			|| str[i_count] == '0'
			|| str[i_count] == 'E'
			|| str[i_count] == 'P'
			|| str[i_count] == 'C'
			|| str[i_count] == 'G')
		{
			if (str[i_count] == 'P')
				(*map)->i_pl = (*map)->i_pl + 1;
			else if (str[i_count] == 'C')
				(*map)->i_collect = (*map)->i_collect + 1;
			else if (str[i_count] == 'E')
				(*map)->i_exit = (*map)->i_exit + 1;
			i_count++;
		}
		else
			return (0);
	}
	return (1);
}

static	void	ft_check_sum_of_equiment(t_lay **map)
{
	int	i_player;
	int	i_collectables;
	int	i_exit;

	i_player = (*map)->i_pl;
	i_collectables = (*map)->i_collect;
	i_exit = (*map)->i_exit;
	if (i_player < 1)
		ft_throw_map_error(map, 210);
	if (i_collectables < 1)
		ft_throw_map_error(map, 220);
	if (i_exit < 1)
		ft_throw_map_error(map, 230);
	if (i_player > 1)
		ft_throw_map_error(map, 240);
	if (i_exit > 1)
		ft_throw_map_error(map, 250);
}
