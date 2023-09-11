#include <stdio.h>

void print_game_instructions(void);
void start_game(void);
void print_high_scores(void);

/**
 * print_game_instructions - Displays instructions for a game.
 */
void print_game_instructions(void)
{
    printf("Welcome to the Adventure Game!\n");
    printf("In this game, you'll embark on a thrilling adventure.\n");
    printf("Type 'start' to begin your journey.\n");
    printf("Type 'help' to see the instructions again.\n");
    printf("Type 'scores' to view high scores.\n");
    printf("Type 'exit' to quit the game.\n");
}

/**
 * start_game - Starts the adventure game.
 */
void start_game(void)
{
    printf("You find yourself in a mysterious forest...\n");
    printf("Your adventure begins now!\n");
}

/**
 * print_high_scores - Displays the high scores of the game.
 */
void print_high_scores(void)
{
    printf("High Scores:\n");
    printf("1. Player1 - 1000 points\n");
    printf("2. Player2 - 800 points\n");
    printf("3. Player3 - 600 points\n");
}

int main()
{
    print_game_instructions();
    
    char userInput[20];
    while (1) {
        printf("\nEnter a command: ");
        scanf("%s", userInput);
        
        if (strcmp(userInput, "start") == 0) {
            start_game();
        } else if (strcmp(userInput, "help") == 0) {
            print_game_instructions();
        } else if (strcmp(userInput, "scores") == 0) {
            print_high_scores();
        } else if (strcmp(userInput, "exit") == 0) {
            printf("Thanks for playing! Goodbye!\n");
            break;
        } else {
            printf("Invalid command. Type 'help' for instructions.\n");
        }
    }
    
    return 0;
}

