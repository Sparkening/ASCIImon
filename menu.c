#include <stdio.h>
#include "menu.h"

int display_main_menu() //display_main_menu is equal to the integer input 
{
    int start_choice;
    printf("\033[1;33m"
           " _______  _______  _______  ___  ___  __   __  _______  __    _ \n"
           "|       ||       ||       ||   ||   ||  |_|  ||       ||  |  | |\n"
           "|   _   ||  _____||       ||   ||   ||       ||   _   ||   |_| |\n"
           "|  |_|  || |_____ |       ||   ||   ||       ||  | |  ||       |\n"
           "|       ||_____  ||      _||   ||   ||       ||  |_|  ||  _    |\n"
           "|   _   | _____| ||     |_ |   ||   || ||_|| ||       || | |   |\n"
           "|__| |__||_______||_______||___||___||_|   |_||_______||_|  |__|\n"
           "\033[1;37m                       Gotta code 'em all!\033[0m\n\n");
    printf("1. Start Game\n");
    printf("2. Load savestate\n");
    printf("3. Settings\n");
    printf("4. Battle-Sim mode aka testing\n\n");
    printf("SELECT YOUR OPTION ");
    scanf("%i", &start_choice);

    return start_choice;
}