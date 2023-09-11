#include <stdio.h>
#include <stdlib.h>

char *square_and_append(int number, char *str)
{
    int square = number * number;
    char square_str[20];

    snprintf(square_str, sizeof(square_str), "%d", square);
    
    strcat(str, square_str);

    return str;
}

int main()
{
    int num = 5;
    char result_str[50] = "The square of ";
    
    square_and_append(num, result_str);
    printf("%s is %s\n", result_str, result_str + 14);
    
    return 0;
}

