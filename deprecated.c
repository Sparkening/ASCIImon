int start_choice = display_main_menu();
    // pokemon health
    int pikachu_hp = 100;
    int charizard_hp = 150;

    // attacks
    int attack_thunderbolt = 20; // pikachu attack
    int attack_fireball = 25;    // charizard attack

    // items/potions
    int potion = 30;

    // fight initialisation
    printf("You encountered a wild charizard! Get ready for a fight!\n");

    while (pikachu_hp > 0 && charizard_hp > 0)
    {
        // Menu
        int player_choice;
        printf("Choose your move!\n");
        printf("1. Thunderbolt\n");
        printf("2. Potion\n");
        printf("Enter your choice: ");
        scanf("%i", &player_choice);

        // Game Loop
        if (player_choice == 1)
        {
            charizard_hp -= attack_thunderbolt;
            printf("Charizard now has %i hp left!\n", charizard_hp);
        }
        else if (player_choice == 2)
        {
            if (pikachu_hp == 100)
            {
                printf("Pikachu is already fully healed! \n");
            }
            else
            {
                pikachu_hp += potion;
                if (pikachu_hp >= 100)
                {
                    pikachu_hp = 100;
                }
                printf("Pikachu has been healed, it's remaining health is %i\n", pikachu_hp);
            }
        }
        else
        {
            printf("Invalid input\n");
        }
        if (charizard_hp > 0)
        {
            pikachu_hp -= attack_fireball;
            printf("Pikachu has been hit by a fireball! It's remaining hp is %i!\n\n", pikachu_hp);
        }
        else if (charizard_hp <= 0)
        {
            printf("Charizard has been defeated! Pikachu has a grand total of %i hp left!\n\n", pikachu_hp);
        }
        if (pikachu_hp <= 0)
        {
            printf("Pikachu has been defeated! Charizard laughs at you!\n\n");
        }
    }
    return 0;
}


















int start_choice = display_main_menu();

    if (start_choice == 1){
        printf("\nStarting game...\n\n");
        start_battle();
    }
    else if (start_choice == 2){
        printf("Loading save...\n");
    } 
    else if (start_choice == 3) {
        printf("Loading settings...\n");
    }
    else {
        printf("Invalid Input\n");
    }


                if (move == 'w' && player_r > 0)
            {
                player_r--;
            }
            else if (move == 's' && player_r < 9)
            {
                player_r++;
            }
            else if (move == 'd' && player_c < 9)
            {
                player_c++;
            }
            else if (move == 'a' && player_c > 0)
            {
                player_c--;
            }
            else
            {
                printf("Invalid Input\n");
            }