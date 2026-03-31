#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "menu.h"
#include "game.h"
#include "system.h"
//#include "testing.h"
#include "battling.h"

int main()
{
    //main two test Asciimon
    Asciimon player_mon = {"Pikamon", 150, 150, 30, 45, 10, WATER}; //element of water for game logic tests
    //Asciimon enemy_mon = {"Charimon", 75, 75, 20, 40, 5, FIRE}; not necessary here since the enemy_mon shouldnt safe its values over time!!!

    int game_is_running = 1;
    GameState current_state = STATE_MAIN_MENU;

    // random seed based on time
    srand(time(NULL));

    while (game_is_running)
    {
        switch (current_state)
        {
        case STATE_MAIN_MENU:
            int menu_option = display_main_menu();
            if (menu_option == 1)
            {
                current_state = STATE_MAIN_GAME;
                player_mon.current_hp = player_mon.max_hp;
            }
            else if (menu_option == 2)
            {
                current_state = STATE_SAVES;
            }
            else if (menu_option == 3)
            {
                current_state = STATE_SETTINGS;
            }
            else if (menu_option == 4)
            {
                current_state = STATE_BATTLE_SIM;
            }
            else
            {
                printf("Invalid Input\n");
            }
            break;

        case STATE_MAIN_GAME:
            init_map();
            player_location();
            build_city();
            draw_map();
            printf("Move (w/a/s/d): ");
            char move;
            scanf(" %c", &move);
            printf("\n");
            switch (move)
            {
            case 'w':
                if (player_r > 0 && world_map[player_r - 1][player_c] != '#')
                {
                    player_r--;
                }
                break;
            case 'a':
                if (player_c > 0 && world_map[player_r][player_c - 1] != '#')
                {
                    player_c--;
                }
                break;
            case 's':
                if (player_r < MAP_RVERT -1 && world_map[player_r + 1][player_c] != '#')
                {
                    player_r++;
                }
                break;
            case 'd':
                if (player_c < MAP_CHORI -1 && world_map[player_r][player_c + 1] != '#')
                {
                    player_c++;
                }
                break;
            default:
                printf("invalid input\n");
                break;
            }
            int spawn_chance = rand() % 10;
            if (spawn_chance == 0 && world_map[player_r][player_c] == '.')
            {
                current_state = STATE_BATTLING; // changes state to the battling state
            }
            break;

        case STATE_SAVES:
            break;

        case STATE_SETTINGS:
            break;

        case STATE_PAUSE_MENU:
            break;

        case STATE_BATTLING:
            int battle_result = battle(&player_mon); //starts the battle
            if (battle_result == 1)
            {
                current_state = STATE_MAIN_GAME;
                printf("Good Job! You won!\n");
            }
            else if (battle_result == 2)
            {
                current_state = STATE_MAIN_MENU;
                printf("Oh no! You lost, better luck next time!\n");
            }

            break;

        case STATE_BATTLE_SIM:
            battle(&player_mon); // from testing.c
            break;
        }
    }

    return 0;
}