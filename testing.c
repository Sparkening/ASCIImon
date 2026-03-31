#include <stdio.h>
#include "system.h"
#include "testing.h"

int start_test_battle(Asciimon *player_mon)
{
    // items/potions
    int potion = 30;

    //pokemon declaration
    //Asciimon player_mon = {"Pikamon", 150, 150, 30, 45, 10};
    Asciimon enemy_mon = {"Charimon", 75, 75, 20, 40, 5, FIRE};

    // fight initialisation
    printf("\nYou encountered a wild %s! It's level is (%i)! Get ready for a fight!\n", enemy_mon.name, enemy_mon.level);

    while (player_mon -> current_hp > 0 && enemy_mon.current_hp > 0)
    {
        // Menu
        int player_choice;
        printf("\nChoose your move!\n");
        printf("1. Thunderbolt\n");
        printf("2. Potion\n");
        printf("Enter your choice: ");

        //scanf check - was an int inputed or a char?s
        if (scanf("%i", &player_choice) != 1)
        {
            while (getchar() != '\n');//empties the buffer
            printf("Please enter a valid Number!\n");
            continue; //restarts the entire function skipping the remaining code for this lap
            
        }
        

        // Game Loop | player choice checks
        if (player_choice == 1)
        {
            enemy_mon.current_hp -= player_mon -> attack_power;
            printf("%s now has %i hp left!\n", enemy_mon.name, enemy_mon.current_hp);
        }
        else if (player_choice == 2)
        {
            if (player_mon -> current_hp == player_mon -> max_hp)
            {
                printf("%s is already fully healed! \n", player_mon -> name);
            }
            else
            {
                player_mon -> current_hp += potion;
                if (player_mon -> current_hp >= player_mon -> max_hp)
                {
                    player_mon -> current_hp = player_mon -> max_hp;
                }
                printf("%s has been healed, it's remaining health is %i\n", player_mon -> name, player_mon -> current_hp);
            }
        }
        else
        {
            printf("Invalid input\n");
        }

        //Health checks
        if (enemy_mon.current_hp > 0)
        {
            player_mon -> current_hp -= enemy_mon.attack_power;
            printf("%s has been hit by a fireball! It's remaining hp is %i!\n\n", player_mon -> name, player_mon -> current_hp);
        }
        else if (enemy_mon.current_hp <= 0)
        {
            printf("%s has been defeated! %s has a grand total of %i hp left!\n\n",enemy_mon.name, player_mon -> name, player_mon -> current_hp);
            return 1;
        }
        if (player_mon -> current_hp <= 0)
        {
            printf("%s has been defeated! %s laughs at you!\n\n", player_mon -> name, enemy_mon.name);
            return 2;
        }
    }
}