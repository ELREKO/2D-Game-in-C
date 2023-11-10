/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_101_utiles.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <rkost@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:38:03 by rkost             #+#    #+#             */
/*   Updated: 2023/11/10 12:42:45 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static	void	ft_map_copy(t_lay **copy, t_lay *src);

t_lay	*copy_t_lay(t_lay *src)
{
	t_lay	*copy;

	copy = malloc(sizeof(t_lay));
	if (!copy)
	{
		copy = NULL;
		ft_throw_map_error(&src, 10);
	}
	copy->i_x = src->i_x;
	copy->i_y = src->i_y;
	copy->i_exit = src->i_exit;
	copy->i_pl = src->i_pl;
	copy->i_collect = src->i_collect;
	copy->map = malloc (sizeof(char *) * (src->i_y + 1));
	if (!copy->map)
	{
		copy = NULL;
		ft_throw_map_error(&src, 10);
	}
	copy->map[src->i_y] = NULL;
	ft_map_copy(&copy, src);
	return (copy);
}

static	void	ft_map_copy(t_lay **copy, t_lay *src)
{
	unsigned int	i_count_x;
	unsigned int	i_count_y;

	i_count_y = 0;
	while (i_count_y < src->i_y)
	{
		i_count_x = 0;
		(*copy)->map [i_count_y] = malloc (sizeof(char) * (src ->i_x + 1));
		if ((*copy)->map[i_count_y] == NULL)
			ft_free_map_struct(copy);
		while (i_count_x <= src->i_x)
		{
			(*copy)->map[i_count_y][i_count_x] = src->map[i_count_y][i_count_x];
			i_count_x++;
		}
		i_count_y++;
	}
}
