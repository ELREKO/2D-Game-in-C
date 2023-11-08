#include "../include/so_long.h"

static t_positon *ft_find_player_position(t_lay **map);
static void	flood_fill_me(t_lay **map, t_positon begin, char ch);
static int ft_sreen_size (t_lay **map);
//int	flood_fill(char **tab, t_positon size, t_positon begin);

// return the player Position
t_positon *ft_check_payable(t_lay **map)
{
    t_positon *player_pos;
    t_lay *map_copy;

    player_pos = ft_find_player_position(map);
    map_copy = copy_t_lay(*map);
    ft_sreen_size(map);

    //ft_print_out_map(map_copy);
    flood_fill_me(&map_copy, *player_pos, 'V');
    //ft_print_out_map(map_copy);
    //printf ("Collectable %i  Exit %i\n", map_copy->i_collect, map_copy->i_exit);
    if (map_copy->i_collect > 0 || map_copy->i_exit > 0)
    {
        ft_free_map_struct(&map_copy);
        ft_throw_map_error(map,300);
    }
    ft_free_map_struct(&map_copy);
    // int i = flood_fill((*map)->map, (t_positon){(*map)->i_x, (*map)->i_y}, (t_positon){player_pos->x, player_pos->y});
    // printf ("\nCollectabel are %i\n", i);
    

    return (player_pos);
}

// Check if the given map compatible with the screen_size
static int ft_sreen_size (t_lay **map)
{
    Display *display;
    Screen *screen = DefaultScreenOfDisplay(display);
    unsigned int screen_widt;
    unsigned int screen_height;

    display = XOpenDisplay(NULL);
    screen = DefaultScreenOfDisplay(display);
    screen_widt = WidthOfScreen(screen);
    screen_height = HeightOfScreen(screen);
    if (((*map)->i_x * 50) > (screen_widt-150))
        ft_throw_map_error(map, 310);
    if (((*map)->i_y * 50) > (screen_height-150))
        ft_throw_map_error(map, 320);
    XCloseDisplay(display);
    return 0;
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


static void flood_fill_me(t_lay **map, t_positon begin, char to_Fill)
{
     if ((*map)->map[begin.y][begin.x] == to_Fill || begin.y < 1 || begin.y >= (*map)->i_y || 
            begin.x < 1 || begin.x >= (*map)->i_x || (*map)->map[begin.y][begin.x] == '1')
     {
        return; // Basisfall: Außerhalb der Karte oder Wand erreicht
    }

    // Führen Sie die Aktionen für 'E' und 'C' aus
    if ((*map)->map[begin.y][begin.x] == 'E')
        (*map)->i_exit = (*map)->i_exit - 1;
    else if ((*map)->map[begin.y][begin.x] == 'C')
        (*map)->i_collect = (*map)->i_collect - 1;

    (*map)->map[begin.y][begin.x] = to_Fill;

    // Rekursive Aufrufe für benachbarte Felder
    flood_fill_me(map, (t_positon){begin.x - 1, begin.y}, to_Fill);
    flood_fill_me(map, (t_positon){begin.x + 1, begin.y}, to_Fill);
    flood_fill_me(map, (t_positon){begin.x, begin.y - 1}, to_Fill);
    flood_fill_me(map, (t_positon){begin.x, begin.y + 1}, to_Fill);
}
