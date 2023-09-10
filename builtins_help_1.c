#include <stdio.h>

void print_colors(void);
void print_shapes(void);
void print_instructions(void);

/**
 * print_colors - Displays a list of available colors.
 */
void print_colors(void)
{
    printf("Colors\n");
    printf("These are the available colors:\n");
    printf("- Red\n");
    printf("- Green\n");
    printf("- Blue\n");
    printf("- Yellow\n");
    printf("- Purple\n");
}

/**
 * print_shapes - Displays a list of geometric shapes.
 */
void print_shapes(void)
{
    printf("Geometric Shapes\n");
    printf("These are some geometric shapes:\n");
    printf("- Circle\n");
    printf("- Triangle\n");
    printf("- Square\n");
    printf("- Rectangle\n");
    printf("- Pentagon\n");
}

/**
 * print_instructions - Displays instructions on how to use the program.
 */
void print_instructions(void)
{
    printf("Drawing Program\n");
    printf("This is a simple drawing program.\n");
    printf("You can choose a color and draw shapes.\n");
    printf("Type 'colors' to see available colors.\n");
    printf("Type 'shapes' to see available shapes.\n");
    printf("Type 'exit' to quit the program.\n");
}

int main()
{
    print_instructions();
    
    printf("\n");
    
    print_colors();
    
    printf("\n");
    
    print_shapes();
    
    return 0;
}

