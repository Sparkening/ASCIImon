#include <stdio.h>
#include "game.h"
#include "system.h"

// world and character testing ignore for now change location later TODO

char world_map[MAP_RVERT][MAP_CHORI];

void init_map() // drawing the world
{
    for (int r = 0; r < MAP_RVERT; r++)
    {
        for (int c = 0; c < MAP_CHORI; c++)
        {
            world_map[r][c] = '.';
        }
    }
}

int player_r = 5;
int player_c = 5;

void player_location() // drawing the playerlocation
{
    world_map[player_r][player_c] = '@';
}

void build_house(int start_r, int start_c, int height, int width)
{
    for (int r = start_r; r < (height + start_r); r++)
    {
        for (int c = start_c; c < (width + start_c); c++)
        {
            world_map[r][c] = '#';
        }
    }
    int door_r = start_r + height - 1;
    int door_c = start_c + width / 2;
    world_map[door_r][door_c] = '+';
}

void build_city()
{
    build_house(4, 8, 5, 10);   // player home
    build_house(4, 40, 5, 10);  // rival home
    build_house(14, 34, 8, 18); // oaks lab
}

void draw_map() // printing the world
{
    for (int r = 0; r < MAP_RVERT; r++)
    {
        for (int c = 0; c < MAP_CHORI; c++)
        {
            if (world_map[r][c] == '.')
            {
                printf("\033[0;32m%c\033[0m", world_map[r][c]);
            }
            else if (world_map[r][c] == '#')
            {
                printf("\033[0;34m%c\033[0m", world_map[r][c]);
            }
            else if (world_map[r][c] == '+')
            {
                printf("\033[0;33m%c\033[0m", world_map[r][c]);
            }
            else
            {
                printf("%c", world_map[r][c]);
            }
        }
        printf("\n");
    }
}