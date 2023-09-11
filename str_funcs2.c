#include <stdio.h>

int custom_strlen(const char *s);
int custom_strcmp(const char *s1, const char *s2);
void custom_strcat(char *dest, const char *src);
int custom_sum(int a, int b);

int custom_strlen(const char *s)
{
    int length = 0;
    
    while (*s != '\0')
    {
        length++;
        s++;
    }
    
    return length;
}

int custom_strcmp(const char *s1, const char *s2)
{
    while (*s1 == *s2)
    {
        if (*s1 == '\0')
            return 0;
        s1++;
        s2++;
    }
    
    return (*s1 - *s2);
}

void custom_strcat(char *dest, const char *src)
{
    while (*dest != '\0')
    {
        dest++;
    }
    
    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    
    *dest = '\0';
}

int custom_sum(int a, int b)
{
    return a + b;
}

int main()
{
    const char *str1 = "Hello, ";
    const char *str2 = "world!";
    char result[100];
    int num1 = 10;
    int num2 = 20;
    
    printf("Length of str1: %d\n", custom_strlen(str1));
    
    printf("Comparison result: %d\n", custom_strcmp(str1, str2));
    
    custom_strcat(result, str1);
    custom_strcat(result, str2);
    printf("Concatenated string: %s\n", result);
    
    printf("Sum of %d and %d: %d\n", num1, num2, custom_sum(num1, num2));
    
    return 0;
}

