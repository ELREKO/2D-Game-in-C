#include "../include/so_long.h"

static t_positon *ft_find_player_position(t_lay **map);
static void	flood_fill(t_lay **map, t_positon begin);

// return the player Position
t_positon *ft_check_payable(t_lay **map)
{
    t_positon *player_pos;

    player_pos = ft_find_player_position(map);
    flood_fill(map, *player_pos);
    
    return (player_pos);
}

static t_positon *ft_find_player_position(t_lay **map)
{
    int i_count_str;
    int i_count_char;
    t_positon *player_pos;

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

static void	flood_fill(t_lay **map, t_positon begin)
{
    printf("iam in Flood Fill x %i y %i map x %i map y %i\n", begin.x, begin.y, (*map)->i_x , (*map)->i_y);
    if (begin.y <= 0 || begin.y >= (*map)->i_y || 
        begin.x <= 0 || begin.x >= (*map)->i_x || 
        (*map)->map[begin.y][begin.x] == '1')
    {
            printf("before Return\n");
	        return;
    }
    if ((*map)->map[begin.y][begin.x] == 'E')
        (*map) -> i_exit = (*map) ->i_exit - 1;
    if ((*map)->map[begin.y][begin.x] == 'C')
        (*map) -> i_collect = (*map) ->i_collect - 1;

    flood_fill(map, (t_positon){begin.x - 1, begin.y});
    // flood_fill(map, (t_positon){begin.x + 1, begin.y});
    // flood_fill(map, (t_positon){begin.x, begin.y - 1});
    // flood_fill(map, (t_positon){begin.x, begin.y + 1});
    printf("%i -- %i\n", begin.x, begin.y);
}